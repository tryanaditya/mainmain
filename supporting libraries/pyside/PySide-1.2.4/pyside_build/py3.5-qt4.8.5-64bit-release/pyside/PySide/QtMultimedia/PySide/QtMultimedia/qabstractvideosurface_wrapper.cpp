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
#include "pyside_qtmultimedia_python.h"

#include "qabstractvideosurface_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qvideoframe.h>
#include <qvideosurfaceformat.h>


// Native ---------------------------------------------------------

QAbstractVideoSurfaceWrapper::QAbstractVideoSurfaceWrapper(QObject * parent) : QAbstractVideoSurface(parent) {
    // ... middle
}

void QAbstractVideoSurfaceWrapper::childEvent(QChildEvent * arg__1)
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

void QAbstractVideoSurfaceWrapper::connectNotify(const char * signal)
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

void QAbstractVideoSurfaceWrapper::customEvent(QEvent * arg__1)
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

void QAbstractVideoSurfaceWrapper::disconnectNotify(const char * signal)
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

bool QAbstractVideoSurfaceWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractVideoSurfaceWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QAbstractVideoSurfaceWrapper::isFormatSupported(const QVideoSurfaceFormat & format) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isFormatSupported"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractVideoSurface::isFormatSupported(format);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], &format)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.isFormatSupported", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVideoSurfaceFormat QAbstractVideoSurfaceWrapper::nearestFormat(const QVideoSurfaceFormat & format) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVideoSurfaceFormat();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "nearestFormat"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractVideoSurface::nearestFormat(format);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], &format)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVideoSurfaceFormat();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.nearestFormat", Shiboken::SbkType< QVideoSurfaceFormat >()->tp_name, pyResult->ob_type->tp_name);
        return ::QVideoSurfaceFormat();
    }
    ::QVideoSurfaceFormat cppResult = ::QVideoSurfaceFormat();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractVideoSurfaceWrapper::present(const QVideoFrame & frame)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "present"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoSurface.present()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], &frame)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.present", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractVideoSurfaceWrapper::start(const QVideoSurfaceFormat & format)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "start"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractVideoSurface::start(format);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], &format)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.start", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractVideoSurfaceWrapper::stop()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stop"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractVideoSurface::stop();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QList<QVideoFrame::PixelFormat > QAbstractVideoSurfaceWrapper::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QVideoFrame::PixelFormat >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportedPixelFormats"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoSurface.supportedPixelFormats()' not implemented.");
        return ::QList<QVideoFrame::PixelFormat >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), &handleType)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QVideoFrame::PixelFormat >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVIDEOFRAME_PIXELFORMAT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoSurface.supportedPixelFormats", "list", pyResult->ob_type->tp_name);
        return ::QList<QVideoFrame::PixelFormat >();
    }
    ::QList<QVideoFrame::PixelFormat > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractVideoSurfaceWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QAbstractVideoSurfaceWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractVideoSurface::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractVideoSurfaceWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractVideoSurface::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractVideoSurfaceWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractVideoSurfaceWrapper* >(this));
        return QAbstractVideoSurface::qt_metacast(_clname);
}

QAbstractVideoSurfaceWrapper::~QAbstractVideoSurfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractVideoSurface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractVideoSurface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractVideoSurface >()))
        return -1;

    ::QAbstractVideoSurfaceWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QAbstractVideoSurface", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractVideoSurface(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QAbstractVideoSurface(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QAbstractVideoSurface(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurface_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAbstractVideoSurface(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QAbstractVideoSurface_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QAbstractVideoSurface(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractVideoSurfaceWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractVideoSurfaceWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractVideoSurface >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractVideoSurface_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QAbstractVideoSurface_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAbstractVideoSurface", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_error(PyObject* self)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractVideoSurface::Error cppResult = const_cast<const ::QAbstractVideoSurface*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_isActive(PyObject* self)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractVideoSurface*>(cppSelf)->isActive();
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

static PyObject* Sbk_QAbstractVideoSurfaceFunc_isFormatSupported(PyObject* self, PyObject* pyArg)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isFormatSupported(QVideoSurfaceFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // isFormatSupported(QVideoSurfaceFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurfaceFunc_isFormatSupported_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QVideoSurfaceFormat cppArg0_local = ::QVideoSurfaceFormat();
        ::QVideoSurfaceFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isFormatSupported(QVideoSurfaceFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractVideoSurface*>(cppSelf)->::QAbstractVideoSurface::isFormatSupported(*cppArg0) : const_cast<const ::QAbstractVideoSurface*>(cppSelf)->isFormatSupported(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractVideoSurfaceFunc_isFormatSupported_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoSurfaceFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractVideoSurface.isFormatSupported", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_nearestFormat(PyObject* self, PyObject* pyArg)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: nearestFormat(QVideoSurfaceFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // nearestFormat(QVideoSurfaceFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurfaceFunc_nearestFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QVideoSurfaceFormat cppArg0_local = ::QVideoSurfaceFormat();
        ::QVideoSurfaceFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // nearestFormat(QVideoSurfaceFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoSurfaceFormat cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractVideoSurface*>(cppSelf)->::QAbstractVideoSurface::nearestFormat(*cppArg0) : const_cast<const ::QAbstractVideoSurface*>(cppSelf)->nearestFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractVideoSurfaceFunc_nearestFormat_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoSurfaceFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractVideoSurface.nearestFormat", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_present(PyObject* self, PyObject* pyArg)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: present(QVideoFrame)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (pyArg)))) {
        overloadId = 0; // present(QVideoFrame)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurfaceFunc_present_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QVideoFrame* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // present(QVideoFrame)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoSurface.present()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->present(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractVideoSurfaceFunc_present_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoFrame", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractVideoSurface.present", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_setError(PyObject* self, PyObject* pyArg)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setError(QAbstractVideoSurface::Error)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX]), (pyArg)))) {
        overloadId = 0; // setError(QAbstractVideoSurface::Error)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurfaceFunc_setError_TypeError;

    // Call function/method
    {
        ::QAbstractVideoSurface::Error cppArg0 = ((::QAbstractVideoSurface::Error)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setError(QAbstractVideoSurface::Error)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setError(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractVideoSurfaceFunc_setError_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAbstractVideoSurface.Error", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractVideoSurface.setError", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_start(PyObject* self, PyObject* pyArg)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: start(QVideoSurfaceFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // start(QVideoSurfaceFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurfaceFunc_start_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QVideoSurfaceFormat cppArg0_local = ::QVideoSurfaceFormat();
        ::QVideoSurfaceFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // start(QVideoSurfaceFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractVideoSurface::start(*cppArg0) : cppSelf->start(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractVideoSurfaceFunc_start_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoSurfaceFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractVideoSurface.start", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_stop(PyObject* self)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractVideoSurface::stop() : cppSelf->stop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_supportedPixelFormats(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAbstractVideoSurface.supportedPixelFormats(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:supportedPixelFormats", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: supportedPixelFormats(QAbstractVideoBuffer::HandleType)const
    if (numArgs == 0) {
        overloadId = 0; // supportedPixelFormats(QAbstractVideoBuffer::HandleType)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // supportedPixelFormats(QAbstractVideoBuffer::HandleType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoSurfaceFunc_supportedPixelFormats_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "handleType");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAbstractVideoSurface.supportedPixelFormats(): got multiple values for keyword argument 'handleType'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QAbstractVideoSurfaceFunc_supportedPixelFormats_TypeError;
            }
        }
        ::QAbstractVideoBuffer::HandleType cppArg0 = QAbstractVideoBuffer::NoHandle;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // supportedPixelFormats(QAbstractVideoBuffer::HandleType)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoSurface.supportedPixelFormats()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QVideoFrame::PixelFormat > cppResult = const_cast<const ::QAbstractVideoSurface*>(cppSelf)->supportedPixelFormats(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVIDEOFRAME_PIXELFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractVideoSurfaceFunc_supportedPixelFormats_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAbstractVideoBuffer.HandleType = QAbstractVideoBuffer.NoHandle", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAbstractVideoSurface.supportedPixelFormats", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractVideoSurfaceFunc_surfaceFormat(PyObject* self)
{
    ::QAbstractVideoSurface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoSurface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // surfaceFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoSurfaceFormat cppResult = const_cast<const ::QAbstractVideoSurface*>(cppSelf)->surfaceFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QAbstractVideoSurface_methods[] = {
    {"error", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_error, METH_NOARGS},
    {"isActive", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_isActive, METH_NOARGS},
    {"isFormatSupported", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_isFormatSupported, METH_O},
    {"nearestFormat", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_nearestFormat, METH_O},
    {"present", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_present, METH_O},
    {"setError", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_setError, METH_O},
    {"start", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_start, METH_O},
    {"stop", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_stop, METH_NOARGS},
    {"supportedPixelFormats", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_supportedPixelFormats, METH_VARARGS|METH_KEYWORDS},
    {"surfaceFormat", (PyCFunction)Sbk_QAbstractVideoSurfaceFunc_surfaceFormat, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractVideoSurface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractVideoSurface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractVideoSurface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAbstractVideoSurface",
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
    /*tp_traverse*/         Sbk_QAbstractVideoSurface_traverse,
    /*tp_clear*/            Sbk_QAbstractVideoSurface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractVideoSurface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractVideoSurface_Init,
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

static void* Sbk_QAbstractVideoSurface_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractVideoSurface*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QAbstractVideoSurface_Error_PythonToCpp_QAbstractVideoSurface_Error(PyObject* pyIn, void* cppOut) {
    *((::QAbstractVideoSurface::Error*)cppOut) = (::QAbstractVideoSurface::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractVideoSurface_Error_PythonToCpp_QAbstractVideoSurface_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX]))
        return QAbstractVideoSurface_Error_PythonToCpp_QAbstractVideoSurface_Error;
    return 0;
}
static PyObject* QAbstractVideoSurface_Error_CppToPython_QAbstractVideoSurface_Error(const void* cppIn) {
    int castCppIn = *((::QAbstractVideoSurface::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractVideoSurface_PythonToCpp_QAbstractVideoSurface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractVideoSurface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractVideoSurface_PythonToCpp_QAbstractVideoSurface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractVideoSurface_Type))
        return QAbstractVideoSurface_PythonToCpp_QAbstractVideoSurface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractVideoSurface_PTR_CppToPython_QAbstractVideoSurface(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractVideoSurface*)cppIn, &Sbk_QAbstractVideoSurface_Type);

}

void init_QAbstractVideoSurface(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractVideoSurface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractVideoSurface", "QAbstractVideoSurface*",
        &Sbk_QAbstractVideoSurface_Type, &Shiboken::callCppDestructor< ::QAbstractVideoSurface >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractVideoSurface_Type,
        QAbstractVideoSurface_PythonToCpp_QAbstractVideoSurface_PTR,
        is_QAbstractVideoSurface_PythonToCpp_QAbstractVideoSurface_PTR_Convertible,
        QAbstractVideoSurface_PTR_CppToPython_QAbstractVideoSurface);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoSurface");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoSurface*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoSurface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractVideoSurface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractVideoSurfaceWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractVideoSurface_Type, &Sbk_QAbstractVideoSurface_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Error'.
    SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractVideoSurface_Type,
        "Error",
        "PySide.QtMultimedia.QAbstractVideoSurface.Error",
        "QAbstractVideoSurface::Error");
    if (!SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX],
        &Sbk_QAbstractVideoSurface_Type, "NoError", (long) QAbstractVideoSurface::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX],
        &Sbk_QAbstractVideoSurface_Type, "UnsupportedFormatError", (long) QAbstractVideoSurface::UnsupportedFormatError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX],
        &Sbk_QAbstractVideoSurface_Type, "IncorrectFormatError", (long) QAbstractVideoSurface::IncorrectFormatError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX],
        &Sbk_QAbstractVideoSurface_Type, "StoppedError", (long) QAbstractVideoSurface::StoppedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX],
        &Sbk_QAbstractVideoSurface_Type, "ResourceError", (long) QAbstractVideoSurface::ResourceError))
        return ;
    // Register converter for enum 'QAbstractVideoSurface::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX],
            QAbstractVideoSurface_Error_CppToPython_QAbstractVideoSurface_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractVideoSurface_Error_PythonToCpp_QAbstractVideoSurface_Error,
            is_QAbstractVideoSurface_Error_PythonToCpp_QAbstractVideoSurface_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOSURFACE_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoSurface::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.

    PySide::Signal::registerSignals(&Sbk_QAbstractVideoSurface_Type, &::QAbstractVideoSurface::staticMetaObject);

    qRegisterMetaType< ::QAbstractVideoSurface::Error >("QAbstractVideoSurface::Error");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractVideoSurface_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractVideoSurface_Type, &::QAbstractVideoSurface::staticMetaObject, sizeof(::QAbstractVideoSurface));
}
