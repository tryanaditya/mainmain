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

#include "qgraphicseffect_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qgraphicseffect.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QGraphicsEffectWrapper::QGraphicsEffectWrapper(QObject * parent) : QGraphicsEffect(parent) {
    // ... middle
}

QRectF QGraphicsEffectWrapper::boundingRectFor(const QRectF & sourceRect) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRectF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "boundingRectFor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsEffect::boundingRectFor(sourceRect);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &sourceRect)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRectF();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsEffect.boundingRectFor", Shiboken::SbkType< QRectF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRectF();
    }
    ::QRectF cppResult = ::QRectF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsEffectWrapper::childEvent(QChildEvent * arg__1)
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

void QGraphicsEffectWrapper::connectNotify(const char * signal)
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

void QGraphicsEffectWrapper::customEvent(QEvent * arg__1)
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

void QGraphicsEffectWrapper::disconnectNotify(const char * signal)
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

void QGraphicsEffectWrapper::draw(QPainter * painter)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "draw"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsEffect.draw()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QGraphicsEffectWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsEffect.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGraphicsEffectWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsEffect.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QGraphicsEffectWrapper::sourceChanged(QFlags<QGraphicsEffect::ChangeFlag> flags)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sourceChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsEffect::sourceChanged(flags);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), &flags)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsEffectWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QGraphicsEffectWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGraphicsEffect::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGraphicsEffectWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGraphicsEffect::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGraphicsEffectWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGraphicsEffectWrapper* >(this));
        return QGraphicsEffect::qt_metacast(_clname);
}

QGraphicsEffectWrapper::~QGraphicsEffectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsEffect_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QGraphicsEffect' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsEffect >()))
        return -1;

    ::QGraphicsEffectWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QGraphicsEffect", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsEffect(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsEffect(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGraphicsEffect(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffect_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsEffect_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsEffect(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QGraphicsEffectWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QGraphicsEffectWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsEffect >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsEffect_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QGraphicsEffect_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsEffect", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsEffectFunc_boundingRect(PyObject* self)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsEffect*>(cppSelf)->boundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsEffectFunc_boundingRectFor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: boundingRectFor(QRectF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // boundingRectFor(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_boundingRectFor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRectF cppArg0_local = ::QRectF();
        ::QRectF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // boundingRectFor(QRectF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsEffect*>(cppSelf)->::QGraphicsEffect::boundingRectFor(*cppArg0) : const_cast<const ::QGraphicsEffect*>(cppSelf)->boundingRectFor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsEffectFunc_boundingRectFor_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsEffect.boundingRectFor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_draw(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: draw(QPainter*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArg)))) {
        overloadId = 0; // draw(QPainter*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_draw_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // draw(QPainter*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsEffect.draw()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->draw(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsEffectFunc_draw_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsEffect.draw", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_drawSource(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawSource(QPainter*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArg)))) {
        overloadId = 0; // drawSource(QPainter*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_drawSource_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // drawSource(QPainter*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->drawSource(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsEffectFunc_drawSource_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsEffect.drawSource", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_isEnabled(PyObject* self)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsEffect*>(cppSelf)->isEnabled();
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

static PyObject* Sbk_QGraphicsEffectFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_setEnabled_TypeError;

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

    Sbk_QGraphicsEffectFunc_setEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsEffect.setEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_sourceBoundingRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect.sourceBoundingRect(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:sourceBoundingRect", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: sourceBoundingRect(Qt::CoordinateSystem)const
    if (numArgs == 0) {
        overloadId = 0; // sourceBoundingRect(Qt::CoordinateSystem)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX]), (pyArgs[0])))) {
        overloadId = 0; // sourceBoundingRect(Qt::CoordinateSystem)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_sourceBoundingRect_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "system");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect.sourceBoundingRect(): got multiple values for keyword argument 'system'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsEffectFunc_sourceBoundingRect_TypeError;
            }
        }
        ::Qt::CoordinateSystem cppArg0 = Qt::LogicalCoordinates;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // sourceBoundingRect(Qt::CoordinateSystem)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsEffect*>(cppSelf)->sourceBoundingRect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsEffectFunc_sourceBoundingRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CoordinateSystem = Qt.LogicalCoordinates", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsEffect.sourceBoundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_sourceChanged(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sourceChanged(QFlags<QGraphicsEffect::ChangeFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // sourceChanged(QFlags<QGraphicsEffect::ChangeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_sourceChanged_TypeError;

    // Call function/method
    {
        ::QFlags<QGraphicsEffect::ChangeFlag> cppArg0 = ((::QFlags<QGraphicsEffect::ChangeFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sourceChanged(QFlags<QGraphicsEffect::ChangeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsEffect::sourceChanged(cppArg0) : cppSelf->sourceChanged(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsEffectFunc_sourceChanged_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsEffect.ChangeFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsEffect.sourceChanged", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_sourceIsPixmap(PyObject* self)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sourceIsPixmap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsEffect*>(cppSelf)->sourceIsPixmap();
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

static PyObject* Sbk_QGraphicsEffectFunc_sourcePixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect.sourcePixmap(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:sourcePixmap", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: sourcePixmap(Qt::CoordinateSystem,QPoint*,QGraphicsEffect::PixmapPadMode)const
    if (numArgs == 0) {
        overloadId = 0; // sourcePixmap(Qt::CoordinateSystem,QPoint*,QGraphicsEffect::PixmapPadMode)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // sourcePixmap(Qt::CoordinateSystem,QPoint*,QGraphicsEffect::PixmapPadMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // sourcePixmap(Qt::CoordinateSystem,QPoint*,QGraphicsEffect::PixmapPadMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // sourcePixmap(Qt::CoordinateSystem,QPoint*,QGraphicsEffect::PixmapPadMode)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsEffectFunc_sourcePixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "system");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect.sourcePixmap(): got multiple values for keyword argument 'system'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsEffectFunc_sourcePixmap_TypeError;
            }
            value = PyDict_GetItemString(kwds, "offset");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect.sourcePixmap(): got multiple values for keyword argument 'offset'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsEffectFunc_sourcePixmap_TypeError;
            }
            value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsEffect.sourcePixmap(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX]), (pyArgs[2]))))
                    goto Sbk_QGraphicsEffectFunc_sourcePixmap_TypeError;
            }
        }
        ::Qt::CoordinateSystem cppArg0 = Qt::LogicalCoordinates;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPoint* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QGraphicsEffect::PixmapPadMode cppArg2 = QGraphicsEffect::PadToEffectiveBoundingRect;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // sourcePixmap(Qt::CoordinateSystem,QPoint*,QGraphicsEffect::PixmapPadMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QGraphicsEffect*>(cppSelf)->sourcePixmap(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsEffectFunc_sourcePixmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CoordinateSystem = Qt.LogicalCoordinates, PySide.QtCore.QPoint = None, PySide.QtGui.QGraphicsEffect.PixmapPadMode = PadToEffectiveBoundingRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsEffect.sourcePixmap", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsEffectFunc_update(PyObject* self)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // update()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->update();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsEffectFunc_updateBoundingRect(PyObject* self)
{
    ::QGraphicsEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateBoundingRect()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateBoundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QGraphicsEffect_methods[] = {
    {"boundingRect", (PyCFunction)Sbk_QGraphicsEffectFunc_boundingRect, METH_NOARGS},
    {"boundingRectFor", (PyCFunction)Sbk_QGraphicsEffectFunc_boundingRectFor, METH_O},
    {"draw", (PyCFunction)Sbk_QGraphicsEffectFunc_draw, METH_O},
    {"drawSource", (PyCFunction)Sbk_QGraphicsEffectFunc_drawSource, METH_O},
    {"isEnabled", (PyCFunction)Sbk_QGraphicsEffectFunc_isEnabled, METH_NOARGS},
    {"setEnabled", (PyCFunction)Sbk_QGraphicsEffectFunc_setEnabled, METH_O},
    {"sourceBoundingRect", (PyCFunction)Sbk_QGraphicsEffectFunc_sourceBoundingRect, METH_VARARGS|METH_KEYWORDS},
    {"sourceChanged", (PyCFunction)Sbk_QGraphicsEffectFunc_sourceChanged, METH_O},
    {"sourceIsPixmap", (PyCFunction)Sbk_QGraphicsEffectFunc_sourceIsPixmap, METH_NOARGS},
    {"sourcePixmap", (PyCFunction)Sbk_QGraphicsEffectFunc_sourcePixmap, METH_VARARGS|METH_KEYWORDS},
    {"update", (PyCFunction)Sbk_QGraphicsEffectFunc_update, METH_NOARGS},
    {"updateBoundingRect", (PyCFunction)Sbk_QGraphicsEffectFunc_updateBoundingRect, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsEffect_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsEffect_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsEffect_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsEffect",
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
    /*tp_traverse*/         Sbk_QGraphicsEffect_traverse,
    /*tp_clear*/            Sbk_QGraphicsEffect_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsEffect_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsEffect_Init,
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

static void* Sbk_QGraphicsEffect_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGraphicsEffect*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect::ChangeFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsEffect::ChangeFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsEffect::ChangeFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsEffect::ChangeFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsEffect::ChangeFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect::ChangeFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsEffect::ChangeFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsEffect::ChangeFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsEffect::ChangeFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsEffect::ChangeFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect::ChangeFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsEffect::ChangeFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsEffect::ChangeFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsEffect::ChangeFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsEffect::ChangeFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsEffect::ChangeFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), self, &cppSelf);
    ::QGraphicsEffect::ChangeFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGraphicsEffect_ChangeFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGraphicsEffect_ChangeFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGraphicsEffect_ChangeFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGraphicsEffect_ChangeFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGraphicsEffect_ChangeFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGraphicsEffect_ChangeFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGraphicsEffect_ChangeFlag_long,
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
static void QGraphicsEffect_ChangeFlag_PythonToCpp_QGraphicsEffect_ChangeFlag(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsEffect::ChangeFlag*)cppOut) = (::QGraphicsEffect::ChangeFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsEffect_ChangeFlag_PythonToCpp_QGraphicsEffect_ChangeFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX]))
        return QGraphicsEffect_ChangeFlag_PythonToCpp_QGraphicsEffect_ChangeFlag;
    return 0;
}
static PyObject* QGraphicsEffect_ChangeFlag_CppToPython_QGraphicsEffect_ChangeFlag(const void* cppIn) {
    int castCppIn = *((::QGraphicsEffect::ChangeFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX], castCppIn);

}

static void QFlags_QGraphicsEffect_ChangeFlag__PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsEffect::ChangeFlag>*)cppOut) = ::QFlags<QGraphicsEffect::ChangeFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGraphicsEffect_ChangeFlag__PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]))
        return QFlags_QGraphicsEffect_ChangeFlag__PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_;
    return 0;
}
static PyObject* QFlags_QGraphicsEffect_ChangeFlag__CppToPython_QFlags_QGraphicsEffect_ChangeFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGraphicsEffect::ChangeFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]));

}

static void QGraphicsEffect_ChangeFlag_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsEffect::ChangeFlag>*)cppOut) = ::QFlags<QGraphicsEffect::ChangeFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGraphicsEffect_ChangeFlag_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX]))
        return QGraphicsEffect_ChangeFlag_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGraphicsEffect::ChangeFlag>*)cppOut) = ::QFlags<QGraphicsEffect::ChangeFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_;
    return 0;
}
static void QGraphicsEffect_PixmapPadMode_PythonToCpp_QGraphicsEffect_PixmapPadMode(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsEffect::PixmapPadMode*)cppOut) = (::QGraphicsEffect::PixmapPadMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsEffect_PixmapPadMode_PythonToCpp_QGraphicsEffect_PixmapPadMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX]))
        return QGraphicsEffect_PixmapPadMode_PythonToCpp_QGraphicsEffect_PixmapPadMode;
    return 0;
}
static PyObject* QGraphicsEffect_PixmapPadMode_CppToPython_QGraphicsEffect_PixmapPadMode(const void* cppIn) {
    int castCppIn = *((::QGraphicsEffect::PixmapPadMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsEffect_PythonToCpp_QGraphicsEffect_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsEffect_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsEffect_PythonToCpp_QGraphicsEffect_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsEffect_Type))
        return QGraphicsEffect_PythonToCpp_QGraphicsEffect_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsEffect_PTR_CppToPython_QGraphicsEffect(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGraphicsEffect*)cppIn, &Sbk_QGraphicsEffect_Type);

}

void init_QGraphicsEffect(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsEffect_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsEffect", "QGraphicsEffect*",
        &Sbk_QGraphicsEffect_Type, &Shiboken::callCppDestructor< ::QGraphicsEffect >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsEffect_Type,
        QGraphicsEffect_PythonToCpp_QGraphicsEffect_PTR,
        is_QGraphicsEffect_PythonToCpp_QGraphicsEffect_PTR_Convertible,
        QGraphicsEffect_PTR_CppToPython_QGraphicsEffect);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsEffect");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsEffect*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsEffect&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsEffect).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsEffectWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsEffect_Type, &Sbk_QGraphicsEffect_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ChangeFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX] = PySide::QFlags::create("ChangeFlags", &SbkPySide_QtGui_QGraphicsEffect_ChangeFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsEffect_Type,
        "ChangeFlag",
        "PySide.QtGui.QGraphicsEffect.ChangeFlag",
        "QGraphicsEffect::ChangeFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX],
        &Sbk_QGraphicsEffect_Type, "SourceAttached", (long) QGraphicsEffect::SourceAttached))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX],
        &Sbk_QGraphicsEffect_Type, "SourceDetached", (long) QGraphicsEffect::SourceDetached))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX],
        &Sbk_QGraphicsEffect_Type, "SourceBoundingRectChanged", (long) QGraphicsEffect::SourceBoundingRectChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX],
        &Sbk_QGraphicsEffect_Type, "SourceInvalidated", (long) QGraphicsEffect::SourceInvalidated))
        return ;
    // Register converter for enum 'QGraphicsEffect::ChangeFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX],
            QGraphicsEffect_ChangeFlag_CppToPython_QGraphicsEffect_ChangeFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsEffect_ChangeFlag_PythonToCpp_QGraphicsEffect_ChangeFlag,
            is_QGraphicsEffect_ChangeFlag_PythonToCpp_QGraphicsEffect_ChangeFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_CHANGEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsEffect::ChangeFlag");
        Shiboken::Conversions::registerConverterName(converter, "ChangeFlag");
    }
    // Register converter for flag 'QFlags<QGraphicsEffect::ChangeFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX],
            QFlags_QGraphicsEffect_ChangeFlag__CppToPython_QFlags_QGraphicsEffect_ChangeFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsEffect_ChangeFlag_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_,
            is_QGraphicsEffect_ChangeFlag_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGraphicsEffect_ChangeFlag__PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_,
            is_QFlags_QGraphicsEffect_ChangeFlag__PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag_,
            is_number_PythonToCpp_QFlags_QGraphicsEffect_ChangeFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSEFFECT_CHANGEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGraphicsEffect::ChangeFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ChangeFlag>");
    }
    // End of 'ChangeFlag' enum/flags.

    // Initialization of enum 'PixmapPadMode'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsEffect_Type,
        "PixmapPadMode",
        "PySide.QtGui.QGraphicsEffect.PixmapPadMode",
        "QGraphicsEffect::PixmapPadMode");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX],
        &Sbk_QGraphicsEffect_Type, "NoPad", (long) QGraphicsEffect::NoPad))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX],
        &Sbk_QGraphicsEffect_Type, "PadToTransparentBorder", (long) QGraphicsEffect::PadToTransparentBorder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX],
        &Sbk_QGraphicsEffect_Type, "PadToEffectiveBoundingRect", (long) QGraphicsEffect::PadToEffectiveBoundingRect))
        return ;
    // Register converter for enum 'QGraphicsEffect::PixmapPadMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX],
            QGraphicsEffect_PixmapPadMode_CppToPython_QGraphicsEffect_PixmapPadMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsEffect_PixmapPadMode_PythonToCpp_QGraphicsEffect_PixmapPadMode,
            is_QGraphicsEffect_PixmapPadMode_PythonToCpp_QGraphicsEffect_PixmapPadMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_PIXMAPPADMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsEffect::PixmapPadMode");
        Shiboken::Conversions::registerConverterName(converter, "PixmapPadMode");
    }
    // End of 'PixmapPadMode' enum.

    PySide::Signal::registerSignals(&Sbk_QGraphicsEffect_Type, &::QGraphicsEffect::staticMetaObject);

    qRegisterMetaType< ::QGraphicsEffect::ChangeFlag >("QGraphicsEffect::ChangeFlag");
    qRegisterMetaType< ::QGraphicsEffect::ChangeFlags >("QGraphicsEffect::ChangeFlags");
    qRegisterMetaType< ::QGraphicsEffect::PixmapPadMode >("QGraphicsEffect::PixmapPadMode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGraphicsEffect_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGraphicsEffect_Type, &::QGraphicsEffect::staticMetaObject, sizeof(::QGraphicsEffect));
}
