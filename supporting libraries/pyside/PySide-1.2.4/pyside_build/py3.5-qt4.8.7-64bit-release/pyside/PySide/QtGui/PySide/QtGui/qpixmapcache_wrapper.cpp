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
#include "pyside_qtgui_python.h"

#include "qpixmapcache_wrapper.h"
#include "qpixmapcache_key_wrapper.h"

// Extra includes
#include <qpixmap.h>
#include <qpixmapcache.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPixmapCache_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPixmapCache >()))
        return -1;

    ::QPixmapCache* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QPixmapCache()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QPixmapCache();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPixmapCache >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QPixmapCacheFunc_cacheLimit(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheLimit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QPixmapCache::cacheLimit();
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

static PyObject* Sbk_QPixmapCacheFunc_clear(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QPixmapCache::clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPixmapCacheFunc_find(PyObject* self, PyObject* args)
{
    ::QPixmapCache* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QPixmapCache*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "find", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: find(QPixmapCache::Key&)
    // 1: find(QPixmapCache::Key,QPixmap*)
    // 2: find(QString)
    // 3: find(QString,QPixmap*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // find(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
            overloadId = 3; // find(QString,QPixmap*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // find(QPixmapCache::Key&)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
            overloadId = 1; // find(QPixmapCache::Key,QPixmap*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapCacheFunc_find_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // find(QPixmapCache::Key & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPixmapCache::Key cppArg0_local = ::QPixmapCache::Key();
            ::QPixmapCache::Key* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // find(QPixmapCache::Key&)
                // Begin code injection

                QPixmap p;
                if (cppSelf->find(*cppArg0, &p)) {
                    pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &p);
                } else {
                    pyResult = Py_None;
                    Py_INCREF(pyResult);
                }

                // End of code injection


            }
            break;
        }
        case 1: // find(const QPixmapCache::Key & key, QPixmap * pixmap)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPixmapCache::Key cppArg0_local = ::QPixmapCache::Key();
            ::QPixmapCache::Key* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // find(QPixmapCache::Key,QPixmap*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QPixmapCache::find(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // find(const QString & key)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // find(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmap * cppResult = ::QPixmapCache::find(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], cppResult);
            }
            break;
        }
        case 3: // find(const QString & key, QPixmap * pixmap)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // find(QString,QPixmap*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QPixmapCache::find(cppArg0, cppArg1);
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

    Sbk_QPixmapCacheFunc_find_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmapCache::Key", "PySide.QtGui.QPixmapCache::Key, PySide.QtGui.QPixmap", "unicode", "unicode, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmapCache.find", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapCacheFunc_insert(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insert(QPixmap)
    // 1: insert(QString,QPixmap)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        overloadId = 1; // insert(QString,QPixmap)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        overloadId = 0; // insert(QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapCacheFunc_insert_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insert(const QPixmap & pixmap)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPixmap cppArg0_local = ::QPixmap();
            ::QPixmap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // insert(QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmapCache::Key cppResult = ::QPixmapCache::insert(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], &cppResult);
            }
            break;
        }
        case 1: // insert(const QString & key, const QPixmap & pixmap)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // insert(QString,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QPixmapCache::insert(cppArg0, *cppArg1);
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

    Sbk_QPixmapCacheFunc_insert_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap", "unicode, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmapCache.insert", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapCacheFunc_remove(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(QPixmapCache::Key)
    // 1: remove(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // remove(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], (pyArg)))) {
        overloadId = 0; // remove(QPixmapCache::Key)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapCacheFunc_remove_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // remove(const QPixmapCache::Key & key)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPixmapCache::Key cppArg0_local = ::QPixmapCache::Key();
            ::QPixmapCache::Key* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // remove(QPixmapCache::Key)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QPixmapCache::remove(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // remove(const QString & key)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // remove(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QPixmapCache::remove(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapCacheFunc_remove_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmapCache::Key", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmapCache.remove", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapCacheFunc_replace(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replace(QPixmapCache::Key,QPixmap)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        overloadId = 0; // replace(QPixmapCache::Key,QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapCacheFunc_replace_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPixmapCache::Key cppArg0_local = ::QPixmapCache::Key();
        ::QPixmapCache::Key* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPixmap cppArg1_local = ::QPixmap();
        ::QPixmap* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // replace(QPixmapCache::Key,QPixmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QPixmapCache::replace(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapCacheFunc_replace_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmapCache::Key, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmapCache.replace", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapCacheFunc_setCacheLimit(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCacheLimit(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCacheLimit(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapCacheFunc_setCacheLimit_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCacheLimit(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QPixmapCache::setCacheLimit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapCacheFunc_setCacheLimit_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmapCache.setCacheLimit", overloads);
        return 0;
}

static PyMethodDef Sbk_QPixmapCacheMethod_find = {
    "find", (PyCFunction)Sbk_QPixmapCacheFunc_find, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QPixmapCache_methods[] = {
    {"cacheLimit", (PyCFunction)Sbk_QPixmapCacheFunc_cacheLimit, METH_NOARGS|METH_STATIC},
    {"clear", (PyCFunction)Sbk_QPixmapCacheFunc_clear, METH_NOARGS|METH_STATIC},
    Sbk_QPixmapCacheMethod_find,
    {"insert", (PyCFunction)Sbk_QPixmapCacheFunc_insert, METH_VARARGS|METH_STATIC},
    {"remove", (PyCFunction)Sbk_QPixmapCacheFunc_remove, METH_O|METH_STATIC},
    {"replace", (PyCFunction)Sbk_QPixmapCacheFunc_replace, METH_VARARGS|METH_STATIC},
    {"setCacheLimit", (PyCFunction)Sbk_QPixmapCacheFunc_setCacheLimit, METH_O|METH_STATIC},

    {0} // Sentinel
};

static PyObject* Sbk_QPixmapCache_getattro(PyObject* self, PyObject* name)
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
        static PyMethodDef non_static_Sbk_QPixmapCacheMethod_find = {
            Sbk_QPixmapCacheMethod_find.ml_name,
            Sbk_QPixmapCacheMethod_find.ml_meth,
            Sbk_QPixmapCacheMethod_find.ml_flags & (~METH_STATIC),
            Sbk_QPixmapCacheMethod_find.ml_doc,
        };
        if (Shiboken::String::compare(name, "find") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QPixmapCacheMethod_find, self, 0);
    }
    return PyObject_GenericGetAttr(self, name);
}

} // extern "C"

static int Sbk_QPixmapCache_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPixmapCache_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPixmapCache_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPixmapCache",
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
    /*tp_getattro*/         Sbk_QPixmapCache_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QPixmapCache_traverse,
    /*tp_clear*/            Sbk_QPixmapCache_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPixmapCache_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPixmapCache_Init,
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
static void QPixmapCache_PythonToCpp_QPixmapCache_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPixmapCache_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPixmapCache_PythonToCpp_QPixmapCache_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPixmapCache_Type))
        return QPixmapCache_PythonToCpp_QPixmapCache_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPixmapCache_PTR_CppToPython_QPixmapCache(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPixmapCache*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPixmapCache_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPixmapCache(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPixmapCache_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPixmapCache", "QPixmapCache*",
        &Sbk_QPixmapCache_Type, &Shiboken::callCppDestructor< ::QPixmapCache >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPixmapCache_Type,
        QPixmapCache_PythonToCpp_QPixmapCache_PTR,
        is_QPixmapCache_PythonToCpp_QPixmapCache_PTR_Convertible,
        QPixmapCache_PTR_CppToPython_QPixmapCache);

    Shiboken::Conversions::registerConverterName(converter, "QPixmapCache");
    Shiboken::Conversions::registerConverterName(converter, "QPixmapCache*");
    Shiboken::Conversions::registerConverterName(converter, "QPixmapCache&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPixmapCache).name());



}
