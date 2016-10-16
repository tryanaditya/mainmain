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
#include "pyside_qtopengl_python.h"

#include "qglcontext_wrapper.h"

// Extra includes
#include <qcolor.h>
#include <qgl.h>
#include <qimage.h>
#include <qpaintdevice.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>


// Native ---------------------------------------------------------

QGLContextWrapper::QGLContextWrapper(const QGLFormat & format) : QGLContext(format) {
    // ... middle
}

bool QGLContextWrapper::chooseContext(const QGLContext * shareContext)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "chooseContext"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::chooseContext(shareContext);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], shareContext)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLContext.chooseContext", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

void * QGLContextWrapper::chooseVisual()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((void*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "chooseVisual"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::chooseVisual();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((void*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLContext.chooseVisual", Shiboken::SbkType< void >()->tp_name, pyResult->ob_type->tp_name);
        return ((void*)0);
    }
    void* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QGLContextWrapper::create(const QGLContext * shareContext)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "create"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::create(shareContext);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], shareContext)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLContext.create", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

void QGLContextWrapper::doneCurrent()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "doneCurrent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::doneCurrent();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGLContextWrapper::makeCurrent()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "makeCurrent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::makeCurrent();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGLContextWrapper::swapBuffers() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "swapBuffers"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::swapBuffers();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void * QGLContextWrapper::tryVisual(const QGLFormat & f, int bufDepth)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((void*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "tryVisual"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLContext::tryVisual(f, bufDepth);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], &f),
        bufDepth
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((void*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLContext.tryVisual", Shiboken::SbkType< void >()->tp_name, pyResult->ob_type->tp_name);
        return ((void*)0);
    }
    void* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QGLContextWrapper::~QGLContextWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLContext_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLContext >()))
        return -1;

    ::QGLContextWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGLContext", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGLContext(QGLFormat)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGLContext(QGLFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContext_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QGLFormat cppArg0_local = ::QGLFormat();
        ::QGLFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);


        if (!PyErr_Occurred()) {
            // QGLContext(QGLFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGLContextWrapper(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLContext >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLContext_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLContext_Init_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext", overloads);
        return -1;
}

static PyObject* Sbk_QGLContextFunc_areSharing(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "areSharing", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: areSharing(const QGLContext*,const QGLContext*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[1])))) {
        overloadId = 0; // areSharing(const QGLContext*,const QGLContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_areSharing_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGLContext* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QGLContext* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // areSharing(const QGLContext*,const QGLContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLContext::areSharing(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_areSharing_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLContext, PySide.QtOpenGL.QGLContext", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext.areSharing", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_bindTexture(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.bindTexture(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.bindTexture(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:bindTexture", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: bindTexture(QImage,GLenum,GLint)
    // 1: bindTexture(QImage,GLenum,GLint,QFlags<QGLContext::BindOption>)
    // 2: bindTexture(QPixmap,GLenum,GLint)
    // 3: bindTexture(QPixmap,GLenum,GLint,QFlags<QGLContext::BindOption>)
    // 4: bindTexture(QString)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 4; // bindTexture(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // bindTexture(QImage,GLenum,GLint)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // bindTexture(QImage,GLenum,GLint)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // bindTexture(QImage,GLenum,GLint)
                } else if (numArgs == 4
                    && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), (pyArgs[3])))) {
                    overloadId = 1; // bindTexture(QImage,GLenum,GLint,QFlags<QGLContext::BindOption>)
                }
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // bindTexture(QPixmap,GLenum,GLint)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // bindTexture(QPixmap,GLenum,GLint)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 2; // bindTexture(QPixmap,GLenum,GLint)
                } else if (numArgs == 4
                    && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), (pyArgs[3])))) {
                    overloadId = 3; // bindTexture(QPixmap,GLenum,GLint,QFlags<QGLContext::BindOption>)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_bindTexture_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindTexture(const QImage & image, GLenum target, GLint format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.bindTexture(): got multiple values for keyword argument 'target'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1]))))
                        goto Sbk_QGLContextFunc_bindTexture_TypeError;
                }
                value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.bindTexture(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), (pyArgs[2]))))
                        goto Sbk_QGLContextFunc_bindTexture_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QImage cppArg0_local = ::QImage();
            ::QImage* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            GLenum cppArg1 = 0x0DE1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            GLint cppArg2 = 0x1908;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // bindTexture(QImage,GLenum,GLint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
        case 1: // bindTexture(const QImage & image, GLenum target, GLint format, QFlags<QGLContext::BindOption> options)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QImage cppArg0_local = ::QImage();
            ::QImage* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            GLenum cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLint cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QGLContext::BindOption> cppArg3 = ((::QFlags<QGLContext::BindOption>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // bindTexture(QImage,GLenum,GLint,QFlags<QGLContext::BindOption>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
        case 2: // bindTexture(const QPixmap & pixmap, GLenum target, GLint format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.bindTexture(): got multiple values for keyword argument 'target'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1]))))
                        goto Sbk_QGLContextFunc_bindTexture_TypeError;
                }
                value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.bindTexture(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLint>(), (pyArgs[2]))))
                        goto Sbk_QGLContextFunc_bindTexture_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPixmap cppArg0_local = ::QPixmap();
            ::QPixmap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            GLenum cppArg1 = 0x0DE1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            GLint cppArg2 = 0x1908;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // bindTexture(QPixmap,GLenum,GLint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
        case 3: // bindTexture(const QPixmap & pixmap, GLenum target, GLint format, QFlags<QGLContext::BindOption> options)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPixmap cppArg0_local = ::QPixmap();
            ::QPixmap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            GLenum cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLint cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QGLContext::BindOption> cppArg3 = ((::QFlags<QGLContext::BindOption>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // bindTexture(QPixmap,GLenum,GLint,QFlags<QGLContext::BindOption>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
        case 4: // bindTexture(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // bindTexture(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_bindTexture_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, unsigned int = 0x0DE1, int = 0x1908", "PySide.QtGui.QImage, unsigned int, int, PySide.QtOpenGL.QGLContext.BindOptions", "PySide.QtGui.QPixmap, unsigned int = 0x0DE1, int = 0x1908", "PySide.QtGui.QPixmap, unsigned int, int, PySide.QtOpenGL.QGLContext.BindOptions", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext.bindTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_chooseContext(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.chooseContext(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:chooseContext", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: chooseContext(const QGLContext*)
    if (numArgs == 0) {
        overloadId = 0; // chooseContext(const QGLContext*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0])))) {
        overloadId = 0; // chooseContext(const QGLContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_chooseContext_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "shareContext");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.chooseContext(): got multiple values for keyword argument 'shareContext'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0]))))
                    goto Sbk_QGLContextFunc_chooseContext_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGLContext* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // chooseContext(const QGLContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLContext::chooseContext(cppArg0) : cppSelf->chooseContext(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_chooseContext_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLContext = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext.chooseContext", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_chooseVisual(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // chooseVisual()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLContext::chooseVisual() : cppSelf->chooseVisual();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLContextFunc_colorIndex(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: colorIndex(QColor)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 0; // colorIndex(QColor)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_colorIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QColor cppArg0_local = ::QColor();
        ::QColor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // colorIndex(QColor)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QGLContext*>(cppSelf)->colorIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_colorIndex_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.colorIndex", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_create(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.create(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:create", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: create(const QGLContext*)
    if (numArgs == 0) {
        overloadId = 0; // create(const QGLContext*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0])))) {
        overloadId = 0; // create(const QGLContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_create_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "shareContext");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.create(): got multiple values for keyword argument 'shareContext'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (pyArgs[0]))))
                    goto Sbk_QGLContextFunc_create_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGLContext* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // create(const QGLContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLContext::create(cppArg0) : cppSelf->create(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_create_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLContext = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext.create", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_currentContext(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentContext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QGLContext * cppResult = ::QGLContext::currentContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLContextFunc_deleteTexture(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deleteTexture(GLuint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArg)))) {
        overloadId = 0; // deleteTexture(GLuint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_deleteTexture_TypeError;

    // Call function/method
    {
        GLuint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deleteTexture(GLuint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deleteTexture(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_deleteTexture_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.deleteTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_device(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintDevice * cppResult = const_cast<const ::QGLContext*>(cppSelf)->device();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLContextFunc_deviceIsPixmap(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceIsPixmap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLContext*>(cppSelf)->deviceIsPixmap();
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

static PyObject* Sbk_QGLContextFunc_doneCurrent(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doneCurrent()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLContext::doneCurrent() : cppSelf->doneCurrent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLContextFunc_drawTexture(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.drawTexture(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.drawTexture(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:drawTexture", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawTexture(QPointF,GLuint,GLenum)
    // 1: drawTexture(QRectF,GLuint,GLenum)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // drawTexture(QRectF,GLuint,GLenum)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2])))) {
            overloadId = 1; // drawTexture(QRectF,GLuint,GLenum)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // drawTexture(QPointF,GLuint,GLenum)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2])))) {
            overloadId = 0; // drawTexture(QPointF,GLuint,GLenum)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_drawTexture_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawTexture(const QPointF & point, GLuint textureId, GLenum textureTarget)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "textureTarget");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.drawTexture(): got multiple values for keyword argument 'textureTarget'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLContextFunc_drawTexture_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            GLuint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLenum cppArg2 = 0x0DE1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawTexture(QPointF,GLuint,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTexture(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawTexture(const QRectF & target, GLuint textureId, GLenum textureTarget)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "textureTarget");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.drawTexture(): got multiple values for keyword argument 'textureTarget'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLContextFunc_drawTexture_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            GLuint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLenum cppArg2 = 0x0DE1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawTexture(QRectF,GLuint,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTexture(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_drawTexture_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, unsigned int, unsigned int = 0x0DE1", "PySide.QtCore.QRectF, unsigned int, unsigned int = 0x0DE1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext.drawTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_format(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFormat cppResult = const_cast<const ::QGLContext*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLContextFunc_getProcAddress(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getProcAddress(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getProcAddress(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_getProcAddress_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getProcAddress(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = const_cast<const ::QGLContext*>(cppSelf)->getProcAddress(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_getProcAddress_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.getProcAddress", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_initialized(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initialized()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLContext*>(cppSelf)->initialized();
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

static PyObject* Sbk_QGLContextFunc_isSharing(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSharing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLContext*>(cppSelf)->isSharing();
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

static PyObject* Sbk_QGLContextFunc_isValid(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLContext*>(cppSelf)->isValid();
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

static PyObject* Sbk_QGLContextFunc_makeCurrent(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // makeCurrent()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLContext::makeCurrent() : cppSelf->makeCurrent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLContextFunc_overlayTransparentColor(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overlayTransparentColor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QGLContext*>(cppSelf)->overlayTransparentColor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLContextFunc_requestedFormat(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // requestedFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFormat cppResult = const_cast<const ::QGLContext*>(cppSelf)->requestedFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLContextFunc_reset(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLContextFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QPaintDevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_setDevice_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDevice(QPaintDevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDevice(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_setFormat(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFormat(QGLFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setFormat(QGLFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_setFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGLFormat cppArg0_local = ::QGLFormat();
        ::QGLFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setFormat(QGLFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_setFormat_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.setFormat", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_setInitialized(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInitialized(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setInitialized(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_setInitialized_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInitialized(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInitialized(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_setInitialized_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.setInitialized", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_setTextureCacheLimit(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextureCacheLimit(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setTextureCacheLimit(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_setTextureCacheLimit_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextureCacheLimit(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGLContext::setTextureCacheLimit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_setTextureCacheLimit_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.setTextureCacheLimit", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_setValid(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValid(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setValid(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_setValid_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValid(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValid(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_setValid_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.setValid", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_setWindowCreated(PyObject* self, PyObject* pyArg)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWindowCreated(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setWindowCreated(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_setWindowCreated_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWindowCreated(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWindowCreated(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLContextFunc_setWindowCreated_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLContext.setWindowCreated", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_swapBuffers(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // swapBuffers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLContext*>(cppSelf)->::QGLContext::swapBuffers() : const_cast<const ::QGLContext*>(cppSelf)->swapBuffers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLContextFunc_textureCacheLimit(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textureCacheLimit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QGLContext::textureCacheLimit();
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

static PyObject* Sbk_QGLContextFunc_tryVisual(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.tryVisual(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.tryVisual(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:tryVisual", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: tryVisual(QGLFormat,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // tryVisual(QGLFormat,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // tryVisual(QGLFormat,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLContextFunc_tryVisual_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "bufDepth");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLContext.tryVisual(): got multiple values for keyword argument 'bufDepth'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QGLContextFunc_tryVisual_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGLFormat cppArg0_local = ::QGLFormat();
        ::QGLFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = 1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // tryVisual(QGLFormat,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGLContext::tryVisual(*cppArg0, cppArg1) : cppSelf->tryVisual(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLContextFunc_tryVisual_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFormat, int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLContext.tryVisual", overloads);
        return 0;
}

static PyObject* Sbk_QGLContextFunc_windowCreated(PyObject* self)
{
    ::QGLContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // windowCreated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLContext*>(cppSelf)->windowCreated();
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

static PyMethodDef Sbk_QGLContext_methods[] = {
    {"areSharing", (PyCFunction)Sbk_QGLContextFunc_areSharing, METH_VARARGS|METH_STATIC},
    {"bindTexture", (PyCFunction)Sbk_QGLContextFunc_bindTexture, METH_VARARGS|METH_KEYWORDS},
    {"chooseContext", (PyCFunction)Sbk_QGLContextFunc_chooseContext, METH_VARARGS|METH_KEYWORDS},
    {"chooseVisual", (PyCFunction)Sbk_QGLContextFunc_chooseVisual, METH_NOARGS},
    {"colorIndex", (PyCFunction)Sbk_QGLContextFunc_colorIndex, METH_O},
    {"create", (PyCFunction)Sbk_QGLContextFunc_create, METH_VARARGS|METH_KEYWORDS},
    {"currentContext", (PyCFunction)Sbk_QGLContextFunc_currentContext, METH_NOARGS|METH_STATIC},
    {"deleteTexture", (PyCFunction)Sbk_QGLContextFunc_deleteTexture, METH_O},
    {"device", (PyCFunction)Sbk_QGLContextFunc_device, METH_NOARGS},
    {"deviceIsPixmap", (PyCFunction)Sbk_QGLContextFunc_deviceIsPixmap, METH_NOARGS},
    {"doneCurrent", (PyCFunction)Sbk_QGLContextFunc_doneCurrent, METH_NOARGS},
    {"drawTexture", (PyCFunction)Sbk_QGLContextFunc_drawTexture, METH_VARARGS|METH_KEYWORDS},
    {"format", (PyCFunction)Sbk_QGLContextFunc_format, METH_NOARGS},
    {"getProcAddress", (PyCFunction)Sbk_QGLContextFunc_getProcAddress, METH_O},
    {"initialized", (PyCFunction)Sbk_QGLContextFunc_initialized, METH_NOARGS},
    {"isSharing", (PyCFunction)Sbk_QGLContextFunc_isSharing, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QGLContextFunc_isValid, METH_NOARGS},
    {"makeCurrent", (PyCFunction)Sbk_QGLContextFunc_makeCurrent, METH_NOARGS},
    {"overlayTransparentColor", (PyCFunction)Sbk_QGLContextFunc_overlayTransparentColor, METH_NOARGS},
    {"requestedFormat", (PyCFunction)Sbk_QGLContextFunc_requestedFormat, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_QGLContextFunc_reset, METH_NOARGS},
    {"setDevice", (PyCFunction)Sbk_QGLContextFunc_setDevice, METH_O},
    {"setFormat", (PyCFunction)Sbk_QGLContextFunc_setFormat, METH_O},
    {"setInitialized", (PyCFunction)Sbk_QGLContextFunc_setInitialized, METH_O},
    {"setTextureCacheLimit", (PyCFunction)Sbk_QGLContextFunc_setTextureCacheLimit, METH_O|METH_STATIC},
    {"setValid", (PyCFunction)Sbk_QGLContextFunc_setValid, METH_O},
    {"setWindowCreated", (PyCFunction)Sbk_QGLContextFunc_setWindowCreated, METH_O},
    {"swapBuffers", (PyCFunction)Sbk_QGLContextFunc_swapBuffers, METH_NOARGS},
    {"textureCacheLimit", (PyCFunction)Sbk_QGLContextFunc_textureCacheLimit, METH_NOARGS|METH_STATIC},
    {"tryVisual", (PyCFunction)Sbk_QGLContextFunc_tryVisual, METH_VARARGS|METH_KEYWORDS},
    {"windowCreated", (PyCFunction)Sbk_QGLContextFunc_windowCreated, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGLContext_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLContext_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLContext_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLContext",
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
    /*tp_traverse*/         Sbk_QGLContext_traverse,
    /*tp_clear*/            Sbk_QGLContext_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLContext_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLContext_Init,
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

PyObject* SbkPySide_QtOpenGL_QGLContext_BindOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QGLContext::BindOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLContext::BindOptions)PyLong_AsLong(self);
    cppArg = (QGLContext::BindOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLContext::BindOptions)PyInt_AsLong(self);
    cppArg = (QGLContext::BindOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLContext_BindOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QGLContext::BindOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLContext::BindOptions)PyLong_AsLong(self);
    cppArg = (QGLContext::BindOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLContext::BindOptions)PyInt_AsLong(self);
    cppArg = (QGLContext::BindOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLContext_BindOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGLContext::BindOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLContext::BindOptions)PyLong_AsLong(self);
    cppArg = (QGLContext::BindOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLContext::BindOptions)PyInt_AsLong(self);
    cppArg = (QGLContext::BindOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLContext_BindOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGLContext::BindOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), self, &cppSelf);
    ::QGLContext::BindOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtOpenGL_QGLContext_BindOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtOpenGL_QGLContext_BindOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtOpenGL_QGLContext_BindOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtOpenGL_QGLContext_BindOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtOpenGL_QGLContext_BindOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtOpenGL_QGLContext_BindOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtOpenGL_QGLContext_BindOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtOpenGL_QGLContext_BindOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtOpenGL_QGLContext_BindOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtOpenGL_QGLContext_BindOption_long,
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
static void QGLContext_BindOption_PythonToCpp_QGLContext_BindOption(PyObject* pyIn, void* cppOut) {
    *((::QGLContext::BindOption*)cppOut) = (::QGLContext::BindOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLContext_BindOption_PythonToCpp_QGLContext_BindOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX]))
        return QGLContext_BindOption_PythonToCpp_QGLContext_BindOption;
    return 0;
}
static PyObject* QGLContext_BindOption_CppToPython_QGLContext_BindOption(const void* cppIn) {
    int castCppIn = *((::QGLContext::BindOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX], castCppIn);

}

static void QFlags_QGLContext_BindOption__PythonToCpp_QFlags_QGLContext_BindOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGLContext::BindOption>*)cppOut) = ::QFlags<QGLContext::BindOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGLContext_BindOption__PythonToCpp_QFlags_QGLContext_BindOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]))
        return QFlags_QGLContext_BindOption__PythonToCpp_QFlags_QGLContext_BindOption_;
    return 0;
}
static PyObject* QFlags_QGLContext_BindOption__CppToPython_QFlags_QGLContext_BindOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGLContext::BindOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]));

}

static void QGLContext_BindOption_PythonToCpp_QFlags_QGLContext_BindOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGLContext::BindOption>*)cppOut) = ::QFlags<QGLContext::BindOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGLContext_BindOption_PythonToCpp_QFlags_QGLContext_BindOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX]))
        return QGLContext_BindOption_PythonToCpp_QFlags_QGLContext_BindOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGLContext_BindOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGLContext::BindOption>*)cppOut) = ::QFlags<QGLContext::BindOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGLContext_BindOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGLContext_BindOption_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLContext_PythonToCpp_QGLContext_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLContext_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLContext_PythonToCpp_QGLContext_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLContext_Type))
        return QGLContext_PythonToCpp_QGLContext_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLContext_PTR_CppToPython_QGLContext(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLContext*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLContext_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGLContext(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLContext_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLContext", "QGLContext*",
        &Sbk_QGLContext_Type, &Shiboken::callCppDestructor< ::QGLContext >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLContext_Type,
        QGLContext_PythonToCpp_QGLContext_PTR,
        is_QGLContext_PythonToCpp_QGLContext_PTR_Convertible,
        QGLContext_PTR_CppToPython_QGLContext);

    Shiboken::Conversions::registerConverterName(converter, "QGLContext");
    Shiboken::Conversions::registerConverterName(converter, "QGLContext*");
    Shiboken::Conversions::registerConverterName(converter, "QGLContext&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLContext).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLContextWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'BindOption'.
    SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX] = PySide::QFlags::create("BindOptions", &SbkPySide_QtOpenGL_QGLContext_BindOption_as_number);
    SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLContext_Type,
        "BindOption",
        "PySide.QtOpenGL.QGLContext.BindOption",
        "QGLContext::BindOption",
        SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX]);
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "NoBindOption", (long) QGLContext::NoBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "InvertedYBindOption", (long) QGLContext::InvertedYBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "MipmapBindOption", (long) QGLContext::MipmapBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "PremultipliedAlphaBindOption", (long) QGLContext::PremultipliedAlphaBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "LinearFilteringBindOption", (long) QGLContext::LinearFilteringBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "MemoryManagedBindOption", (long) QGLContext::MemoryManagedBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "CanFlipNativePixmapBindOption", (long) QGLContext::CanFlipNativePixmapBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "DefaultBindOption", (long) QGLContext::DefaultBindOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
        &Sbk_QGLContext_Type, "InternalBindOption", (long) QGLContext::InternalBindOption))
        return ;
    // Register converter for enum 'QGLContext::BindOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX],
            QGLContext_BindOption_CppToPython_QGLContext_BindOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLContext_BindOption_PythonToCpp_QGLContext_BindOption,
            is_QGLContext_BindOption_PythonToCpp_QGLContext_BindOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLCONTEXT_BINDOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLContext::BindOption");
        Shiboken::Conversions::registerConverterName(converter, "BindOption");
    }
    // Register converter for flag 'QFlags<QGLContext::BindOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX],
            QFlags_QGLContext_BindOption__CppToPython_QFlags_QGLContext_BindOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLContext_BindOption_PythonToCpp_QFlags_QGLContext_BindOption_,
            is_QGLContext_BindOption_PythonToCpp_QFlags_QGLContext_BindOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGLContext_BindOption__PythonToCpp_QFlags_QGLContext_BindOption_,
            is_QFlags_QGLContext_BindOption__PythonToCpp_QFlags_QGLContext_BindOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGLContext_BindOption_,
            is_number_PythonToCpp_QFlags_QGLContext_BindOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLCONTEXT_BINDOPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGLContext::BindOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<BindOption>");
    }
    // End of 'BindOption' enum/flags.


    qRegisterMetaType< ::QGLContext::BindOption >("QGLContext::BindOption");
    qRegisterMetaType< ::QGLContext::BindOptions >("QGLContext::BindOptions");
}
