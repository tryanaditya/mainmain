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
#include "pyside_qtdeclarative_python.h"

#include "qdeclarativeproperty_wrapper.h"

// Extra includes
#include <qdeclarativecontext.h>
#include <qdeclarativeengine.h>
#include <qdeclarativeproperty.h>
#include <qmetaobject.h>
#include <qobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeProperty_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeProperty >()))
        return -1;

    ::QDeclarativeProperty* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDeclarativeProperty", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QDeclarativeProperty()
    // 1: QDeclarativeProperty(QObject*)
    // 2: QDeclarativeProperty(QObject*,QDeclarativeContext*)
    // 3: QDeclarativeProperty(QObject*,QDeclarativeEngine*)
    // 4: QDeclarativeProperty(QObject*,QString)
    // 5: QDeclarativeProperty(QObject*,QString,QDeclarativeContext*)
    // 6: QDeclarativeProperty(QObject*,QString,QDeclarativeEngine*)
    // 7: QDeclarativeProperty(QDeclarativeProperty)
    if (numArgs == 0) {
        overloadId = 0; // QDeclarativeProperty()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QDeclarativeProperty(QObject*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], (pyArgs[1])))) {
            overloadId = 3; // QDeclarativeProperty(QObject*,QDeclarativeEngine*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[1])))) {
            overloadId = 2; // QDeclarativeProperty(QObject*,QDeclarativeContext*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 4; // QDeclarativeProperty(QObject*,QString)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], (pyArgs[2])))) {
                overloadId = 6; // QDeclarativeProperty(QObject*,QString,QDeclarativeEngine*)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[2])))) {
                overloadId = 5; // QDeclarativeProperty(QObject*,QString,QDeclarativeContext*)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (pyArgs[0])))) {
        overloadId = 7; // QDeclarativeProperty(QDeclarativeProperty)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeProperty_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDeclarativeProperty()
        {

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDeclarativeProperty(QObject * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QObject*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDeclarativeProperty(QObject * arg__1, QDeclarativeContext * arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QDeclarativeContext* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QObject*,QDeclarativeContext*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QDeclarativeProperty(QObject * arg__1, QDeclarativeEngine * arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QDeclarativeEngine* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QObject*,QDeclarativeEngine*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QDeclarativeProperty(QObject * arg__1, const QString & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QObject*,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QDeclarativeProperty(QObject * arg__1, const QString & arg__2, QDeclarativeContext * arg__3)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QDeclarativeContext* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QObject*,QString,QDeclarativeContext*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QDeclarativeProperty(QObject * arg__1, const QString & arg__2, QDeclarativeEngine * arg__3)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QDeclarativeEngine* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QObject*,QString,QDeclarativeEngine*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QDeclarativeProperty(const QDeclarativeProperty & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeProperty cppArg0_local = ::QDeclarativeProperty();
            ::QDeclarativeProperty* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDeclarativeProperty(QDeclarativeProperty)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeProperty(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeProperty >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDeclarativeProperty_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDeclarativeProperty_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject", "PySide.QtCore.QObject, PySide.QtDeclarative.QDeclarativeContext", "PySide.QtCore.QObject, PySide.QtDeclarative.QDeclarativeEngine", "PySide.QtCore.QObject, unicode", "PySide.QtCore.QObject, unicode, PySide.QtDeclarative.QDeclarativeContext", "PySide.QtCore.QObject, unicode, PySide.QtDeclarative.QDeclarativeEngine", "PySide.QtDeclarative.QDeclarativeProperty", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeProperty", overloads);
        return -1;
}

static PyObject* Sbk_QDeclarativePropertyFunc_connectNotifySignal(PyObject* self, PyObject* args)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "connectNotifySignal", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: connectNotifySignal(QObject*,const char*)const
    // 1: connectNotifySignal(QObject*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // connectNotifySignal(QObject*,int)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // connectNotifySignal(QObject*,const char*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativePropertyFunc_connectNotifySignal_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // connectNotifySignal(QObject * dest, const char * slot) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // connectNotifySignal(QObject*,const char*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->connectNotifySignal(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // connectNotifySignal(QObject * dest, int method) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // connectNotifySignal(QObject*,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->connectNotifySignal(cppArg0, cppArg1);
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

    Sbk_QDeclarativePropertyFunc_connectNotifySignal_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, " SBK_STR_NAME "", "PySide.QtCore.QObject, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeProperty.connectNotifySignal", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativePropertyFunc_hasNotifySignal(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasNotifySignal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->hasNotifySignal();
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

static PyObject* Sbk_QDeclarativePropertyFunc_index(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // index()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->index();
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

static PyObject* Sbk_QDeclarativePropertyFunc_isDesignable(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDesignable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->isDesignable();
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

static PyObject* Sbk_QDeclarativePropertyFunc_isProperty(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isProperty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->isProperty();
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

static PyObject* Sbk_QDeclarativePropertyFunc_isResettable(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isResettable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->isResettable();
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

static PyObject* Sbk_QDeclarativePropertyFunc_isSignalProperty(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSignalProperty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->isSignalProperty();
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

static PyObject* Sbk_QDeclarativePropertyFunc_isValid(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->isValid();
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

static PyObject* Sbk_QDeclarativePropertyFunc_isWritable(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWritable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->isWritable();
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

static PyObject* Sbk_QDeclarativePropertyFunc_method(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // method()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaMethod cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->method();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativePropertyFunc_name(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->name();
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

static PyObject* Sbk_QDeclarativePropertyFunc_needsNotifySignal(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // needsNotifySignal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->needsNotifySignal();
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

static PyObject* Sbk_QDeclarativePropertyFunc_object(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // object()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->object();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativePropertyFunc_property(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // property()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaProperty cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->property();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativePropertyFunc_propertyType(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->propertyType();
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

static PyObject* Sbk_QDeclarativePropertyFunc_propertyTypeCategory(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyTypeCategory()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeProperty::PropertyTypeCategory cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->propertyTypeCategory();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativePropertyFunc_propertyTypeName(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyTypeName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->propertyTypeName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativePropertyFunc_read(PyObject* self, PyObject* args)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QDeclarativePropertyFunc_read_TypeError;

    if (!PyArg_UnpackTuple(args, "read", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: read()const
    // 1: read(QObject*,QString)
    // 2: read(QObject*,QString,QDeclarativeContext*)
    // 3: read(QObject*,QString,QDeclarativeEngine*)
    if (numArgs == 0) {
        overloadId = 0; // read()const
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // read(QObject*,QString)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], (pyArgs[2])))) {
            overloadId = 3; // read(QObject*,QString,QDeclarativeEngine*)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[2])))) {
            overloadId = 2; // read(QObject*,QString,QDeclarativeContext*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativePropertyFunc_read_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // read() const
        {

            if (!PyErr_Occurred()) {
                // read()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->read();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
        case 1: // read(QObject * arg__1, const QString & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // read(QObject*,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = ::QDeclarativeProperty::read(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
        case 2: // read(QObject * arg__1, const QString & arg__2, QDeclarativeContext * arg__3)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QDeclarativeContext* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // read(QObject*,QString,QDeclarativeContext*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = ::QDeclarativeProperty::read(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
        case 3: // read(QObject * arg__1, const QString & arg__2, QDeclarativeEngine * arg__3)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QDeclarativeEngine* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // read(QObject*,QString,QDeclarativeEngine*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = ::QDeclarativeProperty::read(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDeclarativePropertyFunc_read_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject, unicode", "PySide.QtCore.QObject, unicode, PySide.QtDeclarative.QDeclarativeContext", "PySide.QtCore.QObject, unicode, PySide.QtDeclarative.QDeclarativeEngine", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeProperty.read", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativePropertyFunc_reset(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->reset();
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

static PyObject* Sbk_QDeclarativePropertyFunc_type(PyObject* self)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeProperty::Type cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativePropertyFunc_write(PyObject* self, PyObject* args)
{
    ::QDeclarativeProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QDeclarativePropertyFunc_write_TypeError;

    if (!PyArg_UnpackTuple(args, "write", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: write(QObject*,QString,QVariant)
    // 1: write(QObject*,QString,QVariant,QDeclarativeContext*)
    // 2: write(QObject*,QString,QVariant,QDeclarativeEngine*)
    // 3: write(QVariant)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // write(QObject*,QString,QVariant)
        } else if (numArgs == 4
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], (pyArgs[3])))) {
            overloadId = 2; // write(QObject*,QString,QVariant,QDeclarativeEngine*)
        } else if (numArgs == 4
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[3])))) {
            overloadId = 1; // write(QObject*,QString,QVariant,QDeclarativeContext*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        overloadId = 3; // write(QVariant)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativePropertyFunc_write_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // write(QObject * arg__1, const QString & arg__2, const QVariant & arg__3)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QVariant cppArg2 = ::QVariant();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // write(QObject*,QString,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QDeclarativeProperty::write(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // write(QObject * arg__1, const QString & arg__2, const QVariant & arg__3, QDeclarativeContext * arg__4)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QVariant cppArg2 = ::QVariant();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QDeclarativeContext* cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // write(QObject*,QString,QVariant,QDeclarativeContext*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QDeclarativeProperty::write(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // write(QObject * arg__1, const QString & arg__2, const QVariant & arg__3, QDeclarativeEngine * arg__4)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QVariant cppArg2 = ::QVariant();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QDeclarativeEngine* cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // write(QObject*,QString,QVariant,QDeclarativeEngine*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QDeclarativeProperty::write(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 3: // write(const QVariant & arg__1) const
        {
            ::QVariant cppArg0 = ::QVariant();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // write(QVariant)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QDeclarativeProperty*>(cppSelf)->write(cppArg0);
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

    Sbk_QDeclarativePropertyFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, unicode, QVariant", "PySide.QtCore.QObject, unicode, QVariant, PySide.QtDeclarative.QDeclarativeContext", "PySide.QtCore.QObject, unicode, QVariant, PySide.QtDeclarative.QDeclarativeEngine", "QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeProperty.write", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeProperty___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDeclarativeProperty& cppSelf = *(((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDeclarativePropertyMethod_read = {
    "read", (PyCFunction)Sbk_QDeclarativePropertyFunc_read, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QDeclarativePropertyMethod_write = {
    "write", (PyCFunction)Sbk_QDeclarativePropertyFunc_write, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QDeclarativeProperty_methods[] = {
    {"connectNotifySignal", (PyCFunction)Sbk_QDeclarativePropertyFunc_connectNotifySignal, METH_VARARGS},
    {"hasNotifySignal", (PyCFunction)Sbk_QDeclarativePropertyFunc_hasNotifySignal, METH_NOARGS},
    {"index", (PyCFunction)Sbk_QDeclarativePropertyFunc_index, METH_NOARGS},
    {"isDesignable", (PyCFunction)Sbk_QDeclarativePropertyFunc_isDesignable, METH_NOARGS},
    {"isProperty", (PyCFunction)Sbk_QDeclarativePropertyFunc_isProperty, METH_NOARGS},
    {"isResettable", (PyCFunction)Sbk_QDeclarativePropertyFunc_isResettable, METH_NOARGS},
    {"isSignalProperty", (PyCFunction)Sbk_QDeclarativePropertyFunc_isSignalProperty, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QDeclarativePropertyFunc_isValid, METH_NOARGS},
    {"isWritable", (PyCFunction)Sbk_QDeclarativePropertyFunc_isWritable, METH_NOARGS},
    {"method", (PyCFunction)Sbk_QDeclarativePropertyFunc_method, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QDeclarativePropertyFunc_name, METH_NOARGS},
    {"needsNotifySignal", (PyCFunction)Sbk_QDeclarativePropertyFunc_needsNotifySignal, METH_NOARGS},
    {"object", (PyCFunction)Sbk_QDeclarativePropertyFunc_object, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QDeclarativePropertyFunc_property, METH_NOARGS},
    {"propertyType", (PyCFunction)Sbk_QDeclarativePropertyFunc_propertyType, METH_NOARGS},
    {"propertyTypeCategory", (PyCFunction)Sbk_QDeclarativePropertyFunc_propertyTypeCategory, METH_NOARGS},
    {"propertyTypeName", (PyCFunction)Sbk_QDeclarativePropertyFunc_propertyTypeName, METH_NOARGS},
    Sbk_QDeclarativePropertyMethod_read,
    {"reset", (PyCFunction)Sbk_QDeclarativePropertyFunc_reset, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QDeclarativePropertyFunc_type, METH_NOARGS},
    Sbk_QDeclarativePropertyMethod_write,

    {"__copy__", (PyCFunction)Sbk_QDeclarativeProperty___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QDeclarativeProperty_getattro(PyObject* self, PyObject* name)
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
        static PyMethodDef non_static_Sbk_QDeclarativePropertyMethod_read = {
            Sbk_QDeclarativePropertyMethod_read.ml_name,
            Sbk_QDeclarativePropertyMethod_read.ml_meth,
            Sbk_QDeclarativePropertyMethod_read.ml_flags & (~METH_STATIC),
            Sbk_QDeclarativePropertyMethod_read.ml_doc,
        };
        if (Shiboken::String::compare(name, "read") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QDeclarativePropertyMethod_read, self, 0);
        static PyMethodDef non_static_Sbk_QDeclarativePropertyMethod_write = {
            Sbk_QDeclarativePropertyMethod_write.ml_name,
            Sbk_QDeclarativePropertyMethod_write.ml_meth,
            Sbk_QDeclarativePropertyMethod_write.ml_flags & (~METH_STATIC),
            Sbk_QDeclarativePropertyMethod_write.ml_doc,
        };
        if (Shiboken::String::compare(name, "write") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QDeclarativePropertyMethod_write, self, 0);
    }
    return PyObject_GenericGetAttr(self, name);
}

// Rich comparison
static PyObject* Sbk_QDeclarativeProperty_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDeclarativeProperty& cppSelf = *(((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (pyArg)))) {
                // operator==(const QDeclarativeProperty & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDeclarativeProperty cppArg0_local = ::QDeclarativeProperty();
                ::QDeclarativeProperty* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], pythonToCpp))
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
            goto Sbk_QDeclarativeProperty_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDeclarativeProperty_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QDeclarativeProperty_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeProperty_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDeclarativeProperty_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeProperty",
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
    /*tp_getattro*/         Sbk_QDeclarativeProperty_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QDeclarativeProperty_traverse,
    /*tp_clear*/            Sbk_QDeclarativeProperty_clear,
    /*tp_richcompare*/      Sbk_QDeclarativeProperty_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeProperty_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeProperty_Init,
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
static void QDeclarativeProperty_PropertyTypeCategory_PythonToCpp_QDeclarativeProperty_PropertyTypeCategory(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeProperty::PropertyTypeCategory*)cppOut) = (::QDeclarativeProperty::PropertyTypeCategory) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDeclarativeProperty_PropertyTypeCategory_PythonToCpp_QDeclarativeProperty_PropertyTypeCategory_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX]))
        return QDeclarativeProperty_PropertyTypeCategory_PythonToCpp_QDeclarativeProperty_PropertyTypeCategory;
    return 0;
}
static PyObject* QDeclarativeProperty_PropertyTypeCategory_CppToPython_QDeclarativeProperty_PropertyTypeCategory(const void* cppIn) {
    int castCppIn = *((::QDeclarativeProperty::PropertyTypeCategory*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX], castCppIn);

}

static void QDeclarativeProperty_Type_PythonToCpp_QDeclarativeProperty_Type(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeProperty::Type*)cppOut) = (::QDeclarativeProperty::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDeclarativeProperty_Type_PythonToCpp_QDeclarativeProperty_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX]))
        return QDeclarativeProperty_Type_PythonToCpp_QDeclarativeProperty_Type;
    return 0;
}
static PyObject* QDeclarativeProperty_Type_CppToPython_QDeclarativeProperty_Type(const void* cppIn) {
    int castCppIn = *((::QDeclarativeProperty::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeProperty_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeProperty_Type))
        return QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeProperty_PTR_CppToPython_QDeclarativeProperty(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDeclarativeProperty*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDeclarativeProperty_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDeclarativeProperty_COPY_CppToPython_QDeclarativeProperty(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDeclarativeProperty_Type, new ::QDeclarativeProperty(*((::QDeclarativeProperty*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeProperty*)cppOut) = *((::QDeclarativeProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeProperty_Type))
        return QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_QObjectPTR_PythonToCpp_QDeclarativeProperty(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeProperty*)cppOut) = ::QDeclarativeProperty(((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_QObjectPTR_PythonToCpp_QDeclarativeProperty_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyIn))
        return PySide_QtCore_QObjectPTR_PythonToCpp_QDeclarativeProperty;
    return 0;
}

void init_QDeclarativeProperty(PyObject* module)
{
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeProperty_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeProperty", "QDeclarativeProperty",
        &Sbk_QDeclarativeProperty_Type, &Shiboken::callCppDestructor< ::QDeclarativeProperty >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeProperty_Type,
        QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_PTR,
        is_QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_PTR_Convertible,
        QDeclarativeProperty_PTR_CppToPython_QDeclarativeProperty,
        QDeclarativeProperty_COPY_CppToPython_QDeclarativeProperty);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeProperty");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeProperty*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeProperty&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeProperty).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_COPY,
        is_QDeclarativeProperty_PythonToCpp_QDeclarativeProperty_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_QObjectPTR_PythonToCpp_QDeclarativeProperty,
        is_PySide_QtCore_QObjectPTR_PythonToCpp_QDeclarativeProperty_Convertible);

    // Initialization of enums.

    // Initialization of enum 'PropertyTypeCategory'.
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDeclarativeProperty_Type,
        "PropertyTypeCategory",
        "PySide.QtDeclarative.QDeclarativeProperty.PropertyTypeCategory",
        "QDeclarativeProperty::PropertyTypeCategory");
    if (!SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX],
        &Sbk_QDeclarativeProperty_Type, "InvalidCategory", (long) QDeclarativeProperty::InvalidCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX],
        &Sbk_QDeclarativeProperty_Type, "List", (long) QDeclarativeProperty::List))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX],
        &Sbk_QDeclarativeProperty_Type, "Object", (long) QDeclarativeProperty::Object))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX],
        &Sbk_QDeclarativeProperty_Type, "Normal", (long) QDeclarativeProperty::Normal))
        return ;
    // Register converter for enum 'QDeclarativeProperty::PropertyTypeCategory'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX],
            QDeclarativeProperty_PropertyTypeCategory_CppToPython_QDeclarativeProperty_PropertyTypeCategory);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDeclarativeProperty_PropertyTypeCategory_PythonToCpp_QDeclarativeProperty_PropertyTypeCategory,
            is_QDeclarativeProperty_PropertyTypeCategory_PythonToCpp_QDeclarativeProperty_PropertyTypeCategory_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_PROPERTYTYPECATEGORY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDeclarativeProperty::PropertyTypeCategory");
        Shiboken::Conversions::registerConverterName(converter, "PropertyTypeCategory");
    }
    // End of 'PropertyTypeCategory' enum.

    // Initialization of enum 'Type'.
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDeclarativeProperty_Type,
        "Type",
        "PySide.QtDeclarative.QDeclarativeProperty.Type",
        "QDeclarativeProperty::Type");
    if (!SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX],
        &Sbk_QDeclarativeProperty_Type, "Invalid", (long) QDeclarativeProperty::Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX],
        &Sbk_QDeclarativeProperty_Type, "Property", (long) QDeclarativeProperty::Property))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX],
        &Sbk_QDeclarativeProperty_Type, "SignalProperty", (long) QDeclarativeProperty::SignalProperty))
        return ;
    // Register converter for enum 'QDeclarativeProperty::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX],
            QDeclarativeProperty_Type_CppToPython_QDeclarativeProperty_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDeclarativeProperty_Type_PythonToCpp_QDeclarativeProperty_Type,
            is_QDeclarativeProperty_Type_PythonToCpp_QDeclarativeProperty_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEPROPERTY_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDeclarativeProperty::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.


    qRegisterMetaType< ::QDeclarativeProperty >("QDeclarativeProperty");
    qRegisterMetaType< ::QDeclarativeProperty::PropertyTypeCategory >("QDeclarativeProperty::PropertyTypeCategory");
    qRegisterMetaType< ::QDeclarativeProperty::Type >("QDeclarativeProperty::Type");
}
