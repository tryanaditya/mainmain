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
#include "pyside_phonon_python.h"

#include "phonon_path_wrapper.h"

// Extra includes
#include <QList>
#include <effect.h>
#include <medianode.h>
#include <objectdescription.h>
#include <path.h>

using namespace Phonon;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_Path_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::Path >()))
        return -1;

    ::Phonon::Path* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "Path", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: Path()
    // 1: Path(Phonon::Path)
    if (numArgs == 0) {
        overloadId = 0; // Path()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (pyArgs[0])))) {
        overloadId = 1; // Path(Phonon::Path)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_Path_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // Path()
        {

            if (!PyErr_Occurred()) {
                // Path()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::Path();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // Path(const Phonon::Path & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::Path cppArg0_local = ::Phonon::Path();
            ::Phonon::Path* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // Path(Phonon::Path)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::Path(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::Path >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_Path_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Phonon_Path_Init_TypeError:
        const char* overloads[] = {"", "PySide.phonon.Phonon::Path", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.Path", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_PathFunc_disconnectPath(PyObject* self)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // disconnect()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->disconnect();
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

static PyObject* Sbk_Phonon_PathFunc_effects(PyObject* self)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // effects()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::Effect * > cppResult = const_cast<const ::Phonon::Path*>(cppSelf)->effects();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_PathFunc_insertEffect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.Path.insertEffect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.Path.insertEffect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:insertEffect", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertEffect(Phonon::Effect*,Phonon::Effect*)
    // 1: insertEffect(Phonon::EffectDescription,Phonon::Effect*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTDESCRIPTION_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // insertEffect(Phonon::EffectDescription,Phonon::Effect*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // insertEffect(Phonon::EffectDescription,Phonon::Effect*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // insertEffect(Phonon::Effect*,Phonon::Effect*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertEffect(Phonon::Effect*,Phonon::Effect*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PathFunc_insertEffect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertEffect(Phonon::Effect * newEffect, Phonon::Effect * insertBefore)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "insertBefore");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.Path.insertEffect(): got multiple values for keyword argument 'insertBefore'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], (pyArgs[1]))))
                        goto Sbk_Phonon_PathFunc_insertEffect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::Phonon::Effect* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::Phonon::Effect* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertEffect(Phonon::Effect*,Phonon::Effect*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->insertEffect(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 1: // insertEffect(const Phonon::EffectDescription & desc, Phonon::Effect * insertBefore)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "insertBefore");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.Path.insertEffect(): got multiple values for keyword argument 'insertBefore'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], (pyArgs[1]))))
                        goto Sbk_Phonon_PathFunc_insertEffect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::Phonon::EffectDescription cppArg0_local = ::Phonon::EffectDescription();
            ::Phonon::EffectDescription* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTDESCRIPTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::Phonon::Effect* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertEffect(Phonon::EffectDescription,Phonon::Effect*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Phonon::Effect * cppResult = cppSelf->insertEffect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], cppResult);
                Shiboken::Object::setParent(self, pyArgs[0]);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PathFunc_insertEffect_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::Effect, PySide.phonon.Phonon::Effect = None", "PySide.phonon.Phonon::EffectDescription, PySide.phonon.Phonon::Effect = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.Path.insertEffect", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PathFunc_isValid(PyObject* self)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::Path*>(cppSelf)->isValid();
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

static PyObject* Sbk_Phonon_PathFunc_reconnect(PyObject* self, PyObject* args)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "reconnect", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: reconnect(Phonon::MediaNode*,Phonon::MediaNode*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (pyArgs[1])))) {
        overloadId = 0; // reconnect(Phonon::MediaNode*,Phonon::MediaNode*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PathFunc_reconnect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Phonon::MediaNode* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::Phonon::MediaNode* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // reconnect(Phonon::MediaNode*,Phonon::MediaNode*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->reconnect(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PathFunc_reconnect_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaNode, PySide.phonon.Phonon::MediaNode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.Path.reconnect", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PathFunc_removeEffect(PyObject* self, PyObject* pyArg)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeEffect(Phonon::Effect*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], (pyArg)))) {
        overloadId = 0; // removeEffect(Phonon::Effect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PathFunc_removeEffect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Phonon::Effect* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeEffect(Phonon::Effect*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->removeEffect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PathFunc_removeEffect_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::Effect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.Path.removeEffect", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PathFunc_sink(PyObject* self)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sink()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::MediaNode * cppResult = const_cast<const ::Phonon::Path*>(cppSelf)->sink();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_PathFunc_source(PyObject* self)
{
    ::Phonon::Path* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // source()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::MediaNode * cppResult = const_cast<const ::Phonon::Path*>(cppSelf)->source();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_Path___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::Path& cppSelf = *(((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_Path_methods[] = {
    {"disconnectPath", (PyCFunction)Sbk_Phonon_PathFunc_disconnectPath, METH_NOARGS},
    {"effects", (PyCFunction)Sbk_Phonon_PathFunc_effects, METH_NOARGS},
    {"insertEffect", (PyCFunction)Sbk_Phonon_PathFunc_insertEffect, METH_VARARGS|METH_KEYWORDS},
    {"isValid", (PyCFunction)Sbk_Phonon_PathFunc_isValid, METH_NOARGS},
    {"reconnect", (PyCFunction)Sbk_Phonon_PathFunc_reconnect, METH_VARARGS},
    {"removeEffect", (PyCFunction)Sbk_Phonon_PathFunc_removeEffect, METH_O},
    {"sink", (PyCFunction)Sbk_Phonon_PathFunc_sink, METH_NOARGS},
    {"source", (PyCFunction)Sbk_Phonon_PathFunc_source, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_Phonon_Path___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_Phonon_Path_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::Path& cppSelf = *(((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (pyArg)))) {
                // operator!=(const Phonon::Path & p) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::Phonon::Path cppArg0_local = ::Phonon::Path();
                ::Phonon::Path* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (pyArg)))) {
                // operator==(const Phonon::Path & p) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::Phonon::Path cppArg0_local = ::Phonon::Path();
                ::Phonon::Path* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], pythonToCpp))
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
            goto Sbk_Phonon_Path_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_Phonon_Path_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_Phonon_Path_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_Path_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_Path_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.Path",
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
    /*tp_traverse*/         Sbk_Phonon_Path_traverse,
    /*tp_clear*/            Sbk_Phonon_Path_clear,
    /*tp_richcompare*/      Sbk_Phonon_Path_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_Path_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_Path_Init,
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
static void Path_PythonToCpp_Path_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_Path_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Path_PythonToCpp_Path_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_Path_Type))
        return Path_PythonToCpp_Path_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Path_PTR_CppToPython_Path(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::Path*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_Path_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* Path_COPY_CppToPython_Path(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_Phonon_Path_Type, new ::Phonon::Path(*((::Phonon::Path*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void Path_PythonToCpp_Path_COPY(PyObject* pyIn, void* cppOut) {
    *((::Phonon::Path*)cppOut) = *((::Phonon::Path*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_Path_PythonToCpp_Path_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_Path_Type))
        return Path_PythonToCpp_Path_COPY;
    return 0;
}

void init_Phonon_Path(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_PATH_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_Path_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Path", "Phonon::Path",
        &Sbk_Phonon_Path_Type, &Shiboken::callCppDestructor< ::Phonon::Path >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_Path_Type,
        Path_PythonToCpp_Path_PTR,
        is_Path_PythonToCpp_Path_PTR_Convertible,
        Path_PTR_CppToPython_Path,
        Path_COPY_CppToPython_Path);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::Path");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::Path*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::Path&");
    Shiboken::Conversions::registerConverterName(converter, "Path");
    Shiboken::Conversions::registerConverterName(converter, "Path*");
    Shiboken::Conversions::registerConverterName(converter, "Path&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::Path).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Path_PythonToCpp_Path_COPY,
        is_Path_PythonToCpp_Path_COPY_Convertible);


    qRegisterMetaType< ::Phonon::Path >("Path");
    qRegisterMetaType< ::Phonon::Path >("Phonon::Path");
}
