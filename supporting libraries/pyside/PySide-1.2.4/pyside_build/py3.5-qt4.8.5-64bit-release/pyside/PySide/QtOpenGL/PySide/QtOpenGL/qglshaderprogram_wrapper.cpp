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
#include "pyside_qtopengl_python.h"

#include "qglshaderprogram_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcolor.h>
#include <qcoreevent.h>
#include <qgenericmatrix.h>
#include <qgl.h>
#include <qglshaderprogram.h>
#include <qmatrix4x4.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpoint.h>
#include <qsize.h>
#include <qthread.h>
#include <qtransform.h>
#include <qvector2d.h>
#include <qvector3d.h>
#include <qvector4d.h>


// Native ---------------------------------------------------------

QGLShaderProgramWrapper::QGLShaderProgramWrapper(QObject * parent) : QGLShaderProgram(parent) {
    // ... middle
}

QGLShaderProgramWrapper::QGLShaderProgramWrapper(const QGLContext * context, QObject * parent) : QGLShaderProgram(context, parent) {
    // ... middle
}

void QGLShaderProgramWrapper::childEvent(QChildEvent * arg__1)
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

void QGLShaderProgramWrapper::connectNotify(const char * signal)
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

void QGLShaderProgramWrapper::customEvent(QEvent * arg__1)
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

void QGLShaderProgramWrapper::disconnectNotify(const char * signal)
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

bool QGLShaderProgramWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLShaderProgram.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGLShaderProgramWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLShaderProgram.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QGLShaderProgramWrapper::link()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "link"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLShaderProgram::link();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLShaderProgram.link", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGLShaderProgramWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QGLShaderProgramWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGLShaderProgram::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGLShaderProgramWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGLShaderProgram::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGLShaderProgramWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGLShaderProgramWrapper* >(this));
        return QGLShaderProgram::qt_metacast(_clname);
}

QGLShaderProgramWrapper::~QGLShaderProgramWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLShaderProgram_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLShaderProgram >()))
        return -1;

    ::QGLShaderProgramWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QGLShaderProgram", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGLShaderProgram(QObject*)
    // 1: QGLShaderProgram(const QGLContext*,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QGLShaderProgram(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QGLShaderProgram(const QGLContext*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // QGLShaderProgram(const QGLContext*,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGLShaderProgram(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgram_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLShaderProgram(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QGLShaderProgram_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QGLShaderProgram(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGLShaderProgramWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGLShaderProgramWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QGLShaderProgram(const QGLContext * context, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QGLShaderProgram_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGLContext* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGLShaderProgram(const QGLContext*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGLShaderProgramWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGLShaderProgramWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLShaderProgram >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLShaderProgram_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QGLShaderProgram_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "PySide.QtOpenGL.QGLContext, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram", overloads);
        return -1;
}

static PyObject* Sbk_QGLShaderProgramFunc_addShader(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addShader(QGLShader*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (pyArg)))) {
        overloadId = 0; // addShader(QGLShader*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_addShader_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGLShader* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addShader(QGLShader*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->addShader(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderProgramFunc_addShader_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLShader", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.addShader", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_addShaderFromSourceCode(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addShaderFromSourceCode", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,QByteArray)
    // 1: addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,QString)
    // 2: addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), (pyArgs[0])))) {
        if (numArgs == 2
            && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 2; // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,const char*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 0; // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,QByteArray)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_addShaderFromSourceCode_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit> type, const QByteArray & source)
        {
            ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QByteArray cppArg1_local = ::QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->addShaderFromSourceCode(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit> type, const QString & source)
        {
            ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->addShaderFromSourceCode(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit> type, const char * source)
        {
            ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addShaderFromSourceCode(QFlags<QGLShader::ShaderTypeBit>,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->addShaderFromSourceCode(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderProgramFunc_addShaderFromSourceCode_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLShader.ShaderType, PySide.QtCore.QByteArray", "PySide.QtOpenGL.QGLShader.ShaderType, unicode", "PySide.QtOpenGL.QGLShader.ShaderType, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.addShaderFromSourceCode", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_addShaderFromSourceFile(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addShaderFromSourceFile", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addShaderFromSourceFile(QFlags<QGLShader::ShaderTypeBit>,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // addShaderFromSourceFile(QFlags<QGLShader::ShaderTypeBit>,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_addShaderFromSourceFile_TypeError;

    // Call function/method
    {
        ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addShaderFromSourceFile(QFlags<QGLShader::ShaderTypeBit>,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->addShaderFromSourceFile(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderProgramFunc_addShaderFromSourceFile_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLShader.ShaderType, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.addShaderFromSourceFile", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_attributeLocation(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: attributeLocation(QByteArray)const
    // 1: attributeLocation(QString)const
    // 2: attributeLocation(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 2; // attributeLocation(const char*)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // attributeLocation(QString)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // attributeLocation(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_attributeLocation_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // attributeLocation(const QByteArray & name) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // attributeLocation(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->attributeLocation(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // attributeLocation(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // attributeLocation(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->attributeLocation(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 2: // attributeLocation(const char * name) const
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // attributeLocation(const char*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->attributeLocation(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderProgramFunc_attributeLocation_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "unicode", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.attributeLocation", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_bind(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bind()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->bind();
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

static PyObject* Sbk_QGLShaderProgramFunc_bindAttributeLocation(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "bindAttributeLocation", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: bindAttributeLocation(QByteArray,int)
    // 1: bindAttributeLocation(QString,int)
    // 2: bindAttributeLocation(const char*,int)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 2; // bindAttributeLocation(const char*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // bindAttributeLocation(QString,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // bindAttributeLocation(QByteArray,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_bindAttributeLocation_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindAttributeLocation(const QByteArray & name, int location)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // bindAttributeLocation(QByteArray,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindAttributeLocation(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // bindAttributeLocation(const QString & name, int location)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // bindAttributeLocation(QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindAttributeLocation(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // bindAttributeLocation(const char * name, int location)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // bindAttributeLocation(const char*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindAttributeLocation(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_bindAttributeLocation_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, int", "unicode, int", "" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.bindAttributeLocation", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_disableAttributeArray(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: disableAttributeArray(const char*)
    // 1: disableAttributeArray(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // disableAttributeArray(int)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // disableAttributeArray(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_disableAttributeArray_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // disableAttributeArray(const char * name)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // disableAttributeArray(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->disableAttributeArray(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // disableAttributeArray(int location)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // disableAttributeArray(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->disableAttributeArray(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_disableAttributeArray_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.disableAttributeArray", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_enableAttributeArray(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: enableAttributeArray(const char*)
    // 1: enableAttributeArray(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // enableAttributeArray(int)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // enableAttributeArray(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_enableAttributeArray_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // enableAttributeArray(const char * name)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // enableAttributeArray(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->enableAttributeArray(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // enableAttributeArray(int location)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // enableAttributeArray(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->enableAttributeArray(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_enableAttributeArray_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.enableAttributeArray", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_geometryInputType(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometryInputType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLenum cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->geometryInputType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLShaderProgramFunc_geometryOutputType(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometryOutputType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLenum cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->geometryOutputType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLShaderProgramFunc_geometryOutputVertexCount(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometryOutputVertexCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->geometryOutputVertexCount();
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

static PyObject* Sbk_QGLShaderProgramFunc_hasOpenGLShaderPrograms(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.hasOpenGLShaderPrograms(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:hasOpenGLShaderPrograms", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: hasOpenGLShaderPrograms(const QGLContext*)
    if (numArgs == 0) {
        overloadId = 0; // hasOpenGLShaderPrograms(const QGLContext*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0])))) {
        overloadId = 0; // hasOpenGLShaderPrograms(const QGLContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_hasOpenGLShaderPrograms_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "context");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.hasOpenGLShaderPrograms(): got multiple values for keyword argument 'context'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0]))))
                    goto Sbk_QGLShaderProgramFunc_hasOpenGLShaderPrograms_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGLContext* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // hasOpenGLShaderPrograms(const QGLContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLShaderProgram::hasOpenGLShaderPrograms(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderProgramFunc_hasOpenGLShaderPrograms_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLContext = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.hasOpenGLShaderPrograms", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_isLinked(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLinked()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->isLinked();
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

static PyObject* Sbk_QGLShaderProgramFunc_link(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // link()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLShaderProgram::link() : cppSelf->link();
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

static PyObject* Sbk_QGLShaderProgramFunc_log(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // log()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->log();
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

static PyObject* Sbk_QGLShaderProgramFunc_maxGeometryOutputVertices(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maxGeometryOutputVertices()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->maxGeometryOutputVertices();
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

static PyObject* Sbk_QGLShaderProgramFunc_programId(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // programId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLuint cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->programId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLShaderProgramFunc_release(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // release()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->release();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLShaderProgramFunc_removeAllShaders(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeAllShaders()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAllShaders();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLShaderProgramFunc_removeShader(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeShader(QGLShader*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (pyArg)))) {
        overloadId = 0; // removeShader(QGLShader*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_removeShader_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGLShader* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeShader(QGLShader*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeShader(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_removeShader_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLShader", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.removeShader", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setAttributeArray2D(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray2D(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray2D(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setAttributeArray2D", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeArray(const char*,const QVector2D*,int)
    // 1: setAttributeArray(int,const QVector2D*,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 1; // setAttributeArray(int,const QVector2D*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 1; // setAttributeArray(int,const QVector2D*,int)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 0; // setAttributeArray(const char*,const QVector2D*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setAttributeArray(const char*,const QVector2D*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setAttributeArray2D_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttributeArray(const char * name, const QVector2D * values, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray2D(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeArray2D_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeArray(const char*,const QVector2D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector2D *_list = new QVector2D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setAttributeArray(cppArg0, _list, cppArg2);
                delete[] _list;
                } else {
                cppSelf->setAttributeArray(cppArg0, (QVector2D*)NULL, cppArg2);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setAttributeArray(int location, const QVector2D * values, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray2D(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeArray2D_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeArray(int,const QVector2D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector2D *_list = new QVector2D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setAttributeArray(cppArg0, _list, cppArg2);
                delete[] _list;
                } else {
                cppSelf->setAttributeArray(cppArg0, (QVector2D*)NULL, cppArg2);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setAttributeArray2D_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QVector2D, int = 0", "int, PySide.QtGui.QVector2D, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray2D", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setAttributeArray3D(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray3D(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray3D(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setAttributeArray3D", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeArray(const char*,const QVector3D*,int)
    // 1: setAttributeArray(int,const QVector3D*,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 1; // setAttributeArray(int,const QVector3D*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 1; // setAttributeArray(int,const QVector3D*,int)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 0; // setAttributeArray(const char*,const QVector3D*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setAttributeArray(const char*,const QVector3D*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setAttributeArray3D_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttributeArray(const char * name, const QVector3D * values, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray3D(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeArray3D_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeArray(const char*,const QVector3D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector3D *_list = new QVector3D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setAttributeArray(cppArg0, _list, cppArg2);
                delete[] _list;
                } else {
                cppSelf->setAttributeArray(cppArg0, (QVector3D*)NULL, cppArg2);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setAttributeArray(int location, const QVector3D * values, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray3D(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeArray3D_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeArray(int,const QVector3D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector3D *_list = new QVector3D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setAttributeArray(cppArg0, _list, cppArg2);
                delete[] _list;
                } else {
                cppSelf->setAttributeArray(cppArg0, (QVector3D*)NULL, cppArg2);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setAttributeArray3D_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QVector3D, int = 0", "int, PySide.QtGui.QVector3D, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray3D", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setAttributeArray4D(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray4D(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray4D(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setAttributeArray4D", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeArray(const char*,const QVector4D*,int)
    // 1: setAttributeArray(int,const QVector4D*,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 1; // setAttributeArray(int,const QVector4D*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 1; // setAttributeArray(int,const QVector4D*,int)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 0; // setAttributeArray(const char*,const QVector4D*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setAttributeArray(const char*,const QVector4D*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setAttributeArray4D_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttributeArray(const char * name, const QVector4D * values, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray4D(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeArray4D_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeArray(const char*,const QVector4D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector4D *_list = new QVector4D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setAttributeArray(cppArg0, _list, cppArg2);
                delete[] _list;
                } else {
                cppSelf->setAttributeArray(cppArg0, (QVector4D*)NULL, cppArg2);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setAttributeArray(int location, const QVector4D * values, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray4D(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeArray4D_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeArray(int,const QVector4D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector4D *_list = new QVector4D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setAttributeArray(cppArg0, _list, cppArg2);
                delete[] _list;
                } else {
                cppSelf->setAttributeArray(cppArg0, (QVector4D*)NULL, cppArg2);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setAttributeArray4D_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QVector4D, int = 0", "int, PySide.QtGui.QVector4D, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setAttributeArray4D", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setAttributeBuffer(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeBuffer(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeBuffer(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:setAttributeBuffer", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeBuffer(const char*,GLenum,int,int,int)
    // 1: setAttributeBuffer(int,GLenum,int,int,int)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // setAttributeBuffer(int,GLenum,int,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            overloadId = 1; // setAttributeBuffer(int,GLenum,int,int,int)
        }
    } else if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // setAttributeBuffer(const char*,GLenum,int,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            overloadId = 0; // setAttributeBuffer(const char*,GLenum,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setAttributeBuffer_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttributeBuffer(const char * name, GLenum type, int offset, int tupleSize, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeBuffer(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeBuffer_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLenum cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = 0;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setAttributeBuffer(const char*,GLenum,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeBuffer(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "stride");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShaderProgram.setAttributeBuffer(): got multiple values for keyword argument 'stride'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QGLShaderProgramFunc_setAttributeBuffer_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLenum cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = 0;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setAttributeBuffer(int,GLenum,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeBuffer(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setAttributeBuffer_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", unsigned int, int, int, int = 0", "int, unsigned int, int, int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setAttributeBuffer", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setAttributeValue(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttributeValue", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeValue(const char*,GLfloat)
    // 1: setAttributeValue(const char*,GLfloat,GLfloat)
    // 2: setAttributeValue(const char*,GLfloat,GLfloat,GLfloat)
    // 3: setAttributeValue(const char*,GLfloat,GLfloat,GLfloat,GLfloat)
    // 4: setAttributeValue(const char*,QColor)
    // 5: setAttributeValue(const char*,QVector2D)
    // 6: setAttributeValue(const char*,QVector3D)
    // 7: setAttributeValue(const char*,QVector4D)
    // 8: setAttributeValue(int,GLfloat)
    // 9: setAttributeValue(int,GLfloat,GLfloat)
    // 10: setAttributeValue(int,GLfloat,GLfloat,GLfloat)
    // 11: setAttributeValue(int,GLfloat,GLfloat,GLfloat,GLfloat)
    // 12: setAttributeValue(int,QColor)
    // 13: setAttributeValue(int,QVector2D)
    // 14: setAttributeValue(int,QVector3D)
    // 15: setAttributeValue(int,QVector4D)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (pyArgs[1])))) {
            overloadId = 13; // setAttributeValue(int,QVector2D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
            overloadId = 14; // setAttributeValue(int,QVector3D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
            overloadId = 15; // setAttributeValue(int,QVector4D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 12; // setAttributeValue(int,QColor)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 8; // setAttributeValue(int,GLfloat)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 9; // setAttributeValue(int,GLfloat,GLfloat)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 10; // setAttributeValue(int,GLfloat,GLfloat,GLfloat)
                    } else if (numArgs == 5
                        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[4])))) {
                        overloadId = 11; // setAttributeValue(int,GLfloat,GLfloat,GLfloat,GLfloat)
                    }
                }
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (pyArgs[1])))) {
            overloadId = 5; // setAttributeValue(const char*,QVector2D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
            overloadId = 6; // setAttributeValue(const char*,QVector3D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
            overloadId = 7; // setAttributeValue(const char*,QVector4D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 4; // setAttributeValue(const char*,QColor)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setAttributeValue(const char*,GLfloat)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // setAttributeValue(const char*,GLfloat,GLfloat)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 2; // setAttributeValue(const char*,GLfloat,GLfloat,GLfloat)
                    } else if (numArgs == 5
                        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[4])))) {
                        overloadId = 3; // setAttributeValue(const char*,GLfloat,GLfloat,GLfloat,GLfloat)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setAttributeValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttributeValue(const char * name, GLfloat value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setAttributeValue(const char * name, GLfloat x, GLfloat y)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setAttributeValue(const char * name, GLfloat x, GLfloat y, GLfloat z)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // setAttributeValue(const char * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            GLfloat cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,GLfloat,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // setAttributeValue(const char * name, const QColor & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QColor cppArg1_local = ::QColor();
            ::QColor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // setAttributeValue(const char * name, const QVector2D & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector2D cppArg1_local = ::QVector2D();
            ::QVector2D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,QVector2D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // setAttributeValue(const char * name, const QVector3D & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector3D cppArg1_local = ::QVector3D();
            ::QVector3D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // setAttributeValue(const char * name, const QVector4D & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector4D cppArg1_local = ::QVector4D();
            ::QVector4D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(const char*,QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // setAttributeValue(int location, GLfloat value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttributeValue(int,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // setAttributeValue(int location, GLfloat x, GLfloat y)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeValue(int,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 10: // setAttributeValue(int location, GLfloat x, GLfloat y, GLfloat z)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setAttributeValue(int,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 11: // setAttributeValue(int location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            GLfloat cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setAttributeValue(int,GLfloat,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 12: // setAttributeValue(int location, const QColor & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QColor cppArg1_local = ::QColor();
            ::QColor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(int,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 13: // setAttributeValue(int location, const QVector2D & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector2D cppArg1_local = ::QVector2D();
            ::QVector2D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(int,QVector2D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 14: // setAttributeValue(int location, const QVector3D & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector3D cppArg1_local = ::QVector3D();
            ::QVector3D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(int,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 15: // setAttributeValue(int location, const QVector4D & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector4D cppArg1_local = ::QVector4D();
            ::QVector4D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setAttributeValue(int,QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setAttributeValue_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", float", "" SBK_STR_NAME ", float, float", "" SBK_STR_NAME ", float, float, float", "" SBK_STR_NAME ", float, float, float, float", "" SBK_STR_NAME ", PySide.QtGui.QColor", "" SBK_STR_NAME ", PySide.QtGui.QVector2D", "" SBK_STR_NAME ", PySide.QtGui.QVector3D", "" SBK_STR_NAME ", PySide.QtGui.QVector4D", "int, float", "int, float, float", "int, float, float, float", "int, float, float, float, float", "int, PySide.QtGui.QColor", "int, PySide.QtGui.QVector2D", "int, PySide.QtGui.QVector3D", "int, PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setAttributeValue", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setGeometryInputType(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometryInputType(GLenum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArg)))) {
        overloadId = 0; // setGeometryInputType(GLenum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setGeometryInputType_TypeError;

    // Call function/method
    {
        GLenum cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGeometryInputType(GLenum)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGeometryInputType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setGeometryInputType_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.setGeometryInputType", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setGeometryOutputType(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometryOutputType(GLenum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArg)))) {
        overloadId = 0; // setGeometryOutputType(GLenum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setGeometryOutputType_TypeError;

    // Call function/method
    {
        GLenum cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGeometryOutputType(GLenum)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGeometryOutputType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setGeometryOutputType_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.setGeometryOutputType", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setGeometryOutputVertexCount(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometryOutputVertexCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setGeometryOutputVertexCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setGeometryOutputVertexCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGeometryOutputVertexCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGeometryOutputVertexCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setGeometryOutputVertexCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.setGeometryOutputVertexCount", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValue(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValue", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValue(const char*,GLfloat)
    // 1: setUniformValue(const char*,GLfloat,GLfloat)
    // 2: setUniformValue(const char*,GLfloat,GLfloat,GLfloat)
    // 3: setUniformValue(const char*,GLfloat,GLfloat,GLfloat,GLfloat)
    // 4: setUniformValue(const char*,GLint)
    // 5: setUniformValue(const char*,GLuint)
    // 6: setUniformValue(const char*,QColor)
    // 7: setUniformValue(const char*,QMatrix2x2)
    // 8: setUniformValue(const char*,QMatrix2x3)
    // 9: setUniformValue(const char*,QMatrix2x4)
    // 10: setUniformValue(const char*,QMatrix3x2)
    // 11: setUniformValue(const char*,QMatrix3x3)
    // 12: setUniformValue(const char*,QMatrix3x4)
    // 13: setUniformValue(const char*,QMatrix4x2)
    // 14: setUniformValue(const char*,QMatrix4x3)
    // 15: setUniformValue(const char*,QMatrix4x4)
    // 16: setUniformValue(const char*,QPoint)
    // 17: setUniformValue(const char*,QPointF)
    // 18: setUniformValue(const char*,QSize)
    // 19: setUniformValue(const char*,QSizeF)
    // 20: setUniformValue(const char*,QTransform)
    // 21: setUniformValue(const char*,QVector2D)
    // 22: setUniformValue(const char*,QVector3D)
    // 23: setUniformValue(const char*,QVector4D)
    // 24: setUniformValue(int,GLfloat)
    // 25: setUniformValue(int,GLfloat,GLfloat)
    // 26: setUniformValue(int,GLfloat,GLfloat,GLfloat)
    // 27: setUniformValue(int,GLfloat,GLfloat,GLfloat,GLfloat)
    // 28: setUniformValue(int,GLint)
    // 29: setUniformValue(int,GLuint)
    // 30: setUniformValue(int,QColor)
    // 31: setUniformValue(int,QMatrix2x2)
    // 32: setUniformValue(int,QMatrix2x3)
    // 33: setUniformValue(int,QMatrix2x4)
    // 34: setUniformValue(int,QMatrix3x2)
    // 35: setUniformValue(int,QMatrix3x3)
    // 36: setUniformValue(int,QMatrix3x4)
    // 37: setUniformValue(int,QMatrix4x2)
    // 38: setUniformValue(int,QMatrix4x3)
    // 39: setUniformValue(int,QMatrix4x4)
    // 40: setUniformValue(int,QPoint)
    // 41: setUniformValue(int,QPointF)
    // 42: setUniformValue(int,QSize)
    // 43: setUniformValue(int,QSizeF)
    // 44: setUniformValue(int,QTransform)
    // 45: setUniformValue(int,QVector2D)
    // 46: setUniformValue(int,QVector3D)
    // 47: setUniformValue(int,QVector4D)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (pyArgs[1])))) {
            overloadId = 45; // setUniformValue(int,QVector2D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
            overloadId = 46; // setUniformValue(int,QVector3D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
            overloadId = 47; // setUniformValue(int,QVector4D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[1])))) {
            overloadId = 44; // setUniformValue(int,QTransform)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))) {
            overloadId = 42; // setUniformValue(int,QSize)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1])))) {
            overloadId = 43; // setUniformValue(int,QSizeF)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
            overloadId = 40; // setUniformValue(int,QPoint)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
            overloadId = 41; // setUniformValue(int,QPointF)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArgs[1])))) {
            overloadId = 39; // setUniformValue(int,QMatrix4x4)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X3_IDX], (pyArgs[1])))) {
            overloadId = 38; // setUniformValue(int,QMatrix4x3)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X2_IDX], (pyArgs[1])))) {
            overloadId = 37; // setUniformValue(int,QMatrix4x2)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X4_IDX], (pyArgs[1])))) {
            overloadId = 36; // setUniformValue(int,QMatrix3x4)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], (pyArgs[1])))) {
            overloadId = 35; // setUniformValue(int,QMatrix3x3)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArgs[1])))) {
            overloadId = 34; // setUniformValue(int,QMatrix3x2)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X4_IDX], (pyArgs[1])))) {
            overloadId = 33; // setUniformValue(int,QMatrix2x4)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], (pyArgs[1])))) {
            overloadId = 32; // setUniformValue(int,QMatrix2x3)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X2_IDX], (pyArgs[1])))) {
            overloadId = 31; // setUniformValue(int,QMatrix2x2)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArgs[1])))) {
            overloadId = 29; // setUniformValue(int,GLuint)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 30; // setUniformValue(int,QColor)
        } else if (PyFloat_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 24; // setUniformValue(int,GLfloat)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 25; // setUniformValue(int,GLfloat,GLfloat)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 26; // setUniformValue(int,GLfloat,GLfloat,GLfloat)
                    } else if (numArgs == 5
                        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[4])))) {
                        overloadId = 27; // setUniformValue(int,GLfloat,GLfloat,GLfloat,GLfloat)
                    }
                }
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), (pyArgs[1])))) {
            overloadId = 28; // setUniformValue(int,GLint)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (pyArgs[1])))) {
            overloadId = 21; // setUniformValue(const char*,QVector2D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
            overloadId = 22; // setUniformValue(const char*,QVector3D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
            overloadId = 23; // setUniformValue(const char*,QVector4D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[1])))) {
            overloadId = 20; // setUniformValue(const char*,QTransform)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))) {
            overloadId = 18; // setUniformValue(const char*,QSize)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1])))) {
            overloadId = 19; // setUniformValue(const char*,QSizeF)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
            overloadId = 16; // setUniformValue(const char*,QPoint)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
            overloadId = 17; // setUniformValue(const char*,QPointF)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArgs[1])))) {
            overloadId = 15; // setUniformValue(const char*,QMatrix4x4)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X3_IDX], (pyArgs[1])))) {
            overloadId = 14; // setUniformValue(const char*,QMatrix4x3)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X2_IDX], (pyArgs[1])))) {
            overloadId = 13; // setUniformValue(const char*,QMatrix4x2)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X4_IDX], (pyArgs[1])))) {
            overloadId = 12; // setUniformValue(const char*,QMatrix3x4)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], (pyArgs[1])))) {
            overloadId = 11; // setUniformValue(const char*,QMatrix3x3)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArgs[1])))) {
            overloadId = 10; // setUniformValue(const char*,QMatrix3x2)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X4_IDX], (pyArgs[1])))) {
            overloadId = 9; // setUniformValue(const char*,QMatrix2x4)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], (pyArgs[1])))) {
            overloadId = 8; // setUniformValue(const char*,QMatrix2x3)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X2_IDX], (pyArgs[1])))) {
            overloadId = 7; // setUniformValue(const char*,QMatrix2x2)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArgs[1])))) {
            overloadId = 5; // setUniformValue(const char*,GLuint)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 6; // setUniformValue(const char*,QColor)
        } else if (PyFloat_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setUniformValue(const char*,GLfloat)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // setUniformValue(const char*,GLfloat,GLfloat)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 2; // setUniformValue(const char*,GLfloat,GLfloat,GLfloat)
                    } else if (numArgs == 5
                        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLfloat>(), (pyArgs[4])))) {
                        overloadId = 3; // setUniformValue(const char*,GLfloat,GLfloat,GLfloat,GLfloat)
                    }
                }
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), (pyArgs[1])))) {
            overloadId = 4; // setUniformValue(const char*,GLint)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValue(const char * name, GLfloat value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setUniformValue(const char * name, GLfloat x, GLfloat y)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setUniformValue(const char * name, GLfloat x, GLfloat y, GLfloat z)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // setUniformValue(const char * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            GLfloat cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,GLfloat,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // setUniformValue(const char * name, GLint value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,GLint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // setUniformValue(const char * name, GLuint value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLuint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,GLuint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // setUniformValue(const char * name, const QColor & color)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QColor cppArg1_local = ::QColor();
            ::QColor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // setUniformValue(const char * name, const QMatrix2x2 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix2x2 cppArg1_local = ::QMatrix2x2();
            ::QMatrix2x2* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X2_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix2x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // setUniformValue(const char * name, const QMatrix2x3 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix2x3 cppArg1_local = ::QMatrix2x3();
            ::QMatrix2x3* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix2x3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // setUniformValue(const char * name, const QMatrix2x4 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix2x4 cppArg1_local = ::QMatrix2x4();
            ::QMatrix2x4* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X4_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix2x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 10: // setUniformValue(const char * name, const QMatrix3x2 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix3x2 cppArg1_local = ::QMatrix3x2();
            ::QMatrix3x2* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix3x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 11: // setUniformValue(const char * name, const QMatrix3x3 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix3x3 cppArg1_local = ::QMatrix3x3();
            ::QMatrix3x3* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix3x3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 12: // setUniformValue(const char * name, const QMatrix3x4 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix3x4 cppArg1_local = ::QMatrix3x4();
            ::QMatrix3x4* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X4_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix3x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 13: // setUniformValue(const char * name, const QMatrix4x2 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix4x2 cppArg1_local = ::QMatrix4x2();
            ::QMatrix4x2* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X2_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix4x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 14: // setUniformValue(const char * name, const QMatrix4x3 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix4x3 cppArg1_local = ::QMatrix4x3();
            ::QMatrix4x3* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X3_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix4x3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 15: // setUniformValue(const char * name, const QMatrix4x4 & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix4x4 cppArg1_local = ::QMatrix4x4();
            ::QMatrix4x4* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 16: // setUniformValue(const char * name, const QPoint & point)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPoint cppArg1_local = ::QPoint();
            ::QPoint* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 17: // setUniformValue(const char * name, const QPointF & point)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPointF cppArg1_local = ::QPointF();
            ::QPointF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 18: // setUniformValue(const char * name, const QSize & size)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QSize cppArg1_local = ::QSize();
            ::QSize* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 19: // setUniformValue(const char * name, const QSizeF & size)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QSizeF cppArg1_local = ::QSizeF();
            ::QSizeF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QSizeF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 20: // setUniformValue(const char * name, const QTransform & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTransform cppArg1_local = ::QTransform();
            ::QTransform* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 21: // setUniformValue(const char * name, const QVector2D & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector2D cppArg1_local = ::QVector2D();
            ::QVector2D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QVector2D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 22: // setUniformValue(const char * name, const QVector3D & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector3D cppArg1_local = ::QVector3D();
            ::QVector3D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 23: // setUniformValue(const char * name, const QVector4D & value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector4D cppArg1_local = ::QVector4D();
            ::QVector4D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(const char*,QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 24: // setUniformValue(int location, GLfloat value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUniformValue(int,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 25: // setUniformValue(int location, GLfloat x, GLfloat y)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setUniformValue(int,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 26: // setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setUniformValue(int,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 27: // setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLfloat cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLfloat cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLfloat cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            GLfloat cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setUniformValue(int,GLfloat,GLfloat,GLfloat,GLfloat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 28: // setUniformValue(int location, GLint value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUniformValue(int,GLint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 29: // setUniformValue(int location, GLuint value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            GLuint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUniformValue(int,GLuint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 30: // setUniformValue(int location, const QColor & color)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QColor cppArg1_local = ::QColor();
            ::QColor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 31: // setUniformValue(int location, const QMatrix2x2 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix2x2 cppArg1_local = ::QMatrix2x2();
            ::QMatrix2x2* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X2_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix2x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 32: // setUniformValue(int location, const QMatrix2x3 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix2x3 cppArg1_local = ::QMatrix2x3();
            ::QMatrix2x3* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix2x3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 33: // setUniformValue(int location, const QMatrix2x4 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix2x4 cppArg1_local = ::QMatrix2x4();
            ::QMatrix2x4* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X4_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix2x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 34: // setUniformValue(int location, const QMatrix3x2 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix3x2 cppArg1_local = ::QMatrix3x2();
            ::QMatrix3x2* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix3x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 35: // setUniformValue(int location, const QMatrix3x3 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix3x3 cppArg1_local = ::QMatrix3x3();
            ::QMatrix3x3* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix3x3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 36: // setUniformValue(int location, const QMatrix3x4 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix3x4 cppArg1_local = ::QMatrix3x4();
            ::QMatrix3x4* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X4_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix3x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 37: // setUniformValue(int location, const QMatrix4x2 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix4x2 cppArg1_local = ::QMatrix4x2();
            ::QMatrix4x2* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X2_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix4x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 38: // setUniformValue(int location, const QMatrix4x3 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix4x3 cppArg1_local = ::QMatrix4x3();
            ::QMatrix4x3* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X3_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix4x3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 39: // setUniformValue(int location, const QMatrix4x4 & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMatrix4x4 cppArg1_local = ::QMatrix4x4();
            ::QMatrix4x4* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 40: // setUniformValue(int location, const QPoint & point)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPoint cppArg1_local = ::QPoint();
            ::QPoint* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 41: // setUniformValue(int location, const QPointF & point)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPointF cppArg1_local = ::QPointF();
            ::QPointF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 42: // setUniformValue(int location, const QSize & size)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QSize cppArg1_local = ::QSize();
            ::QSize* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 43: // setUniformValue(int location, const QSizeF & size)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QSizeF cppArg1_local = ::QSizeF();
            ::QSizeF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QSizeF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 44: // setUniformValue(int location, const QTransform & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTransform cppArg1_local = ::QTransform();
            ::QTransform* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 45: // setUniformValue(int location, const QVector2D & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector2D cppArg1_local = ::QVector2D();
            ::QVector2D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QVector2D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 46: // setUniformValue(int location, const QVector3D & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector3D cppArg1_local = ::QVector3D();
            ::QVector3D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 47: // setUniformValue(int location, const QVector4D & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector4D cppArg1_local = ::QVector4D();
            ::QVector4D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setUniformValue(int,QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUniformValue(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValue_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", float", "" SBK_STR_NAME ", float, float", "" SBK_STR_NAME ", float, float, float", "" SBK_STR_NAME ", float, float, float, float", "" SBK_STR_NAME ", int", "" SBK_STR_NAME ", unsigned int", "" SBK_STR_NAME ", PySide.QtGui.QColor", "" SBK_STR_NAME ", PySide.QtGui.QMatrix2x2", "" SBK_STR_NAME ", PySide.QtGui.QMatrix2x3", "" SBK_STR_NAME ", PySide.QtGui.QMatrix2x4", "" SBK_STR_NAME ", PySide.QtGui.QMatrix3x2", "" SBK_STR_NAME ", PySide.QtGui.QMatrix3x3", "" SBK_STR_NAME ", PySide.QtGui.QMatrix3x4", "" SBK_STR_NAME ", PySide.QtGui.QMatrix4x2", "" SBK_STR_NAME ", PySide.QtGui.QMatrix4x3", "" SBK_STR_NAME ", PySide.QtGui.QMatrix4x4", "" SBK_STR_NAME ", PySide.QtCore.QPoint", "" SBK_STR_NAME ", PySide.QtCore.QPointF", "" SBK_STR_NAME ", PySide.QtCore.QSize", "" SBK_STR_NAME ", PySide.QtCore.QSizeF", "" SBK_STR_NAME ", PySide.QtGui.QTransform", "" SBK_STR_NAME ", PySide.QtGui.QVector2D", "" SBK_STR_NAME ", PySide.QtGui.QVector3D", "" SBK_STR_NAME ", PySide.QtGui.QVector4D", "int, float", "int, float, float", "int, float, float, float", "int, float, float, float, float", "int, int", "int, unsigned int", "int, PySide.QtGui.QColor", "int, PySide.QtGui.QMatrix2x2", "int, PySide.QtGui.QMatrix2x3", "int, PySide.QtGui.QMatrix2x4", "int, PySide.QtGui.QMatrix3x2", "int, PySide.QtGui.QMatrix3x3", "int, PySide.QtGui.QMatrix3x4", "int, PySide.QtGui.QMatrix4x2", "int, PySide.QtGui.QMatrix4x3", "int, PySide.QtGui.QMatrix4x4", "int, PySide.QtCore.QPoint", "int, PySide.QtCore.QPointF", "int, PySide.QtCore.QSize", "int, PySide.QtCore.QSizeF", "int, PySide.QtGui.QTransform", "int, PySide.QtGui.QVector2D", "int, PySide.QtGui.QVector3D", "int, PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValue", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray2D(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray2D", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QVector2D*,int)
    // 1: setUniformValueArray(int,const QVector2D*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QVector2D*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QVector2D*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray2D_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QVector2D * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QVector2D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector2D *_list = new QVector2D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QVector2D*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QVector2D * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QVector2D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector2D *_list = new QVector2D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QVector2D*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray2D_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QVector2D, int", "int, PySide.QtGui.QVector2D, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray2D", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray2x2(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray2x2", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix2x2*,int)
    // 1: setUniformValueArray(int,const QMatrix2x2*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix2x2*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix2x2*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray2x2_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix2x2 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix2x2*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix2x2 *_list = new QMatrix2x2[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X2_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix2x2*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix2x2 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix2x2*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix2x2 *_list = new QMatrix2x2[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X2_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix2x2*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray2x2_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix2x2, int", "int, PySide.QtGui.QMatrix2x2, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray2x2", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray2x3(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray2x3", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix2x3*,int)
    // 1: setUniformValueArray(int,const QMatrix2x3*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix2x3*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix2x3*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray2x3_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix2x3 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix2x3*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix2x3 *_list = new QMatrix2x3[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix2x3*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix2x3 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix2x3*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix2x3 *_list = new QMatrix2x3[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix2x3*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray2x3_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix2x3, int", "int, PySide.QtGui.QMatrix2x3, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray2x3", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray2x4(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray2x4", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix2x4*,int)
    // 1: setUniformValueArray(int,const QMatrix2x4*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix2x4*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix2x4*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray2x4_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix2x4 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix2x4*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix2x4 *_list = new QMatrix2x4[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X4_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix2x4*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix2x4 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix2x4*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix2x4 *_list = new QMatrix2x4[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X4_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix2x4*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray2x4_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix2x4, int", "int, PySide.QtGui.QMatrix2x4, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray2x4", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray3D(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray3D", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QVector3D*,int)
    // 1: setUniformValueArray(int,const QVector3D*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QVector3D*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QVector3D*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray3D_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QVector3D * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QVector3D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector3D *_list = new QVector3D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QVector3D*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QVector3D * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QVector3D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector3D *_list = new QVector3D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QVector3D*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray3D_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QVector3D, int", "int, PySide.QtGui.QVector3D, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray3D", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray3x2(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray3x2", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix3x2*,int)
    // 1: setUniformValueArray(int,const QMatrix3x2*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix3x2*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix3x2*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray3x2_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix3x2 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix3x2*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix3x2 *_list = new QMatrix3x2[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix3x2*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix3x2 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix3x2*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix3x2 *_list = new QMatrix3x2[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix3x2*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray3x2_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix3x2, int", "int, PySide.QtGui.QMatrix3x2, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray3x2", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray3x3(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray3x3", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix3x3*,int)
    // 1: setUniformValueArray(int,const QMatrix3x3*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix3x3*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix3x3*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray3x3_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix3x3 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix3x3*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix3x3 *_list = new QMatrix3x3[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix3x3*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix3x3 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix3x3*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix3x3 *_list = new QMatrix3x3[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix3x3*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray3x3_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix3x3, int", "int, PySide.QtGui.QMatrix3x3, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray3x3", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray3x4(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray3x4", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix3x4*,int)
    // 1: setUniformValueArray(int,const QMatrix3x4*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix3x4*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix3x4*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray3x4_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix3x4 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix3x4*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix3x4 *_list = new QMatrix3x4[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X4_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix3x4*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix3x4 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix3x4*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix3x4 *_list = new QMatrix3x4[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X4_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix3x4*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray3x4_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix3x4, int", "int, PySide.QtGui.QMatrix3x4, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray3x4", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray4D(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray4D", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QVector4D*,int)
    // 1: setUniformValueArray(int,const QVector4D*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QVector4D*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QVector4D*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray4D_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QVector4D * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QVector4D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector4D *_list = new QVector4D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QVector4D*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QVector4D * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QVector4D*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QVector4D *_list = new QVector4D[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QVector4D*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray4D_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QVector4D, int", "int, PySide.QtGui.QVector4D, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray4D", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray4x2(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray4x2", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix4x2*,int)
    // 1: setUniformValueArray(int,const QMatrix4x2*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix4x2*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix4x2*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray4x2_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix4x2 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix4x2*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix4x2 *_list = new QMatrix4x2[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X2_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix4x2*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix4x2 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix4x2*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix4x2 *_list = new QMatrix4x2[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X2_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix4x2*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray4x2_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix4x2, int", "int, PySide.QtGui.QMatrix4x2, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray4x2", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray4x3(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray4x3", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix4x3*,int)
    // 1: setUniformValueArray(int,const QMatrix4x3*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix4x3*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix4x3*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray4x3_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix4x3 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix4x3*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix4x3 *_list = new QMatrix4x3[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X3_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix4x3*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix4x3 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix4x3*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix4x3 *_list = new QMatrix4x3[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X3_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix4x3*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray4x3_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix4x3, int", "int, PySide.QtGui.QMatrix4x3, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray4x3", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArray4x4(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArray4x4", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const QMatrix4x4*,int)
    // 1: setUniformValueArray(int,const QMatrix4x4*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const QMatrix4x4*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const QMatrix4x4*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArray4x4_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const QMatrix4x4 * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const QMatrix4x4*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix4x4 *_list = new QMatrix4x4[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix4x4*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const QMatrix4x4 * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const QMatrix4x4*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                QMatrix4x4 *_list = new QMatrix4x4[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (QMatrix4x4*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArray4x4_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtGui.QMatrix4x4, int", "int, PySide.QtGui.QMatrix4x4, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArray4x4", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArrayInt(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArrayInt", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const GLint*,int)
    // 1: setUniformValueArray(int,const GLint*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const GLint*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const GLint*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArrayInt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const GLint * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const GLint*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                GLint *_list = new GLint[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (GLint*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const GLint * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const GLint*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                GLint *_list = new GLint[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (GLint*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArrayInt_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtOpenGL.GLint, int", "int, PySide.QtOpenGL.GLint, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArrayInt", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_setUniformValueArrayUint(PyObject* self, PyObject* args)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUniformValueArrayUint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUniformValueArray(const char*,const GLuint*,int)
    // 1: setUniformValueArray(int,const GLuint*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 1; // setUniformValueArray(int,const GLuint*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && PySequence_Check(pyArgs[1])) {
        overloadId = 0; // setUniformValueArray(const char*,const GLuint*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_setUniformValueArrayUint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUniformValueArray(const char * name, const GLuint * values, int count)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(const char*,const GLuint*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                GLuint *_list = new GLuint[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (GLuint*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
        case 1: // setUniformValueArray(int location, const GLuint * values, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUniformValueArray(int,const GLuint*,int)
                // Begin code injection

                // TEMPLATE - callArrayFunction - START
                int _size = PySequence_Size(pyArgs[2-1]);
                if (_size) {
                GLuint *_list = new GLuint[_size];
                if (_size) {
                Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[2-1], "Failed to parse sequence with type %VECTOR_TYPE."));
                for(int i=0; i < _size; i++) {
                    PyObject* pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), pv, &(_list[i]));
                }
                }
                cppSelf->setUniformValueArray(cppArg0, _list, _size);
                delete[] _list;
                } else {
                cppSelf->setUniformValueArray(cppArg0, (GLuint*)NULL, 0);
                }
                // TEMPLATE - callArrayFunction - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLShaderProgramFunc_setUniformValueArrayUint_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtOpenGL.GLuint, int", "int, PySide.QtOpenGL.GLuint, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShaderProgram.setUniformValueArrayUint", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderProgramFunc_shaders(PyObject* self)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shaders()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGLShader * > cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->shaders();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtOpenGLTypeConverters[SBK_QTOPENGL_QLIST_QGLSHADERPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLShaderProgramFunc_uniformLocation(PyObject* self, PyObject* pyArg)
{
    ::QGLShaderProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShaderProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: uniformLocation(QByteArray)const
    // 1: uniformLocation(QString)const
    // 2: uniformLocation(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 2; // uniformLocation(const char*)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // uniformLocation(QString)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // uniformLocation(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderProgramFunc_uniformLocation_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // uniformLocation(const QByteArray & name) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // uniformLocation(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->uniformLocation(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // uniformLocation(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // uniformLocation(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->uniformLocation(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 2: // uniformLocation(const char * name) const
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // uniformLocation(const char*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QGLShaderProgram*>(cppSelf)->uniformLocation(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderProgramFunc_uniformLocation_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "unicode", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShaderProgram.uniformLocation", overloads);
        return 0;
}

static PyMethodDef Sbk_QGLShaderProgram_methods[] = {
    {"addShader", (PyCFunction)Sbk_QGLShaderProgramFunc_addShader, METH_O},
    {"addShaderFromSourceCode", (PyCFunction)Sbk_QGLShaderProgramFunc_addShaderFromSourceCode, METH_VARARGS},
    {"addShaderFromSourceFile", (PyCFunction)Sbk_QGLShaderProgramFunc_addShaderFromSourceFile, METH_VARARGS},
    {"attributeLocation", (PyCFunction)Sbk_QGLShaderProgramFunc_attributeLocation, METH_O},
    {"bind", (PyCFunction)Sbk_QGLShaderProgramFunc_bind, METH_NOARGS},
    {"bindAttributeLocation", (PyCFunction)Sbk_QGLShaderProgramFunc_bindAttributeLocation, METH_VARARGS},
    {"disableAttributeArray", (PyCFunction)Sbk_QGLShaderProgramFunc_disableAttributeArray, METH_O},
    {"enableAttributeArray", (PyCFunction)Sbk_QGLShaderProgramFunc_enableAttributeArray, METH_O},
    {"geometryInputType", (PyCFunction)Sbk_QGLShaderProgramFunc_geometryInputType, METH_NOARGS},
    {"geometryOutputType", (PyCFunction)Sbk_QGLShaderProgramFunc_geometryOutputType, METH_NOARGS},
    {"geometryOutputVertexCount", (PyCFunction)Sbk_QGLShaderProgramFunc_geometryOutputVertexCount, METH_NOARGS},
    {"hasOpenGLShaderPrograms", (PyCFunction)Sbk_QGLShaderProgramFunc_hasOpenGLShaderPrograms, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"isLinked", (PyCFunction)Sbk_QGLShaderProgramFunc_isLinked, METH_NOARGS},
    {"link", (PyCFunction)Sbk_QGLShaderProgramFunc_link, METH_NOARGS},
    {"log", (PyCFunction)Sbk_QGLShaderProgramFunc_log, METH_NOARGS},
    {"maxGeometryOutputVertices", (PyCFunction)Sbk_QGLShaderProgramFunc_maxGeometryOutputVertices, METH_NOARGS},
    {"programId", (PyCFunction)Sbk_QGLShaderProgramFunc_programId, METH_NOARGS},
    {"release", (PyCFunction)Sbk_QGLShaderProgramFunc_release, METH_NOARGS},
    {"removeAllShaders", (PyCFunction)Sbk_QGLShaderProgramFunc_removeAllShaders, METH_NOARGS},
    {"removeShader", (PyCFunction)Sbk_QGLShaderProgramFunc_removeShader, METH_O},
    {"setAttributeArray2D", (PyCFunction)Sbk_QGLShaderProgramFunc_setAttributeArray2D, METH_VARARGS|METH_KEYWORDS},
    {"setAttributeArray3D", (PyCFunction)Sbk_QGLShaderProgramFunc_setAttributeArray3D, METH_VARARGS|METH_KEYWORDS},
    {"setAttributeArray4D", (PyCFunction)Sbk_QGLShaderProgramFunc_setAttributeArray4D, METH_VARARGS|METH_KEYWORDS},
    {"setAttributeBuffer", (PyCFunction)Sbk_QGLShaderProgramFunc_setAttributeBuffer, METH_VARARGS|METH_KEYWORDS},
    {"setAttributeValue", (PyCFunction)Sbk_QGLShaderProgramFunc_setAttributeValue, METH_VARARGS},
    {"setGeometryInputType", (PyCFunction)Sbk_QGLShaderProgramFunc_setGeometryInputType, METH_O},
    {"setGeometryOutputType", (PyCFunction)Sbk_QGLShaderProgramFunc_setGeometryOutputType, METH_O},
    {"setGeometryOutputVertexCount", (PyCFunction)Sbk_QGLShaderProgramFunc_setGeometryOutputVertexCount, METH_O},
    {"setUniformValue", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValue, METH_VARARGS},
    {"setUniformValueArray2D", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray2D, METH_VARARGS},
    {"setUniformValueArray2x2", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray2x2, METH_VARARGS},
    {"setUniformValueArray2x3", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray2x3, METH_VARARGS},
    {"setUniformValueArray2x4", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray2x4, METH_VARARGS},
    {"setUniformValueArray3D", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray3D, METH_VARARGS},
    {"setUniformValueArray3x2", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray3x2, METH_VARARGS},
    {"setUniformValueArray3x3", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray3x3, METH_VARARGS},
    {"setUniformValueArray3x4", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray3x4, METH_VARARGS},
    {"setUniformValueArray4D", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray4D, METH_VARARGS},
    {"setUniformValueArray4x2", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray4x2, METH_VARARGS},
    {"setUniformValueArray4x3", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray4x3, METH_VARARGS},
    {"setUniformValueArray4x4", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArray4x4, METH_VARARGS},
    {"setUniformValueArrayInt", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArrayInt, METH_VARARGS},
    {"setUniformValueArrayUint", (PyCFunction)Sbk_QGLShaderProgramFunc_setUniformValueArrayUint, METH_VARARGS},
    {"shaders", (PyCFunction)Sbk_QGLShaderProgramFunc_shaders, METH_NOARGS},
    {"uniformLocation", (PyCFunction)Sbk_QGLShaderProgramFunc_uniformLocation, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGLShaderProgram_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLShaderProgram_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLShaderProgram_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLShaderProgram",
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
    /*tp_traverse*/         Sbk_QGLShaderProgram_traverse,
    /*tp_clear*/            Sbk_QGLShaderProgram_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLShaderProgram_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLShaderProgram_Init,
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

static void* Sbk_QGLShaderProgram_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGLShaderProgram*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLShaderProgram_PythonToCpp_QGLShaderProgram_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLShaderProgram_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLShaderProgram_PythonToCpp_QGLShaderProgram_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLShaderProgram_Type))
        return QGLShaderProgram_PythonToCpp_QGLShaderProgram_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLShaderProgram_PTR_CppToPython_QGLShaderProgram(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGLShaderProgram*)cppIn, &Sbk_QGLShaderProgram_Type);

}

void init_QGLShaderProgram(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLSHADERPROGRAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLShaderProgram_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLShaderProgram", "QGLShaderProgram*",
        &Sbk_QGLShaderProgram_Type, &Shiboken::callCppDestructor< ::QGLShaderProgram >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLShaderProgram_Type,
        QGLShaderProgram_PythonToCpp_QGLShaderProgram_PTR,
        is_QGLShaderProgram_PythonToCpp_QGLShaderProgram_PTR_Convertible,
        QGLShaderProgram_PTR_CppToPython_QGLShaderProgram);

    Shiboken::Conversions::registerConverterName(converter, "QGLShaderProgram");
    Shiboken::Conversions::registerConverterName(converter, "QGLShaderProgram*");
    Shiboken::Conversions::registerConverterName(converter, "QGLShaderProgram&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLShaderProgram).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLShaderProgramWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGLShaderProgram_Type, &Sbk_QGLShaderProgram_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QGLShaderProgram_Type, &::QGLShaderProgram::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGLShaderProgram_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGLShaderProgram_Type, &::QGLShaderProgram::staticMetaObject, sizeof(::QGLShaderProgram));
}
