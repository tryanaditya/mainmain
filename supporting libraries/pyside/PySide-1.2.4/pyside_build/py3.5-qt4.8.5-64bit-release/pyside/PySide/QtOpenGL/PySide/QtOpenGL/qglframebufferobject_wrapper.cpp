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

#include "qglframebufferobject_wrapper.h"

// Extra includes
#include <qglframebufferobject.h>
#include <qimage.h>
#include <qpaintengine.h>
#include <qpoint.h>
#include <qrect.h>
#include <qsize.h>


// Native ---------------------------------------------------------

QGLFramebufferObjectWrapper::QGLFramebufferObjectWrapper(const QSize & size, GLenum target) : QGLFramebufferObject(size, target) {
    // ... middle
}

QGLFramebufferObjectWrapper::QGLFramebufferObjectWrapper(const QSize & size, QGLFramebufferObject::Attachment attachment, GLenum target, GLenum internal_format) : QGLFramebufferObject(size, attachment, target, internal_format) {
    // ... middle
}

QGLFramebufferObjectWrapper::QGLFramebufferObjectWrapper(const QSize & size, const QGLFramebufferObjectFormat & format) : QGLFramebufferObject(size, format) {
    // ... middle
}

QGLFramebufferObjectWrapper::QGLFramebufferObjectWrapper(int width, int height, GLenum target) : QGLFramebufferObject(width, height, target) {
    // ... middle
}

QGLFramebufferObjectWrapper::QGLFramebufferObjectWrapper(int width, int height, QGLFramebufferObject::Attachment attachment, GLenum target, GLenum internal_format) : QGLFramebufferObject(width, height, attachment, target, internal_format) {
    // ... middle
}

QGLFramebufferObjectWrapper::QGLFramebufferObjectWrapper(int width, int height, const QGLFramebufferObjectFormat & format) : QGLFramebufferObject(width, height, format) {
    // ... middle
}

int QGLFramebufferObjectWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLFramebufferObject::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLFramebufferObject.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QGLFramebufferObjectWrapper::metric(QPaintDevice::PaintDeviceMetric metric) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLFramebufferObject::metric(metric);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLFramebufferObject.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QGLFramebufferObjectWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGLFramebufferObject::paintEngine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGLFramebufferObject.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QGLFramebufferObjectWrapper::~QGLFramebufferObjectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLFramebufferObject_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLFramebufferObject >()))
        return -1;

    ::QGLFramebufferObjectWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QGLFramebufferObject", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QGLFramebufferObject(QSize,GLenum)
    // 1: QGLFramebufferObject(QSize,QGLFramebufferObject::Attachment,GLenum,GLenum)
    // 2: QGLFramebufferObject(QSize,QGLFramebufferObjectFormat)
    // 3: QGLFramebufferObject(int,int,GLenum)
    // 4: QGLFramebufferObject(int,int,QGLFramebufferObject::Attachment,GLenum,GLenum)
    // 5: QGLFramebufferObject(int,int,QGLFramebufferObjectFormat)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 3; // QGLFramebufferObject(int,int,GLenum)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (pyArgs[2])))) {
            overloadId = 5; // QGLFramebufferObject(int,int,QGLFramebufferObjectFormat)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 4; // QGLFramebufferObject(int,int,QGLFramebufferObject::Attachment,GLenum,GLenum)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 4; // QGLFramebufferObject(int,int,QGLFramebufferObject::Attachment,GLenum,GLenum)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[4])))) {
                    overloadId = 4; // QGLFramebufferObject(int,int,QGLFramebufferObject::Attachment,GLenum,GLenum)
                }
            }
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2])))) {
            overloadId = 3; // QGLFramebufferObject(int,int,GLenum)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QGLFramebufferObject(QSize,GLenum)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (pyArgs[1])))) {
            overloadId = 2; // QGLFramebufferObject(QSize,QGLFramebufferObjectFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QGLFramebufferObject(QSize,QGLFramebufferObject::Attachment,GLenum,GLenum)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // QGLFramebufferObject(QSize,QGLFramebufferObject::Attachment,GLenum,GLenum)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[3])))) {
                    overloadId = 1; // QGLFramebufferObject(QSize,QGLFramebufferObject::Attachment,GLenum,GLenum)
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1])))) {
            overloadId = 0; // QGLFramebufferObject(QSize,GLenum)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObject_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLFramebufferObject(const QSize & size, GLenum target)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): got multiple values for keyword argument 'target'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[1]))))
                        goto Sbk_QGLFramebufferObject_Init_TypeError;
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

            GLenum cppArg1 = 0x0DE1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGLFramebufferObject(QSize,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectWrapper(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGLFramebufferObject(const QSize & size, QGLFramebufferObject::Attachment attachment, GLenum target, GLenum internal_format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): got multiple values for keyword argument 'target'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLFramebufferObject_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "internal_format");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): got multiple values for keyword argument 'internal_format'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[3]))))
                        goto Sbk_QGLFramebufferObject_Init_TypeError;
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

            ::QGLFramebufferObject::Attachment cppArg1 = ((::QGLFramebufferObject::Attachment)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLenum cppArg2 = 0x0DE1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            GLenum cppArg3 = 0x8058;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QGLFramebufferObject(QSize,QGLFramebufferObject::Attachment,GLenum,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectWrapper(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QGLFramebufferObject(const QSize & size, const QGLFramebufferObjectFormat & format)
        {
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
            ::QGLFramebufferObjectFormat cppArg1_local = ::QGLFramebufferObjectFormat();
            ::QGLFramebufferObjectFormat* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QGLFramebufferObject(QSize,QGLFramebufferObjectFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectWrapper(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QGLFramebufferObject(int width, int height, GLenum target)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): got multiple values for keyword argument 'target'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLFramebufferObject_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            GLenum cppArg2 = 0x0DE1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QGLFramebufferObject(int,int,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QGLFramebufferObject(int width, int height, QGLFramebufferObject::Attachment attachment, GLenum target, GLenum internal_format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "target");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): got multiple values for keyword argument 'target'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[3]))))
                        goto Sbk_QGLFramebufferObject_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "internal_format");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject(): got multiple values for keyword argument 'internal_format'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[4]))))
                        goto Sbk_QGLFramebufferObject_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QGLFramebufferObject::Attachment cppArg2 = ((::QGLFramebufferObject::Attachment)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            GLenum cppArg3 = 0x0DE1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            GLenum cppArg4 = 0x8058;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QGLFramebufferObject(int,int,QGLFramebufferObject::Attachment,GLenum,GLenum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QGLFramebufferObject(int width, int height, const QGLFramebufferObjectFormat & format)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QGLFramebufferObjectFormat cppArg2_local = ::QGLFramebufferObjectFormat();
            ::QGLFramebufferObjectFormat* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // QGLFramebufferObject(int,int,QGLFramebufferObjectFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectWrapper(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLFramebufferObject >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLFramebufferObject_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLFramebufferObject_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, unsigned int = 0x0DE1", "PySide.QtCore.QSize, PySide.QtOpenGL.QGLFramebufferObject.Attachment, unsigned int = 0x0DE1, unsigned int = 0x8058", "PySide.QtCore.QSize, PySide.QtOpenGL.QGLFramebufferObjectFormat", "int, int, unsigned int = 0x0DE1", "int, int, PySide.QtOpenGL.QGLFramebufferObject.Attachment, unsigned int = 0x0DE1, unsigned int = 0x8058", "int, int, PySide.QtOpenGL.QGLFramebufferObjectFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLFramebufferObject", overloads);
        return -1;
}

static PyObject* Sbk_QGLFramebufferObjectFunc_attachment(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attachment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFramebufferObject::Attachment cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->attachment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLFramebufferObjectFunc_bind(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QGLFramebufferObjectFunc_bindDefault(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bindDefault()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLFramebufferObject::bindDefault();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_blitFramebuffer(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.blitFramebuffer(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.blitFramebuffer(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:blitFramebuffer", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: blitFramebuffer(QGLFramebufferObject*,QRect,QGLFramebufferObject*,QRect,GLbitfield,GLenum)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // blitFramebuffer(QGLFramebufferObject*,QRect,QGLFramebufferObject*,QRect,GLbitfield,GLenum)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLbitfield>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 0; // blitFramebuffer(QGLFramebufferObject*,QRect,QGLFramebufferObject*,QRect,GLbitfield,GLenum)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[5])))) {
                overloadId = 0; // blitFramebuffer(QGLFramebufferObject*,QRect,QGLFramebufferObject*,QRect,GLbitfield,GLenum)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFunc_blitFramebuffer_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "buffers");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.blitFramebuffer(): got multiple values for keyword argument 'buffers'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLbitfield>(), (pyArgs[4]))))
                    goto Sbk_QGLFramebufferObjectFunc_blitFramebuffer_TypeError;
            }
            value = PyDict_GetItemString(kwds, "filter");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.blitFramebuffer(): got multiple values for keyword argument 'filter'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[5]))))
                    goto Sbk_QGLFramebufferObjectFunc_blitFramebuffer_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGLFramebufferObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRect cppArg1_local = ::QRect();
        ::QRect* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QGLFramebufferObject* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QRect cppArg3_local = ::QRect();
        ::QRect* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);

        GLbitfield cppArg4 = 0x00004000;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        GLenum cppArg5 = 0x2600;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // blitFramebuffer(QGLFramebufferObject*,QRect,QGLFramebufferObject*,QRect,GLbitfield,GLenum)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGLFramebufferObject::blitFramebuffer(cppArg0, *cppArg1, cppArg2, *cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFramebufferObjectFunc_blitFramebuffer_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFramebufferObject, PySide.QtCore.QRect, PySide.QtOpenGL.QGLFramebufferObject, PySide.QtCore.QRect, unsigned int = 0x00004000, unsigned int = 0x2600", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLFramebufferObject.blitFramebuffer", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFunc_devType(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLFramebufferObject*>(cppSelf)->::QGLFramebufferObject::devType() : const_cast<const ::QGLFramebufferObject*>(cppSelf)->devType();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_drawTexture(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.drawTexture(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.drawTexture(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFunc_drawTexture_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawTexture(const QPointF & point, GLuint textureId, GLenum textureTarget)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "textureTarget");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.drawTexture(): got multiple values for keyword argument 'textureTarget'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLFramebufferObjectFunc_drawTexture_TypeError;
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
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFramebufferObject.drawTexture(): got multiple values for keyword argument 'textureTarget'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArgs[2]))))
                        goto Sbk_QGLFramebufferObjectFunc_drawTexture_TypeError;
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

    Sbk_QGLFramebufferObjectFunc_drawTexture_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, unsigned int, unsigned int = 0x0DE1", "PySide.QtCore.QRectF, unsigned int, unsigned int = 0x0DE1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLFramebufferObject.drawTexture", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFunc_format(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFramebufferObjectFormat cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLFramebufferObjectFunc_handle(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLuint cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->handle();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_hasOpenGLFramebufferBlit(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOpenGLFramebufferBlit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLFramebufferObject::hasOpenGLFramebufferBlit();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_hasOpenGLFramebufferObjects(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOpenGLFramebufferObjects()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLFramebufferObject::hasOpenGLFramebufferObjects();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_isBound(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isBound()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->isBound();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_isValid(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->isValid();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLFramebufferObject*>(cppSelf)->::QGLFramebufferObject::metric(cppArg0) : const_cast<const ::QGLFramebufferObject*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLFramebufferObjectFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFramebufferObject.metric", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFunc_paintEngine(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGLFramebufferObject*>(cppSelf)->::QGLFramebufferObject::paintEngine() : const_cast<const ::QGLFramebufferObject*>(cppSelf)->paintEngine();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_release(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // release()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->release();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_size(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->size();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_texture(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // texture()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLuint cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->texture();
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

static PyObject* Sbk_QGLFramebufferObjectFunc_toImage(PyObject* self)
{
    ::QGLFramebufferObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toImage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QGLFramebufferObject*>(cppSelf)->toImage();
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

static PyMethodDef Sbk_QGLFramebufferObject_methods[] = {
    {"attachment", (PyCFunction)Sbk_QGLFramebufferObjectFunc_attachment, METH_NOARGS},
    {"bind", (PyCFunction)Sbk_QGLFramebufferObjectFunc_bind, METH_NOARGS},
    {"bindDefault", (PyCFunction)Sbk_QGLFramebufferObjectFunc_bindDefault, METH_NOARGS|METH_STATIC},
    {"blitFramebuffer", (PyCFunction)Sbk_QGLFramebufferObjectFunc_blitFramebuffer, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"devType", (PyCFunction)Sbk_QGLFramebufferObjectFunc_devType, METH_NOARGS},
    {"drawTexture", (PyCFunction)Sbk_QGLFramebufferObjectFunc_drawTexture, METH_VARARGS|METH_KEYWORDS},
    {"format", (PyCFunction)Sbk_QGLFramebufferObjectFunc_format, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QGLFramebufferObjectFunc_handle, METH_NOARGS},
    {"hasOpenGLFramebufferBlit", (PyCFunction)Sbk_QGLFramebufferObjectFunc_hasOpenGLFramebufferBlit, METH_NOARGS|METH_STATIC},
    {"hasOpenGLFramebufferObjects", (PyCFunction)Sbk_QGLFramebufferObjectFunc_hasOpenGLFramebufferObjects, METH_NOARGS|METH_STATIC},
    {"isBound", (PyCFunction)Sbk_QGLFramebufferObjectFunc_isBound, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QGLFramebufferObjectFunc_isValid, METH_NOARGS},
    {"metric", (PyCFunction)Sbk_QGLFramebufferObjectFunc_metric, METH_O},
    {"paintEngine", (PyCFunction)Sbk_QGLFramebufferObjectFunc_paintEngine, METH_NOARGS},
    {"release", (PyCFunction)Sbk_QGLFramebufferObjectFunc_release, METH_NOARGS},
    {"size", (PyCFunction)Sbk_QGLFramebufferObjectFunc_size, METH_NOARGS},
    {"texture", (PyCFunction)Sbk_QGLFramebufferObjectFunc_texture, METH_NOARGS},
    {"toImage", (PyCFunction)Sbk_QGLFramebufferObjectFunc_toImage, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGLFramebufferObject_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLFramebufferObject_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLFramebufferObject_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLFramebufferObject",
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
    /*tp_traverse*/         Sbk_QGLFramebufferObject_traverse,
    /*tp_clear*/            Sbk_QGLFramebufferObject_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLFramebufferObject_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLFramebufferObject_Init,
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

static void* Sbk_QGLFramebufferObject_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QGLFramebufferObject*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QGLFramebufferObject_Attachment_PythonToCpp_QGLFramebufferObject_Attachment(PyObject* pyIn, void* cppOut) {
    *((::QGLFramebufferObject::Attachment*)cppOut) = (::QGLFramebufferObject::Attachment) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLFramebufferObject_Attachment_PythonToCpp_QGLFramebufferObject_Attachment_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX]))
        return QGLFramebufferObject_Attachment_PythonToCpp_QGLFramebufferObject_Attachment;
    return 0;
}
static PyObject* QGLFramebufferObject_Attachment_CppToPython_QGLFramebufferObject_Attachment(const void* cppIn) {
    int castCppIn = *((::QGLFramebufferObject::Attachment*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLFramebufferObject_PythonToCpp_QGLFramebufferObject_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLFramebufferObject_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLFramebufferObject_PythonToCpp_QGLFramebufferObject_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLFramebufferObject_Type))
        return QGLFramebufferObject_PythonToCpp_QGLFramebufferObject_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLFramebufferObject_PTR_CppToPython_QGLFramebufferObject(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLFramebufferObject*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLFramebufferObject_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGLFramebufferObject(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLFramebufferObject_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLFramebufferObject", "QGLFramebufferObject*",
        &Sbk_QGLFramebufferObject_Type, &Shiboken::callCppDestructor< ::QGLFramebufferObject >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLFramebufferObject_Type,
        QGLFramebufferObject_PythonToCpp_QGLFramebufferObject_PTR,
        is_QGLFramebufferObject_PythonToCpp_QGLFramebufferObject_PTR_Convertible,
        QGLFramebufferObject_PTR_CppToPython_QGLFramebufferObject);

    Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObject");
    Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObject*");
    Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObject&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLFramebufferObject).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLFramebufferObjectWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGLFramebufferObject_Type, &Sbk_QGLFramebufferObject_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Attachment'.
    SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLFramebufferObject_Type,
        "Attachment",
        "PySide.QtOpenGL.QGLFramebufferObject.Attachment",
        "QGLFramebufferObject::Attachment");
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX],
        &Sbk_QGLFramebufferObject_Type, "NoAttachment", (long) QGLFramebufferObject::NoAttachment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX],
        &Sbk_QGLFramebufferObject_Type, "CombinedDepthStencil", (long) QGLFramebufferObject::CombinedDepthStencil))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX],
        &Sbk_QGLFramebufferObject_Type, "Depth", (long) QGLFramebufferObject::Depth))
        return ;
    // Register converter for enum 'QGLFramebufferObject::Attachment'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX],
            QGLFramebufferObject_Attachment_CppToPython_QGLFramebufferObject_Attachment);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLFramebufferObject_Attachment_PythonToCpp_QGLFramebufferObject_Attachment,
            is_QGLFramebufferObject_Attachment_PythonToCpp_QGLFramebufferObject_Attachment_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObject::Attachment");
        Shiboken::Conversions::registerConverterName(converter, "Attachment");
    }
    // End of 'Attachment' enum.


    qRegisterMetaType< ::QGLFramebufferObject::Attachment >("QGLFramebufferObject::Attachment");
}
