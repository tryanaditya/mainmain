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

#include "qtextdocument_wrapper.h"

// Extra includes
#include <QList>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextFormat>
#include <QVector>
#include <qabstracttextdocumentlayout.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qfont.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <qprinter.h>
#include <qrect.h>
#include <qregexp.h>
#include <qsize.h>
#include <qtextcursor.h>
#include <qtextdocument.h>
#include <qtextformat.h>
#include <qtextobject.h>
#include <qtextoption.h>
#include <qthread.h>
#include <qurl.h>


// Native ---------------------------------------------------------

QTextDocumentWrapper::QTextDocumentWrapper(QObject * parent) : QTextDocument(parent) {
    // ... middle
}

QTextDocumentWrapper::QTextDocumentWrapper(const QString & text, QObject * parent) : QTextDocument(text, parent) {
    // ... middle
}

void QTextDocumentWrapper::childEvent(QChildEvent * arg__1)
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

void QTextDocumentWrapper::clear()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clear"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTextDocument::clear();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QTextDocumentWrapper::connectNotify(const char * signal)
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

QTextObject * QTextDocumentWrapper::createObject(const QTextFormat & f)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QTextObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createObject"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTextDocument::createObject(f);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], &f)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QTextObject*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOBJECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextDocument.createObject", Shiboken::SbkType< QTextObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QTextObject*)0);
    }
    ::QTextObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QTextDocumentWrapper::customEvent(QEvent * arg__1)
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

void QTextDocumentWrapper::disconnectNotify(const char * signal)
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

bool QTextDocumentWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextDocument.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QTextDocumentWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextDocument.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QVariant QTextDocumentWrapper::loadResource(int type, const QUrl & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "loadResource"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTextDocument::loadResource(type, name);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iN)",
        type,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextDocument.loadResource", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QTextDocumentWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QTextDocumentWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QTextDocument::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QTextDocumentWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QTextDocument::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QTextDocumentWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QTextDocumentWrapper* >(this));
        return QTextDocument::qt_metacast(_clname);
}

QTextDocumentWrapper::~QTextDocumentWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextDocument_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextDocument >()))
        return -1;

    ::QTextDocumentWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QTextDocument", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTextDocument(QObject*)
    // 1: QTextDocument(QString,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QTextDocument(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QTextDocument(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QTextDocument(QString,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // QTextDocument(QString,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocument_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextDocument(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QTextDocument_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextDocument(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QTextDocumentWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QTextDocumentWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QTextDocument(const QString & text, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QTextDocument_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTextDocument(QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QTextDocumentWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QTextDocumentWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextDocument >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextDocument_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QTextDocument_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "unicode, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument", overloads);
        return -1;
}

static PyObject* Sbk_QTextDocumentFunc_addResource(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addResource", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addResource(int,QUrl,QVariant)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[2])))) {
        overloadId = 0; // addResource(int,QUrl,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_addResource_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = ::QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        ::QVariant cppArg2 = ::QVariant();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addResource(int,QUrl,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addResource(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_addResource_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QUrl, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.addResource", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_adjustSize(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // adjustSize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->adjustSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextDocumentFunc_allFormats(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allFormats()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QTextFormat > cppResult = const_cast<const ::QTextDocument*>(cppSelf)->allFormats();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_availableRedoSteps(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableRedoSteps()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->availableRedoSteps();
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

static PyObject* Sbk_QTextDocumentFunc_availableUndoSteps(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableUndoSteps()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->availableUndoSteps();
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

static PyObject* Sbk_QTextDocumentFunc_begin(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // begin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->begin();
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

static PyObject* Sbk_QTextDocumentFunc_blockCount(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->blockCount();
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

static PyObject* Sbk_QTextDocumentFunc_characterAt(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: characterAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // characterAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_characterAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // characterAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QTextDocument*>(cppSelf)->characterAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_characterAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.characterAt", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_characterCount(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // characterCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->characterCount();
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

static PyObject* Sbk_QTextDocumentFunc_clear(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTextDocument::clear() : cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextDocumentFunc_clearUndoRedoStacks(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.clearUndoRedoStacks(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:clearUndoRedoStacks", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: clearUndoRedoStacks(QTextDocument::Stacks)
    if (numArgs == 0) {
        overloadId = 0; // clearUndoRedoStacks(QTextDocument::Stacks)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX]), (pyArgs[0])))) {
        overloadId = 0; // clearUndoRedoStacks(QTextDocument::Stacks)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_clearUndoRedoStacks_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "historyToClear");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.clearUndoRedoStacks(): got multiple values for keyword argument 'historyToClear'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX]), (pyArgs[0]))))
                    goto Sbk_QTextDocumentFunc_clearUndoRedoStacks_TypeError;
            }
        }
        ::QTextDocument::Stacks cppArg0 = QTextDocument::UndoAndRedoStacks;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // clearUndoRedoStacks(QTextDocument::Stacks)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearUndoRedoStacks(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_clearUndoRedoStacks_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextDocument.Stacks = UndoAndRedoStacks", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.clearUndoRedoStacks", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_clone(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.clone(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:clone", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: clone(QObject*)const
    if (numArgs == 0) {
        overloadId = 0; // clone(QObject*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // clone(QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_clone_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.clone(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QTextDocumentFunc_clone_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // clone(QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextDocument * cppResult = const_cast<const ::QTextDocument*>(cppSelf)->clone(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_clone_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.clone", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_createObject(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createObject(QTextFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // createObject(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_createObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextFormat cppArg0_local = ::QTextFormat();
        ::QTextFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // createObject(QTextFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextObject * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTextDocument::createObject(*cppArg0) : cppSelf->createObject(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_createObject_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.createObject", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_defaultCursorMoveStyle(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultCursorMoveStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CursorMoveStyle cppResult = const_cast<const ::QTextDocument*>(cppSelf)->defaultCursorMoveStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_defaultFont(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultFont()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QTextDocument*>(cppSelf)->defaultFont();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_defaultStyleSheet(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultStyleSheet()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextDocument*>(cppSelf)->defaultStyleSheet();
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

static PyObject* Sbk_QTextDocumentFunc_defaultTextOption(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultTextOption()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextOption cppResult = const_cast<const ::QTextDocument*>(cppSelf)->defaultTextOption();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_documentLayout(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentLayout()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractTextDocumentLayout * cppResult = const_cast<const ::QTextDocument*>(cppSelf)->documentLayout();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_documentMargin(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextDocument*>(cppSelf)->documentMargin();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_drawContents(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.drawContents(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.drawContents(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:drawContents", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawContents(QPainter*,QRectF)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // drawContents(QPainter*,QRectF)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            overloadId = 0; // drawContents(QPainter*,QRectF)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_drawContents_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "rect");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.drawContents(): got multiple values for keyword argument 'rect'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1]))))
                    goto Sbk_QTextDocumentFunc_drawContents_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRectF cppArg1_local = QRectF();
        ::QRectF* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // drawContents(QPainter*,QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->drawContents(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_drawContents_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF = QRectF()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.drawContents", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_end(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // end()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->end();
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

static PyObject* Sbk_QTextDocumentFunc_find(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:find", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: find(QRegExp,QTextCursor,QFlags<QTextDocument::FindFlag>)const
    // 1: find(QRegExp,int,QFlags<QTextDocument::FindFlag>)const
    // 2: find(QString,QTextCursor,QFlags<QTextDocument::FindFlag>)const
    // 3: find(QString,int,QFlags<QTextDocument::FindFlag>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // find(QString,int,QFlags<QTextDocument::FindFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // find(QString,int,QFlags<QTextDocument::FindFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 3; // find(QString,int,QFlags<QTextDocument::FindFlag>)const
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // find(QString,QTextCursor,QFlags<QTextDocument::FindFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 2; // find(QString,QTextCursor,QFlags<QTextDocument::FindFlag>)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // find(QRegExp,int,QFlags<QTextDocument::FindFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // find(QRegExp,int,QFlags<QTextDocument::FindFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // find(QRegExp,int,QFlags<QTextDocument::FindFlag>)const
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // find(QRegExp,QTextCursor,QFlags<QTextDocument::FindFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 0; // find(QRegExp,QTextCursor,QFlags<QTextDocument::FindFlag>)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_find_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // find(const QRegExp & expr, const QTextCursor & from, QFlags<QTextDocument::FindFlag> options) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "options");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): got multiple values for keyword argument 'options'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QTextDocumentFunc_find_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRegExp cppArg0_local = ::QRegExp();
            ::QRegExp* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextCursor cppArg1_local = ::QTextCursor();
            ::QTextCursor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QFlags<QTextDocument::FindFlag> cppArg2 = QFlags<QTextDocument::FindFlag>(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // find(QRegExp,QTextCursor,QFlags<QTextDocument::FindFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCursor cppResult = const_cast<const ::QTextDocument*>(cppSelf)->find(*cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
            }
            break;
        }
        case 1: // find(const QRegExp & expr, int from, QFlags<QTextDocument::FindFlag> options) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "from");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): got multiple values for keyword argument 'from'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QTextDocumentFunc_find_TypeError;
                }
                value = PyDict_GetItemString(kwds, "options");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): got multiple values for keyword argument 'options'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QTextDocumentFunc_find_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRegExp cppArg0_local = ::QRegExp();
            ::QRegExp* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QTextDocument::FindFlag> cppArg2 = QFlags<QTextDocument::FindFlag>(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // find(QRegExp,int,QFlags<QTextDocument::FindFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCursor cppResult = const_cast<const ::QTextDocument*>(cppSelf)->find(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
            }
            break;
        }
        case 2: // find(const QString & subString, const QTextCursor & from, QFlags<QTextDocument::FindFlag> options) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "options");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): got multiple values for keyword argument 'options'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QTextDocumentFunc_find_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextCursor cppArg1_local = ::QTextCursor();
            ::QTextCursor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QFlags<QTextDocument::FindFlag> cppArg2 = QFlags<QTextDocument::FindFlag>(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // find(QString,QTextCursor,QFlags<QTextDocument::FindFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCursor cppResult = const_cast<const ::QTextDocument*>(cppSelf)->find(cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
            }
            break;
        }
        case 3: // find(const QString & subString, int from, QFlags<QTextDocument::FindFlag> options) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "from");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): got multiple values for keyword argument 'from'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QTextDocumentFunc_find_TypeError;
                }
                value = PyDict_GetItemString(kwds, "options");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.find(): got multiple values for keyword argument 'options'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QTextDocumentFunc_find_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QTextDocument::FindFlag> cppArg2 = QFlags<QTextDocument::FindFlag>(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // find(QString,int,QFlags<QTextDocument::FindFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCursor cppResult = const_cast<const ::QTextDocument*>(cppSelf)->find(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_find_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRegExp, PySide.QtGui.QTextCursor, PySide.QtGui.QTextDocument.FindFlags = 0", "PySide.QtCore.QRegExp, int = 0, PySide.QtGui.QTextDocument.FindFlags = 0", "unicode, PySide.QtGui.QTextCursor, PySide.QtGui.QTextDocument.FindFlags = 0", "unicode, int = 0, PySide.QtGui.QTextDocument.FindFlags = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.find", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_findBlock(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findBlock(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // findBlock(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_findBlock_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findBlock(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->findBlock(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_findBlock_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.findBlock", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_findBlockByLineNumber(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findBlockByLineNumber(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // findBlockByLineNumber(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_findBlockByLineNumber_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findBlockByLineNumber(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->findBlockByLineNumber(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_findBlockByLineNumber_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.findBlockByLineNumber", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_findBlockByNumber(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findBlockByNumber(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // findBlockByNumber(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_findBlockByNumber_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findBlockByNumber(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->findBlockByNumber(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_findBlockByNumber_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.findBlockByNumber", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_firstBlock(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstBlock()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->firstBlock();
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

static PyObject* Sbk_QTextDocumentFunc_frameAt(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: frameAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // frameAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_frameAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // frameAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrame * cppResult = const_cast<const ::QTextDocument*>(cppSelf)->frameAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_frameAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.frameAt", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_idealWidth(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // idealWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextDocument*>(cppSelf)->idealWidth();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_indentWidth(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // indentWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextDocument*>(cppSelf)->indentWidth();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_isEmpty(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocument*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QTextDocumentFunc_isModified(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isModified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocument*>(cppSelf)->isModified();
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

static PyObject* Sbk_QTextDocumentFunc_isRedoAvailable(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRedoAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocument*>(cppSelf)->isRedoAvailable();
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

static PyObject* Sbk_QTextDocumentFunc_isUndoAvailable(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUndoAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocument*>(cppSelf)->isUndoAvailable();
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

static PyObject* Sbk_QTextDocumentFunc_isUndoRedoEnabled(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUndoRedoEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocument*>(cppSelf)->isUndoRedoEnabled();
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

static PyObject* Sbk_QTextDocumentFunc_lastBlock(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastBlock()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextDocument*>(cppSelf)->lastBlock();
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

static PyObject* Sbk_QTextDocumentFunc_lineCount(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->lineCount();
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

static PyObject* Sbk_QTextDocumentFunc_loadResource(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "loadResource", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: loadResource(int,QUrl)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
        overloadId = 0; // loadResource(int,QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_loadResource_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = ::QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // loadResource(int,QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTextDocument::loadResource(cppArg0, *cppArg1) : cppSelf->loadResource(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_loadResource_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.loadResource", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_markContentsDirty(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "markContentsDirty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: markContentsDirty(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // markContentsDirty(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_markContentsDirty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // markContentsDirty(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->markContentsDirty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_markContentsDirty_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.markContentsDirty", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_maximumBlockCount(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumBlockCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->maximumBlockCount();
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

static PyObject* Sbk_QTextDocumentFunc_metaInformation(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: metaInformation(QTextDocument::MetaInformation)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX]), (pyArg)))) {
        overloadId = 0; // metaInformation(QTextDocument::MetaInformation)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_metaInformation_TypeError;

    // Call function/method
    {
        ::QTextDocument::MetaInformation cppArg0 = ((::QTextDocument::MetaInformation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metaInformation(QTextDocument::MetaInformation)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextDocument*>(cppSelf)->metaInformation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_metaInformation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextDocument.MetaInformation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.metaInformation", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_object(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: object(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // object(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_object_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // object(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextObject * cppResult = const_cast<const ::QTextDocument*>(cppSelf)->object(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_object_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.object", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_objectForFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: objectForFormat(QTextFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // objectForFormat(QTextFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_objectForFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextFormat cppArg0_local = ::QTextFormat();
        ::QTextFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // objectForFormat(QTextFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextObject * cppResult = const_cast<const ::QTextDocument*>(cppSelf)->objectForFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_objectForFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.objectForFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_pageCount(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pageCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->pageCount();
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

static PyObject* Sbk_QTextDocumentFunc_pageSize(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pageSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QTextDocument*>(cppSelf)->pageSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_print_(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: print(QPrinter*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (pyArg)))) {
        overloadId = 0; // print(QPrinter*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_print__TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPrinter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // print(QPrinter*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QTextDocument*>(cppSelf)->print(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_print__TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.print_", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_redo(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "redo", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: redo()
    // 1: redo(QTextCursor*)
    if (numArgs == 0) {
        overloadId = 0; // redo()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[0])))) {
        overloadId = 1; // redo(QTextCursor*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_redo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // redo()
        {

            if (!PyErr_Occurred()) {
                // redo()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->redo();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // redo(QTextCursor * cursor)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextCursor* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // redo(QTextCursor*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->redo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_redo_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextCursor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.redo", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_resource(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "resource", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: resource(int,QUrl)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
        overloadId = 0; // resource(int,QUrl)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_resource_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = ::QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // resource(int,QUrl)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QTextDocument*>(cppSelf)->resource(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_resource_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.resource", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_revision(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextDocument*>(cppSelf)->revision();
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

static PyObject* Sbk_QTextDocumentFunc_rootFrame(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rootFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrame * cppResult = const_cast<const ::QTextDocument*>(cppSelf)->rootFrame();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_setDefaultCursorMoveStyle(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultCursorMoveStyle(Qt::CursorMoveStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setDefaultCursorMoveStyle(Qt::CursorMoveStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setDefaultCursorMoveStyle_TypeError;

    // Call function/method
    {
        ::Qt::CursorMoveStyle cppArg0 = ((::Qt::CursorMoveStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultCursorMoveStyle(Qt::CursorMoveStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultCursorMoveStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setDefaultCursorMoveStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CursorMoveStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setDefaultCursorMoveStyle", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setDefaultFont(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setDefaultFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDefaultFont(QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultFont(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setDefaultFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setDefaultFont", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setDefaultStyleSheet(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultStyleSheet(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultStyleSheet(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setDefaultStyleSheet_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultStyleSheet(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultStyleSheet(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setDefaultStyleSheet_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setDefaultStyleSheet", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setDefaultTextOption(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultTextOption(QTextOption)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultTextOption(QTextOption)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setDefaultTextOption_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextOption cppArg0_local = ::QTextOption();
        ::QTextOption* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDefaultTextOption(QTextOption)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultTextOption(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setDefaultTextOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setDefaultTextOption", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setDocumentLayout(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocumentLayout(QAbstractTextDocumentLayout*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_IDX], (pyArg)))) {
        overloadId = 0; // setDocumentLayout(QAbstractTextDocumentLayout*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setDocumentLayout_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractTextDocumentLayout* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocumentLayout(QAbstractTextDocumentLayout*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocumentLayout(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setDocumentLayout_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractTextDocumentLayout", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setDocumentLayout", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setDocumentMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocumentMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setDocumentMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setDocumentMargin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocumentMargin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocumentMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setDocumentMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setDocumentMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setHtml(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHtml(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHtml(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setHtml_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHtml(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHtml(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setHtml_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setHtml", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setIndentWidth(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIndentWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setIndentWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setIndentWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIndentWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIndentWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setIndentWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setIndentWidth", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setMaximumBlockCount(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumBlockCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setMaximumBlockCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setMaximumBlockCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaximumBlockCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumBlockCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setMaximumBlockCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setMaximumBlockCount", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setMetaInformation(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setMetaInformation", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMetaInformation(QTextDocument::MetaInformation,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setMetaInformation(QTextDocument::MetaInformation,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setMetaInformation_TypeError;

    // Call function/method
    {
        ::QTextDocument::MetaInformation cppArg0 = ((::QTextDocument::MetaInformation)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMetaInformation(QTextDocument::MetaInformation,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMetaInformation(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setMetaInformation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextDocument.MetaInformation, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.setMetaInformation", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setModified(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.setModified(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:setModified", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: setModified(bool)
    if (numArgs == 0) {
        overloadId = 0; // setModified(bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // setModified(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setModified_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "m");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.setModified(): got multiple values for keyword argument 'm'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_QTextDocumentFunc_setModified_TypeError;
            }
        }
        bool cppArg0 = true;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // setModified(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModified(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setModified_TypeError:
        const char* overloads[] = {"bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.setModified", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setPageSize(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPageSize(QSizeF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArg)))) {
        overloadId = 0; // setPageSize(QSizeF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setPageSize_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSizeF cppArg0_local = ::QSizeF();
        ::QSizeF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPageSize(QSizeF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPageSize(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setPageSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSizeF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setPageSize", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setPlainText(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPlainText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPlainText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setPlainText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPlainText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPlainText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setPlainText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setPlainText", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setTextWidth(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTextWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setTextWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setTextWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setTextWidth", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setUndoRedoEnabled(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUndoRedoEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUndoRedoEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setUndoRedoEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUndoRedoEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUndoRedoEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setUndoRedoEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setUndoRedoEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_setUseDesignMetrics(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUseDesignMetrics(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUseDesignMetrics(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_setUseDesignMetrics_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUseDesignMetrics(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUseDesignMetrics(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_setUseDesignMetrics_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocument.setUseDesignMetrics", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_size(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QTextDocument*>(cppSelf)->size();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_textWidth(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextDocument*>(cppSelf)->textWidth();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextDocumentFunc_toHtml(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.toHtml(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toHtml", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toHtml(QByteArray)const
    if (numArgs == 0) {
        overloadId = 0; // toHtml(QByteArray)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 0; // toHtml(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_toHtml_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "encoding");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextDocument.toHtml(): got multiple values for keyword argument 'encoding'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0]))))
                    goto Sbk_QTextDocumentFunc_toHtml_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // toHtml(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextDocument*>(cppSelf)->toHtml(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFunc_toHtml_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.toHtml", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_toPlainText(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPlainText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextDocument*>(cppSelf)->toPlainText();
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

static PyObject* Sbk_QTextDocumentFunc_undo(PyObject* self, PyObject* args)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "undo", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: undo()
    // 1: undo(QTextCursor*)
    if (numArgs == 0) {
        overloadId = 0; // undo()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[0])))) {
        overloadId = 1; // undo(QTextCursor*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFunc_undo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // undo()
        {

            if (!PyErr_Occurred()) {
                // undo()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->undo();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // undo(QTextCursor * cursor)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextCursor* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // undo(QTextCursor*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->undo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextDocumentFunc_undo_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextCursor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocument.undo", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFunc_useDesignMetrics(PyObject* self)
{
    ::QTextDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // useDesignMetrics()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocument*>(cppSelf)->useDesignMetrics();
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

static PyMethodDef Sbk_QTextDocument_methods[] = {
    {"addResource", (PyCFunction)Sbk_QTextDocumentFunc_addResource, METH_VARARGS},
    {"adjustSize", (PyCFunction)Sbk_QTextDocumentFunc_adjustSize, METH_NOARGS},
    {"allFormats", (PyCFunction)Sbk_QTextDocumentFunc_allFormats, METH_NOARGS},
    {"availableRedoSteps", (PyCFunction)Sbk_QTextDocumentFunc_availableRedoSteps, METH_NOARGS},
    {"availableUndoSteps", (PyCFunction)Sbk_QTextDocumentFunc_availableUndoSteps, METH_NOARGS},
    {"begin", (PyCFunction)Sbk_QTextDocumentFunc_begin, METH_NOARGS},
    {"blockCount", (PyCFunction)Sbk_QTextDocumentFunc_blockCount, METH_NOARGS},
    {"characterAt", (PyCFunction)Sbk_QTextDocumentFunc_characterAt, METH_O},
    {"characterCount", (PyCFunction)Sbk_QTextDocumentFunc_characterCount, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QTextDocumentFunc_clear, METH_NOARGS},
    {"clearUndoRedoStacks", (PyCFunction)Sbk_QTextDocumentFunc_clearUndoRedoStacks, METH_VARARGS|METH_KEYWORDS},
    {"clone", (PyCFunction)Sbk_QTextDocumentFunc_clone, METH_VARARGS|METH_KEYWORDS},
    {"createObject", (PyCFunction)Sbk_QTextDocumentFunc_createObject, METH_O},
    {"defaultCursorMoveStyle", (PyCFunction)Sbk_QTextDocumentFunc_defaultCursorMoveStyle, METH_NOARGS},
    {"defaultFont", (PyCFunction)Sbk_QTextDocumentFunc_defaultFont, METH_NOARGS},
    {"defaultStyleSheet", (PyCFunction)Sbk_QTextDocumentFunc_defaultStyleSheet, METH_NOARGS},
    {"defaultTextOption", (PyCFunction)Sbk_QTextDocumentFunc_defaultTextOption, METH_NOARGS},
    {"documentLayout", (PyCFunction)Sbk_QTextDocumentFunc_documentLayout, METH_NOARGS},
    {"documentMargin", (PyCFunction)Sbk_QTextDocumentFunc_documentMargin, METH_NOARGS},
    {"drawContents", (PyCFunction)Sbk_QTextDocumentFunc_drawContents, METH_VARARGS|METH_KEYWORDS},
    {"end", (PyCFunction)Sbk_QTextDocumentFunc_end, METH_NOARGS},
    {"find", (PyCFunction)Sbk_QTextDocumentFunc_find, METH_VARARGS|METH_KEYWORDS},
    {"findBlock", (PyCFunction)Sbk_QTextDocumentFunc_findBlock, METH_O},
    {"findBlockByLineNumber", (PyCFunction)Sbk_QTextDocumentFunc_findBlockByLineNumber, METH_O},
    {"findBlockByNumber", (PyCFunction)Sbk_QTextDocumentFunc_findBlockByNumber, METH_O},
    {"firstBlock", (PyCFunction)Sbk_QTextDocumentFunc_firstBlock, METH_NOARGS},
    {"frameAt", (PyCFunction)Sbk_QTextDocumentFunc_frameAt, METH_O},
    {"idealWidth", (PyCFunction)Sbk_QTextDocumentFunc_idealWidth, METH_NOARGS},
    {"indentWidth", (PyCFunction)Sbk_QTextDocumentFunc_indentWidth, METH_NOARGS},
    {"isEmpty", (PyCFunction)Sbk_QTextDocumentFunc_isEmpty, METH_NOARGS},
    {"isModified", (PyCFunction)Sbk_QTextDocumentFunc_isModified, METH_NOARGS},
    {"isRedoAvailable", (PyCFunction)Sbk_QTextDocumentFunc_isRedoAvailable, METH_NOARGS},
    {"isUndoAvailable", (PyCFunction)Sbk_QTextDocumentFunc_isUndoAvailable, METH_NOARGS},
    {"isUndoRedoEnabled", (PyCFunction)Sbk_QTextDocumentFunc_isUndoRedoEnabled, METH_NOARGS},
    {"lastBlock", (PyCFunction)Sbk_QTextDocumentFunc_lastBlock, METH_NOARGS},
    {"lineCount", (PyCFunction)Sbk_QTextDocumentFunc_lineCount, METH_NOARGS},
    {"loadResource", (PyCFunction)Sbk_QTextDocumentFunc_loadResource, METH_VARARGS},
    {"markContentsDirty", (PyCFunction)Sbk_QTextDocumentFunc_markContentsDirty, METH_VARARGS},
    {"maximumBlockCount", (PyCFunction)Sbk_QTextDocumentFunc_maximumBlockCount, METH_NOARGS},
    {"metaInformation", (PyCFunction)Sbk_QTextDocumentFunc_metaInformation, METH_O},
    {"object", (PyCFunction)Sbk_QTextDocumentFunc_object, METH_O},
    {"objectForFormat", (PyCFunction)Sbk_QTextDocumentFunc_objectForFormat, METH_O},
    {"pageCount", (PyCFunction)Sbk_QTextDocumentFunc_pageCount, METH_NOARGS},
    {"pageSize", (PyCFunction)Sbk_QTextDocumentFunc_pageSize, METH_NOARGS},
    {"print_", (PyCFunction)Sbk_QTextDocumentFunc_print_, METH_O},
    {"redo", (PyCFunction)Sbk_QTextDocumentFunc_redo, METH_VARARGS},
    {"resource", (PyCFunction)Sbk_QTextDocumentFunc_resource, METH_VARARGS},
    {"revision", (PyCFunction)Sbk_QTextDocumentFunc_revision, METH_NOARGS},
    {"rootFrame", (PyCFunction)Sbk_QTextDocumentFunc_rootFrame, METH_NOARGS},
    {"setDefaultCursorMoveStyle", (PyCFunction)Sbk_QTextDocumentFunc_setDefaultCursorMoveStyle, METH_O},
    {"setDefaultFont", (PyCFunction)Sbk_QTextDocumentFunc_setDefaultFont, METH_O},
    {"setDefaultStyleSheet", (PyCFunction)Sbk_QTextDocumentFunc_setDefaultStyleSheet, METH_O},
    {"setDefaultTextOption", (PyCFunction)Sbk_QTextDocumentFunc_setDefaultTextOption, METH_O},
    {"setDocumentLayout", (PyCFunction)Sbk_QTextDocumentFunc_setDocumentLayout, METH_O},
    {"setDocumentMargin", (PyCFunction)Sbk_QTextDocumentFunc_setDocumentMargin, METH_O},
    {"setHtml", (PyCFunction)Sbk_QTextDocumentFunc_setHtml, METH_O},
    {"setIndentWidth", (PyCFunction)Sbk_QTextDocumentFunc_setIndentWidth, METH_O},
    {"setMaximumBlockCount", (PyCFunction)Sbk_QTextDocumentFunc_setMaximumBlockCount, METH_O},
    {"setMetaInformation", (PyCFunction)Sbk_QTextDocumentFunc_setMetaInformation, METH_VARARGS},
    {"setModified", (PyCFunction)Sbk_QTextDocumentFunc_setModified, METH_VARARGS|METH_KEYWORDS},
    {"setPageSize", (PyCFunction)Sbk_QTextDocumentFunc_setPageSize, METH_O},
    {"setPlainText", (PyCFunction)Sbk_QTextDocumentFunc_setPlainText, METH_O},
    {"setTextWidth", (PyCFunction)Sbk_QTextDocumentFunc_setTextWidth, METH_O},
    {"setUndoRedoEnabled", (PyCFunction)Sbk_QTextDocumentFunc_setUndoRedoEnabled, METH_O},
    {"setUseDesignMetrics", (PyCFunction)Sbk_QTextDocumentFunc_setUseDesignMetrics, METH_O},
    {"size", (PyCFunction)Sbk_QTextDocumentFunc_size, METH_NOARGS},
    {"textWidth", (PyCFunction)Sbk_QTextDocumentFunc_textWidth, METH_NOARGS},
    {"toHtml", (PyCFunction)Sbk_QTextDocumentFunc_toHtml, METH_VARARGS|METH_KEYWORDS},
    {"toPlainText", (PyCFunction)Sbk_QTextDocumentFunc_toPlainText, METH_NOARGS},
    {"undo", (PyCFunction)Sbk_QTextDocumentFunc_undo, METH_VARARGS},
    {"useDesignMetrics", (PyCFunction)Sbk_QTextDocumentFunc_useDesignMetrics, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextDocument_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextDocument_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextDocument_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextDocument",
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
    /*tp_traverse*/         Sbk_QTextDocument_traverse,
    /*tp_clear*/            Sbk_QTextDocument_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextDocument_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextDocument_Init,
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

static void* Sbk_QTextDocument_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QTextDocument*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QTextDocument_FindFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument::FindFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextDocument::FindFlags)PyLong_AsLong(self);
    cppArg = (QTextDocument::FindFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextDocument::FindFlags)PyInt_AsLong(self);
    cppArg = (QTextDocument::FindFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextDocument_FindFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument::FindFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextDocument::FindFlags)PyLong_AsLong(self);
    cppArg = (QTextDocument::FindFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextDocument::FindFlags)PyInt_AsLong(self);
    cppArg = (QTextDocument::FindFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextDocument_FindFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument::FindFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextDocument::FindFlags)PyLong_AsLong(self);
    cppArg = (QTextDocument::FindFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextDocument::FindFlags)PyInt_AsLong(self);
    cppArg = (QTextDocument::FindFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextDocument_FindFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextDocument::FindFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), self, &cppSelf);
    ::QTextDocument::FindFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QTextDocument_FindFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QTextDocument_FindFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QTextDocument_FindFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QTextDocument_FindFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QTextDocument_FindFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QTextDocument_FindFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QTextDocument_FindFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QTextDocument_FindFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QTextDocument_FindFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QTextDocument_FindFlag_long,
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
static void QTextDocument_MetaInformation_PythonToCpp_QTextDocument_MetaInformation(PyObject* pyIn, void* cppOut) {
    *((::QTextDocument::MetaInformation*)cppOut) = (::QTextDocument::MetaInformation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextDocument_MetaInformation_PythonToCpp_QTextDocument_MetaInformation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX]))
        return QTextDocument_MetaInformation_PythonToCpp_QTextDocument_MetaInformation;
    return 0;
}
static PyObject* QTextDocument_MetaInformation_CppToPython_QTextDocument_MetaInformation(const void* cppIn) {
    int castCppIn = *((::QTextDocument::MetaInformation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX], castCppIn);

}

static void QTextDocument_FindFlag_PythonToCpp_QTextDocument_FindFlag(PyObject* pyIn, void* cppOut) {
    *((::QTextDocument::FindFlag*)cppOut) = (::QTextDocument::FindFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextDocument_FindFlag_PythonToCpp_QTextDocument_FindFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX]))
        return QTextDocument_FindFlag_PythonToCpp_QTextDocument_FindFlag;
    return 0;
}
static PyObject* QTextDocument_FindFlag_CppToPython_QTextDocument_FindFlag(const void* cppIn) {
    int castCppIn = *((::QTextDocument::FindFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX], castCppIn);

}

static void QFlags_QTextDocument_FindFlag__PythonToCpp_QFlags_QTextDocument_FindFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextDocument::FindFlag>*)cppOut) = ::QFlags<QTextDocument::FindFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextDocument_FindFlag__PythonToCpp_QFlags_QTextDocument_FindFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]))
        return QFlags_QTextDocument_FindFlag__PythonToCpp_QFlags_QTextDocument_FindFlag_;
    return 0;
}
static PyObject* QFlags_QTextDocument_FindFlag__CppToPython_QFlags_QTextDocument_FindFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextDocument::FindFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]));

}

static void QTextDocument_FindFlag_PythonToCpp_QFlags_QTextDocument_FindFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextDocument::FindFlag>*)cppOut) = ::QFlags<QTextDocument::FindFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextDocument_FindFlag_PythonToCpp_QFlags_QTextDocument_FindFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX]))
        return QTextDocument_FindFlag_PythonToCpp_QFlags_QTextDocument_FindFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextDocument_FindFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextDocument::FindFlag>*)cppOut) = ::QFlags<QTextDocument::FindFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextDocument_FindFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextDocument_FindFlag_;
    return 0;
}
static void QTextDocument_ResourceType_PythonToCpp_QTextDocument_ResourceType(PyObject* pyIn, void* cppOut) {
    *((::QTextDocument::ResourceType*)cppOut) = (::QTextDocument::ResourceType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextDocument_ResourceType_PythonToCpp_QTextDocument_ResourceType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX]))
        return QTextDocument_ResourceType_PythonToCpp_QTextDocument_ResourceType;
    return 0;
}
static PyObject* QTextDocument_ResourceType_CppToPython_QTextDocument_ResourceType(const void* cppIn) {
    int castCppIn = *((::QTextDocument::ResourceType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX], castCppIn);

}

static void QTextDocument_Stacks_PythonToCpp_QTextDocument_Stacks(PyObject* pyIn, void* cppOut) {
    *((::QTextDocument::Stacks*)cppOut) = (::QTextDocument::Stacks) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextDocument_Stacks_PythonToCpp_QTextDocument_Stacks_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX]))
        return QTextDocument_Stacks_PythonToCpp_QTextDocument_Stacks;
    return 0;
}
static PyObject* QTextDocument_Stacks_CppToPython_QTextDocument_Stacks(const void* cppIn) {
    int castCppIn = *((::QTextDocument::Stacks*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextDocument_PythonToCpp_QTextDocument_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextDocument_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextDocument_PythonToCpp_QTextDocument_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextDocument_Type))
        return QTextDocument_PythonToCpp_QTextDocument_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextDocument_PTR_CppToPython_QTextDocument(const void* cppIn) {
    return PySide::getWrapperForQObject((::QTextDocument*)cppIn, &Sbk_QTextDocument_Type);

}

void init_QTextDocument(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextDocument_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextDocument", "QTextDocument*",
        &Sbk_QTextDocument_Type, &Shiboken::callCppDestructor< ::QTextDocument >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextDocument_Type,
        QTextDocument_PythonToCpp_QTextDocument_PTR,
        is_QTextDocument_PythonToCpp_QTextDocument_PTR_Convertible,
        QTextDocument_PTR_CppToPython_QTextDocument);

    Shiboken::Conversions::registerConverterName(converter, "QTextDocument");
    Shiboken::Conversions::registerConverterName(converter, "QTextDocument*");
    Shiboken::Conversions::registerConverterName(converter, "QTextDocument&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextDocument).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextDocumentWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QTextDocument_Type, &Sbk_QTextDocument_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'MetaInformation'.
    SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextDocument_Type,
        "MetaInformation",
        "PySide.QtGui.QTextDocument.MetaInformation",
        "QTextDocument::MetaInformation");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX],
        &Sbk_QTextDocument_Type, "DocumentTitle", (long) QTextDocument::DocumentTitle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX],
        &Sbk_QTextDocument_Type, "DocumentUrl", (long) QTextDocument::DocumentUrl))
        return ;
    // Register converter for enum 'QTextDocument::MetaInformation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX],
            QTextDocument_MetaInformation_CppToPython_QTextDocument_MetaInformation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextDocument_MetaInformation_PythonToCpp_QTextDocument_MetaInformation,
            is_QTextDocument_MetaInformation_PythonToCpp_QTextDocument_MetaInformation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextDocument::MetaInformation");
        Shiboken::Conversions::registerConverterName(converter, "MetaInformation");
    }
    // End of 'MetaInformation' enum.

    // Initialization of enum 'FindFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX] = PySide::QFlags::create("FindFlags", &SbkPySide_QtGui_QTextDocument_FindFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextDocument_Type,
        "FindFlag",
        "PySide.QtGui.QTextDocument.FindFlag",
        "QTextDocument::FindFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX],
        &Sbk_QTextDocument_Type, "FindBackward", (long) QTextDocument::FindBackward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX],
        &Sbk_QTextDocument_Type, "FindCaseSensitively", (long) QTextDocument::FindCaseSensitively))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX],
        &Sbk_QTextDocument_Type, "FindWholeWords", (long) QTextDocument::FindWholeWords))
        return ;
    // Register converter for enum 'QTextDocument::FindFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX],
            QTextDocument_FindFlag_CppToPython_QTextDocument_FindFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextDocument_FindFlag_PythonToCpp_QTextDocument_FindFlag,
            is_QTextDocument_FindFlag_PythonToCpp_QTextDocument_FindFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextDocument::FindFlag");
        Shiboken::Conversions::registerConverterName(converter, "FindFlag");
    }
    // Register converter for flag 'QFlags<QTextDocument::FindFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX],
            QFlags_QTextDocument_FindFlag__CppToPython_QFlags_QTextDocument_FindFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextDocument_FindFlag_PythonToCpp_QFlags_QTextDocument_FindFlag_,
            is_QTextDocument_FindFlag_PythonToCpp_QFlags_QTextDocument_FindFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextDocument_FindFlag__PythonToCpp_QFlags_QTextDocument_FindFlag_,
            is_QFlags_QTextDocument_FindFlag__PythonToCpp_QFlags_QTextDocument_FindFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextDocument_FindFlag_,
            is_number_PythonToCpp_QFlags_QTextDocument_FindFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextDocument::FindFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FindFlag>");
    }
    // End of 'FindFlag' enum/flags.

    // Initialization of enum 'ResourceType'.
    SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextDocument_Type,
        "ResourceType",
        "PySide.QtGui.QTextDocument.ResourceType",
        "QTextDocument::ResourceType");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX],
        &Sbk_QTextDocument_Type, "HtmlResource", (long) QTextDocument::HtmlResource))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX],
        &Sbk_QTextDocument_Type, "ImageResource", (long) QTextDocument::ImageResource))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX],
        &Sbk_QTextDocument_Type, "StyleSheetResource", (long) QTextDocument::StyleSheetResource))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX],
        &Sbk_QTextDocument_Type, "UserResource", (long) QTextDocument::UserResource))
        return ;
    // Register converter for enum 'QTextDocument::ResourceType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX],
            QTextDocument_ResourceType_CppToPython_QTextDocument_ResourceType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextDocument_ResourceType_PythonToCpp_QTextDocument_ResourceType,
            is_QTextDocument_ResourceType_PythonToCpp_QTextDocument_ResourceType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextDocument::ResourceType");
        Shiboken::Conversions::registerConverterName(converter, "ResourceType");
    }
    // End of 'ResourceType' enum.

    // Initialization of enum 'Stacks'.
    SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextDocument_Type,
        "Stacks",
        "PySide.QtGui.QTextDocument.Stacks",
        "QTextDocument::Stacks");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX],
        &Sbk_QTextDocument_Type, "UndoStack", (long) QTextDocument::UndoStack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX],
        &Sbk_QTextDocument_Type, "RedoStack", (long) QTextDocument::RedoStack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX],
        &Sbk_QTextDocument_Type, "UndoAndRedoStacks", (long) QTextDocument::UndoAndRedoStacks))
        return ;
    // Register converter for enum 'QTextDocument::Stacks'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX],
            QTextDocument_Stacks_CppToPython_QTextDocument_Stacks);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextDocument_Stacks_PythonToCpp_QTextDocument_Stacks,
            is_QTextDocument_Stacks_PythonToCpp_QTextDocument_Stacks_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextDocument::Stacks");
        Shiboken::Conversions::registerConverterName(converter, "Stacks");
    }
    // End of 'Stacks' enum.

    PySide::Signal::registerSignals(&Sbk_QTextDocument_Type, &::QTextDocument::staticMetaObject);

    qRegisterMetaType< ::QTextDocument::MetaInformation >("QTextDocument::MetaInformation");
    qRegisterMetaType< ::QTextDocument::FindFlag >("QTextDocument::FindFlag");
    qRegisterMetaType< ::QTextDocument::FindFlags >("QTextDocument::FindFlags");
    qRegisterMetaType< ::QTextDocument::ResourceType >("QTextDocument::ResourceType");
    qRegisterMetaType< ::QTextDocument::Stacks >("QTextDocument::Stacks");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QTextDocument_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QTextDocument_Type, &::QTextDocument::staticMetaObject, sizeof(::QTextDocument));
}
