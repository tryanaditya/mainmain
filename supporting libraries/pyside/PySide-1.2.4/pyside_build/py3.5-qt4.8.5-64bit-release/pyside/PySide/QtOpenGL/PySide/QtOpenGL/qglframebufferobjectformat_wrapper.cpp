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

#include "qglframebufferobjectformat_wrapper.h"

// Extra includes
#include <qglframebufferobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLFramebufferObjectFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLFramebufferObjectFormat >()))
        return -1;

    ::QGLFramebufferObjectFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGLFramebufferObjectFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGLFramebufferObjectFormat()
    // 1: QGLFramebufferObjectFormat(QGLFramebufferObjectFormat)
    if (numArgs == 0) {
        overloadId = 0; // QGLFramebufferObjectFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QGLFramebufferObjectFormat(QGLFramebufferObjectFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLFramebufferObjectFormat()
        {

            if (!PyErr_Occurred()) {
                // QGLFramebufferObjectFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGLFramebufferObjectFormat(const QGLFramebufferObjectFormat & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGLFramebufferObjectFormat cppArg0_local = ::QGLFramebufferObjectFormat();
            ::QGLFramebufferObjectFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QGLFramebufferObjectFormat(QGLFramebufferObjectFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFramebufferObjectFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLFramebufferObjectFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLFramebufferObjectFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLFramebufferObjectFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtOpenGL.QGLFramebufferObjectFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLFramebufferObjectFormat", overloads);
        return -1;
}

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_attachment(PyObject* self)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attachment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFramebufferObject::Attachment cppResult = const_cast<const ::QGLFramebufferObjectFormat*>(cppSelf)->attachment();
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

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_internalTextureFormat(PyObject* self)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // internalTextureFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLenum cppResult = const_cast<const ::QGLFramebufferObjectFormat*>(cppSelf)->internalTextureFormat();
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

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_mipmap(PyObject* self)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mipmap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFramebufferObjectFormat*>(cppSelf)->mipmap();
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

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_samples(PyObject* self)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // samples()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFramebufferObjectFormat*>(cppSelf)->samples();
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

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_setAttachment(PyObject* self, PyObject* pyArg)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAttachment(QGLFramebufferObject::Attachment)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX]), (pyArg)))) {
        overloadId = 0; // setAttachment(QGLFramebufferObject::Attachment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFormatFunc_setAttachment_TypeError;

    // Call function/method
    {
        ::QGLFramebufferObject::Attachment cppArg0 = ((::QGLFramebufferObject::Attachment)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAttachment(QGLFramebufferObject::Attachment)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttachment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFramebufferObjectFormatFunc_setAttachment_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFramebufferObject.Attachment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFramebufferObjectFormat.setAttachment", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_setInternalTextureFormat(PyObject* self, PyObject* pyArg)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInternalTextureFormat(GLenum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArg)))) {
        overloadId = 0; // setInternalTextureFormat(GLenum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFormatFunc_setInternalTextureFormat_TypeError;

    // Call function/method
    {
        GLenum cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInternalTextureFormat(GLenum)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInternalTextureFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFramebufferObjectFormatFunc_setInternalTextureFormat_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFramebufferObjectFormat.setInternalTextureFormat", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_setMipmap(PyObject* self, PyObject* pyArg)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMipmap(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setMipmap(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFormatFunc_setMipmap_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMipmap(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMipmap(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFramebufferObjectFormatFunc_setMipmap_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFramebufferObjectFormat.setMipmap", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_setSamples(PyObject* self, PyObject* pyArg)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSamples(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSamples(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFormatFunc_setSamples_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSamples(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSamples(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFramebufferObjectFormatFunc_setSamples_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFramebufferObjectFormat.setSamples", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_setTextureTarget(PyObject* self, PyObject* pyArg)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextureTarget(GLenum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<GLenum>(), (pyArg)))) {
        overloadId = 0; // setTextureTarget(GLenum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFramebufferObjectFormatFunc_setTextureTarget_TypeError;

    // Call function/method
    {
        GLenum cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextureTarget(GLenum)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextureTarget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFramebufferObjectFormatFunc_setTextureTarget_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFramebufferObjectFormat.setTextureTarget", overloads);
        return 0;
}

static PyObject* Sbk_QGLFramebufferObjectFormatFunc_textureTarget(PyObject* self)
{
    ::QGLFramebufferObjectFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textureTarget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            GLenum cppResult = const_cast<const ::QGLFramebufferObjectFormat*>(cppSelf)->textureTarget();
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

static PyObject* Sbk_QGLFramebufferObjectFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGLFramebufferObjectFormat& cppSelf = *(((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGLFramebufferObjectFormat_methods[] = {
    {"attachment", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_attachment, METH_NOARGS},
    {"internalTextureFormat", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_internalTextureFormat, METH_NOARGS},
    {"mipmap", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_mipmap, METH_NOARGS},
    {"samples", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_samples, METH_NOARGS},
    {"setAttachment", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_setAttachment, METH_O},
    {"setInternalTextureFormat", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_setInternalTextureFormat, METH_O},
    {"setMipmap", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_setMipmap, METH_O},
    {"setSamples", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_setSamples, METH_O},
    {"setTextureTarget", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_setTextureTarget, METH_O},
    {"textureTarget", (PyCFunction)Sbk_QGLFramebufferObjectFormatFunc_textureTarget, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QGLFramebufferObjectFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QGLFramebufferObjectFormat_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGLFramebufferObjectFormat& cppSelf = *(((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (pyArg)))) {
                // operator!=(const QGLFramebufferObjectFormat & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGLFramebufferObjectFormat cppArg0_local = ::QGLFramebufferObjectFormat();
                ::QGLFramebufferObjectFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (pyArg)))) {
                // operator==(const QGLFramebufferObjectFormat & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGLFramebufferObjectFormat cppArg0_local = ::QGLFramebufferObjectFormat();
                ::QGLFramebufferObjectFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QGLFramebufferObjectFormat_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QGLFramebufferObjectFormat_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QGLFramebufferObjectFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLFramebufferObjectFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLFramebufferObjectFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLFramebufferObjectFormat",
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
    /*tp_traverse*/         Sbk_QGLFramebufferObjectFormat_traverse,
    /*tp_clear*/            Sbk_QGLFramebufferObjectFormat_clear,
    /*tp_richcompare*/      Sbk_QGLFramebufferObjectFormat_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLFramebufferObjectFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLFramebufferObjectFormat_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLFramebufferObjectFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLFramebufferObjectFormat_Type))
        return QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLFramebufferObjectFormat_PTR_CppToPython_QGLFramebufferObjectFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLFramebufferObjectFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLFramebufferObjectFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QGLFramebufferObjectFormat_COPY_CppToPython_QGLFramebufferObjectFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QGLFramebufferObjectFormat_Type, new ::QGLFramebufferObjectFormat(*((::QGLFramebufferObjectFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QGLFramebufferObjectFormat*)cppOut) = *((::QGLFramebufferObjectFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLFramebufferObjectFormat_Type))
        return QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_COPY;
    return 0;
}

void init_QGLFramebufferObjectFormat(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLFRAMEBUFFEROBJECTFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLFramebufferObjectFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLFramebufferObjectFormat", "QGLFramebufferObjectFormat",
        &Sbk_QGLFramebufferObjectFormat_Type, &Shiboken::callCppDestructor< ::QGLFramebufferObjectFormat >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLFramebufferObjectFormat_Type,
        QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_PTR,
        is_QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_PTR_Convertible,
        QGLFramebufferObjectFormat_PTR_CppToPython_QGLFramebufferObjectFormat,
        QGLFramebufferObjectFormat_COPY_CppToPython_QGLFramebufferObjectFormat);

    Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObjectFormat");
    Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObjectFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QGLFramebufferObjectFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLFramebufferObjectFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_COPY,
        is_QGLFramebufferObjectFormat_PythonToCpp_QGLFramebufferObjectFormat_COPY_Convertible);


    qRegisterMetaType< ::QGLFramebufferObjectFormat >("QGLFramebufferObjectFormat");
}
