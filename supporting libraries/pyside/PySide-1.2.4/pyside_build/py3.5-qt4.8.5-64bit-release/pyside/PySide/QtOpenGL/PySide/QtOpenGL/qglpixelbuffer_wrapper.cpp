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

#include "qglpixelbuffer_wrapper.h"

// Extra includes
#include <QImage>
#include <qgl.h>
#include <qglpixelbuffer.h>
#include <qimage.h>
#include <qpaintengine.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qsize.h>


// Native ---------------------------------------------------------

QGLPixelBufferWrapper::QGLPixelBufferWrapper(const QSize & size, const QGLFormat & format, QGLWidget * shareWidget) : QGLPixelBuffer(size, format, shareWidget) {
    // ... middle
}

QGLPixelBufferWrapper::QGLPixelBufferWrapper(int width, int height, const QGLFormat & format, QGLWidget * shareWidget) : QGLPixelBuffer(width, height, format, shareWidget) {
    // ... middle
}

int QGLPixelBufferWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLPixelBuffer::devType();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLPixelBuffer.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QGLPixelBufferWrapper::metric(QPaintDevice::PaintDeviceMetric metric) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLPixelBuffer::metric(metric);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &metric)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLPixelBuffer.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QGLPixelBufferWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLPixelBuffer::paintEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPaintEngine*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLPixelBuffer.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QGLPixelBufferWrapper::~QGLPixelBufferWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLPixelBuffer_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLPixelBuffer >()))
        return -1;

    ::QGLPixelBufferWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QGLPixelBuffer", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QGLPixelBuffer(QSize,QGLFormat,QGLWidget*)
    // 1: QGLPixelBuffer(int,int,QGLFormat,QGLWidget*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QGLPixelBuffer(int,int,QGLFormat,QGLWidget*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // QGLPixelBuffer(int,int,QGLFormat,QGLWidget*)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLWIDGET_IDX], (pyArgs[3])))) {
                overloadId = 1; // QGLPixelBuffer(int,int,QGLFormat,QGLWidget*)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QGLPixelBuffer(QSize,QGLFormat,QGLWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // QGLPixelBuffer(QSize,QGLFormat,QGLWidget*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 0; // QGLPixelBuffer(QSize,QGLFormat,QGLWidget*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLPixelBuffer_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLPixelBuffer(const QSize & size, const QGLFormat & format, QGLWidget * shareWidget)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[1]))))
                        goto Sbk_QGLPixelBuffer_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "shareWidget");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer(): got multiple values for keyword argument 'shareWidget'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLWIDGET_IDX], (pyArgs[2]))))
                        goto Sbk_QGLPixelBuffer_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QGLFormat cppArg1_local = QGLFormat::defaultFormat();
            ::QGLFormat* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QGLWidget* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QGLPixelBuffer(QSize,QGLFormat,QGLWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLPixelBufferWrapper(*cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGLPixelBuffer(int width, int height, const QGLFormat & format, QGLWidget * shareWidget)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[2]))))
                        goto Sbk_QGLPixelBuffer_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "shareWidget");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer(): got multiple values for keyword argument 'shareWidget'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLWIDGET_IDX], (pyArgs[3]))))
                        goto Sbk_QGLPixelBuffer_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QGLFormat cppArg2_local = QGLFormat::defaultFormat();
            ::QGLFormat* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return -1;
            ::QGLWidget* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QGLPixelBuffer(int,int,QGLFormat,QGLWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLPixelBufferWrapper(cppArg0, cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLPixelBuffer >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLPixelBuffer_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLPixelBuffer_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, PySide.QtOpenGL.QGLFormat = QGLFormat.defaultFormat(), PySide.QtOpenGL.QGLWidget = None", "int, int, PySide.QtOpenGL.QGLFormat = QGLFormat.defaultFormat(), PySide.QtOpenGL.QGLWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLPixelBuffer", overloads);
        return -1;
}

static PyObject* Sbk_QGLPixelBufferFunc_bindTexture(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.bindTexture(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.bindTexture(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:bindTexture", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: bindTexture(QImage,GLenum)
    // 1: bindTexture(QPixmap,GLenum)
    // 2: bindTexture(QString)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 2; // bindTexture(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // bindTexture(QImage,GLenum)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))) {
            overloadId = 0; // bindTexture(QImage,GLenum)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // bindTexture(QPixmap,GLenum)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))) {
            overloadId = 1; // bindTexture(QPixmap,GLenum)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLPixelBufferFunc_bindTexture_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindTexture(const QImage & image, GLenum target)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.bindTexture(): got multiple values for keyword argument 'target'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1]))))
                        goto Sbk_QGLPixelBufferFunc_bindTexture_TypeError;
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

            if (!PyErr_Occurred()) {
                // bindTexture(QImage,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
        case 1: // bindTexture(const QPixmap & pixmap, GLenum target)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.bindTexture(): got multiple values for keyword argument 'target'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1]))))
                        goto Sbk_QGLPixelBufferFunc_bindTexture_TypeError;
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

            if (!PyErr_Occurred()) {
                // bindTexture(QPixmap,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                GLuint cppResult = cppSelf->bindTexture(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), &cppResult);
            }
            break;
        }
        case 2: // bindTexture(const QString & fileName)
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

    Sbk_QGLPixelBufferFunc_bindTexture_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, unsigned int = 0x0DE1", "PySide.QtGui.QPixmap, unsigned int = 0x0DE1", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLPixelBuffer.bindTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLPixelBufferFunc_bindToDynamicTexture(PyObject* self, PyObject* pyArg)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: bindToDynamicTexture(GLuint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArg)))) {
        overloadId = 0; // bindToDynamicTexture(GLuint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLPixelBufferFunc_bindToDynamicTexture_TypeError;

    // Call function/method
    {
        GLuint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // bindToDynamicTexture(GLuint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->bindToDynamicTexture(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLPixelBufferFunc_bindToDynamicTexture_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLPixelBuffer.bindToDynamicTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLPixelBufferFunc_deleteTexture(PyObject* self, PyObject* pyArg)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deleteTexture(GLuint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArg)))) {
        overloadId = 0; // deleteTexture(GLuint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLPixelBufferFunc_deleteTexture_TypeError;

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

    Sbk_QGLPixelBufferFunc_deleteTexture_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLPixelBuffer.deleteTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLPixelBufferFunc_devType(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLPixelBuffer*>(cppSelf)->::QGLPixelBuffer::devType() : const_cast<const ::QGLPixelBuffer*>(cppSelf)->devType();
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

static PyObject* Sbk_QGLPixelBufferFunc_doneCurrent(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doneCurrent()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->doneCurrent();
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

static PyObject* Sbk_QGLPixelBufferFunc_drawTexture(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.drawTexture(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.drawTexture(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QGLPixelBufferFunc_drawTexture_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawTexture(const QPointF & point, GLuint textureId, GLenum textureTarget)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "textureTarget");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.drawTexture(): got multiple values for keyword argument 'textureTarget'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLPixelBufferFunc_drawTexture_TypeError;
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
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLPixelBuffer.drawTexture(): got multiple values for keyword argument 'textureTarget'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLPixelBufferFunc_drawTexture_TypeError;
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

    Sbk_QGLPixelBufferFunc_drawTexture_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, unsigned int, unsigned int = 0x0DE1", "PySide.QtCore.QRectF, unsigned int, unsigned int = 0x0DE1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLPixelBuffer.drawTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLPixelBufferFunc_format(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFormat cppResult = const_cast<const ::QGLPixelBuffer*>(cppSelf)->format();
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

static PyObject* Sbk_QGLPixelBufferFunc_generateDynamicTexture(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // generateDynamicTexture()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLuint cppResult = const_cast<const ::QGLPixelBuffer*>(cppSelf)->generateDynamicTexture();
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

static PyObject* Sbk_QGLPixelBufferFunc_handle(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QGLPixelBuffer*>(cppSelf)->handle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLPixelBufferFunc_hasOpenGLPbuffers(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOpenGLPbuffers()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLPixelBuffer::hasOpenGLPbuffers();
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

static PyObject* Sbk_QGLPixelBufferFunc_isValid(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLPixelBuffer*>(cppSelf)->isValid();
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

static PyObject* Sbk_QGLPixelBufferFunc_makeCurrent(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // makeCurrent()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->makeCurrent();
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

static PyObject* Sbk_QGLPixelBufferFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: metric(QPaintDevice::PaintDeviceMetric)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), (pyArg)))) {
        overloadId = 0; // metric(QPaintDevice::PaintDeviceMetric)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLPixelBufferFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLPixelBuffer*>(cppSelf)->::QGLPixelBuffer::metric(cppArg0) : const_cast<const ::QGLPixelBuffer*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLPixelBufferFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLPixelBuffer.metric", overloads);
        return 0;
}

static PyObject* Sbk_QGLPixelBufferFunc_paintEngine(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLPixelBuffer*>(cppSelf)->::QGLPixelBuffer::paintEngine() : const_cast<const ::QGLPixelBuffer*>(cppSelf)->paintEngine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLPixelBufferFunc_releaseFromDynamicTexture(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // releaseFromDynamicTexture()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->releaseFromDynamicTexture();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLPixelBufferFunc_size(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QGLPixelBuffer*>(cppSelf)->size();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLPixelBufferFunc_toImage(PyObject* self)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toImage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QGLPixelBuffer*>(cppSelf)->toImage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLPixelBufferFunc_updateDynamicTexture(PyObject* self, PyObject* pyArg)
{
    ::QGLPixelBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLPixelBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updateDynamicTexture(GLuint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLuint>(), (pyArg)))) {
        overloadId = 0; // updateDynamicTexture(GLuint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLPixelBufferFunc_updateDynamicTexture_TypeError;

    // Call function/method
    {
        GLuint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // updateDynamicTexture(GLuint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QGLPixelBuffer*>(cppSelf)->updateDynamicTexture(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLPixelBufferFunc_updateDynamicTexture_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLPixelBuffer.updateDynamicTexture", overloads);
        return 0;
}

static PyMethodDef Sbk_QGLPixelBuffer_methods[] = {
    {"bindTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_bindTexture, METH_VARARGS|METH_KEYWORDS},
    {"bindToDynamicTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_bindToDynamicTexture, METH_O},
    {"deleteTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_deleteTexture, METH_O},
    {"devType", (PyCFunction)Sbk_QGLPixelBufferFunc_devType, METH_NOARGS},
    {"doneCurrent", (PyCFunction)Sbk_QGLPixelBufferFunc_doneCurrent, METH_NOARGS},
    {"drawTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_drawTexture, METH_VARARGS|METH_KEYWORDS},
    {"format", (PyCFunction)Sbk_QGLPixelBufferFunc_format, METH_NOARGS},
    {"generateDynamicTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_generateDynamicTexture, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QGLPixelBufferFunc_handle, METH_NOARGS},
    {"hasOpenGLPbuffers", (PyCFunction)Sbk_QGLPixelBufferFunc_hasOpenGLPbuffers, METH_NOARGS|METH_STATIC},
    {"isValid", (PyCFunction)Sbk_QGLPixelBufferFunc_isValid, METH_NOARGS},
    {"makeCurrent", (PyCFunction)Sbk_QGLPixelBufferFunc_makeCurrent, METH_NOARGS},
    {"metric", (PyCFunction)Sbk_QGLPixelBufferFunc_metric, METH_O},
    {"paintEngine", (PyCFunction)Sbk_QGLPixelBufferFunc_paintEngine, METH_NOARGS},
    {"releaseFromDynamicTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_releaseFromDynamicTexture, METH_NOARGS},
    {"size", (PyCFunction)Sbk_QGLPixelBufferFunc_size, METH_NOARGS},
    {"toImage", (PyCFunction)Sbk_QGLPixelBufferFunc_toImage, METH_NOARGS},
    {"updateDynamicTexture", (PyCFunction)Sbk_QGLPixelBufferFunc_updateDynamicTexture, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGLPixelBuffer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLPixelBuffer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLPixelBuffer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLPixelBuffer",
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
    /*tp_traverse*/         Sbk_QGLPixelBuffer_traverse,
    /*tp_clear*/            Sbk_QGLPixelBuffer_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLPixelBuffer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLPixelBuffer_Init,
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

static void* Sbk_QGLPixelBuffer_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QGLPixelBuffer*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLPixelBuffer_PythonToCpp_QGLPixelBuffer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLPixelBuffer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLPixelBuffer_PythonToCpp_QGLPixelBuffer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLPixelBuffer_Type))
        return QGLPixelBuffer_PythonToCpp_QGLPixelBuffer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLPixelBuffer_PTR_CppToPython_QGLPixelBuffer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLPixelBuffer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLPixelBuffer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGLPixelBuffer(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLPIXELBUFFER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLPixelBuffer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLPixelBuffer", "QGLPixelBuffer*",
        &Sbk_QGLPixelBuffer_Type, &Shiboken::callCppDestructor< ::QGLPixelBuffer >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLPixelBuffer_Type,
        QGLPixelBuffer_PythonToCpp_QGLPixelBuffer_PTR,
        is_QGLPixelBuffer_PythonToCpp_QGLPixelBuffer_PTR_Convertible,
        QGLPixelBuffer_PTR_CppToPython_QGLPixelBuffer);

    Shiboken::Conversions::registerConverterName(converter, "QGLPixelBuffer");
    Shiboken::Conversions::registerConverterName(converter, "QGLPixelBuffer*");
    Shiboken::Conversions::registerConverterName(converter, "QGLPixelBuffer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLPixelBuffer).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLPixelBufferWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGLPixelBuffer_Type, &Sbk_QGLPixelBuffer_typeDiscovery);


}
