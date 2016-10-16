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

#include "qkeyevent_wrapper.h"

// Extra includes
#include <qevent.h>


// Native ---------------------------------------------------------

QKeyEventWrapper::QKeyEventWrapper(QEvent::Type type, int key, QFlags<Qt::KeyboardModifier> modifiers, const QString & text, bool autorep, ushort count) : QKeyEvent(type, key, modifiers, text, autorep, count) {
    // ... middle
}

QKeyEventWrapper::~QKeyEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QKeyEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QKeyEvent >()))
        return -1;

    ::QKeyEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent(): too many arguments");
        return -1;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:QKeyEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,QString,bool,ushort)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // QKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,QString,bool,ushort)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // QKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,QString,bool,ushort)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4])))) {
                if (numArgs == 5) {
                    overloadId = 0; // QKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,QString,bool,ushort)
                } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[5])))) {
                    overloadId = 0; // QKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,QString,bool,ushort)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeyEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "text");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent(): got multiple values for keyword argument 'text'.");
                return -1;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_QKeyEvent_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "autorep");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent(): got multiple values for keyword argument 'autorep'.");
                return -1;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4]))))
                    goto Sbk_QKeyEvent_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "count");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent(): got multiple values for keyword argument 'count'.");
                return -1;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[5]))))
                    goto Sbk_QKeyEvent_Init_TypeError;
            }
        }
        ::QEvent::Type cppArg0 = ((::QEvent::Type)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QString();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        bool cppArg4 = false;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        ushort cppArg5 = 1;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // QKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,QString,bool,ushort)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QKeyEventWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QKeyEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QKeyEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QKeyEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type, int, PySide.QtCore.Qt.KeyboardModifiers, unicode = QString(), bool = false, unsigned short = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QKeyEvent", overloads);
        return -1;
}

static PyObject* Sbk_QKeyEventFunc_count(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->count();
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

static PyObject* Sbk_QKeyEventFunc_createExtendedKeyEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 9) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent.createExtendedKeyEvent(): too many arguments");
        return 0;
    } else if (numArgs < 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent.createExtendedKeyEvent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOOO:createExtendedKeyEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return 0;


    // Overloaded function decisor
    // 0: createExtendedKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,quint32,quint32,quint32,QString,bool,ushort)
    if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 0; // createExtendedKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,quint32,quint32,quint32,QString,bool,ushort)
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[6])))) {
            if (numArgs == 7) {
                overloadId = 0; // createExtendedKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,quint32,quint32,quint32,QString,bool,ushort)
            } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[7])))) {
                if (numArgs == 8) {
                    overloadId = 0; // createExtendedKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,quint32,quint32,quint32,QString,bool,ushort)
                } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[8])))) {
                    overloadId = 0; // createExtendedKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,quint32,quint32,quint32,QString,bool,ushort)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeyEventFunc_createExtendedKeyEvent_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "text");
            if (value && pyArgs[6]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent.createExtendedKeyEvent(): got multiple values for keyword argument 'text'.");
                return 0;
            } else if (value) {
                pyArgs[6] = value;
                if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[6]))))
                    goto Sbk_QKeyEventFunc_createExtendedKeyEvent_TypeError;
            }
            value = PyDict_GetItemString(kwds, "autorep");
            if (value && pyArgs[7]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent.createExtendedKeyEvent(): got multiple values for keyword argument 'autorep'.");
                return 0;
            } else if (value) {
                pyArgs[7] = value;
                if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[7]))))
                    goto Sbk_QKeyEventFunc_createExtendedKeyEvent_TypeError;
            }
            value = PyDict_GetItemString(kwds, "count");
            if (value && pyArgs[8]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeyEvent.createExtendedKeyEvent(): got multiple values for keyword argument 'count'.");
                return 0;
            } else if (value) {
                pyArgs[8] = value;
                if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[8]))))
                    goto Sbk_QKeyEventFunc_createExtendedKeyEvent_TypeError;
            }
        }
        ::QEvent::Type cppArg0 = ((::QEvent::Type)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        quint32 cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        quint32 cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        quint32 cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        ::QString cppArg6 = QString();
        if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
        bool cppArg7 = false;
        if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
        ushort cppArg8 = 1;
        if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);

        if (!PyErr_Occurred()) {
            // createExtendedKeyEvent(QEvent::Type,int,QFlags<Qt::KeyboardModifier>,quint32,quint32,quint32,QString,bool,ushort)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QKeyEvent * cppResult = ::QKeyEvent::createExtendedKeyEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeyEventFunc_createExtendedKeyEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type, int, PySide.QtCore.Qt.KeyboardModifiers, unsigned int, unsigned int, unsigned int, unicode = QString(), bool = false, unsigned short = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QKeyEvent.createExtendedKeyEvent", overloads);
        return 0;
}

static PyObject* Sbk_QKeyEventFunc_hasExtendedInfo(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasExtendedInfo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->hasExtendedInfo();
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

static PyObject* Sbk_QKeyEventFunc_isAutoRepeat(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAutoRepeat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->isAutoRepeat();
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

static PyObject* Sbk_QKeyEventFunc_key(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // key()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->key();
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

static PyObject* Sbk_QKeyEventFunc_matches(PyObject* self, PyObject* pyArg)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: matches(QKeySequence::StandardKey)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArg)))) {
        overloadId = 0; // matches(QKeySequence::StandardKey)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeyEventFunc_matches_TypeError;

    // Call function/method
    {
        ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // matches(QKeySequence::StandardKey)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->matches(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeyEventFunc_matches_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence.StandardKey", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeyEvent.matches", overloads);
        return 0;
}

static PyObject* Sbk_QKeyEventFunc_modifiers(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // modifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->modifiers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QKeyEventFunc_nativeModifiers(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nativeModifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint32 cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->nativeModifiers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QKeyEventFunc_nativeScanCode(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nativeScanCode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint32 cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->nativeScanCode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QKeyEventFunc_nativeVirtualKey(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nativeVirtualKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint32 cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->nativeVirtualKey();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QKeyEventFunc_text(PyObject* self)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QKeyEvent*>(cppSelf)->text();
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

static PyMethodDef Sbk_QKeyEvent_methods[] = {
    {"count", (PyCFunction)Sbk_QKeyEventFunc_count, METH_NOARGS},
    {"createExtendedKeyEvent", (PyCFunction)Sbk_QKeyEventFunc_createExtendedKeyEvent, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"hasExtendedInfo", (PyCFunction)Sbk_QKeyEventFunc_hasExtendedInfo, METH_NOARGS},
    {"isAutoRepeat", (PyCFunction)Sbk_QKeyEventFunc_isAutoRepeat, METH_NOARGS},
    {"key", (PyCFunction)Sbk_QKeyEventFunc_key, METH_NOARGS},
    {"matches", (PyCFunction)Sbk_QKeyEventFunc_matches, METH_O},
    {"modifiers", (PyCFunction)Sbk_QKeyEventFunc_modifiers, METH_NOARGS},
    {"nativeModifiers", (PyCFunction)Sbk_QKeyEventFunc_nativeModifiers, METH_NOARGS},
    {"nativeScanCode", (PyCFunction)Sbk_QKeyEventFunc_nativeScanCode, METH_NOARGS},
    {"nativeVirtualKey", (PyCFunction)Sbk_QKeyEventFunc_nativeVirtualKey, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QKeyEventFunc_text, METH_NOARGS},

    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QKeyEvent_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QKeyEvent& cppSelf = *(((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArg)))) {
                // operator!=(QKeySequence::StandardKey arg__1)
                ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
                pythonToCpp(pyArg, &cppArg0);
                SBK_UNUSED(cppArg0)
                // Begin code injection

                bool ret = !(&cppSelf == cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ret);

                // End of code injection
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArg)))) {
                // operator==(QKeySequence::StandardKey key)
                ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = &cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArg)))) {
                // operator==(QKeySequence::StandardKey key)
                ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = &cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QKeyEvent_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QKeyEvent_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

static PyObject* Sbk_QKeyEvent_get_autor(PyObject* self, void*)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    uint cppOut_local = cppSelf->autor;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QKeyEvent_set_autor(PyObject* self, PyObject* pyIn, void*)
{
    ::QKeyEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeyEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'autor' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'autor', 'uint' or convertible type expected");
        return -1;
    }

    uint cppOut_local = cppSelf->autor;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->autor = cppOut_local;

    return 0;
}

// Getters and Setters for QKeyEvent
static PyGetSetDef Sbk_QKeyEvent_getsetlist[] = {
    {const_cast<char*>("autor"), Sbk_QKeyEvent_get_autor, Sbk_QKeyEvent_set_autor},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QKeyEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QKeyEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QKeyEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QKeyEvent",
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
    /*tp_traverse*/         Sbk_QKeyEvent_traverse,
    /*tp_clear*/            Sbk_QKeyEvent_clear,
    /*tp_richcompare*/      Sbk_QKeyEvent_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QKeyEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QKeyEvent_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QKeyEvent_Init,
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

static void* Sbk_QKeyEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QKeyEvent*>(cptr)->type() == QEvent::KeyPress ||  reinterpret_cast< ::QKeyEvent*>(cptr)->type() == QEvent::KeyRelease ||  reinterpret_cast< ::QKeyEvent*>(cptr)->type() == QEvent::ShortcutOverride)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QKeyEvent_PythonToCpp_QKeyEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QKeyEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QKeyEvent_PythonToCpp_QKeyEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QKeyEvent_Type))
        return QKeyEvent_PythonToCpp_QKeyEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QKeyEvent_PTR_CppToPython_QKeyEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QKeyEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QKeyEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QKeyEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QKeyEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QKeyEvent", "QKeyEvent*",
        &Sbk_QKeyEvent_Type, &Shiboken::callCppDestructor< ::QKeyEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QKeyEvent_Type,
        QKeyEvent_PythonToCpp_QKeyEvent_PTR,
        is_QKeyEvent_PythonToCpp_QKeyEvent_PTR_Convertible,
        QKeyEvent_PTR_CppToPython_QKeyEvent);

    Shiboken::Conversions::registerConverterName(converter, "QKeyEvent");
    Shiboken::Conversions::registerConverterName(converter, "QKeyEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QKeyEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QKeyEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QKeyEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QKeyEvent_Type, &Sbk_QKeyEvent_typeDiscovery);


}
