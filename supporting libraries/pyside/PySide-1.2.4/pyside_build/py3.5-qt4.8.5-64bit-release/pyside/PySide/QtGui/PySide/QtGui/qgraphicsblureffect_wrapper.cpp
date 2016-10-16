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

#include "qgraphicsblureffect_wrapper.h"

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

QGraphicsBlurEffectWrapper::QGraphicsBlurEffectWrapper(QObject * parent) : QGraphicsBlurEffect(parent) {
    // ... middle
}

QRectF QGraphicsBlurEffectWrapper::boundingRectFor(const QRectF & rect) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRectF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "boundingRectFor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsBlurEffect::boundingRectFor(rect);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &rect)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsBlurEffect.boundingRectFor", Shiboken::SbkType< QRectF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRectF();
    }
    ::QRectF cppResult = ::QRectF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsBlurEffectWrapper::childEvent(QChildEvent * arg__1)
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

void QGraphicsBlurEffectWrapper::connectNotify(const char * signal)
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

void QGraphicsBlurEffectWrapper::customEvent(QEvent * arg__1)
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

void QGraphicsBlurEffectWrapper::disconnectNotify(const char * signal)
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

void QGraphicsBlurEffectWrapper::draw(QPainter * painter)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "draw"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsBlurEffect::draw(painter);
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

bool QGraphicsBlurEffectWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsBlurEffect.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGraphicsBlurEffectWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsBlurEffect.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QGraphicsBlurEffectWrapper::sourceChanged(QFlags<QGraphicsEffect::ChangeFlag> flags)
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

void QGraphicsBlurEffectWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QGraphicsBlurEffectWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGraphicsBlurEffect::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGraphicsBlurEffectWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGraphicsBlurEffect::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGraphicsBlurEffectWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGraphicsBlurEffectWrapper* >(this));
        return QGraphicsBlurEffect::qt_metacast(_clname);
}

QGraphicsBlurEffectWrapper::~QGraphicsBlurEffectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsBlurEffect_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsBlurEffect >()))
        return -1;

    ::QGraphicsBlurEffectWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QGraphicsBlurEffect", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsBlurEffect(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsBlurEffect(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGraphicsBlurEffect(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsBlurEffect_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsBlurEffect(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsBlurEffect_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsBlurEffect(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QGraphicsBlurEffectWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QGraphicsBlurEffectWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsBlurEffect >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsBlurEffect_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QGraphicsBlurEffect_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsBlurEffect", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsBlurEffectFunc_blurHints(PyObject* self)
{
    ::QGraphicsBlurEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsBlurEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blurHints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGraphicsBlurEffect::BlurHint> cppResult = const_cast<const ::QGraphicsBlurEffect*>(cppSelf)->blurHints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsBlurEffectFunc_blurRadius(PyObject* self)
{
    ::QGraphicsBlurEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsBlurEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blurRadius()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsBlurEffect*>(cppSelf)->blurRadius();
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

static PyObject* Sbk_QGraphicsBlurEffectFunc_boundingRectFor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsBlurEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsBlurEffectFunc_boundingRectFor_TypeError;

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
            QRectF cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsBlurEffect*>(cppSelf)->::QGraphicsBlurEffect::boundingRectFor(*cppArg0) : const_cast<const ::QGraphicsBlurEffect*>(cppSelf)->boundingRectFor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsBlurEffectFunc_boundingRectFor_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsBlurEffect.boundingRectFor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsBlurEffectFunc_draw(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsBlurEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: draw(QPainter*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArg)))) {
        overloadId = 0; // draw(QPainter*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsBlurEffectFunc_draw_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // draw(QPainter*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsBlurEffect::draw(cppArg0) : cppSelf->draw(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsBlurEffectFunc_draw_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsBlurEffect.draw", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsBlurEffectFunc_setBlurHints(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsBlurEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlurHints(QFlags<QGraphicsBlurEffect::BlurHint>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), (pyArg)))) {
        overloadId = 0; // setBlurHints(QFlags<QGraphicsBlurEffect::BlurHint>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsBlurEffectFunc_setBlurHints_TypeError;

    // Call function/method
    {
        ::QFlags<QGraphicsBlurEffect::BlurHint> cppArg0 = ((::QFlags<QGraphicsBlurEffect::BlurHint>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBlurHints(QFlags<QGraphicsBlurEffect::BlurHint>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlurHints(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsBlurEffectFunc_setBlurHints_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsBlurEffect.BlurHints", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsBlurEffect.setBlurHints", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsBlurEffectFunc_setBlurRadius(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsBlurEffect*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlurRadius(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBlurRadius(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsBlurEffectFunc_setBlurRadius_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBlurRadius(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlurRadius(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsBlurEffectFunc_setBlurRadius_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsBlurEffect.setBlurRadius", overloads);
        return 0;
}

static PyMethodDef Sbk_QGraphicsBlurEffect_methods[] = {
    {"blurHints", (PyCFunction)Sbk_QGraphicsBlurEffectFunc_blurHints, METH_NOARGS},
    {"blurRadius", (PyCFunction)Sbk_QGraphicsBlurEffectFunc_blurRadius, METH_NOARGS},
    {"boundingRectFor", (PyCFunction)Sbk_QGraphicsBlurEffectFunc_boundingRectFor, METH_O},
    {"draw", (PyCFunction)Sbk_QGraphicsBlurEffectFunc_draw, METH_O},
    {"setBlurHints", (PyCFunction)Sbk_QGraphicsBlurEffectFunc_setBlurHints, METH_O},
    {"setBlurRadius", (PyCFunction)Sbk_QGraphicsBlurEffectFunc_setBlurRadius, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsBlurEffect_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsBlurEffect_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsBlurEffect_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsBlurEffect",
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
    /*tp_traverse*/         Sbk_QGraphicsBlurEffect_traverse,
    /*tp_clear*/            Sbk_QGraphicsBlurEffect_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsBlurEffect_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsBlurEffect_Init,
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

static void* Sbk_QGraphicsBlurEffect_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGraphicsBlurEffect*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___and__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect::BlurHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsBlurEffect::BlurHints)PyLong_AsLong(self);
    cppArg = (QGraphicsBlurEffect::BlurHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsBlurEffect::BlurHints)PyInt_AsLong(self);
    cppArg = (QGraphicsBlurEffect::BlurHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___or__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect::BlurHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsBlurEffect::BlurHints)PyLong_AsLong(self);
    cppArg = (QGraphicsBlurEffect::BlurHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsBlurEffect::BlurHints)PyInt_AsLong(self);
    cppArg = (QGraphicsBlurEffect::BlurHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect::BlurHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsBlurEffect::BlurHints)PyLong_AsLong(self);
    cppArg = (QGraphicsBlurEffect::BlurHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsBlurEffect::BlurHints)PyInt_AsLong(self);
    cppArg = (QGraphicsBlurEffect::BlurHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsBlurEffect::BlurHints cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), self, &cppSelf);
    ::QGraphicsBlurEffect::BlurHints cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint_long,
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
static void QGraphicsBlurEffect_BlurHint_PythonToCpp_QGraphicsBlurEffect_BlurHint(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsBlurEffect::BlurHint*)cppOut) = (::QGraphicsBlurEffect::BlurHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsBlurEffect_BlurHint_PythonToCpp_QGraphicsBlurEffect_BlurHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX]))
        return QGraphicsBlurEffect_BlurHint_PythonToCpp_QGraphicsBlurEffect_BlurHint;
    return 0;
}
static PyObject* QGraphicsBlurEffect_BlurHint_CppToPython_QGraphicsBlurEffect_BlurHint(const void* cppIn) {
    int castCppIn = *((::QGraphicsBlurEffect::BlurHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX], castCppIn);

}

static void QFlags_QGraphicsBlurEffect_BlurHint__PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsBlurEffect::BlurHint>*)cppOut) = ::QFlags<QGraphicsBlurEffect::BlurHint>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGraphicsBlurEffect_BlurHint__PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]))
        return QFlags_QGraphicsBlurEffect_BlurHint__PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_;
    return 0;
}
static PyObject* QFlags_QGraphicsBlurEffect_BlurHint__CppToPython_QFlags_QGraphicsBlurEffect_BlurHint_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGraphicsBlurEffect::BlurHint>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]));

}

static void QGraphicsBlurEffect_BlurHint_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsBlurEffect::BlurHint>*)cppOut) = ::QFlags<QGraphicsBlurEffect::BlurHint>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGraphicsBlurEffect_BlurHint_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX]))
        return QGraphicsBlurEffect_BlurHint_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGraphicsBlurEffect::BlurHint>*)cppOut) = ::QFlags<QGraphicsBlurEffect::BlurHint>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsBlurEffect_PythonToCpp_QGraphicsBlurEffect_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsBlurEffect_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsBlurEffect_PythonToCpp_QGraphicsBlurEffect_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsBlurEffect_Type))
        return QGraphicsBlurEffect_PythonToCpp_QGraphicsBlurEffect_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsBlurEffect_PTR_CppToPython_QGraphicsBlurEffect(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGraphicsBlurEffect*)cppIn, &Sbk_QGraphicsBlurEffect_Type);

}

void init_QGraphicsBlurEffect(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsBlurEffect_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsBlurEffect", "QGraphicsBlurEffect*",
        &Sbk_QGraphicsBlurEffect_Type, &Shiboken::callCppDestructor< ::QGraphicsBlurEffect >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsBlurEffect_Type,
        QGraphicsBlurEffect_PythonToCpp_QGraphicsBlurEffect_PTR,
        is_QGraphicsBlurEffect_PythonToCpp_QGraphicsBlurEffect_PTR_Convertible,
        QGraphicsBlurEffect_PTR_CppToPython_QGraphicsBlurEffect);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsBlurEffect");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsBlurEffect*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsBlurEffect&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsBlurEffect).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsBlurEffectWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsBlurEffect_Type, &Sbk_QGraphicsBlurEffect_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'BlurHint'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX] = PySide::QFlags::create("BlurHints", &SbkPySide_QtGui_QGraphicsBlurEffect_BlurHint_as_number);
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsBlurEffect_Type,
        "BlurHint",
        "PySide.QtGui.QGraphicsBlurEffect.BlurHint",
        "QGraphicsBlurEffect::BlurHint",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX],
        &Sbk_QGraphicsBlurEffect_Type, "PerformanceHint", (long) QGraphicsBlurEffect::PerformanceHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX],
        &Sbk_QGraphicsBlurEffect_Type, "QualityHint", (long) QGraphicsBlurEffect::QualityHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX],
        &Sbk_QGraphicsBlurEffect_Type, "AnimationHint", (long) QGraphicsBlurEffect::AnimationHint))
        return ;
    // Register converter for enum 'QGraphicsBlurEffect::BlurHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX],
            QGraphicsBlurEffect_BlurHint_CppToPython_QGraphicsBlurEffect_BlurHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsBlurEffect_BlurHint_PythonToCpp_QGraphicsBlurEffect_BlurHint,
            is_QGraphicsBlurEffect_BlurHint_PythonToCpp_QGraphicsBlurEffect_BlurHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSBLUREFFECT_BLURHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsBlurEffect::BlurHint");
        Shiboken::Conversions::registerConverterName(converter, "BlurHint");
    }
    // Register converter for flag 'QFlags<QGraphicsBlurEffect::BlurHint>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX],
            QFlags_QGraphicsBlurEffect_BlurHint__CppToPython_QFlags_QGraphicsBlurEffect_BlurHint_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsBlurEffect_BlurHint_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_,
            is_QGraphicsBlurEffect_BlurHint_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGraphicsBlurEffect_BlurHint__PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_,
            is_QFlags_QGraphicsBlurEffect_BlurHint__PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint_,
            is_number_PythonToCpp_QFlags_QGraphicsBlurEffect_BlurHint__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSBLUREFFECT_BLURHINT__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGraphicsBlurEffect::BlurHint>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<BlurHint>");
    }
    // End of 'BlurHint' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QGraphicsBlurEffect_Type, &::QGraphicsBlurEffect::staticMetaObject);

    qRegisterMetaType< ::QGraphicsBlurEffect::BlurHint >("QGraphicsBlurEffect::BlurHint");
    qRegisterMetaType< ::QGraphicsBlurEffect::BlurHints >("QGraphicsBlurEffect::BlurHints");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGraphicsBlurEffect_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGraphicsBlurEffect_Type, &::QGraphicsBlurEffect::staticMetaObject, sizeof(::QGraphicsBlurEffect));
}
