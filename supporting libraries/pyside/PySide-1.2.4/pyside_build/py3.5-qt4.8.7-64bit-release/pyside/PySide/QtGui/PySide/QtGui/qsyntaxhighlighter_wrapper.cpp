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
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtgui_python.h"

#include "qsyntaxhighlighter_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcolor.h>
#include <qcoreevent.h>
#include <qfont.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsyntaxhighlighter.h>
#include <qtextdocument.h>
#include <qtextedit.h>
#include <qtextformat.h>
#include <qtextobject.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QSyntaxHighlighterWrapper::QSyntaxHighlighterWrapper(QObject * parent) : QSyntaxHighlighter(parent) {
    // ... middle
}

QSyntaxHighlighterWrapper::QSyntaxHighlighterWrapper(QTextDocument * parent) : QSyntaxHighlighter(parent) {
    // ... middle
}

QSyntaxHighlighterWrapper::QSyntaxHighlighterWrapper(QTextEdit * parent) : QSyntaxHighlighter(parent) {
    // ... middle
}

void QSyntaxHighlighterWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QSyntaxHighlighterWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSyntaxHighlighterWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QSyntaxHighlighterWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QSyntaxHighlighterWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSyntaxHighlighter.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSyntaxHighlighterWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSyntaxHighlighter.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QSyntaxHighlighterWrapper::highlightBlock(const QString & text)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "highlightBlock"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSyntaxHighlighter.highlightBlock()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &text)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSyntaxHighlighterWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

const QMetaObject* QSyntaxHighlighterWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSyntaxHighlighter::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSyntaxHighlighterWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSyntaxHighlighter::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSyntaxHighlighterWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSyntaxHighlighterWrapper* >(this));
        return QSyntaxHighlighter::qt_metacast(_clname);
}

QSyntaxHighlighterWrapper::~QSyntaxHighlighterWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSyntaxHighlighter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QSyntaxHighlighter' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSyntaxHighlighter >()))
        return -1;

    ::QSyntaxHighlighterWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSyntaxHighlighter", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSyntaxHighlighter(QObject*)
    // 1: QSyntaxHighlighter(QTextDocument*)
    // 2: QSyntaxHighlighter(QTextEdit*)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QSyntaxHighlighter(QTextEdit*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSyntaxHighlighter(QTextDocument*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSyntaxHighlighter(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighter_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSyntaxHighlighter(QObject * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSyntaxHighlighter(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSyntaxHighlighterWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSyntaxHighlighterWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QSyntaxHighlighter(QTextDocument * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextDocument* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSyntaxHighlighter(QTextDocument*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSyntaxHighlighterWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSyntaxHighlighterWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 2: // QSyntaxHighlighter(QTextEdit * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextEdit* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSyntaxHighlighter(QTextEdit*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSyntaxHighlighterWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSyntaxHighlighterWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSyntaxHighlighter >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSyntaxHighlighter_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QSyntaxHighlighter_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", "PySide.QtGui.QTextDocument", "PySide.QtGui.QTextEdit", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QSyntaxHighlighter", overloads);
        return -1;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_currentBlock(PyObject* self)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentBlock()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QSyntaxHighlighter*>(cppSelf)->currentBlock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_currentBlockState(PyObject* self)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentBlockState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSyntaxHighlighter*>(cppSelf)->currentBlockState();
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

static PyObject* Sbk_QSyntaxHighlighterFunc_currentBlockUserData(PyObject* self)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentBlockUserData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlockUserData * cppResult = const_cast<const ::QSyntaxHighlighter*>(cppSelf)->currentBlockUserData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKUSERDATA_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_document(PyObject* self)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // document()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextDocument * cppResult = const_cast<const ::QSyntaxHighlighter*>(cppSelf)->document();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], cppResult);
            Shiboken::Object::setParent(pyResult, self);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_format(PyObject* self, PyObject* pyArg)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: format(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // format(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_format_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // format(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QSyntaxHighlighter*>(cppSelf)->format(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSyntaxHighlighterFunc_format_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSyntaxHighlighter.format", overloads);
        return 0;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_highlightBlock(PyObject* self, PyObject* pyArg)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: highlightBlock(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // highlightBlock(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_highlightBlock_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // highlightBlock(QString)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSyntaxHighlighter.highlightBlock()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->highlightBlock(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSyntaxHighlighterFunc_highlightBlock_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSyntaxHighlighter.highlightBlock", overloads);
        return 0;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_previousBlockState(PyObject* self)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // previousBlockState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSyntaxHighlighter*>(cppSelf)->previousBlockState();
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

static PyObject* Sbk_QSyntaxHighlighterFunc_rehighlight(PyObject* self)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rehighlight()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->rehighlight();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_rehighlightBlock(PyObject* self, PyObject* pyArg)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rehighlightBlock(QTextBlock)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArg)))) {
        overloadId = 0; // rehighlightBlock(QTextBlock)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_rehighlightBlock_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlock cppArg0_local = ::QTextBlock();
        ::QTextBlock* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // rehighlightBlock(QTextBlock)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->rehighlightBlock(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSyntaxHighlighterFunc_rehighlightBlock_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlock", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSyntaxHighlighter.rehighlightBlock", overloads);
        return 0;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_setCurrentBlockState(PyObject* self, PyObject* pyArg)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentBlockState(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentBlockState(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_setCurrentBlockState_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentBlockState(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentBlockState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSyntaxHighlighterFunc_setCurrentBlockState_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSyntaxHighlighter.setCurrentBlockState", overloads);
        return 0;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_setCurrentBlockUserData(PyObject* self, PyObject* pyArg)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentBlockUserData(QTextBlockUserData*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKUSERDATA_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentBlockUserData(QTextBlockUserData*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_setCurrentBlockUserData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlockUserData* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentBlockUserData(QTextBlockUserData*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentBlockUserData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Ownership transferences.
            Shiboken::Object::releaseOwnership(pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSyntaxHighlighterFunc_setCurrentBlockUserData_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlockUserData", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSyntaxHighlighter.setCurrentBlockUserData", overloads);
        return 0;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_setDocument(PyObject* self, PyObject* pyArg)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocument(QTextDocument*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (pyArg)))) {
        overloadId = 0; // setDocument(QTextDocument*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_setDocument_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextDocument* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocument(QTextDocument*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocument(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSyntaxHighlighterFunc_setDocument_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextDocument", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSyntaxHighlighter.setDocument", overloads);
        return 0;
}

static PyObject* Sbk_QSyntaxHighlighterFunc_setFormat(PyObject* self, PyObject* args)
{
    ::QSyntaxHighlighter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSyntaxHighlighter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFormat", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setFormat(int,int,QColor)
    // 1: setFormat(int,int,QFont)
    // 2: setFormat(int,int,QTextCharFormat)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArgs[2])))) {
            overloadId = 2; // setFormat(int,int,QTextCharFormat)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[2])))) {
            overloadId = 1; // setFormat(int,int,QFont)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[2])))) {
            overloadId = 0; // setFormat(int,int,QColor)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSyntaxHighlighterFunc_setFormat_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setFormat(int start, int count, const QColor & color)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QColor cppArg2_local = ::QColor();
            ::QColor* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // setFormat(int,int,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFormat(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setFormat(int start, int count, const QFont & font)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QFont cppArg2_local = ::QFont();
            ::QFont* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // setFormat(int,int,QFont)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFormat(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setFormat(int start, int count, const QTextCharFormat & format)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTextCharFormat cppArg2_local = ::QTextCharFormat();
            ::QTextCharFormat* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // setFormat(int,int,QTextCharFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFormat(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSyntaxHighlighterFunc_setFormat_TypeError:
        const char* overloads[] = {"int, int, PySide.QtGui.QColor", "int, int, PySide.QtGui.QFont", "int, int, PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QSyntaxHighlighter.setFormat", overloads);
        return 0;
}

static PyMethodDef Sbk_QSyntaxHighlighter_methods[] = {
    {"currentBlock", (PyCFunction)Sbk_QSyntaxHighlighterFunc_currentBlock, METH_NOARGS},
    {"currentBlockState", (PyCFunction)Sbk_QSyntaxHighlighterFunc_currentBlockState, METH_NOARGS},
    {"currentBlockUserData", (PyCFunction)Sbk_QSyntaxHighlighterFunc_currentBlockUserData, METH_NOARGS},
    {"document", (PyCFunction)Sbk_QSyntaxHighlighterFunc_document, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QSyntaxHighlighterFunc_format, METH_O},
    {"highlightBlock", (PyCFunction)Sbk_QSyntaxHighlighterFunc_highlightBlock, METH_O},
    {"previousBlockState", (PyCFunction)Sbk_QSyntaxHighlighterFunc_previousBlockState, METH_NOARGS},
    {"rehighlight", (PyCFunction)Sbk_QSyntaxHighlighterFunc_rehighlight, METH_NOARGS},
    {"rehighlightBlock", (PyCFunction)Sbk_QSyntaxHighlighterFunc_rehighlightBlock, METH_O},
    {"setCurrentBlockState", (PyCFunction)Sbk_QSyntaxHighlighterFunc_setCurrentBlockState, METH_O},
    {"setCurrentBlockUserData", (PyCFunction)Sbk_QSyntaxHighlighterFunc_setCurrentBlockUserData, METH_O},
    {"setDocument", (PyCFunction)Sbk_QSyntaxHighlighterFunc_setDocument, METH_O},
    {"setFormat", (PyCFunction)Sbk_QSyntaxHighlighterFunc_setFormat, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSyntaxHighlighter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSyntaxHighlighter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSyntaxHighlighter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QSyntaxHighlighter",
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
    /*tp_traverse*/         Sbk_QSyntaxHighlighter_traverse,
    /*tp_clear*/            Sbk_QSyntaxHighlighter_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSyntaxHighlighter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSyntaxHighlighter_Init,
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

static void* Sbk_QSyntaxHighlighter_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSyntaxHighlighter*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSyntaxHighlighter_PythonToCpp_QSyntaxHighlighter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSyntaxHighlighter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSyntaxHighlighter_PythonToCpp_QSyntaxHighlighter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSyntaxHighlighter_Type))
        return QSyntaxHighlighter_PythonToCpp_QSyntaxHighlighter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSyntaxHighlighter_PTR_CppToPython_QSyntaxHighlighter(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSyntaxHighlighter*)cppIn, &Sbk_QSyntaxHighlighter_Type);

}

void init_QSyntaxHighlighter(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSyntaxHighlighter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSyntaxHighlighter", "QSyntaxHighlighter*",
        &Sbk_QSyntaxHighlighter_Type, &Shiboken::callCppDestructor< ::QSyntaxHighlighter >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSyntaxHighlighter_Type,
        QSyntaxHighlighter_PythonToCpp_QSyntaxHighlighter_PTR,
        is_QSyntaxHighlighter_PythonToCpp_QSyntaxHighlighter_PTR_Convertible,
        QSyntaxHighlighter_PTR_CppToPython_QSyntaxHighlighter);

    Shiboken::Conversions::registerConverterName(converter, "QSyntaxHighlighter");
    Shiboken::Conversions::registerConverterName(converter, "QSyntaxHighlighter*");
    Shiboken::Conversions::registerConverterName(converter, "QSyntaxHighlighter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSyntaxHighlighter).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSyntaxHighlighterWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSyntaxHighlighter_Type, &Sbk_QSyntaxHighlighter_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QSyntaxHighlighter_Type, &::QSyntaxHighlighter::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSyntaxHighlighter_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSyntaxHighlighter_Type, &::QSyntaxHighlighter::staticMetaObject, sizeof(::QSyntaxHighlighter));
}
