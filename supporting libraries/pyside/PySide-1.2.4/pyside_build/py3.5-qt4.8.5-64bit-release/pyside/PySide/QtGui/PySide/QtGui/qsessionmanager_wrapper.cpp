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
#include "pyside_qtgui_python.h"

#include "qsessionmanager_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QSessionManagerFunc_allowsErrorInteraction(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allowsErrorInteraction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->allowsErrorInteraction();
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

static PyObject* Sbk_QSessionManagerFunc_allowsInteraction(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allowsInteraction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->allowsInteraction();
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

static PyObject* Sbk_QSessionManagerFunc_cancel(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cancel()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cancel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSessionManagerFunc_discardCommand(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // discardCommand()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSessionManager*>(cppSelf)->discardCommand();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSessionManagerFunc_isPhase2(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isPhase2()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSessionManager*>(cppSelf)->isPhase2();
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

static PyObject* Sbk_QSessionManagerFunc_release(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // release()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->release();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSessionManagerFunc_requestPhase2(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // requestPhase2()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->requestPhase2();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSessionManagerFunc_restartCommand(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restartCommand()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSessionManager*>(cppSelf)->restartCommand();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSessionManagerFunc_restartHint(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restartHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSessionManager::RestartHint cppResult = const_cast<const ::QSessionManager*>(cppSelf)->restartHint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSessionManagerFunc_sessionId(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sessionId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSessionManager*>(cppSelf)->sessionId();
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

static PyObject* Sbk_QSessionManagerFunc_sessionKey(PyObject* self)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sessionKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSessionManager*>(cppSelf)->sessionKey();
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

static PyObject* Sbk_QSessionManagerFunc_setDiscardCommand(PyObject* self, PyObject* pyArg)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDiscardCommand(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setDiscardCommand(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSessionManagerFunc_setDiscardCommand_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDiscardCommand(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDiscardCommand(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSessionManagerFunc_setDiscardCommand_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSessionManager.setDiscardCommand", overloads);
        return 0;
}

static PyObject* Sbk_QSessionManagerFunc_setManagerProperty(PyObject* self, PyObject* args)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setManagerProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setManagerProperty(QString,QString)
    // 1: setManagerProperty(QString,QStringList)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            overloadId = 1; // setManagerProperty(QString,QStringList)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // setManagerProperty(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSessionManagerFunc_setManagerProperty_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setManagerProperty(const QString & name, const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setManagerProperty(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setManagerProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setManagerProperty(const QString & name, const QStringList & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setManagerProperty(QString,QStringList)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setManagerProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSessionManagerFunc_setManagerProperty_TypeError:
        const char* overloads[] = {"unicode, unicode", "unicode, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QSessionManager.setManagerProperty", overloads);
        return 0;
}

static PyObject* Sbk_QSessionManagerFunc_setRestartCommand(PyObject* self, PyObject* pyArg)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRestartCommand(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setRestartCommand(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSessionManagerFunc_setRestartCommand_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRestartCommand(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRestartCommand(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSessionManagerFunc_setRestartCommand_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSessionManager.setRestartCommand", overloads);
        return 0;
}

static PyObject* Sbk_QSessionManagerFunc_setRestartHint(PyObject* self, PyObject* pyArg)
{
    ::QSessionManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSessionManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRestartHint(QSessionManager::RestartHint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX]), (pyArg)))) {
        overloadId = 0; // setRestartHint(QSessionManager::RestartHint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSessionManagerFunc_setRestartHint_TypeError;

    // Call function/method
    {
        ::QSessionManager::RestartHint cppArg0 = ((::QSessionManager::RestartHint)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRestartHint(QSessionManager::RestartHint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRestartHint(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSessionManagerFunc_setRestartHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSessionManager.RestartHint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSessionManager.setRestartHint", overloads);
        return 0;
}

static PyMethodDef Sbk_QSessionManager_methods[] = {
    {"allowsErrorInteraction", (PyCFunction)Sbk_QSessionManagerFunc_allowsErrorInteraction, METH_NOARGS},
    {"allowsInteraction", (PyCFunction)Sbk_QSessionManagerFunc_allowsInteraction, METH_NOARGS},
    {"cancel", (PyCFunction)Sbk_QSessionManagerFunc_cancel, METH_NOARGS},
    {"discardCommand", (PyCFunction)Sbk_QSessionManagerFunc_discardCommand, METH_NOARGS},
    {"isPhase2", (PyCFunction)Sbk_QSessionManagerFunc_isPhase2, METH_NOARGS},
    {"release", (PyCFunction)Sbk_QSessionManagerFunc_release, METH_NOARGS},
    {"requestPhase2", (PyCFunction)Sbk_QSessionManagerFunc_requestPhase2, METH_NOARGS},
    {"restartCommand", (PyCFunction)Sbk_QSessionManagerFunc_restartCommand, METH_NOARGS},
    {"restartHint", (PyCFunction)Sbk_QSessionManagerFunc_restartHint, METH_NOARGS},
    {"sessionId", (PyCFunction)Sbk_QSessionManagerFunc_sessionId, METH_NOARGS},
    {"sessionKey", (PyCFunction)Sbk_QSessionManagerFunc_sessionKey, METH_NOARGS},
    {"setDiscardCommand", (PyCFunction)Sbk_QSessionManagerFunc_setDiscardCommand, METH_O},
    {"setManagerProperty", (PyCFunction)Sbk_QSessionManagerFunc_setManagerProperty, METH_VARARGS},
    {"setRestartCommand", (PyCFunction)Sbk_QSessionManagerFunc_setRestartCommand, METH_O},
    {"setRestartHint", (PyCFunction)Sbk_QSessionManagerFunc_setRestartHint, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSessionManager_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSessionManager_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSessionManager_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QSessionManager",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          SbkDeallocWrapperWithPrivateDtor,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QSessionManager_traverse,
    /*tp_clear*/            Sbk_QSessionManager_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSessionManager_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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

static void* Sbk_QSessionManager_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSessionManager*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QSessionManager_RestartHint_PythonToCpp_QSessionManager_RestartHint(PyObject* pyIn, void* cppOut) {
    *((::QSessionManager::RestartHint*)cppOut) = (::QSessionManager::RestartHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSessionManager_RestartHint_PythonToCpp_QSessionManager_RestartHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX]))
        return QSessionManager_RestartHint_PythonToCpp_QSessionManager_RestartHint;
    return 0;
}
static PyObject* QSessionManager_RestartHint_CppToPython_QSessionManager_RestartHint(const void* cppIn) {
    int castCppIn = *((::QSessionManager::RestartHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSessionManager_PythonToCpp_QSessionManager_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSessionManager_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSessionManager_PythonToCpp_QSessionManager_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSessionManager_Type))
        return QSessionManager_PythonToCpp_QSessionManager_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSessionManager_PTR_CppToPython_QSessionManager(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSessionManager*)cppIn, &Sbk_QSessionManager_Type);

}

void init_QSessionManager(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSessionManager_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSessionManager", "QSessionManager*",
        &Sbk_QSessionManager_Type, 0, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSessionManager_Type,
        QSessionManager_PythonToCpp_QSessionManager_PTR,
        is_QSessionManager_PythonToCpp_QSessionManager_PTR_Convertible,
        QSessionManager_PTR_CppToPython_QSessionManager);

    Shiboken::Conversions::registerConverterName(converter, "QSessionManager");
    Shiboken::Conversions::registerConverterName(converter, "QSessionManager*");
    Shiboken::Conversions::registerConverterName(converter, "QSessionManager&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSessionManager).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSessionManager_Type, &Sbk_QSessionManager_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'RestartHint'.
    SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSessionManager_Type,
        "RestartHint",
        "PySide.QtGui.QSessionManager.RestartHint",
        "QSessionManager::RestartHint");
    if (!SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX],
        &Sbk_QSessionManager_Type, "RestartIfRunning", (long) QSessionManager::RestartIfRunning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX],
        &Sbk_QSessionManager_Type, "RestartAnyway", (long) QSessionManager::RestartAnyway))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX],
        &Sbk_QSessionManager_Type, "RestartImmediately", (long) QSessionManager::RestartImmediately))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX],
        &Sbk_QSessionManager_Type, "RestartNever", (long) QSessionManager::RestartNever))
        return ;
    // Register converter for enum 'QSessionManager::RestartHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX],
            QSessionManager_RestartHint_CppToPython_QSessionManager_RestartHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSessionManager_RestartHint_PythonToCpp_QSessionManager_RestartHint,
            is_QSessionManager_RestartHint_PythonToCpp_QSessionManager_RestartHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSessionManager::RestartHint");
        Shiboken::Conversions::registerConverterName(converter, "RestartHint");
    }
    // End of 'RestartHint' enum.

    PySide::Signal::registerSignals(&Sbk_QSessionManager_Type, &::QSessionManager::staticMetaObject);

    qRegisterMetaType< ::QSessionManager::RestartHint >("QSessionManager::RestartHint");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSessionManager_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSessionManager_Type, &::QSessionManager::staticMetaObject, sizeof(::QSessionManager));
}
