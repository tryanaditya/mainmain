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

#include "qapplication_wrapper.h"

// Extra includes
#include <QBasicTimer>
#include <QFont>
#include <QFontMetrics>
#include <QIcon>
#include <QList>
#include <QLocale>
#include <QPalette>
#include <QStyle>
#include <qapplication.h>
#include <qbytearray.h>
#include <qclipboard.h>
#include <qcoreapplication.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdesktopwidget.h>
#include <qfont.h>
#include <qfontmetrics.h>
#include <qicon.h>
#include <qinputcontext.h>
#include <qlocale.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qsessionmanager.h>
#include <qsize.h>
#include <qstyle.h>
#include <qthread.h>
#include <qtranslator.h>
#include <qwidget.h>


// Begin code injection
// ========================================================================
// START of custom code block [file: glue/qapplication_init.cpp]
// Borrowed reference to QtGui module
extern PyObject* moduleQtGui;

static int QApplicationArgCount;
static char** QApplicationArgValues;
static const char QAPP_MACRO[] = "qApp";

bool QApplicationConstructorStart(PyObject* argv)
{
    if (QApplication::instance()) {
        PyErr_SetString(PyExc_RuntimeError, "A QApplication instance already exists.");
        return false;
    }

    return Shiboken::sequenceToArgcArgv(argv, &QApplicationArgCount, &QApplicationArgValues, "PySideApp");
}

void QApplicationConstructorEnd(PyObject* self)
{
    // Verify if qApp is in main module
    PyObject* globalsDict = PyEval_GetGlobals();
    if (globalsDict) {
        PyObject* qAppObj = PyDict_GetItemString(globalsDict, QAPP_MACRO);
        if (qAppObj)
            PyDict_SetItemString(globalsDict, QAPP_MACRO, self);
    }

    PyObject_SetAttrString(moduleQtGui, QAPP_MACRO, self);
    PySide::registerCleanupFunction(&PySide::destroyQCoreApplication);
    Py_INCREF(self);
}

static void QApplicationConstructor(PyObject* self, PyObject* argv, QApplicationWrapper** cptr)
{
    if (QApplicationConstructorStart(argv)) {
        *cptr = new QApplicationWrapper(QApplicationArgCount, QApplicationArgValues);
        Shiboken::Object::releaseOwnership(reinterpret_cast<SbkObject*>(self));
        QApplicationConstructorEnd(self);
    }
}

template <typename T>
static void QApplicationConstructor(PyObject* self, PyObject* argv, T extraArg, QApplicationWrapper** cptr)
{
    if (QApplicationConstructorStart(argv)) {
        *cptr = new QApplicationWrapper(QApplicationArgCount, QApplicationArgValues, extraArg);
        Shiboken::Object::releaseOwnership(reinterpret_cast<SbkObject*>(self));
        QApplicationConstructorEnd(self);
    }
}

// END of custom code block [file: glue/qapplication_init.cpp]
// ========================================================================

// End of code injection

// Native ---------------------------------------------------------

QApplicationWrapper::QApplicationWrapper(int & argc, char ** argv) : QApplication(argc, argv) {
    // ... middle
}

QApplicationWrapper::QApplicationWrapper(int & argc, char ** argv, QApplication::Type arg__3) : QApplication(argc, argv, arg__3) {
    // ... middle
}

QApplicationWrapper::QApplicationWrapper(int & argc, char ** argv, bool GUIenabled) : QApplication(argc, argv, GUIenabled) {
    // ... middle
}

void QApplicationWrapper::childEvent(QChildEvent * arg__1)
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

void QApplicationWrapper::commitData(QSessionManager & sm)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "commitData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QApplication::commitData(sm);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], &sm)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QApplicationWrapper::connectNotify(const char * signal)
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

void QApplicationWrapper::customEvent(QEvent * arg__1)
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

void QApplicationWrapper::disconnectNotify(const char * signal)
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

bool QApplicationWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QApplication::event(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QApplication.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QApplicationWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QApplication.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QApplicationWrapper::notify(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "notify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QApplication::notify(arg__1, arg__2);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QApplication.notify", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QApplicationWrapper::saveState(QSessionManager & sm)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "saveState"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QApplication::saveState(sm);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], &sm)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QApplicationWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QApplicationWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QApplication::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QApplicationWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QApplication::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QApplicationWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QApplicationWrapper* >(this));
        return QApplication::qt_metacast(_clname);
}

QApplicationWrapper::~QApplicationWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QApplication_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QApplication >()))
        return -1;

    ::QApplicationWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QApplication", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QApplication(PySequence)
    // 1: QApplication(PySequence,QApplication::Type)
    // 2: QApplication(PySequence,bool)
    if (PySequence_Check(pyArgs[0])) {
        if (numArgs == 1) {
            overloadId = 0; // QApplication(PySequence)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // QApplication(PySequence,QApplication::Type)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 2; // QApplication(PySequence,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplication_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QApplication(PySequence arg__1)
        {

            if (!PyErr_Occurred()) {
                // QApplication(PySequence)
                // Begin code injection

                QApplicationConstructor(self, pyArgs[0], &cptr);

                // End of code injection

            }
            break;
        }
        case 1: // QApplication(PySequence arg__1, QApplication::Type arg__2)
        {
            ::QApplication::Type cppArg1 = ((::QApplication::Type)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // QApplication(PySequence,QApplication::Type)
                // Begin code injection

                QApplicationConstructor(self, pyArgs[0], cppArg1, &cptr);

                // End of code injection

            }
            break;
        }
        case 2: // QApplication(PySequence arg__1, bool arg__2)
        {
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // QApplication(PySequence,bool)
                // Begin code injection

                QApplicationConstructor(self, pyArgs[0], cppArg1, &cptr);

                // End of code injection

            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QApplication >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QApplication_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QApplication_Init_TypeError:
        const char* overloads[] = {"PySequence", "PySequence, PySide.QtGui.QApplication.Type", "PySequence, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication", overloads);
        return -1;
}

static PyObject* Sbk_QApplicationFunc_aboutQt(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // aboutQt()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::aboutQt();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QApplicationFunc_activeModalWidget(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activeModalWidget()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = ::QApplication::activeModalWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_activePopupWidget(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activePopupWidget()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = ::QApplication::activePopupWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_activeWindow(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activeWindow()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = ::QApplication::activeWindow();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_alert(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.alert(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.alert(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:alert", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: alert(QWidget*,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // alert(QWidget*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // alert(QWidget*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_alert_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "duration");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.alert(): got multiple values for keyword argument 'duration'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QApplicationFunc_alert_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // alert(QWidget*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::alert(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_alert_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.alert", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_allWidgets(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allWidgets()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWidget * > cppResult = ::QApplication::allWidgets();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIDGETPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_autoSipEnabled(PyObject* self)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoSipEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QApplication*>(cppSelf)->autoSipEnabled();
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

static PyObject* Sbk_QApplicationFunc_beep(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // beep()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::beep();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QApplicationFunc_changeOverrideCursor(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeOverrideCursor(QCursor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // changeOverrideCursor(QCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_changeOverrideCursor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCursor cppArg0_local = ::QCursor();
        ::QCursor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // changeOverrideCursor(QCursor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::changeOverrideCursor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_changeOverrideCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.changeOverrideCursor", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_clipboard(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipboard()

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QClipboard * cppResult = ::QApplication::clipboard();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], cppResult);

            // Begin code injection

            // TEMPLATE - set_qapp_parent_for_orphan - START
            if (pyResult && (pyResult != Py_None)) {
                SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                if (!Shiboken::Object::hasParentInfo(_pySelf))
                    Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
            }
            // TEMPLATE - set_qapp_parent_for_orphan - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_closeAllWindows(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closeAllWindows()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::closeAllWindows();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QApplicationFunc_colorSpec(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colorSpec()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::colorSpec();
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

static PyObject* Sbk_QApplicationFunc_commitData(PyObject* self, PyObject* pyArg)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: commitData(QSessionManager&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (pyArg)))) {
        overloadId = 0; // commitData(QSessionManager&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_commitData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSessionManager* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // commitData(QSessionManager&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QApplication::commitData(*cppArg0) : cppSelf->commitData(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_commitData_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSessionManager", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.commitData", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_cursorFlashTime(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursorFlashTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::cursorFlashTime();
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

static PyObject* Sbk_QApplicationFunc_desktop(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // desktop()

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDesktopWidget * cppResult = ::QApplication::desktop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDESKTOPWIDGET_IDX], cppResult);

            // Begin code injection

            // TEMPLATE - set_qapp_parent_for_orphan - START
            if (pyResult && (pyResult != Py_None)) {
                SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                if (!Shiboken::Object::hasParentInfo(_pySelf))
                    Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
            }
            // TEMPLATE - set_qapp_parent_for_orphan - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_desktopSettingsAware(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // desktopSettingsAware()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QApplication::desktopSettingsAware();
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

static PyObject* Sbk_QApplicationFunc_doubleClickInterval(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doubleClickInterval()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::doubleClickInterval();
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

static PyObject* Sbk_QApplicationFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QApplication::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.event", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_exec_(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exec()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::exec();
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

static PyObject* Sbk_QApplicationFunc_focusWidget(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focusWidget()

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = ::QApplication::focusWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

            // Begin code injection

            // TEMPLATE - set_qapp_parent_for_orphan - START
            if (pyResult && (pyResult != Py_None)) {
                SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                if (!Shiboken::Object::hasParentInfo(_pySelf))
                    Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
            }
            // TEMPLATE - set_qapp_parent_for_orphan - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_font(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "font", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: font()
    // 1: font(const QWidget*)
    // 2: font(const char*)
    if (numArgs == 0) {
        overloadId = 0; // font()
    } else if (numArgs == 1
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 2; // font(const char*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // font(const QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_font_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // font()
        {

            if (!PyErr_Occurred()) {
                // font()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFont cppResult = ::QApplication::font();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
            }
            break;
        }
        case 1: // font(const QWidget * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // font(const QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFont cppResult = ::QApplication::font(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
            }
            break;
        }
        case 2: // font(const char * className)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // font(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFont cppResult = ::QApplication::font(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_font_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QWidget", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.font", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_fontMetrics(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontMetrics()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFontMetrics cppResult = ::QApplication::fontMetrics();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_globalStrut(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalStrut()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = ::QApplication::globalStrut();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_inputContext(PyObject* self)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // inputContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QInputContext * cppResult = const_cast<const ::QApplication*>(cppSelf)->inputContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTCONTEXT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_isEffectEnabled(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isEffectEnabled(Qt::UIEffect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX]), (pyArg)))) {
        overloadId = 0; // isEffectEnabled(Qt::UIEffect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_isEffectEnabled_TypeError;

    // Call function/method
    {
        ::Qt::UIEffect cppArg0 = ((::Qt::UIEffect)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isEffectEnabled(Qt::UIEffect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QApplication::isEffectEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_isEffectEnabled_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.UIEffect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.isEffectEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_isLeftToRight(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLeftToRight()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QApplication::isLeftToRight();
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

static PyObject* Sbk_QApplicationFunc_isRightToLeft(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRightToLeft()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QApplication::isRightToLeft();
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

static PyObject* Sbk_QApplicationFunc_isSessionRestored(PyObject* self)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSessionRestored()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QApplication*>(cppSelf)->isSessionRestored();
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

static PyObject* Sbk_QApplicationFunc_keyboardInputDirection(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyboardInputDirection()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = ::QApplication::keyboardInputDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_keyboardInputInterval(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyboardInputInterval()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::keyboardInputInterval();
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

static PyObject* Sbk_QApplicationFunc_keyboardInputLocale(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyboardInputLocale()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale cppResult = ::QApplication::keyboardInputLocale();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_keyboardModifiers(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyboardModifiers()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = ::QApplication::keyboardModifiers();
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

static PyObject* Sbk_QApplicationFunc_layoutDirection(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // layoutDirection()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = ::QApplication::layoutDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_mouseButtons(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mouseButtons()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = ::QApplication::mouseButtons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_notify(PyObject* self, PyObject* args)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "notify", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: notify(QObject*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // notify(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_notify_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // notify(QObject*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QApplication::notify(cppArg0, cppArg1) : cppSelf->notify(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_notify_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.notify", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_overrideCursor(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overrideCursor()

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCursor * cppResult = ::QApplication::overrideCursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], cppResult);

            // Begin code injection

            // TEMPLATE - set_qapp_parent_for_orphan - START
            if (pyResult && (pyResult != Py_None)) {
                SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                if (!Shiboken::Object::hasParentInfo(_pySelf))
                    Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
            }
            // TEMPLATE - set_qapp_parent_for_orphan - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_palette(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "palette", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: palette()
    // 1: palette(const QWidget*)
    // 2: palette(const char*)
    if (numArgs == 0) {
        overloadId = 0; // palette()
    } else if (numArgs == 1
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 2; // palette(const char*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // palette(const QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_palette_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // palette()
        {

            if (!PyErr_Occurred()) {
                // palette()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPalette cppResult = ::QApplication::palette();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
            }
            break;
        }
        case 1: // palette(const QWidget * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // palette(const QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPalette cppResult = ::QApplication::palette(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
            }
            break;
        }
        case 2: // palette(const char * className)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // palette(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPalette cppResult = ::QApplication::palette(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_palette_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QWidget", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.palette", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_queryKeyboardModifiers(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queryKeyboardModifiers()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = ::QApplication::queryKeyboardModifiers();
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

static PyObject* Sbk_QApplicationFunc_quitOnLastWindowClosed(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // quitOnLastWindowClosed()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QApplication::quitOnLastWindowClosed();
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

static PyObject* Sbk_QApplicationFunc_restoreOverrideCursor(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restoreOverrideCursor()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::restoreOverrideCursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QApplicationFunc_saveState(PyObject* self, PyObject* pyArg)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: saveState(QSessionManager&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSESSIONMANAGER_IDX], (pyArg)))) {
        overloadId = 0; // saveState(QSessionManager&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_saveState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSessionManager* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveState(QSessionManager&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QApplication::saveState(*cppArg0) : cppSelf->saveState(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_saveState_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSessionManager", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.saveState", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_sessionId(PyObject* self)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sessionId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QApplication*>(cppSelf)->sessionId();
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

static PyObject* Sbk_QApplicationFunc_sessionKey(PyObject* self)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sessionKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QApplication*>(cppSelf)->sessionKey();
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

static PyObject* Sbk_QApplicationFunc_setActiveWindow(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActiveWindow(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setActiveWindow(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setActiveWindow_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActiveWindow(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setActiveWindow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setActiveWindow_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setActiveWindow", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setAutoSipEnabled(PyObject* self, PyObject* pyArg)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoSipEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoSipEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setAutoSipEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoSipEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoSipEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setAutoSipEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setAutoSipEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setColorSpec(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColorSpec(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setColorSpec(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setColorSpec_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColorSpec(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setColorSpec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setColorSpec_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setColorSpec", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setCursorFlashTime(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursorFlashTime(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCursorFlashTime(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setCursorFlashTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCursorFlashTime(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setCursorFlashTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setCursorFlashTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setCursorFlashTime", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setDesktopSettingsAware(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDesktopSettingsAware(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDesktopSettingsAware(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setDesktopSettingsAware_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDesktopSettingsAware(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setDesktopSettingsAware(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setDesktopSettingsAware_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setDesktopSettingsAware", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setDoubleClickInterval(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDoubleClickInterval(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setDoubleClickInterval(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setDoubleClickInterval_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDoubleClickInterval(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setDoubleClickInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setDoubleClickInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setDoubleClickInterval", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setEffectEnabled(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setEffectEnabled(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setEffectEnabled(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setEffectEnabled", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setEffectEnabled(Qt::UIEffect,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setEffectEnabled(Qt::UIEffect,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setEffectEnabled(Qt::UIEffect,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setEffectEnabled_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "enable");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setEffectEnabled(): got multiple values for keyword argument 'enable'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QApplicationFunc_setEffectEnabled_TypeError;
            }
        }
        ::Qt::UIEffect cppArg0 = ((::Qt::UIEffect)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setEffectEnabled(Qt::UIEffect,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setEffectEnabled(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setEffectEnabled_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.UIEffect, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.setEffectEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setFont(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setFont(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setFont(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setFont", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFont(QFont,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setFont(QFont,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // setFont(QFont,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setFont_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "className");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setFont(): got multiple values for keyword argument 'className'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                    goto Sbk_QApplicationFunc_setFont_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        const char* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFont(QFont,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setFont(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setGlobalStrut(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGlobalStrut(QSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setGlobalStrut(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setGlobalStrut_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setGlobalStrut(QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setGlobalStrut(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setGlobalStrut_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setGlobalStrut", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setGraphicsSystem(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGraphicsSystem(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setGraphicsSystem(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setGraphicsSystem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGraphicsSystem(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setGraphicsSystem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setGraphicsSystem_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setGraphicsSystem", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setInputContext(PyObject* self, PyObject* pyArg)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInputContext(QInputContext*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTCONTEXT_IDX], (pyArg)))) {
        overloadId = 0; // setInputContext(QInputContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setInputContext_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputContext* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInputContext(QInputContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInputContext(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setInputContext_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputContext", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setInputContext", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setKeyboardInputInterval(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setKeyboardInputInterval(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setKeyboardInputInterval(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setKeyboardInputInterval_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setKeyboardInputInterval(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setKeyboardInputInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setKeyboardInputInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setKeyboardInputInterval", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setLayoutDirection(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLayoutDirection(Qt::LayoutDirection)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setLayoutDirection(Qt::LayoutDirection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setLayoutDirection_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLayoutDirection(Qt::LayoutDirection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setLayoutDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setLayoutDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setLayoutDirection", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setOverrideCursor(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOverrideCursor(QCursor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // setOverrideCursor(QCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setOverrideCursor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCursor cppArg0_local = ::QCursor();
        ::QCursor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setOverrideCursor(QCursor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setOverrideCursor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setOverrideCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setOverrideCursor", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setPalette(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setPalette(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setPalette(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setPalette", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPalette(QPalette,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setPalette(QPalette,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // setPalette(QPalette,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setPalette_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "className");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QApplication.setPalette(): got multiple values for keyword argument 'className'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                    goto Sbk_QApplicationFunc_setPalette_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPalette cppArg0_local = ::QPalette();
        ::QPalette* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        const char* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setPalette(QPalette,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setPalette(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setPalette_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.setPalette", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setQuitOnLastWindowClosed(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQuitOnLastWindowClosed(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setQuitOnLastWindowClosed(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setQuitOnLastWindowClosed_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setQuitOnLastWindowClosed(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setQuitOnLastWindowClosed(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setQuitOnLastWindowClosed_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setQuitOnLastWindowClosed", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setStartDragDistance(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartDragDistance(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setStartDragDistance(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setStartDragDistance_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStartDragDistance(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setStartDragDistance(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setStartDragDistance_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setStartDragDistance", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setStartDragTime(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartDragTime(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setStartDragTime(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setStartDragTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStartDragTime(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setStartDragTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setStartDragTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setStartDragTime", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setStyle(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyle(QStyle*)
    // 1: setStyle(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (pyArg)))) {
        overloadId = 0; // setStyle(QStyle*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setStyle(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setStyle_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setStyle(QStyle * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QStyle* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setStyle(QStyle*)

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QApplication::setStyle(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                // Begin code injection

                Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyArg);

                // End of code injection
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // setStyle(const QString & arg__1)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setStyle(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStyle * cppResult = ::QApplication::setStyle(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_setStyle_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setStyle", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setStyleSheet(PyObject* self, PyObject* pyArg)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyleSheet(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStyleSheet(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setStyleSheet_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyleSheet(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyleSheet(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setStyleSheet_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setStyleSheet", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setWheelScrollLines(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWheelScrollLines(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setWheelScrollLines(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setWheelScrollLines_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWheelScrollLines(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setWheelScrollLines(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setWheelScrollLines_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setWheelScrollLines", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_setWindowIcon(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWindowIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setWindowIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_setWindowIcon_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QIcon cppArg0_local = ::QIcon();
        ::QIcon* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setWindowIcon(QIcon)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::setWindowIcon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QApplicationFunc_setWindowIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QApplication.setWindowIcon", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_startDragDistance(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startDragDistance()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::startDragDistance();
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

static PyObject* Sbk_QApplicationFunc_startDragTime(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startDragTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::startDragTime();
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

static PyObject* Sbk_QApplicationFunc_style(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStyle * cppResult = ::QApplication::style();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], cppResult);

            // Begin code injection

            // TEMPLATE - set_qapp_parent_for_orphan - START
            if (pyResult && (pyResult != Py_None)) {
                SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                if (!Shiboken::Object::hasParentInfo(_pySelf))
                    Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
            }
            // TEMPLATE - set_qapp_parent_for_orphan - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_styleSheet(PyObject* self)
{
    ::QApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // styleSheet()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QApplication*>(cppSelf)->styleSheet();
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

static PyObject* Sbk_QApplicationFunc_syncX(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // syncX()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QApplication::syncX();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QApplicationFunc_topLevelAt(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "topLevelAt", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: topLevelAt(QPoint)
    // 1: topLevelAt(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // topLevelAt(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // topLevelAt(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_topLevelAt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // topLevelAt(const QPoint & p)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // topLevelAt(QPoint)

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QWidget * cppResult = ::QApplication::topLevelAt(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

                // Begin code injection

                // TEMPLATE - set_qapp_parent_for_orphan - START
                if (pyResult && (pyResult != Py_None)) {
                    SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                    if (!Shiboken::Object::hasParentInfo(_pySelf))
                        Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
                }
                // TEMPLATE - set_qapp_parent_for_orphan - END

                // End of code injection
            }
            break;
        }
        case 1: // topLevelAt(int x, int y)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // topLevelAt(int,int)

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QWidget * cppResult = ::QApplication::topLevelAt(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

                // Begin code injection

                // TEMPLATE - set_qapp_parent_for_orphan - START
                if (pyResult && (pyResult != Py_None)) {
                    SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                    if (!Shiboken::Object::hasParentInfo(_pySelf))
                        Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
                }
                // TEMPLATE - set_qapp_parent_for_orphan - END

                // End of code injection
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_topLevelAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.topLevelAt", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_topLevelWidgets(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topLevelWidgets()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWidget * > cppResult = ::QApplication::topLevelWidgets();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIDGETPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_type(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QApplication::Type cppResult = ::QApplication::type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QApplicationFunc_wheelScrollLines(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wheelScrollLines()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QApplication::wheelScrollLines();
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

static PyObject* Sbk_QApplicationFunc_widgetAt(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "widgetAt", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: widgetAt(QPoint)
    // 1: widgetAt(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // widgetAt(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // widgetAt(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QApplicationFunc_widgetAt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // widgetAt(const QPoint & p)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // widgetAt(QPoint)

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QWidget * cppResult = ::QApplication::widgetAt(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

                // Begin code injection

                // TEMPLATE - set_qapp_parent_for_orphan - START
                if (pyResult && (pyResult != Py_None)) {
                    SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                    if (!Shiboken::Object::hasParentInfo(_pySelf))
                        Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
                }
                // TEMPLATE - set_qapp_parent_for_orphan - END

                // End of code injection
            }
            break;
        }
        case 1: // widgetAt(int x, int y)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // widgetAt(int,int)

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QWidget * cppResult = ::QApplication::widgetAt(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

                // Begin code injection

                // TEMPLATE - set_qapp_parent_for_orphan - START
                if (pyResult && (pyResult != Py_None)) {
                    SbkObject* _pySelf = reinterpret_cast<SbkObject*>(pyResult);
                    if (!Shiboken::Object::hasParentInfo(_pySelf))
                        Shiboken::Object::setParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp), pyResult);
                }
                // TEMPLATE - set_qapp_parent_for_orphan - END

                // End of code injection
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QApplicationFunc_widgetAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QApplication.widgetAt", overloads);
        return 0;
}

static PyObject* Sbk_QApplicationFunc_windowIcon(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // windowIcon()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = ::QApplication::windowIcon();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QApplication_methods[] = {
    {"aboutQt", (PyCFunction)Sbk_QApplicationFunc_aboutQt, METH_NOARGS|METH_STATIC},
    {"activeModalWidget", (PyCFunction)Sbk_QApplicationFunc_activeModalWidget, METH_NOARGS|METH_STATIC},
    {"activePopupWidget", (PyCFunction)Sbk_QApplicationFunc_activePopupWidget, METH_NOARGS|METH_STATIC},
    {"activeWindow", (PyCFunction)Sbk_QApplicationFunc_activeWindow, METH_NOARGS|METH_STATIC},
    {"alert", (PyCFunction)Sbk_QApplicationFunc_alert, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"allWidgets", (PyCFunction)Sbk_QApplicationFunc_allWidgets, METH_NOARGS|METH_STATIC},
    {"autoSipEnabled", (PyCFunction)Sbk_QApplicationFunc_autoSipEnabled, METH_NOARGS},
    {"beep", (PyCFunction)Sbk_QApplicationFunc_beep, METH_NOARGS|METH_STATIC},
    {"changeOverrideCursor", (PyCFunction)Sbk_QApplicationFunc_changeOverrideCursor, METH_O|METH_STATIC},
    {"clipboard", (PyCFunction)Sbk_QApplicationFunc_clipboard, METH_NOARGS|METH_STATIC},
    {"closeAllWindows", (PyCFunction)Sbk_QApplicationFunc_closeAllWindows, METH_NOARGS|METH_STATIC},
    {"colorSpec", (PyCFunction)Sbk_QApplicationFunc_colorSpec, METH_NOARGS|METH_STATIC},
    {"commitData", (PyCFunction)Sbk_QApplicationFunc_commitData, METH_O},
    {"cursorFlashTime", (PyCFunction)Sbk_QApplicationFunc_cursorFlashTime, METH_NOARGS|METH_STATIC},
    {"desktop", (PyCFunction)Sbk_QApplicationFunc_desktop, METH_NOARGS|METH_STATIC},
    {"desktopSettingsAware", (PyCFunction)Sbk_QApplicationFunc_desktopSettingsAware, METH_NOARGS|METH_STATIC},
    {"doubleClickInterval", (PyCFunction)Sbk_QApplicationFunc_doubleClickInterval, METH_NOARGS|METH_STATIC},
    {"event", (PyCFunction)Sbk_QApplicationFunc_event, METH_O},
    {"exec_", (PyCFunction)Sbk_QApplicationFunc_exec_, METH_NOARGS|METH_STATIC},
    {"focusWidget", (PyCFunction)Sbk_QApplicationFunc_focusWidget, METH_NOARGS|METH_STATIC},
    {"font", (PyCFunction)Sbk_QApplicationFunc_font, METH_VARARGS|METH_STATIC},
    {"fontMetrics", (PyCFunction)Sbk_QApplicationFunc_fontMetrics, METH_NOARGS|METH_STATIC},
    {"globalStrut", (PyCFunction)Sbk_QApplicationFunc_globalStrut, METH_NOARGS|METH_STATIC},
    {"inputContext", (PyCFunction)Sbk_QApplicationFunc_inputContext, METH_NOARGS},
    {"isEffectEnabled", (PyCFunction)Sbk_QApplicationFunc_isEffectEnabled, METH_O|METH_STATIC},
    {"isLeftToRight", (PyCFunction)Sbk_QApplicationFunc_isLeftToRight, METH_NOARGS|METH_STATIC},
    {"isRightToLeft", (PyCFunction)Sbk_QApplicationFunc_isRightToLeft, METH_NOARGS|METH_STATIC},
    {"isSessionRestored", (PyCFunction)Sbk_QApplicationFunc_isSessionRestored, METH_NOARGS},
    {"keyboardInputDirection", (PyCFunction)Sbk_QApplicationFunc_keyboardInputDirection, METH_NOARGS|METH_STATIC},
    {"keyboardInputInterval", (PyCFunction)Sbk_QApplicationFunc_keyboardInputInterval, METH_NOARGS|METH_STATIC},
    {"keyboardInputLocale", (PyCFunction)Sbk_QApplicationFunc_keyboardInputLocale, METH_NOARGS|METH_STATIC},
    {"keyboardModifiers", (PyCFunction)Sbk_QApplicationFunc_keyboardModifiers, METH_NOARGS|METH_STATIC},
    {"layoutDirection", (PyCFunction)Sbk_QApplicationFunc_layoutDirection, METH_NOARGS|METH_STATIC},
    {"mouseButtons", (PyCFunction)Sbk_QApplicationFunc_mouseButtons, METH_NOARGS|METH_STATIC},
    {"notify", (PyCFunction)Sbk_QApplicationFunc_notify, METH_VARARGS},
    {"overrideCursor", (PyCFunction)Sbk_QApplicationFunc_overrideCursor, METH_NOARGS|METH_STATIC},
    {"palette", (PyCFunction)Sbk_QApplicationFunc_palette, METH_VARARGS|METH_STATIC},
    {"queryKeyboardModifiers", (PyCFunction)Sbk_QApplicationFunc_queryKeyboardModifiers, METH_NOARGS|METH_STATIC},
    {"quitOnLastWindowClosed", (PyCFunction)Sbk_QApplicationFunc_quitOnLastWindowClosed, METH_NOARGS|METH_STATIC},
    {"restoreOverrideCursor", (PyCFunction)Sbk_QApplicationFunc_restoreOverrideCursor, METH_NOARGS|METH_STATIC},
    {"saveState", (PyCFunction)Sbk_QApplicationFunc_saveState, METH_O},
    {"sessionId", (PyCFunction)Sbk_QApplicationFunc_sessionId, METH_NOARGS},
    {"sessionKey", (PyCFunction)Sbk_QApplicationFunc_sessionKey, METH_NOARGS},
    {"setActiveWindow", (PyCFunction)Sbk_QApplicationFunc_setActiveWindow, METH_O|METH_STATIC},
    {"setAutoSipEnabled", (PyCFunction)Sbk_QApplicationFunc_setAutoSipEnabled, METH_O},
    {"setColorSpec", (PyCFunction)Sbk_QApplicationFunc_setColorSpec, METH_O|METH_STATIC},
    {"setCursorFlashTime", (PyCFunction)Sbk_QApplicationFunc_setCursorFlashTime, METH_O|METH_STATIC},
    {"setDesktopSettingsAware", (PyCFunction)Sbk_QApplicationFunc_setDesktopSettingsAware, METH_O|METH_STATIC},
    {"setDoubleClickInterval", (PyCFunction)Sbk_QApplicationFunc_setDoubleClickInterval, METH_O|METH_STATIC},
    {"setEffectEnabled", (PyCFunction)Sbk_QApplicationFunc_setEffectEnabled, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setFont", (PyCFunction)Sbk_QApplicationFunc_setFont, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setGlobalStrut", (PyCFunction)Sbk_QApplicationFunc_setGlobalStrut, METH_O|METH_STATIC},
    {"setGraphicsSystem", (PyCFunction)Sbk_QApplicationFunc_setGraphicsSystem, METH_O|METH_STATIC},
    {"setInputContext", (PyCFunction)Sbk_QApplicationFunc_setInputContext, METH_O},
    {"setKeyboardInputInterval", (PyCFunction)Sbk_QApplicationFunc_setKeyboardInputInterval, METH_O|METH_STATIC},
    {"setLayoutDirection", (PyCFunction)Sbk_QApplicationFunc_setLayoutDirection, METH_O|METH_STATIC},
    {"setOverrideCursor", (PyCFunction)Sbk_QApplicationFunc_setOverrideCursor, METH_O|METH_STATIC},
    {"setPalette", (PyCFunction)Sbk_QApplicationFunc_setPalette, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setQuitOnLastWindowClosed", (PyCFunction)Sbk_QApplicationFunc_setQuitOnLastWindowClosed, METH_O|METH_STATIC},
    {"setStartDragDistance", (PyCFunction)Sbk_QApplicationFunc_setStartDragDistance, METH_O|METH_STATIC},
    {"setStartDragTime", (PyCFunction)Sbk_QApplicationFunc_setStartDragTime, METH_O|METH_STATIC},
    {"setStyle", (PyCFunction)Sbk_QApplicationFunc_setStyle, METH_O|METH_STATIC},
    {"setStyleSheet", (PyCFunction)Sbk_QApplicationFunc_setStyleSheet, METH_O},
    {"setWheelScrollLines", (PyCFunction)Sbk_QApplicationFunc_setWheelScrollLines, METH_O|METH_STATIC},
    {"setWindowIcon", (PyCFunction)Sbk_QApplicationFunc_setWindowIcon, METH_O|METH_STATIC},
    {"startDragDistance", (PyCFunction)Sbk_QApplicationFunc_startDragDistance, METH_NOARGS|METH_STATIC},
    {"startDragTime", (PyCFunction)Sbk_QApplicationFunc_startDragTime, METH_NOARGS|METH_STATIC},
    {"style", (PyCFunction)Sbk_QApplicationFunc_style, METH_NOARGS|METH_STATIC},
    {"styleSheet", (PyCFunction)Sbk_QApplicationFunc_styleSheet, METH_NOARGS},
    {"syncX", (PyCFunction)Sbk_QApplicationFunc_syncX, METH_NOARGS|METH_STATIC},
    {"topLevelAt", (PyCFunction)Sbk_QApplicationFunc_topLevelAt, METH_VARARGS|METH_STATIC},
    {"topLevelWidgets", (PyCFunction)Sbk_QApplicationFunc_topLevelWidgets, METH_NOARGS|METH_STATIC},
    {"type", (PyCFunction)Sbk_QApplicationFunc_type, METH_NOARGS|METH_STATIC},
    {"wheelScrollLines", (PyCFunction)Sbk_QApplicationFunc_wheelScrollLines, METH_NOARGS|METH_STATIC},
    {"widgetAt", (PyCFunction)Sbk_QApplicationFunc_widgetAt, METH_VARARGS|METH_STATIC},
    {"windowIcon", (PyCFunction)Sbk_QApplicationFunc_windowIcon, METH_NOARGS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QApplication_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QApplication_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QApplication_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QApplication",
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
    /*tp_traverse*/         Sbk_QApplication_traverse,
    /*tp_clear*/            Sbk_QApplication_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QApplication_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QApplication_Init,
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

static void* Sbk_QApplication_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QApplication*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QApplication_Type_PythonToCpp_QApplication_Type(PyObject* pyIn, void* cppOut) {
    *((::QApplication::Type*)cppOut) = (::QApplication::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QApplication_Type_PythonToCpp_QApplication_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX]))
        return QApplication_Type_PythonToCpp_QApplication_Type;
    return 0;
}
static PyObject* QApplication_Type_CppToPython_QApplication_Type(const void* cppIn) {
    int castCppIn = *((::QApplication::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX], castCppIn);

}

static void QApplication_ColorSpec_PythonToCpp_QApplication_ColorSpec(PyObject* pyIn, void* cppOut) {
    *((::QApplication::ColorSpec*)cppOut) = (::QApplication::ColorSpec) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QApplication_ColorSpec_PythonToCpp_QApplication_ColorSpec_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX]))
        return QApplication_ColorSpec_PythonToCpp_QApplication_ColorSpec;
    return 0;
}
static PyObject* QApplication_ColorSpec_CppToPython_QApplication_ColorSpec(const void* cppIn) {
    int castCppIn = *((::QApplication::ColorSpec*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QApplication_PythonToCpp_QApplication_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QApplication_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QApplication_PythonToCpp_QApplication_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QApplication_Type))
        return QApplication_PythonToCpp_QApplication_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QApplication_PTR_CppToPython_QApplication(const void* cppIn) {
    return PySide::getWrapperForQObject((::QApplication*)cppIn, &Sbk_QApplication_Type);

}

void init_QApplication(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QApplication_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QApplication", "QApplication*",
        &Sbk_QApplication_Type, &Shiboken::callCppDestructor< ::QApplication >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QApplication_Type,
        QApplication_PythonToCpp_QApplication_PTR,
        is_QApplication_PythonToCpp_QApplication_PTR_Convertible,
        QApplication_PTR_CppToPython_QApplication);

    Shiboken::Conversions::registerConverterName(converter, "QApplication");
    Shiboken::Conversions::registerConverterName(converter, "QApplication*");
    Shiboken::Conversions::registerConverterName(converter, "QApplication&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QApplication).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QApplicationWrapper).name());



    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QApplication_Type, &Sbk_QApplication_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QApplication_Type,
        "Type",
        "PySide.QtGui.QApplication.Type",
        "QApplication::Type");
    if (!SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX],
        &Sbk_QApplication_Type, "Tty", (long) QApplication::Tty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX],
        &Sbk_QApplication_Type, "GuiClient", (long) QApplication::GuiClient))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX],
        &Sbk_QApplication_Type, "GuiServer", (long) QApplication::GuiServer))
        return ;
    // Register converter for enum 'QApplication::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX],
            QApplication_Type_CppToPython_QApplication_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QApplication_Type_PythonToCpp_QApplication_Type,
            is_QApplication_Type_PythonToCpp_QApplication_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QApplication::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.

    // Initialization of enum 'ColorSpec'.
    SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QApplication_Type,
        "ColorSpec",
        "PySide.QtGui.QApplication.ColorSpec",
        "QApplication::ColorSpec");
    if (!SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX],
        &Sbk_QApplication_Type, "NormalColor", (long) QApplication::NormalColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX],
        &Sbk_QApplication_Type, "CustomColor", (long) QApplication::CustomColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX],
        &Sbk_QApplication_Type, "ManyColor", (long) QApplication::ManyColor))
        return ;
    // Register converter for enum 'QApplication::ColorSpec'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX],
            QApplication_ColorSpec_CppToPython_QApplication_ColorSpec);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QApplication_ColorSpec_PythonToCpp_QApplication_ColorSpec,
            is_QApplication_ColorSpec_PythonToCpp_QApplication_ColorSpec_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QAPPLICATION_COLORSPEC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QApplication::ColorSpec");
        Shiboken::Conversions::registerConverterName(converter, "ColorSpec");
    }
    // End of 'ColorSpec' enum.

    PySide::Signal::registerSignals(&Sbk_QApplication_Type, &::QApplication::staticMetaObject);


    qRegisterMetaType< ::QApplication::Type >("QApplication::Type");
    qRegisterMetaType< ::QApplication::ColorSpec >("QApplication::ColorSpec");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QApplication_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QApplication_Type, &::QApplication::staticMetaObject, sizeof(::QApplication));
}

