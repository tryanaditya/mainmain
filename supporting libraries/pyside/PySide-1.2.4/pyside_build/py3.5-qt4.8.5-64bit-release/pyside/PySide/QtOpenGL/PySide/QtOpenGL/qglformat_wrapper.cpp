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

#include "qglformat_wrapper.h"

// Extra includes
#include <qgl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLFormat >()))
        return -1;

    ::QGLFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFormat(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QGLFormat", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGLFormat()
    // 1: QGLFormat(QFlags<QGL::FormatOption>,int)
    // 2: QGLFormat(QGLFormat)
    if (numArgs == 0) {
        overloadId = 0; // QGLFormat()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QGLFormat(QFlags<QGL::FormatOption>,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // QGLFormat(QFlags<QGL::FormatOption>,int)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QGLFormat(QGLFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLFormat()
        {

            if (!PyErr_Occurred()) {
                // QGLFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGLFormat(QFlags<QGL::FormatOption> options, int plane)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "plane");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtOpenGL.QGLFormat(): got multiple values for keyword argument 'plane'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QGLFormat_Init_TypeError;
                }
            }
            ::QFlags<QGL::FormatOption> cppArg0 = ((::QFlags<QGL::FormatOption>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGLFormat(QFlags<QGL::FormatOption>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFormat(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QGLFormat(const QGLFormat & other)
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
                // QGLFormat(QGLFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtOpenGL.QGL.FormatOptions, int = 0", "PySide.QtOpenGL.QGLFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLFormat", overloads);
        return -1;
}

static PyObject* Sbk_QGLFormatFunc_accum(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // accum()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->accum();
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

static PyObject* Sbk_QGLFormatFunc_accumBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // accumBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->accumBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_alpha(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alpha()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->alpha();
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

static PyObject* Sbk_QGLFormatFunc_alphaBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alphaBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->alphaBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_blueBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blueBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->blueBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_defaultFormat(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultFormat()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFormat cppResult = ::QGLFormat::defaultFormat();
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

static PyObject* Sbk_QGLFormatFunc_defaultOverlayFormat(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultOverlayFormat()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFormat cppResult = ::QGLFormat::defaultOverlayFormat();
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

static PyObject* Sbk_QGLFormatFunc_depth(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // depth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->depth();
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

static PyObject* Sbk_QGLFormatFunc_depthBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // depthBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->depthBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_directRendering(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // directRendering()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->directRendering();
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

static PyObject* Sbk_QGLFormatFunc_doubleBuffer(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doubleBuffer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->doubleBuffer();
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

static PyObject* Sbk_QGLFormatFunc_greenBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // greenBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->greenBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_hasOpenGL(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOpenGL()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLFormat::hasOpenGL();
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

static PyObject* Sbk_QGLFormatFunc_hasOpenGLOverlays(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOpenGLOverlays()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGLFormat::hasOpenGLOverlays();
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

static PyObject* Sbk_QGLFormatFunc_hasOverlay(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOverlay()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->hasOverlay();
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

static PyObject* Sbk_QGLFormatFunc_majorVersion(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // majorVersion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->majorVersion();
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

static PyObject* Sbk_QGLFormatFunc_minorVersion(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minorVersion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->minorVersion();
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

static PyObject* Sbk_QGLFormatFunc_openGLVersionFlags(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // openGLVersionFlags()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGLFormat::OpenGLVersionFlag> cppResult = ::QGLFormat::openGLVersionFlags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLFormatFunc_plane(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // plane()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->plane();
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

static PyObject* Sbk_QGLFormatFunc_profile(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // profile()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGLFormat::OpenGLContextProfile cppResult = const_cast<const ::QGLFormat*>(cppSelf)->profile();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGLFormatFunc_redBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // redBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->redBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_rgba(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rgba()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->rgba();
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

static PyObject* Sbk_QGLFormatFunc_sampleBuffers(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sampleBuffers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->sampleBuffers();
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

static PyObject* Sbk_QGLFormatFunc_samples(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // samples()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->samples();
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

static PyObject* Sbk_QGLFormatFunc_setAccum(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAccum(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAccum(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setAccum_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAccum(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAccum(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setAccum_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setAccum", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setAccumBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAccumBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setAccumBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setAccumBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAccumBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAccumBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setAccumBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setAccumBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setAlpha(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlpha(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAlpha(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setAlpha_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlpha(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlpha(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setAlpha_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setAlpha", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setAlphaBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlphaBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setAlphaBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setAlphaBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlphaBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlphaBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setAlphaBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setAlphaBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setBlueBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlueBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setBlueBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setBlueBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBlueBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlueBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setBlueBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setBlueBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setDefaultFormat(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultFormat(QGLFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultFormat(QGLFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setDefaultFormat_TypeError;

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
            // setDefaultFormat(QGLFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGLFormat::setDefaultFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setDefaultFormat_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setDefaultFormat", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setDefaultOverlayFormat(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultOverlayFormat(QGLFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultOverlayFormat(QGLFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setDefaultOverlayFormat_TypeError;

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
            // setDefaultOverlayFormat(QGLFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGLFormat::setDefaultOverlayFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setDefaultOverlayFormat_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setDefaultOverlayFormat", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setDepth(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDepth(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDepth(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setDepth_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDepth(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDepth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setDepth_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setDepth", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setDepthBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDepthBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setDepthBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setDepthBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDepthBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDepthBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setDepthBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setDepthBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setDirectRendering(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirectRendering(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDirectRendering(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setDirectRendering_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDirectRendering(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDirectRendering(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setDirectRendering_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setDirectRendering", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setDoubleBuffer(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDoubleBuffer(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDoubleBuffer(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setDoubleBuffer_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDoubleBuffer(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDoubleBuffer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setDoubleBuffer_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setDoubleBuffer", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setGreenBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGreenBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setGreenBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setGreenBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGreenBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGreenBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setGreenBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setGreenBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setOption(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOption(QFlags<QGL::FormatOption>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), (pyArg)))) {
        overloadId = 0; // setOption(QFlags<QGL::FormatOption>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setOption_TypeError;

    // Call function/method
    {
        ::QFlags<QGL::FormatOption> cppArg0 = ((::QFlags<QGL::FormatOption>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOption(QFlags<QGL::FormatOption>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setOption_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGL.FormatOptions", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setOption", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setOverlay(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOverlay(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOverlay(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setOverlay_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOverlay(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOverlay(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setOverlay_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setOverlay", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setPlane(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPlane(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPlane(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setPlane_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPlane(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPlane(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setPlane_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setPlane", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setProfile(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProfile(QGLFormat::OpenGLContextProfile)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX]), (pyArg)))) {
        overloadId = 0; // setProfile(QGLFormat::OpenGLContextProfile)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setProfile_TypeError;

    // Call function/method
    {
        ::QGLFormat::OpenGLContextProfile cppArg0 = ((::QGLFormat::OpenGLContextProfile)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProfile(QGLFormat::OpenGLContextProfile)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProfile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setProfile_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGLFormat.OpenGLContextProfile", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setProfile", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setRedBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRedBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setRedBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setRedBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRedBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRedBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setRedBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setRedBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setRgba(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRgba(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setRgba(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setRgba_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRgba(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRgba(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setRgba_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setRgba", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setSampleBuffers(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSampleBuffers(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSampleBuffers(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setSampleBuffers_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSampleBuffers(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSampleBuffers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setSampleBuffers_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setSampleBuffers", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setSamples(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSamples(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSamples(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setSamples_TypeError;

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

    Sbk_QGLFormatFunc_setSamples_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setSamples", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setStencil(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStencil(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setStencil(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setStencil_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStencil(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStencil(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setStencil_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setStencil", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setStencilBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStencilBufferSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setStencilBufferSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setStencilBufferSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStencilBufferSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStencilBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setStencilBufferSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setStencilBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setStereo(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStereo(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setStereo(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setStereo_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStereo(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStereo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setStereo_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setStereo", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setSwapInterval(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSwapInterval(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSwapInterval(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setSwapInterval_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSwapInterval(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSwapInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setSwapInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.setSwapInterval", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_setVersion(PyObject* self, PyObject* args)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setVersion", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setVersion(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setVersion(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_setVersion_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setVersion(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVersion(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFormatFunc_setVersion_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLFormat.setVersion", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormatFunc_stencil(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stencil()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->stencil();
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

static PyObject* Sbk_QGLFormatFunc_stencilBufferSize(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stencilBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->stencilBufferSize();
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

static PyObject* Sbk_QGLFormatFunc_stereo(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stereo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->stereo();
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

static PyObject* Sbk_QGLFormatFunc_swapInterval(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // swapInterval()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLFormat*>(cppSelf)->swapInterval();
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

static PyObject* Sbk_QGLFormatFunc_testOption(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testOption(QFlags<QGL::FormatOption>)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), (pyArg)))) {
        overloadId = 0; // testOption(QFlags<QGL::FormatOption>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFormatFunc_testOption_TypeError;

    // Call function/method
    {
        ::QFlags<QGL::FormatOption> cppArg0 = ((::QFlags<QGL::FormatOption>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testOption(QFlags<QGL::FormatOption>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLFormat*>(cppSelf)->testOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLFormatFunc_testOption_TypeError:
        const char* overloads[] = {"PySide.QtOpenGL.QGL.FormatOptions", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLFormat.testOption", overloads);
        return 0;
}

static PyObject* Sbk_QGLFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGLFormat& cppSelf = *(((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGLFormat_methods[] = {
    {"accum", (PyCFunction)Sbk_QGLFormatFunc_accum, METH_NOARGS},
    {"accumBufferSize", (PyCFunction)Sbk_QGLFormatFunc_accumBufferSize, METH_NOARGS},
    {"alpha", (PyCFunction)Sbk_QGLFormatFunc_alpha, METH_NOARGS},
    {"alphaBufferSize", (PyCFunction)Sbk_QGLFormatFunc_alphaBufferSize, METH_NOARGS},
    {"blueBufferSize", (PyCFunction)Sbk_QGLFormatFunc_blueBufferSize, METH_NOARGS},
    {"defaultFormat", (PyCFunction)Sbk_QGLFormatFunc_defaultFormat, METH_NOARGS|METH_STATIC},
    {"defaultOverlayFormat", (PyCFunction)Sbk_QGLFormatFunc_defaultOverlayFormat, METH_NOARGS|METH_STATIC},
    {"depth", (PyCFunction)Sbk_QGLFormatFunc_depth, METH_NOARGS},
    {"depthBufferSize", (PyCFunction)Sbk_QGLFormatFunc_depthBufferSize, METH_NOARGS},
    {"directRendering", (PyCFunction)Sbk_QGLFormatFunc_directRendering, METH_NOARGS},
    {"doubleBuffer", (PyCFunction)Sbk_QGLFormatFunc_doubleBuffer, METH_NOARGS},
    {"greenBufferSize", (PyCFunction)Sbk_QGLFormatFunc_greenBufferSize, METH_NOARGS},
    {"hasOpenGL", (PyCFunction)Sbk_QGLFormatFunc_hasOpenGL, METH_NOARGS|METH_STATIC},
    {"hasOpenGLOverlays", (PyCFunction)Sbk_QGLFormatFunc_hasOpenGLOverlays, METH_NOARGS|METH_STATIC},
    {"hasOverlay", (PyCFunction)Sbk_QGLFormatFunc_hasOverlay, METH_NOARGS},
    {"majorVersion", (PyCFunction)Sbk_QGLFormatFunc_majorVersion, METH_NOARGS},
    {"minorVersion", (PyCFunction)Sbk_QGLFormatFunc_minorVersion, METH_NOARGS},
    {"openGLVersionFlags", (PyCFunction)Sbk_QGLFormatFunc_openGLVersionFlags, METH_NOARGS|METH_STATIC},
    {"plane", (PyCFunction)Sbk_QGLFormatFunc_plane, METH_NOARGS},
    {"profile", (PyCFunction)Sbk_QGLFormatFunc_profile, METH_NOARGS},
    {"redBufferSize", (PyCFunction)Sbk_QGLFormatFunc_redBufferSize, METH_NOARGS},
    {"rgba", (PyCFunction)Sbk_QGLFormatFunc_rgba, METH_NOARGS},
    {"sampleBuffers", (PyCFunction)Sbk_QGLFormatFunc_sampleBuffers, METH_NOARGS},
    {"samples", (PyCFunction)Sbk_QGLFormatFunc_samples, METH_NOARGS},
    {"setAccum", (PyCFunction)Sbk_QGLFormatFunc_setAccum, METH_O},
    {"setAccumBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setAccumBufferSize, METH_O},
    {"setAlpha", (PyCFunction)Sbk_QGLFormatFunc_setAlpha, METH_O},
    {"setAlphaBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setAlphaBufferSize, METH_O},
    {"setBlueBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setBlueBufferSize, METH_O},
    {"setDefaultFormat", (PyCFunction)Sbk_QGLFormatFunc_setDefaultFormat, METH_O|METH_STATIC},
    {"setDefaultOverlayFormat", (PyCFunction)Sbk_QGLFormatFunc_setDefaultOverlayFormat, METH_O|METH_STATIC},
    {"setDepth", (PyCFunction)Sbk_QGLFormatFunc_setDepth, METH_O},
    {"setDepthBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setDepthBufferSize, METH_O},
    {"setDirectRendering", (PyCFunction)Sbk_QGLFormatFunc_setDirectRendering, METH_O},
    {"setDoubleBuffer", (PyCFunction)Sbk_QGLFormatFunc_setDoubleBuffer, METH_O},
    {"setGreenBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setGreenBufferSize, METH_O},
    {"setOption", (PyCFunction)Sbk_QGLFormatFunc_setOption, METH_O},
    {"setOverlay", (PyCFunction)Sbk_QGLFormatFunc_setOverlay, METH_O},
    {"setPlane", (PyCFunction)Sbk_QGLFormatFunc_setPlane, METH_O},
    {"setProfile", (PyCFunction)Sbk_QGLFormatFunc_setProfile, METH_O},
    {"setRedBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setRedBufferSize, METH_O},
    {"setRgba", (PyCFunction)Sbk_QGLFormatFunc_setRgba, METH_O},
    {"setSampleBuffers", (PyCFunction)Sbk_QGLFormatFunc_setSampleBuffers, METH_O},
    {"setSamples", (PyCFunction)Sbk_QGLFormatFunc_setSamples, METH_O},
    {"setStencil", (PyCFunction)Sbk_QGLFormatFunc_setStencil, METH_O},
    {"setStencilBufferSize", (PyCFunction)Sbk_QGLFormatFunc_setStencilBufferSize, METH_O},
    {"setStereo", (PyCFunction)Sbk_QGLFormatFunc_setStereo, METH_O},
    {"setSwapInterval", (PyCFunction)Sbk_QGLFormatFunc_setSwapInterval, METH_O},
    {"setVersion", (PyCFunction)Sbk_QGLFormatFunc_setVersion, METH_VARARGS},
    {"stencil", (PyCFunction)Sbk_QGLFormatFunc_stencil, METH_NOARGS},
    {"stencilBufferSize", (PyCFunction)Sbk_QGLFormatFunc_stencilBufferSize, METH_NOARGS},
    {"stereo", (PyCFunction)Sbk_QGLFormatFunc_stereo, METH_NOARGS},
    {"swapInterval", (PyCFunction)Sbk_QGLFormatFunc_swapInterval, METH_NOARGS},
    {"testOption", (PyCFunction)Sbk_QGLFormatFunc_testOption, METH_O},

    {"__copy__", (PyCFunction)Sbk_QGLFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QGLFormat_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGLFormat& cppSelf = *(((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArg)))) {
                // operator!=(const QGLFormat & arg__2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGLFormat cppArg0_local = ::QGLFormat();
                ::QGLFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (pyArg)))) {
                // operator==(const QGLFormat & arg__2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGLFormat cppArg0_local = ::QGLFormat();
                ::QGLFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], pythonToCpp))
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
            goto Sbk_QGLFormat_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QGLFormat_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QGLFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QGLFormat__repr__(PyObject* self)
{
    ::QGLFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLFormat",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QGLFormat__repr__,
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
    /*tp_traverse*/         Sbk_QGLFormat_traverse,
    /*tp_clear*/            Sbk_QGLFormat_clear,
    /*tp_richcompare*/      Sbk_QGLFormat_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLFormat_Init,
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

PyObject* SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat::OpenGLVersionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLFormat::OpenGLVersionFlags)PyLong_AsLong(self);
    cppArg = (QGLFormat::OpenGLVersionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLFormat::OpenGLVersionFlags)PyInt_AsLong(self);
    cppArg = (QGLFormat::OpenGLVersionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat::OpenGLVersionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLFormat::OpenGLVersionFlags)PyLong_AsLong(self);
    cppArg = (QGLFormat::OpenGLVersionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLFormat::OpenGLVersionFlags)PyInt_AsLong(self);
    cppArg = (QGLFormat::OpenGLVersionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat::OpenGLVersionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGLFormat::OpenGLVersionFlags)PyLong_AsLong(self);
    cppArg = (QGLFormat::OpenGLVersionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGLFormat::OpenGLVersionFlags)PyInt_AsLong(self);
    cppArg = (QGLFormat::OpenGLVersionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGLFormat::OpenGLVersionFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), self, &cppSelf);
    ::QGLFormat::OpenGLVersionFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag_long,
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
static void QGLFormat_OpenGLContextProfile_PythonToCpp_QGLFormat_OpenGLContextProfile(PyObject* pyIn, void* cppOut) {
    *((::QGLFormat::OpenGLContextProfile*)cppOut) = (::QGLFormat::OpenGLContextProfile) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLFormat_OpenGLContextProfile_PythonToCpp_QGLFormat_OpenGLContextProfile_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX]))
        return QGLFormat_OpenGLContextProfile_PythonToCpp_QGLFormat_OpenGLContextProfile;
    return 0;
}
static PyObject* QGLFormat_OpenGLContextProfile_CppToPython_QGLFormat_OpenGLContextProfile(const void* cppIn) {
    int castCppIn = *((::QGLFormat::OpenGLContextProfile*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX], castCppIn);

}

static void QGLFormat_OpenGLVersionFlag_PythonToCpp_QGLFormat_OpenGLVersionFlag(PyObject* pyIn, void* cppOut) {
    *((::QGLFormat::OpenGLVersionFlag*)cppOut) = (::QGLFormat::OpenGLVersionFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGLFormat_OpenGLVersionFlag_PythonToCpp_QGLFormat_OpenGLVersionFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX]))
        return QGLFormat_OpenGLVersionFlag_PythonToCpp_QGLFormat_OpenGLVersionFlag;
    return 0;
}
static PyObject* QGLFormat_OpenGLVersionFlag_CppToPython_QGLFormat_OpenGLVersionFlag(const void* cppIn) {
    int castCppIn = *((::QGLFormat::OpenGLVersionFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX], castCppIn);

}

static void QFlags_QGLFormat_OpenGLVersionFlag__PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGLFormat::OpenGLVersionFlag>*)cppOut) = ::QFlags<QGLFormat::OpenGLVersionFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGLFormat_OpenGLVersionFlag__PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]))
        return QFlags_QGLFormat_OpenGLVersionFlag__PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_;
    return 0;
}
static PyObject* QFlags_QGLFormat_OpenGLVersionFlag__CppToPython_QFlags_QGLFormat_OpenGLVersionFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGLFormat::OpenGLVersionFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]));

}

static void QGLFormat_OpenGLVersionFlag_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGLFormat::OpenGLVersionFlag>*)cppOut) = ::QFlags<QGLFormat::OpenGLVersionFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGLFormat_OpenGLVersionFlag_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX]))
        return QGLFormat_OpenGLVersionFlag_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGLFormat::OpenGLVersionFlag>*)cppOut) = ::QFlags<QGLFormat::OpenGLVersionFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGLFormat_PythonToCpp_QGLFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLFormat_PythonToCpp_QGLFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLFormat_Type))
        return QGLFormat_PythonToCpp_QGLFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLFormat_PTR_CppToPython_QGLFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QGLFormat_COPY_CppToPython_QGLFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QGLFormat_Type, new ::QGLFormat(*((::QGLFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QGLFormat_PythonToCpp_QGLFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QGLFormat*)cppOut) = *((::QGLFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QGLFormat_PythonToCpp_QGLFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLFormat_Type))
        return QGLFormat_PythonToCpp_QGLFormat_COPY;
    return 0;
}

// Implicit conversions.
static void QFlags_QGL_FormatOption__PythonToCpp_QGLFormat(PyObject* pyIn, void* cppOut) {
    ::QFlags<QGL::FormatOption> cppIn = ((::QFlags<QGL::FormatOption>)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), pyIn, &cppIn);
    *((::QGLFormat*)cppOut) = ::QGLFormat(cppIn);
}
static PythonToCppFunc is_QFlags_QGL_FormatOption__PythonToCpp_QGLFormat_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX], pyIn))
        return QFlags_QGL_FormatOption__PythonToCpp_QGLFormat;
    return 0;
}

void init_QGLFormat(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLFormat", "QGLFormat",
        &Sbk_QGLFormat_Type, &Shiboken::callCppDestructor< ::QGLFormat >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLFormat_Type,
        QGLFormat_PythonToCpp_QGLFormat_PTR,
        is_QGLFormat_PythonToCpp_QGLFormat_PTR_Convertible,
        QGLFormat_PTR_CppToPython_QGLFormat,
        QGLFormat_COPY_CppToPython_QGLFormat);

    Shiboken::Conversions::registerConverterName(converter, "QGLFormat");
    Shiboken::Conversions::registerConverterName(converter, "QGLFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QGLFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QGLFormat_PythonToCpp_QGLFormat_COPY,
        is_QGLFormat_PythonToCpp_QGLFormat_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QFlags_QGL_FormatOption__PythonToCpp_QGLFormat,
        is_QFlags_QGL_FormatOption__PythonToCpp_QGLFormat_Convertible);

    // Initialization of enums.

    // Initialization of enum 'OpenGLContextProfile'.
    SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLFormat_Type,
        "OpenGLContextProfile",
        "PySide.QtOpenGL.QGLFormat.OpenGLContextProfile",
        "QGLFormat::OpenGLContextProfile");
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX],
        &Sbk_QGLFormat_Type, "NoProfile", (long) QGLFormat::NoProfile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX],
        &Sbk_QGLFormat_Type, "CoreProfile", (long) QGLFormat::CoreProfile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX],
        &Sbk_QGLFormat_Type, "CompatibilityProfile", (long) QGLFormat::CompatibilityProfile))
        return ;
    // Register converter for enum 'QGLFormat::OpenGLContextProfile'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX],
            QGLFormat_OpenGLContextProfile_CppToPython_QGLFormat_OpenGLContextProfile);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLFormat_OpenGLContextProfile_PythonToCpp_QGLFormat_OpenGLContextProfile,
            is_QGLFormat_OpenGLContextProfile_PythonToCpp_QGLFormat_OpenGLContextProfile_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLCONTEXTPROFILE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLFormat::OpenGLContextProfile");
        Shiboken::Conversions::registerConverterName(converter, "OpenGLContextProfile");
    }
    // End of 'OpenGLContextProfile' enum.

    // Initialization of enum 'OpenGLVersionFlag'.
    SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX] = PySide::QFlags::create("OpenGLVersionFlags", &SbkPySide_QtOpenGL_QGLFormat_OpenGLVersionFlag_as_number);
    SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGLFormat_Type,
        "OpenGLVersionFlag",
        "PySide.QtOpenGL.QGLFormat.OpenGLVersionFlag",
        "QGLFormat::OpenGLVersionFlag",
        SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX]);
    if (!SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_None", (long) QGLFormat::OpenGL_Version_None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_1_1", (long) QGLFormat::OpenGL_Version_1_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_1_2", (long) QGLFormat::OpenGL_Version_1_2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_1_3", (long) QGLFormat::OpenGL_Version_1_3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_1_4", (long) QGLFormat::OpenGL_Version_1_4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_1_5", (long) QGLFormat::OpenGL_Version_1_5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_2_0", (long) QGLFormat::OpenGL_Version_2_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_2_1", (long) QGLFormat::OpenGL_Version_2_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_ES_Common_Version_1_0", (long) QGLFormat::OpenGL_ES_Common_Version_1_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_ES_CommonLite_Version_1_0", (long) QGLFormat::OpenGL_ES_CommonLite_Version_1_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_ES_Common_Version_1_1", (long) QGLFormat::OpenGL_ES_Common_Version_1_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_ES_CommonLite_Version_1_1", (long) QGLFormat::OpenGL_ES_CommonLite_Version_1_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_ES_Version_2_0", (long) QGLFormat::OpenGL_ES_Version_2_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_3_0", (long) QGLFormat::OpenGL_Version_3_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_3_1", (long) QGLFormat::OpenGL_Version_3_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_3_2", (long) QGLFormat::OpenGL_Version_3_2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_3_3", (long) QGLFormat::OpenGL_Version_3_3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
        &Sbk_QGLFormat_Type, "OpenGL_Version_4_0", (long) QGLFormat::OpenGL_Version_4_0))
        return ;
    // Register converter for enum 'QGLFormat::OpenGLVersionFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX],
            QGLFormat_OpenGLVersionFlag_CppToPython_QGLFormat_OpenGLVersionFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLFormat_OpenGLVersionFlag_PythonToCpp_QGLFormat_OpenGLVersionFlag,
            is_QGLFormat_OpenGLVersionFlag_PythonToCpp_QGLFormat_OpenGLVersionFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGLFORMAT_OPENGLVERSIONFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGLFormat::OpenGLVersionFlag");
        Shiboken::Conversions::registerConverterName(converter, "OpenGLVersionFlag");
    }
    // Register converter for flag 'QFlags<QGLFormat::OpenGLVersionFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX],
            QFlags_QGLFormat_OpenGLVersionFlag__CppToPython_QFlags_QGLFormat_OpenGLVersionFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGLFormat_OpenGLVersionFlag_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_,
            is_QGLFormat_OpenGLVersionFlag_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGLFormat_OpenGLVersionFlag__PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_,
            is_QFlags_QGLFormat_OpenGLVersionFlag__PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag_,
            is_number_PythonToCpp_QFlags_QGLFormat_OpenGLVersionFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGLFORMAT_OPENGLVERSIONFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGLFormat::OpenGLVersionFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<OpenGLVersionFlag>");
    }
    // End of 'OpenGLVersionFlag' enum/flags.


    qRegisterMetaType< ::QGLFormat >("QGLFormat");
    qRegisterMetaType< ::QGLFormat::OpenGLContextProfile >("QGLFormat::OpenGLContextProfile");
    qRegisterMetaType< ::QGLFormat::OpenGLVersionFlag >("QGLFormat::OpenGLVersionFlag");
    qRegisterMetaType< ::QGLFormat::OpenGLVersionFlags >("QGLFormat::OpenGLVersionFlags");
}
