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

#include "qglshader_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qgl.h>
#include <qglshaderprogram.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QGLShaderWrapper::QGLShaderWrapper(QFlags<QGLShader::ShaderTypeBit> type, QObject * parent) : QGLShader(type, parent) {
    // ... middle
}

QGLShaderWrapper::QGLShaderWrapper(QFlags<QGLShader::ShaderTypeBit> type, const QGLContext * context, QObject * parent) : QGLShader(type, context, parent) {
    // ... middle
}

void QGLShaderWrapper::childEvent(QChildEvent * arg__1)
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

void QGLShaderWrapper::connectNotify(const char * signal)
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

void QGLShaderWrapper::customEvent(QEvent * arg__1)
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

void QGLShaderWrapper::disconnectNotify(const char * signal)
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

bool QGLShaderWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLShader.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGLShaderWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLShader.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QGLShaderWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QGLShaderWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGLShader::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGLShaderWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGLShader::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGLShaderWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGLShaderWrapper* >(this));
        return QGLShader::qt_metacast(_clname);
}

QGLShaderWrapper::~QGLShaderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLShader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLShader >()))
        return -1;

    ::QGLShaderWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShader(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QGLShader", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QGLShader(QFlags<QGLShader::ShaderTypeBit>,QObject*)
    // 1: QGLShader(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*,QObject*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QGLShader(QFlags<QGLShader::ShaderTypeBit>,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QGLShader(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
                overloadId = 1; // QGLShader(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*,QObject*)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // QGLShader(QFlags<QGLShader::ShaderTypeBit>,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShader_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLShader(QFlags<QGLShader::ShaderTypeBit> type, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShader(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QGLShader_Init_TypeError;
                }
            }
            ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGLShader(QFlags<QGLShader::ShaderTypeBit>,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGLShaderWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGLShaderWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 1: // QGLShader(QFlags<QGLShader::ShaderTypeBit> type, const QGLContext * context, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShader(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QGLShader_Init_TypeError;
                }
            }
            ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QGLContext* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QGLShader(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGLShaderWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGLShaderWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLShader >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLShader_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QGLShader_Init_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLShader.ShaderType, PySide.QtCore.QObject = None", "PySide.QtOpenGL.QGLShader.ShaderType, PySide.QtOpenGL.QGLContext, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShader", overloads);
        return -1;
}

static PyObject* Sbk_QGLShaderFunc_compileSourceCode(PyObject* self, PyObject* pyArg)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: compileSourceCode(QByteArray)
    // 1: compileSourceCode(QString)
    // 2: compileSourceCode(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 2; // compileSourceCode(const char*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // compileSourceCode(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // compileSourceCode(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderFunc_compileSourceCode_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // compileSourceCode(const QByteArray & source)
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
                // compileSourceCode(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->compileSourceCode(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // compileSourceCode(const QString & source)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // compileSourceCode(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->compileSourceCode(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // compileSourceCode(const char * source)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // compileSourceCode(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->compileSourceCode(cppArg0);
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

    Sbk_QGLShaderFunc_compileSourceCode_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "unicode", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShader.compileSourceCode", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderFunc_compileSourceFile(PyObject* self, PyObject* pyArg)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: compileSourceFile(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // compileSourceFile(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderFunc_compileSourceFile_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // compileSourceFile(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->compileSourceFile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderFunc_compileSourceFile_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLShader.compileSourceFile", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderFunc_hasOpenGLShaders(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShader.hasOpenGLShaders(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShader.hasOpenGLShaders(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:hasOpenGLShaders", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hasOpenGLShaders(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // hasOpenGLShaders(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[1])))) {
            overloadId = 0; // hasOpenGLShaders(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLShaderFunc_hasOpenGLShaders_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "context");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLShader.hasOpenGLShaders(): got multiple values for keyword argument 'context'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[1]))))
                    goto Sbk_QGLShaderFunc_hasOpenGLShaders_TypeError;
            }
        }
        ::QFlags<QGLShader::ShaderTypeBit> cppArg0 = ((::QFlags<QGLShader::ShaderTypeBit>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QGLContext* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // hasOpenGLShaders(QFlags<QGLShader::ShaderTypeBit>,const QGLContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLShader::hasOpenGLShaders(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLShaderFunc_hasOpenGLShaders_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLShader.ShaderType, PySide.QtOpenGL.QGLContext = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLShader.hasOpenGLShaders", overloads);
        return 0;
}

static PyObject* Sbk_QGLShaderFunc_isCompiled(PyObject* self)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCompiled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLShader*>(cppSelf)->isCompiled();
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

static PyObject* Sbk_QGLShaderFunc_log(PyObject* self)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // log()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QGLShader*>(cppSelf)->log();
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

static PyObject* Sbk_QGLShaderFunc_shaderId(PyObject* self)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shaderId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLuint cppResult = const_cast<const ::QGLShader*>(cppSelf)->shaderId();
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

static PyObject* Sbk_QGLShaderFunc_shaderType(PyObject* self)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shaderType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGLShader::ShaderTypeBit> cppResult = const_cast<const ::QGLShader*>(cppSelf)->shaderType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLShaderFunc_sourceCode(PyObject* self)
{
    ::QGLShader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLShader*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sourceCode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QGLShader*>(cppSelf)->sourceCode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGLShader_methods[] = {
    {"compileSourceCode", (PyCFunction)Sbk_QGLShaderFunc_compileSourceCode, METH_O},
    {"compileSourceFile", (PyCFunction)Sbk_QGLShaderFunc_compileSourceFile, METH_O},
    {"hasOpenGLShaders", (PyCFunction)Sbk_QGLShaderFunc_hasOpenGLShaders, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"isCompiled", (PyCFunction)Sbk_QGLShaderFunc_isCompiled, METH_NOARGS},
    {"log", (PyCFunction)Sbk_QGLShaderFunc_log, METH_NOARGS},
    {"shaderId", (PyCFunction)Sbk_QGLShaderFunc_shaderId, METH_NOARGS},
    {"shaderType", (PyCFunction)Sbk_QGLShaderFunc_shaderType, METH_NOARGS},
    {"sourceCode", (PyCFunction)Sbk_QGLShaderFunc_sourceCode, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGLShader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLShader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLShader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLShader",
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
    /*tp_traverse*/         Sbk_QGLShader_traverse,
    /*tp_clear*/            Sbk_QGLShader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLShader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLShader_Init,
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

static void* Sbk_QGLShader_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGLShader*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___and__(PyObject* self, PyObject* pyArg)
{
    ::QGLShader::ShaderType cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLShader::ShaderType)PyLong_AsLong(self);
    cppArg = (QGLShader::ShaderType)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLShader::ShaderType)PyInt_AsLong(self);
    cppArg = (QGLShader::ShaderType)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___or__(PyObject* self, PyObject* pyArg)
{
    ::QGLShader::ShaderType cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLShader::ShaderType)PyLong_AsLong(self);
    cppArg = (QGLShader::ShaderType)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLShader::ShaderType)PyInt_AsLong(self);
    cppArg = (QGLShader::ShaderType)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGLShader::ShaderType cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLShader::ShaderType)PyLong_AsLong(self);
    cppArg = (QGLShader::ShaderType)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLShader::ShaderType)PyInt_AsLong(self);
    cppArg = (QGLShader::ShaderType)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGLShader::ShaderType cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), self, &cppSelf);
    ::QGLShader::ShaderType cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit_long,
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
static void QGLShader_ShaderTypeBit_PythonToCpp_QGLShader_ShaderTypeBit(PyObject* pyIn, void* cppOut) {
    *((::QGLShader::ShaderTypeBit*)cppOut) = (::QGLShader::ShaderTypeBit) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLShader_ShaderTypeBit_PythonToCpp_QGLShader_ShaderTypeBit_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX]))
        return QGLShader_ShaderTypeBit_PythonToCpp_QGLShader_ShaderTypeBit;
    return 0;
}
static PyObject* QGLShader_ShaderTypeBit_CppToPython_QGLShader_ShaderTypeBit(const void* cppIn) {
    int castCppIn = *((::QGLShader::ShaderTypeBit*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX], castCppIn);

}

static void QFlags_QGLShader_ShaderTypeBit__PythonToCpp_QFlags_QGLShader_ShaderTypeBit_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGLShader::ShaderTypeBit>*)cppOut) = ::QFlags<QGLShader::ShaderTypeBit>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGLShader_ShaderTypeBit__PythonToCpp_QFlags_QGLShader_ShaderTypeBit__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]))
        return QFlags_QGLShader_ShaderTypeBit__PythonToCpp_QFlags_QGLShader_ShaderTypeBit_;
    return 0;
}
static PyObject* QFlags_QGLShader_ShaderTypeBit__CppToPython_QFlags_QGLShader_ShaderTypeBit_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGLShader::ShaderTypeBit>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]));

}

static void QGLShader_ShaderTypeBit_PythonToCpp_QFlags_QGLShader_ShaderTypeBit_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGLShader::ShaderTypeBit>*)cppOut) = ::QFlags<QGLShader::ShaderTypeBit>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGLShader_ShaderTypeBit_PythonToCpp_QFlags_QGLShader_ShaderTypeBit__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX]))
        return QGLShader_ShaderTypeBit_PythonToCpp_QFlags_QGLShader_ShaderTypeBit_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGLShader_ShaderTypeBit_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGLShader::ShaderTypeBit>*)cppOut) = ::QFlags<QGLShader::ShaderTypeBit>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGLShader_ShaderTypeBit__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGLShader_ShaderTypeBit_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLShader_PythonToCpp_QGLShader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLShader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLShader_PythonToCpp_QGLShader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLShader_Type))
        return QGLShader_PythonToCpp_QGLShader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLShader_PTR_CppToPython_QGLShader(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGLShader*)cppIn, &Sbk_QGLShader_Type);

}

void init_QGLShader(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLShader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLShader", "QGLShader*",
        &Sbk_QGLShader_Type, &Shiboken::callCppDestructor< ::QGLShader >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLShader_Type,
        QGLShader_PythonToCpp_QGLShader_PTR,
        is_QGLShader_PythonToCpp_QGLShader_PTR_Convertible,
        QGLShader_PTR_CppToPython_QGLShader);

    Shiboken::Conversions::registerConverterName(converter, "QGLShader");
    Shiboken::Conversions::registerConverterName(converter, "QGLShader*");
    Shiboken::Conversions::registerConverterName(converter, "QGLShader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLShader).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLShaderWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGLShader_Type, &Sbk_QGLShader_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ShaderTypeBit'.
    SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX] = PySide::QFlags::create("ShaderType", &SbkPySide_QtOpenGL_QGLShader_ShaderTypeBit_as_number);
    SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLShader_Type,
        "ShaderTypeBit",
        "PySide.QtOpenGL.QGLShader.ShaderTypeBit",
        "QGLShader::ShaderTypeBit",
        SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX]);
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX],
        &Sbk_QGLShader_Type, "Vertex", (long) QGLShader::Vertex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX],
        &Sbk_QGLShader_Type, "Fragment", (long) QGLShader::Fragment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX],
        &Sbk_QGLShader_Type, "Geometry", (long) QGLShader::Geometry))
        return ;
    // Register converter for enum 'QGLShader::ShaderTypeBit'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX],
            QGLShader_ShaderTypeBit_CppToPython_QGLShader_ShaderTypeBit);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLShader_ShaderTypeBit_PythonToCpp_QGLShader_ShaderTypeBit,
            is_QGLShader_ShaderTypeBit_PythonToCpp_QGLShader_ShaderTypeBit_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLSHADER_SHADERTYPEBIT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLShader::ShaderTypeBit");
        Shiboken::Conversions::registerConverterName(converter, "ShaderTypeBit");
    }
    // Register converter for flag 'QFlags<QGLShader::ShaderTypeBit>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX],
            QFlags_QGLShader_ShaderTypeBit__CppToPython_QFlags_QGLShader_ShaderTypeBit_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLShader_ShaderTypeBit_PythonToCpp_QFlags_QGLShader_ShaderTypeBit_,
            is_QGLShader_ShaderTypeBit_PythonToCpp_QFlags_QGLShader_ShaderTypeBit__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGLShader_ShaderTypeBit__PythonToCpp_QFlags_QGLShader_ShaderTypeBit_,
            is_QFlags_QGLShader_ShaderTypeBit__PythonToCpp_QFlags_QGLShader_ShaderTypeBit__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGLShader_ShaderTypeBit_,
            is_number_PythonToCpp_QFlags_QGLShader_ShaderTypeBit__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLSHADER_SHADERTYPEBIT__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGLShader::ShaderTypeBit>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ShaderTypeBit>");
    }
    // End of 'ShaderTypeBit' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QGLShader_Type, &::QGLShader::staticMetaObject);

    qRegisterMetaType< ::QGLShader::ShaderTypeBit >("QGLShader::ShaderTypeBit");
    qRegisterMetaType< ::QGLShader::ShaderType >("QGLShader::ShaderType");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGLShader_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGLShader_Type, &::QGLShader::staticMetaObject, sizeof(::QGLShader));
}
