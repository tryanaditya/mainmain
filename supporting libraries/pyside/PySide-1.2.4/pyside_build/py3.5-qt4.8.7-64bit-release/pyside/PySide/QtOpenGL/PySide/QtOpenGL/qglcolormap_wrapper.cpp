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

#include "qglcolormap_wrapper.h"

// Extra includes
#include <qcolor.h>
#include <qglcolormap.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGLColormap_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGLColormap >()))
        return -1;

    ::QGLColormap* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGLColormap", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGLColormap()
    // 1: QGLColormap(QGLColormap)
    if (numArgs == 0) {
        overloadId = 0; // QGLColormap()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (pyArgs[0])))) {
        overloadId = 1; // QGLColormap(QGLColormap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormap_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGLColormap()
        {

            if (!PyErr_Occurred()) {
                // QGLColormap()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLColormap();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGLColormap(const QGLColormap & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGLColormap cppArg0_local = ::QGLColormap();
            ::QGLColormap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QGLColormap(QGLColormap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGLColormap(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGLColormap >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGLColormap_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGLColormap_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtOpenGL.QGLColormap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLColormap", overloads);
        return -1;
}

static PyObject* Sbk_QGLColormapFunc_entryColor(PyObject* self, PyObject* pyArg)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: entryColor(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // entryColor(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormapFunc_entryColor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // entryColor(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QGLColormap*>(cppSelf)->entryColor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLColormapFunc_entryColor_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLColormap.entryColor", overloads);
        return 0;
}

static PyObject* Sbk_QGLColormapFunc_entryRgb(PyObject* self, PyObject* pyArg)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: entryRgb(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // entryRgb(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormapFunc_entryRgb_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // entryRgb(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = const_cast<const ::QGLColormap*>(cppSelf)->entryRgb(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLColormapFunc_entryRgb_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLColormap.entryRgb", overloads);
        return 0;
}

static PyObject* Sbk_QGLColormapFunc_find(PyObject* self, PyObject* pyArg)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: find(uint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // find(uint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormapFunc_find_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // find(uint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLColormap*>(cppSelf)->find(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLColormapFunc_find_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLColormap.find", overloads);
        return 0;
}

static PyObject* Sbk_QGLColormapFunc_findNearest(PyObject* self, PyObject* pyArg)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findNearest(uint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // findNearest(uint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormapFunc_findNearest_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findNearest(uint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLColormap*>(cppSelf)->findNearest(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGLColormapFunc_findNearest_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLColormap.findNearest", overloads);
        return 0;
}

static PyObject* Sbk_QGLColormapFunc_handle(PyObject* self)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = cppSelf->handle();
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

static PyObject* Sbk_QGLColormapFunc_isEmpty(PyObject* self)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGLColormap*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QGLColormapFunc_setEntry(PyObject* self, PyObject* args)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setEntry", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setEntry(int,QColor)
    // 1: setEntry(int,uint)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[1])))) {
            overloadId = 1; // setEntry(int,uint)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 0; // setEntry(int,QColor)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormapFunc_setEntry_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setEntry(int idx, const QColor & color)
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
                // setEntry(int,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setEntry(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setEntry(int idx, unsigned int color)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            unsigned int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setEntry(int,uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setEntry(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLColormapFunc_setEntry_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QColor", "int, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtOpenGL.QGLColormap.setEntry", overloads);
        return 0;
}

static PyObject* Sbk_QGLColormapFunc_setHandle(PyObject* self, PyObject* pyArg)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHandle(Qt::HANDLE)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), (pyArg)))) {
        overloadId = 0; // setHandle(Qt::HANDLE)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLColormapFunc_setHandle_TypeError;

    // Call function/method
    {
        ::Qt::HANDLE cppArg0 = ::Qt::HANDLE();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHandle(Qt::HANDLE)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHandle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLColormapFunc_setHandle_TypeError:
        const char* overloads[] = {"Qt::HANDLE", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGLColormap.setHandle", overloads);
        return 0;
}

static PyObject* Sbk_QGLColormapFunc_size(PyObject* self)
{
    ::QGLColormap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGLColormap*>(cppSelf)->size();
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

static PyObject* Sbk_QGLColormap___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGLColormap& cppSelf = *(((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGLColormap_methods[] = {
    {"entryColor", (PyCFunction)Sbk_QGLColormapFunc_entryColor, METH_O},
    {"entryRgb", (PyCFunction)Sbk_QGLColormapFunc_entryRgb, METH_O},
    {"find", (PyCFunction)Sbk_QGLColormapFunc_find, METH_O},
    {"findNearest", (PyCFunction)Sbk_QGLColormapFunc_findNearest, METH_O},
    {"handle", (PyCFunction)Sbk_QGLColormapFunc_handle, METH_NOARGS},
    {"isEmpty", (PyCFunction)Sbk_QGLColormapFunc_isEmpty, METH_NOARGS},
    {"setEntry", (PyCFunction)Sbk_QGLColormapFunc_setEntry, METH_VARARGS},
    {"setHandle", (PyCFunction)Sbk_QGLColormapFunc_setHandle, METH_O},
    {"size", (PyCFunction)Sbk_QGLColormapFunc_size, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QGLColormap___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGLColormap_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGLColormap_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGLColormap_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGLColormap",
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
    /*tp_traverse*/         Sbk_QGLColormap_traverse,
    /*tp_clear*/            Sbk_QGLColormap_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGLColormap_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGLColormap_Init,
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
static void QGLColormap_PythonToCpp_QGLColormap_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGLColormap_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGLColormap_PythonToCpp_QGLColormap_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLColormap_Type))
        return QGLColormap_PythonToCpp_QGLColormap_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGLColormap_PTR_CppToPython_QGLColormap(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGLColormap*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGLColormap_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QGLColormap_COPY_CppToPython_QGLColormap(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QGLColormap_Type, new ::QGLColormap(*((::QGLColormap*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QGLColormap_PythonToCpp_QGLColormap_COPY(PyObject* pyIn, void* cppOut) {
    *((::QGLColormap*)cppOut) = *((::QGLColormap*)Shiboken::Conversions::cppPointer(SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QGLColormap_PythonToCpp_QGLColormap_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGLColormap_Type))
        return QGLColormap_PythonToCpp_QGLColormap_COPY;
    return 0;
}

void init_QGLColormap(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGLCOLORMAP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGLColormap_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGLColormap", "QGLColormap",
        &Sbk_QGLColormap_Type, &Shiboken::callCppDestructor< ::QGLColormap >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGLColormap_Type,
        QGLColormap_PythonToCpp_QGLColormap_PTR,
        is_QGLColormap_PythonToCpp_QGLColormap_PTR_Convertible,
        QGLColormap_PTR_CppToPython_QGLColormap,
        QGLColormap_COPY_CppToPython_QGLColormap);

    Shiboken::Conversions::registerConverterName(converter, "QGLColormap");
    Shiboken::Conversions::registerConverterName(converter, "QGLColormap*");
    Shiboken::Conversions::registerConverterName(converter, "QGLColormap&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGLColormap).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QGLColormap_PythonToCpp_QGLColormap_COPY,
        is_QGLColormap_PythonToCpp_QGLColormap_COPY_Convertible);


    qRegisterMetaType< ::QGLColormap >("QGLColormap");
}
