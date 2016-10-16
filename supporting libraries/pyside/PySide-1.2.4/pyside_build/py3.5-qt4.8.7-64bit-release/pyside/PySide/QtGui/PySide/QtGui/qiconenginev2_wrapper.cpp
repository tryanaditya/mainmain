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

#include "qiconenginev2_wrapper.h"

// Extra includes
#include <QList>
#include <qdatastream.h>
#include <qiconengine.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qrect.h>
#include <qsize.h>


// Native ---------------------------------------------------------

QIconEngineV2Wrapper::QIconEngineV2Wrapper() : QIconEngineV2() {
    // ... middle
}

QSize QIconEngineV2Wrapper::actualSize(const QSize & size, QIcon::Mode mode, QIcon::State state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "actualSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngine::actualSize(size, mode, state);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &size),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), &mode),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), &state)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QIconEngineV2.actualSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QIconEngineV2Wrapper::addFile(const QString & fileName, const QSize & size, QIcon::Mode mode, QIcon::State state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addFile"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngine::addFile(fileName, size, mode, state);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &fileName),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &size),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), &mode),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), &state)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QIconEngineV2Wrapper::addPixmap(const QPixmap & pixmap, QIcon::Mode mode, QIcon::State state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addPixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngine::addPixmap(pixmap, mode, state);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &pixmap),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), &mode),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), &state)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QIconEngineV2 * QIconEngineV2Wrapper::clone() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QIconEngineV2*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clone"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngineV2::clone();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QIconEngineV2*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QIconEngineV2.clone", Shiboken::SbkType< QIconEngineV2 >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QIconEngineV2*)0);
    }
    ::QIconEngineV2* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QIconEngineV2Wrapper::key() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "key"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngineV2::key();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QIconEngineV2.key", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QIconEngineV2Wrapper::paint(QPainter * painter, const QRect & rect, QIcon::Mode mode, QIcon::State state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paint"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QIconEngineV2.paint()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), &mode),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), &state)
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

QPixmap QIconEngineV2Wrapper::pixmap(const QSize & size, QIcon::Mode mode, QIcon::State state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPixmap();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngine::pixmap(size, mode, state);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &size),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), &mode),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), &state)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPixmap();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QIconEngineV2.pixmap", Shiboken::SbkType< QPixmap >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPixmap();
    }
    ::QPixmap cppResult = ::QPixmap();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QIconEngineV2Wrapper::read(QDataStream & in)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "read"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngineV2::read(in);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &in)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QIconEngineV2.read", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QIconEngineV2Wrapper::write(QDataStream & out) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "write"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIconEngineV2::write(out);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &out)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QIconEngineV2.write", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

QIconEngineV2Wrapper::~QIconEngineV2Wrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QIconEngineV2_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QIconEngineV2' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QIconEngineV2 >()))
        return -1;

    ::QIconEngineV2Wrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QIconEngineV2()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QIconEngineV2Wrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QIconEngineV2 >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QIconEngineV2Func_availableSizes(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIconEngineV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIconEngineV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIconEngineV2.availableSizes(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:availableSizes", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: availableSizes(QIcon::Mode,QIcon::State)
    if (numArgs == 0) {
        overloadId = 0; // availableSizes(QIcon::Mode,QIcon::State)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // availableSizes(QIcon::Mode,QIcon::State)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // availableSizes(QIcon::Mode,QIcon::State)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconEngineV2Func_availableSizes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIconEngineV2.availableSizes(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QIconEngineV2Func_availableSizes_TypeError;
            }
            value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIconEngineV2.availableSizes(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[1]))))
                    goto Sbk_QIconEngineV2Func_availableSizes_TypeError;
            }
        }
        ::QIcon::Mode cppArg0 = QIcon::Normal;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QIcon::State cppArg1 = QIcon::Off;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // availableSizes(QIcon::Mode,QIcon::State)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSize > cppResult = cppSelf->availableSizes(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconEngineV2Func_availableSizes_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon.Mode = QIcon.Normal, PySide.QtGui.QIcon.State = QIcon.Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIconEngineV2.availableSizes", overloads);
        return 0;
}

static PyObject* Sbk_QIconEngineV2Func_clone(PyObject* self)
{
    ::QIconEngineV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIconEngineV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clone()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIconEngineV2 * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QIconEngineV2*>(cppSelf)->::QIconEngineV2::clone() : const_cast<const ::QIconEngineV2*>(cppSelf)->clone();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QIconEngineV2Func_iconName(PyObject* self)
{
    ::QIconEngineV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIconEngineV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->iconName();
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

static PyObject* Sbk_QIconEngineV2Func_key(PyObject* self)
{
    ::QIconEngineV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIconEngineV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // key()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QIconEngineV2*>(cppSelf)->::QIconEngineV2::key() : const_cast<const ::QIconEngineV2*>(cppSelf)->key();
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

static PyObject* Sbk_QIconEngineV2Func_read(PyObject* self, PyObject* pyArg)
{
    ::QIconEngineV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIconEngineV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(QDataStream&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // read(QDataStream&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconEngineV2Func_read_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(QDataStream&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QIconEngineV2::read(*cppArg0) : cppSelf->read(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconEngineV2Func_read_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIconEngineV2.read", overloads);
        return 0;
}

static PyObject* Sbk_QIconEngineV2Func_write(PyObject* self, PyObject* pyArg)
{
    ::QIconEngineV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIconEngineV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: write(QDataStream&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // write(QDataStream&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconEngineV2Func_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // write(QDataStream&)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QIconEngineV2*>(cppSelf)->::QIconEngineV2::write(*cppArg0) : const_cast<const ::QIconEngineV2*>(cppSelf)->write(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconEngineV2Func_write_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIconEngineV2.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QIconEngineV2_methods[] = {
    {"availableSizes", (PyCFunction)Sbk_QIconEngineV2Func_availableSizes, METH_VARARGS|METH_KEYWORDS},
    {"clone", (PyCFunction)Sbk_QIconEngineV2Func_clone, METH_NOARGS},
    {"iconName", (PyCFunction)Sbk_QIconEngineV2Func_iconName, METH_NOARGS},
    {"key", (PyCFunction)Sbk_QIconEngineV2Func_key, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QIconEngineV2Func_read, METH_O},
    {"write", (PyCFunction)Sbk_QIconEngineV2Func_write, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QIconEngineV2_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QIconEngineV2_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QIconEngineV2_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QIconEngineV2",
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
    /*tp_traverse*/         Sbk_QIconEngineV2_traverse,
    /*tp_clear*/            Sbk_QIconEngineV2_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QIconEngineV2_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QIconEngineV2_Init,
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

static void* Sbk_QIconEngineV2_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QIconEngine >()))
        return dynamic_cast< ::QIconEngineV2*>(reinterpret_cast< ::QIconEngine*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QIconEngineV2_IconEngineHook_PythonToCpp_QIconEngineV2_IconEngineHook(PyObject* pyIn, void* cppOut) {
    *((::QIconEngineV2::IconEngineHook*)cppOut) = (::QIconEngineV2::IconEngineHook) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QIconEngineV2_IconEngineHook_PythonToCpp_QIconEngineV2_IconEngineHook_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX]))
        return QIconEngineV2_IconEngineHook_PythonToCpp_QIconEngineV2_IconEngineHook;
    return 0;
}
static PyObject* QIconEngineV2_IconEngineHook_CppToPython_QIconEngineV2_IconEngineHook(const void* cppIn) {
    int castCppIn = *((::QIconEngineV2::IconEngineHook*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QIconEngineV2_PythonToCpp_QIconEngineV2_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QIconEngineV2_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QIconEngineV2_PythonToCpp_QIconEngineV2_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QIconEngineV2_Type))
        return QIconEngineV2_PythonToCpp_QIconEngineV2_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QIconEngineV2_PTR_CppToPython_QIconEngineV2(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QIconEngineV2*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QIconEngineV2_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QIconEngineV2(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QIconEngineV2_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QIconEngineV2", "QIconEngineV2*",
        &Sbk_QIconEngineV2_Type, &Shiboken::callCppDestructor< ::QIconEngineV2 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICONENGINE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QIconEngineV2_Type,
        QIconEngineV2_PythonToCpp_QIconEngineV2_PTR,
        is_QIconEngineV2_PythonToCpp_QIconEngineV2_PTR_Convertible,
        QIconEngineV2_PTR_CppToPython_QIconEngineV2);

    Shiboken::Conversions::registerConverterName(converter, "QIconEngineV2");
    Shiboken::Conversions::registerConverterName(converter, "QIconEngineV2*");
    Shiboken::Conversions::registerConverterName(converter, "QIconEngineV2&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QIconEngineV2).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QIconEngineV2Wrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QIconEngineV2_Type, &Sbk_QIconEngineV2_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'IconEngineHook'.
    SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QIconEngineV2_Type,
        "IconEngineHook",
        "PySide.QtGui.QIconEngineV2.IconEngineHook",
        "QIconEngineV2::IconEngineHook");
    if (!SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX],
        &Sbk_QIconEngineV2_Type, "AvailableSizesHook", (long) QIconEngineV2::AvailableSizesHook))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX],
        &Sbk_QIconEngineV2_Type, "IconNameHook", (long) QIconEngineV2::IconNameHook))
        return ;
    // Register converter for enum 'QIconEngineV2::IconEngineHook'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX],
            QIconEngineV2_IconEngineHook_CppToPython_QIconEngineV2_IconEngineHook);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QIconEngineV2_IconEngineHook_PythonToCpp_QIconEngineV2_IconEngineHook,
            is_QIconEngineV2_IconEngineHook_PythonToCpp_QIconEngineV2_IconEngineHook_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_ICONENGINEHOOK_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QIconEngineV2::IconEngineHook");
        Shiboken::Conversions::registerConverterName(converter, "IconEngineHook");
    }
    // End of 'IconEngineHook' enum.


    qRegisterMetaType< ::QIconEngineV2::IconEngineHook >("QIconEngineV2::IconEngineHook");
}
