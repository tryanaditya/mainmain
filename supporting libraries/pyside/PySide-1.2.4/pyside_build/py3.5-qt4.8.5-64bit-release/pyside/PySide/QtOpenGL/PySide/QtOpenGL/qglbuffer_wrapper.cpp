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

#include "qglbuffer_wrapper.h"

// Extra includes
#include <qglbuffer.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLBuffer_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLBuffer >()))
        return -1;

    ::QGLBuffer* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGLBuffer", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGLBuffer()
    // 1: QGLBuffer(QGLBuffer::Type)
    // 2: QGLBuffer(QGLBuffer)
    if (numArgs == 0) {
        overloadId = 0; // QGLBuffer()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (pyArgs[0])))) {
        overloadId = 2; // QGLBuffer(QGLBuffer)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 1; // QGLBuffer(QGLBuffer::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBuffer_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLBuffer()
        {

            if (!PyErr_Occurred()) {
                // QGLBuffer()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLBuffer();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGLBuffer(QGLBuffer::Type type)
        {
            ::QGLBuffer::Type cppArg0 = ((::QGLBuffer::Type)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QGLBuffer(QGLBuffer::Type)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLBuffer(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QGLBuffer(const QGLBuffer & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGLBuffer* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QGLBuffer(QGLBuffer)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLBuffer(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLBuffer >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLBuffer_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLBuffer_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtOpenGL.QGLBuffer.Type", "PySide.QtOpenGL.QGLBuffer", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLBuffer", overloads);
        return -1;
}

static PyObject* Sbk_QGLBufferFunc_allocate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLBuffer.allocate(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLBuffer.allocate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:allocate", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: allocate(const void*,int)
    // 1: allocate(int)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // allocate(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // allocate(const void*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // allocate(const void*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBufferFunc_allocate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // allocate(const void * data, int count)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "count");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLBuffer.allocate(): got multiple values for keyword argument 'count'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QGLBufferFunc_allocate_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1 = -1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // allocate(const void*,int)
                // Begin code injection

                int size = (cppArg1 < 0) ? cppArg0->size() : cppArg1;
                cppSelf->allocate((const void*) cppArg0->data(), size);

                // End of code injection


            }
            break;
        }
        case 1: // allocate(int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // allocate(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->allocate(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLBufferFunc_allocate_TypeError:
        const char* overloads[] = {"void, int = -1", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLBuffer.allocate", overloads);
        return 0;
}

static PyObject* Sbk_QGLBufferFunc_bind(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QGLBufferFunc_bufferId(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bufferId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLuint cppResult = const_cast<const ::QGLBuffer*>(cppSelf)->bufferId();
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

static PyObject* Sbk_QGLBufferFunc_create(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // create()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->create();
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

static PyObject* Sbk_QGLBufferFunc_destroy(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // destroy()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->destroy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGLBufferFunc_isCreated(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCreated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLBuffer*>(cppSelf)->isCreated();
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

static PyObject* Sbk_QGLBufferFunc_map(PyObject* self, PyObject* pyArg)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: map(QGLBuffer::Access)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX]), (pyArg)))) {
        overloadId = 0; // map(QGLBuffer::Access)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBufferFunc_map_TypeError;

    // Call function/method
    {
        ::QGLBuffer::Access cppArg0 = ((::QGLBuffer::Access)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // map(QGLBuffer::Access)
            // Begin code injection

            Py_ssize_t dataSize = cppSelf->size();
            void* data = cppSelf->map(cppArg0);

            if (!data) {
                Py_INCREF(Py_None);
                pyResult = Py_None;
            } else if (cppArg0 == QGLBuffer::ReadOnly) {
                pyResult = Shiboken::Buffer::newObject(data, dataSize, Shiboken::Buffer::ReadOnly);
            } else {
                pyResult = Shiboken::Buffer::newObject(data, dataSize, Shiboken::Buffer::ReadWrite);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLBufferFunc_map_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLBuffer.Access", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLBuffer.map", overloads);
        return 0;
}

static PyObject* Sbk_QGLBufferFunc_read(PyObject* self, PyObject* args)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "read", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: read(int,void*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // read(int,void*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBufferFunc_read_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // read(int,void*,int)
            // Begin code injection

            char *data = new char[cppArg1];
            bool result = cppSelf->read(cppArg0, data, cppArg1);
            QByteArray ret;
            if (result)
                ret.append((const char*)data, cppArg1);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &result));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ret));
            delete[] data;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLBufferFunc_read_TypeError:
        const char* overloads[] = {"int, void, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLBuffer.read", overloads);
        return 0;
}

static PyObject* Sbk_QGLBufferFunc_release(PyObject* self, PyObject* args)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    }
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "release", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: release()
    // 1: release(QGLBuffer::Type)
    if (numArgs == 0) {
        overloadId = 0; // release()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 1; // release(QGLBuffer::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBufferFunc_release_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // release()
        {

            if (!PyErr_Occurred()) {
                // release()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->release();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // release(QGLBuffer::Type type)
        {
            ::QGLBuffer::Type cppArg0 = ((::QGLBuffer::Type)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // release(QGLBuffer::Type)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QGLBuffer::release(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLBufferFunc_release_TypeError:
        const char* overloads[] = {"", "PySide.QtOpenGL.QGLBuffer.Type", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLBuffer.release", overloads);
        return 0;
}

static PyObject* Sbk_QGLBufferFunc_setUsagePattern(PyObject* self, PyObject* pyArg)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUsagePattern(QGLBuffer::UsagePattern)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX]), (pyArg)))) {
        overloadId = 0; // setUsagePattern(QGLBuffer::UsagePattern)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBufferFunc_setUsagePattern_TypeError;

    // Call function/method
    {
        ::QGLBuffer::UsagePattern cppArg0 = ((::QGLBuffer::UsagePattern)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUsagePattern(QGLBuffer::UsagePattern)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUsagePattern(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLBufferFunc_setUsagePattern_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLBuffer.UsagePattern", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLBuffer.setUsagePattern", overloads);
        return 0;
}

static PyObject* Sbk_QGLBufferFunc_size(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLBuffer*>(cppSelf)->size();
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

static PyObject* Sbk_QGLBufferFunc_type(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLBuffer::Type cppResult = const_cast<const ::QGLBuffer*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLBufferFunc_unmap(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unmap()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->unmap();
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

static PyObject* Sbk_QGLBufferFunc_usagePattern(PyObject* self)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // usagePattern()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLBuffer::UsagePattern cppResult = const_cast<const ::QGLBuffer*>(cppSelf)->usagePattern();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLBufferFunc_write(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGLBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLBuffer.write(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLBuffer.write(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:write", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: write(int,const void*,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // write(int,const void*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // write(int,const void*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLBufferFunc_write_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "count");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLBuffer.write(): got multiple values for keyword argument 'count'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QGLBufferFunc_write_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QByteArray cppArg1_local = ::QByteArray();
        ::QByteArray* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2 = -1;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // write(int,const void*,int)
            // Begin code injection

            int size = (cppArg2 < 0) ? cppArg1->size() : cppArg2;
            cppSelf->write(cppArg0, (const void*) cppArg1->data(), size);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLBufferFunc_write_TypeError:
        const char* overloads[] = {"int, void, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLBuffer.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QGLBufferMethod_release = {
    "release", (PyCFunction)Sbk_QGLBufferFunc_release, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QGLBuffer_methods[] = {
    {"allocate", (PyCFunction)Sbk_QGLBufferFunc_allocate, METH_VARARGS|METH_KEYWORDS},
    {"bind", (PyCFunction)Sbk_QGLBufferFunc_bind, METH_NOARGS},
    {"bufferId", (PyCFunction)Sbk_QGLBufferFunc_bufferId, METH_NOARGS},
    {"create", (PyCFunction)Sbk_QGLBufferFunc_create, METH_NOARGS},
    {"destroy", (PyCFunction)Sbk_QGLBufferFunc_destroy, METH_NOARGS},
    {"isCreated", (PyCFunction)Sbk_QGLBufferFunc_isCreated, METH_NOARGS},
    {"map", (PyCFunction)Sbk_QGLBufferFunc_map, METH_O},
    {"read", (PyCFunction)Sbk_QGLBufferFunc_read, METH_VARARGS},
    Sbk_QGLBufferMethod_release,
    {"setUsagePattern", (PyCFunction)Sbk_QGLBufferFunc_setUsagePattern, METH_O},
    {"size", (PyCFunction)Sbk_QGLBufferFunc_size, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QGLBufferFunc_type, METH_NOARGS},
    {"unmap", (PyCFunction)Sbk_QGLBufferFunc_unmap, METH_NOARGS},
    {"usagePattern", (PyCFunction)Sbk_QGLBufferFunc_usagePattern, METH_NOARGS},
    {"write", (PyCFunction)Sbk_QGLBufferFunc_write, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

static PyObject* Sbk_QGLBuffer_getattro(PyObject* self, PyObject* name)
{
    if (self) {
        // Search the method in the instance dict
        if (reinterpret_cast<SbkObject*>(self)->ob_dict) {
            PyObject* meth = PyDict_GetItem(reinterpret_cast<SbkObject*>(self)->ob_dict, name);
            if (meth) {
                Py_INCREF(meth);
                return meth;
            }
        }
        // Search the method in the type dict
        if (Shiboken::Object::isUserType(self)) {
            PyObject* meth = PyDict_GetItem(self->ob_type->tp_dict, name);
            if (meth)
                return PyFunction_Check(meth) ? SBK_PyMethod_New(meth, self) : PyObject_GenericGetAttr(self, name);
        }
        static PyMethodDef non_static_Sbk_QGLBufferMethod_release = {
            Sbk_QGLBufferMethod_release.ml_name,
            Sbk_QGLBufferMethod_release.ml_meth,
            Sbk_QGLBufferMethod_release.ml_flags & (~METH_STATIC),
            Sbk_QGLBufferMethod_release.ml_doc,
        };
        if (Shiboken::String::compare(name, "release") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QGLBufferMethod_release, self, 0);
    }
    return PyObject_GenericGetAttr(self, name);
}

} // extern "C"

static int Sbk_QGLBuffer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLBuffer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLBuffer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLBuffer",
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
    /*tp_getattro*/         Sbk_QGLBuffer_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QGLBuffer_traverse,
    /*tp_clear*/            Sbk_QGLBuffer_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLBuffer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLBuffer_Init,
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


// Type conversion functions.

// Python to C++ enum conversion.
static void QGLBuffer_Type_PythonToCpp_QGLBuffer_Type(PyObject* pyIn, void* cppOut) {
    *((::QGLBuffer::Type*)cppOut) = (::QGLBuffer::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLBuffer_Type_PythonToCpp_QGLBuffer_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX]))
        return QGLBuffer_Type_PythonToCpp_QGLBuffer_Type;
    return 0;
}
static PyObject* QGLBuffer_Type_CppToPython_QGLBuffer_Type(const void* cppIn) {
    int castCppIn = *((::QGLBuffer::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX], castCppIn);

}

static void QGLBuffer_UsagePattern_PythonToCpp_QGLBuffer_UsagePattern(PyObject* pyIn, void* cppOut) {
    *((::QGLBuffer::UsagePattern*)cppOut) = (::QGLBuffer::UsagePattern) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLBuffer_UsagePattern_PythonToCpp_QGLBuffer_UsagePattern_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX]))
        return QGLBuffer_UsagePattern_PythonToCpp_QGLBuffer_UsagePattern;
    return 0;
}
static PyObject* QGLBuffer_UsagePattern_CppToPython_QGLBuffer_UsagePattern(const void* cppIn) {
    int castCppIn = *((::QGLBuffer::UsagePattern*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX], castCppIn);

}

static void QGLBuffer_Access_PythonToCpp_QGLBuffer_Access(PyObject* pyIn, void* cppOut) {
    *((::QGLBuffer::Access*)cppOut) = (::QGLBuffer::Access) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLBuffer_Access_PythonToCpp_QGLBuffer_Access_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX]))
        return QGLBuffer_Access_PythonToCpp_QGLBuffer_Access;
    return 0;
}
static PyObject* QGLBuffer_Access_CppToPython_QGLBuffer_Access(const void* cppIn) {
    int castCppIn = *((::QGLBuffer::Access*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLBuffer_PythonToCpp_QGLBuffer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLBuffer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLBuffer_PythonToCpp_QGLBuffer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLBuffer_Type))
        return QGLBuffer_PythonToCpp_QGLBuffer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLBuffer_PTR_CppToPython_QGLBuffer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLBuffer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLBuffer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGLBuffer(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLBuffer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLBuffer", "QGLBuffer*",
        &Sbk_QGLBuffer_Type, &Shiboken::callCppDestructor< ::QGLBuffer >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLBuffer_Type,
        QGLBuffer_PythonToCpp_QGLBuffer_PTR,
        is_QGLBuffer_PythonToCpp_QGLBuffer_PTR_Convertible,
        QGLBuffer_PTR_CppToPython_QGLBuffer);

    Shiboken::Conversions::registerConverterName(converter, "QGLBuffer");
    Shiboken::Conversions::registerConverterName(converter, "QGLBuffer*");
    Shiboken::Conversions::registerConverterName(converter, "QGLBuffer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLBuffer).name());


    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLBuffer_Type,
        "Type",
        "PySide.QtOpenGL.QGLBuffer.Type",
        "QGLBuffer::Type");
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX],
        &Sbk_QGLBuffer_Type, "VertexBuffer", (long) QGLBuffer::VertexBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX],
        &Sbk_QGLBuffer_Type, "IndexBuffer", (long) QGLBuffer::IndexBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX],
        &Sbk_QGLBuffer_Type, "PixelPackBuffer", (long) QGLBuffer::PixelPackBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX],
        &Sbk_QGLBuffer_Type, "PixelUnpackBuffer", (long) QGLBuffer::PixelUnpackBuffer))
        return ;
    // Register converter for enum 'QGLBuffer::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX],
            QGLBuffer_Type_CppToPython_QGLBuffer_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLBuffer_Type_PythonToCpp_QGLBuffer_Type,
            is_QGLBuffer_Type_PythonToCpp_QGLBuffer_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLBuffer::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.

    // Initialization of enum 'UsagePattern'.
    SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLBuffer_Type,
        "UsagePattern",
        "PySide.QtOpenGL.QGLBuffer.UsagePattern",
        "QGLBuffer::UsagePattern");
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "StreamDraw", (long) QGLBuffer::StreamDraw))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "StreamRead", (long) QGLBuffer::StreamRead))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "StreamCopy", (long) QGLBuffer::StreamCopy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "StaticDraw", (long) QGLBuffer::StaticDraw))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "StaticRead", (long) QGLBuffer::StaticRead))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "StaticCopy", (long) QGLBuffer::StaticCopy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "DynamicDraw", (long) QGLBuffer::DynamicDraw))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "DynamicRead", (long) QGLBuffer::DynamicRead))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
        &Sbk_QGLBuffer_Type, "DynamicCopy", (long) QGLBuffer::DynamicCopy))
        return ;
    // Register converter for enum 'QGLBuffer::UsagePattern'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX],
            QGLBuffer_UsagePattern_CppToPython_QGLBuffer_UsagePattern);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLBuffer_UsagePattern_PythonToCpp_QGLBuffer_UsagePattern,
            is_QGLBuffer_UsagePattern_PythonToCpp_QGLBuffer_UsagePattern_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_USAGEPATTERN_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLBuffer::UsagePattern");
        Shiboken::Conversions::registerConverterName(converter, "UsagePattern");
    }
    // End of 'UsagePattern' enum.

    // Initialization of enum 'Access'.
    SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLBuffer_Type,
        "Access",
        "PySide.QtOpenGL.QGLBuffer.Access",
        "QGLBuffer::Access");
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX],
        &Sbk_QGLBuffer_Type, "ReadOnly", (long) QGLBuffer::ReadOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX],
        &Sbk_QGLBuffer_Type, "WriteOnly", (long) QGLBuffer::WriteOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX],
        &Sbk_QGLBuffer_Type, "ReadWrite", (long) QGLBuffer::ReadWrite))
        return ;
    // Register converter for enum 'QGLBuffer::Access'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX],
            QGLBuffer_Access_CppToPython_QGLBuffer_Access);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLBuffer_Access_PythonToCpp_QGLBuffer_Access,
            is_QGLBuffer_Access_PythonToCpp_QGLBuffer_Access_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLBUFFER_ACCESS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLBuffer::Access");
        Shiboken::Conversions::registerConverterName(converter, "Access");
    }
    // End of 'Access' enum.


    qRegisterMetaType< ::QGLBuffer::Type >("QGLBuffer::Type");
    qRegisterMetaType< ::QGLBuffer::UsagePattern >("QGLBuffer::UsagePattern");
    qRegisterMetaType< ::QGLBuffer::Access >("QGLBuffer::Access");
}
