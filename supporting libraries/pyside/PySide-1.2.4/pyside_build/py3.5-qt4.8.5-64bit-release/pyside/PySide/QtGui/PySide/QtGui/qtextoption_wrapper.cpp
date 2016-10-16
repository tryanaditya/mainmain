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

#include "qtextoption_wrapper.h"
#include "qtextoption_tab_wrapper.h"

// Extra includes
#include <QList>
#include <qtextoption.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextOption_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextOption >()))
        return -1;

    ::QTextOption* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextOption", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextOption()
    // 1: QTextOption(QFlags<Qt::AlignmentFlag>)
    // 2: QTextOption(QTextOption)
    if (numArgs == 0) {
        overloadId = 0; // QTextOption()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 1; // QTextOption(QFlags<Qt::AlignmentFlag>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextOption(QTextOption)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOption_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextOption()
        {

            if (!PyErr_Occurred()) {
                // QTextOption()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextOption();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextOption(QFlags<Qt::AlignmentFlag> alignment)
        {
            ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextOption(QFlags<Qt::AlignmentFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextOption(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextOption(const QTextOption & o)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextOption cppArg0_local = ::QTextOption();
            ::QTextOption* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextOption(QTextOption)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextOption(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextOption >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextOption_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextOption_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.Qt.Alignment", "PySide.QtGui.QTextOption", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextOption", overloads);
        return -1;
}

static PyObject* Sbk_QTextOptionFunc_alignment(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QTextOption*>(cppSelf)->alignment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextOptionFunc_flags(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QTextOption::Flag> cppResult = const_cast<const ::QTextOption*>(cppSelf)->flags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextOptionFunc_setAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setAlignment_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlignment(QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setFlags(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFlags(QFlags<QTextOption::Flag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setFlags(QFlags<QTextOption::Flag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setFlags_TypeError;

    // Call function/method
    {
        ::QFlags<QTextOption::Flag> cppArg0 = ((::QFlags<QTextOption::Flag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFlags(QFlags<QTextOption::Flag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setFlags_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextOption.Flags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setFlags", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setTabArray(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabArray(QList<qreal>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QREAL_IDX], (pyArg)))) {
        overloadId = 0; // setTabArray(QList<qreal>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setTabArray_TypeError;

    // Call function/method
    {
        ::QList<qreal > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabArray(QList<qreal>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabArray(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setTabArray_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setTabArray", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setTabStop(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabStop(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTabStop(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setTabStop_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabStop(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabStop(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setTabStop_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setTabStop", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setTabs(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabs(QList<QTextOption::Tab>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX], (pyArg)))) {
        overloadId = 0; // setTabs(QList<QTextOption::Tab>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setTabs_TypeError;

    // Call function/method
    {
        ::QList<QTextOption::Tab > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabs(QList<QTextOption::Tab>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabs(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setTabs_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setTabs", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setTextDirection(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextDirection(Qt::LayoutDirection)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setTextDirection(Qt::LayoutDirection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setTextDirection_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextDirection(Qt::LayoutDirection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setTextDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setTextDirection", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setUseDesignMetrics(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUseDesignMetrics(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUseDesignMetrics(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setUseDesignMetrics_TypeError;

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

    Sbk_QTextOptionFunc_setUseDesignMetrics_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setUseDesignMetrics", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_setWrapMode(PyObject* self, PyObject* pyArg)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWrapMode(QTextOption::WrapMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setWrapMode(QTextOption::WrapMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOptionFunc_setWrapMode_TypeError;

    // Call function/method
    {
        ::QTextOption::WrapMode cppArg0 = ((::QTextOption::WrapMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWrapMode(QTextOption::WrapMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWrapMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextOptionFunc_setWrapMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextOption.WrapMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextOption.setWrapMode", overloads);
        return 0;
}

static PyObject* Sbk_QTextOptionFunc_tabArray(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabArray()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<qreal > cppResult = const_cast<const ::QTextOption*>(cppSelf)->tabArray();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QREAL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextOptionFunc_tabStop(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabStop()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextOption*>(cppSelf)->tabStop();
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

static PyObject* Sbk_QTextOptionFunc_tabs(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabs()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QTextOption::Tab > cppResult = const_cast<const ::QTextOption*>(cppSelf)->tabs();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextOptionFunc_textDirection(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = const_cast<const ::QTextOption*>(cppSelf)->textDirection();
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

static PyObject* Sbk_QTextOptionFunc_useDesignMetrics(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // useDesignMetrics()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextOption*>(cppSelf)->useDesignMetrics();
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

static PyObject* Sbk_QTextOptionFunc_wrapMode(PyObject* self)
{
    ::QTextOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wrapMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextOption::WrapMode cppResult = const_cast<const ::QTextOption*>(cppSelf)->wrapMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextOption___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextOption& cppSelf = *(((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextOption_methods[] = {
    {"alignment", (PyCFunction)Sbk_QTextOptionFunc_alignment, METH_NOARGS},
    {"flags", (PyCFunction)Sbk_QTextOptionFunc_flags, METH_NOARGS},
    {"setAlignment", (PyCFunction)Sbk_QTextOptionFunc_setAlignment, METH_O},
    {"setFlags", (PyCFunction)Sbk_QTextOptionFunc_setFlags, METH_O},
    {"setTabArray", (PyCFunction)Sbk_QTextOptionFunc_setTabArray, METH_O},
    {"setTabStop", (PyCFunction)Sbk_QTextOptionFunc_setTabStop, METH_O},
    {"setTabs", (PyCFunction)Sbk_QTextOptionFunc_setTabs, METH_O},
    {"setTextDirection", (PyCFunction)Sbk_QTextOptionFunc_setTextDirection, METH_O},
    {"setUseDesignMetrics", (PyCFunction)Sbk_QTextOptionFunc_setUseDesignMetrics, METH_O},
    {"setWrapMode", (PyCFunction)Sbk_QTextOptionFunc_setWrapMode, METH_O},
    {"tabArray", (PyCFunction)Sbk_QTextOptionFunc_tabArray, METH_NOARGS},
    {"tabStop", (PyCFunction)Sbk_QTextOptionFunc_tabStop, METH_NOARGS},
    {"tabs", (PyCFunction)Sbk_QTextOptionFunc_tabs, METH_NOARGS},
    {"textDirection", (PyCFunction)Sbk_QTextOptionFunc_textDirection, METH_NOARGS},
    {"useDesignMetrics", (PyCFunction)Sbk_QTextOptionFunc_useDesignMetrics, METH_NOARGS},
    {"wrapMode", (PyCFunction)Sbk_QTextOptionFunc_wrapMode, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextOption___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextOption_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextOption_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextOption_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextOption",
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
    /*tp_traverse*/         Sbk_QTextOption_traverse,
    /*tp_clear*/            Sbk_QTextOption_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextOption_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextOption_Init,
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

PyObject* SbkPySide_QtGui_QTextOption_Flag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextOption::Flags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextOption::Flags)PyLong_AsLong(self);
    cppArg = (QTextOption::Flags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextOption::Flags)PyInt_AsLong(self);
    cppArg = (QTextOption::Flags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextOption_Flag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextOption::Flags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextOption::Flags)PyLong_AsLong(self);
    cppArg = (QTextOption::Flags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextOption::Flags)PyInt_AsLong(self);
    cppArg = (QTextOption::Flags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextOption_Flag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextOption::Flags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextOption::Flags)PyLong_AsLong(self);
    cppArg = (QTextOption::Flags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextOption::Flags)PyInt_AsLong(self);
    cppArg = (QTextOption::Flags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextOption_Flag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextOption::Flags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), self, &cppSelf);
    ::QTextOption::Flags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QTextOption_Flag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QTextOption_Flag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QTextOption_Flag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QTextOption_Flag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QTextOption_Flag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QTextOption_Flag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QTextOption_Flag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QTextOption_Flag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QTextOption_Flag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QTextOption_Flag_long,
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
static void QTextOption_TabType_PythonToCpp_QTextOption_TabType(PyObject* pyIn, void* cppOut) {
    *((::QTextOption::TabType*)cppOut) = (::QTextOption::TabType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextOption_TabType_PythonToCpp_QTextOption_TabType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX]))
        return QTextOption_TabType_PythonToCpp_QTextOption_TabType;
    return 0;
}
static PyObject* QTextOption_TabType_CppToPython_QTextOption_TabType(const void* cppIn) {
    int castCppIn = *((::QTextOption::TabType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX], castCppIn);

}

static void QTextOption_WrapMode_PythonToCpp_QTextOption_WrapMode(PyObject* pyIn, void* cppOut) {
    *((::QTextOption::WrapMode*)cppOut) = (::QTextOption::WrapMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextOption_WrapMode_PythonToCpp_QTextOption_WrapMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX]))
        return QTextOption_WrapMode_PythonToCpp_QTextOption_WrapMode;
    return 0;
}
static PyObject* QTextOption_WrapMode_CppToPython_QTextOption_WrapMode(const void* cppIn) {
    int castCppIn = *((::QTextOption::WrapMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX], castCppIn);

}

static void QTextOption_Flag_PythonToCpp_QTextOption_Flag(PyObject* pyIn, void* cppOut) {
    *((::QTextOption::Flag*)cppOut) = (::QTextOption::Flag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextOption_Flag_PythonToCpp_QTextOption_Flag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX]))
        return QTextOption_Flag_PythonToCpp_QTextOption_Flag;
    return 0;
}
static PyObject* QTextOption_Flag_CppToPython_QTextOption_Flag(const void* cppIn) {
    int castCppIn = *((::QTextOption::Flag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX], castCppIn);

}

static void QFlags_QTextOption_Flag__PythonToCpp_QFlags_QTextOption_Flag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextOption::Flag>*)cppOut) = ::QFlags<QTextOption::Flag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextOption_Flag__PythonToCpp_QFlags_QTextOption_Flag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]))
        return QFlags_QTextOption_Flag__PythonToCpp_QFlags_QTextOption_Flag_;
    return 0;
}
static PyObject* QFlags_QTextOption_Flag__CppToPython_QFlags_QTextOption_Flag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextOption::Flag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]));

}

static void QTextOption_Flag_PythonToCpp_QFlags_QTextOption_Flag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextOption::Flag>*)cppOut) = ::QFlags<QTextOption::Flag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextOption_Flag_PythonToCpp_QFlags_QTextOption_Flag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX]))
        return QTextOption_Flag_PythonToCpp_QFlags_QTextOption_Flag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextOption_Flag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextOption::Flag>*)cppOut) = ::QFlags<QTextOption::Flag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextOption_Flag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextOption_Flag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextOption_PythonToCpp_QTextOption_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextOption_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextOption_PythonToCpp_QTextOption_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextOption_Type))
        return QTextOption_PythonToCpp_QTextOption_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextOption_PTR_CppToPython_QTextOption(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextOption*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextOption_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextOption_COPY_CppToPython_QTextOption(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextOption_Type, new ::QTextOption(*((::QTextOption*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextOption_PythonToCpp_QTextOption_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextOption*)cppOut) = *((::QTextOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextOption_PythonToCpp_QTextOption_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextOption_Type))
        return QTextOption_PythonToCpp_QTextOption_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_QFlags_Qt_AlignmentFlag__PythonToCpp_QTextOption(PyObject* pyIn, void* cppOut) {
    ::QFlags<Qt::AlignmentFlag> cppIn = ((::QFlags<Qt::AlignmentFlag>)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), pyIn, &cppIn);
    *((::QTextOption*)cppOut) = ::QTextOption(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_QFlags_Qt_AlignmentFlag__PythonToCpp_QTextOption_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX], pyIn))
        return PySide_QtCore_QFlags_Qt_AlignmentFlag__PythonToCpp_QTextOption;
    return 0;
}

void init_QTextOption(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextOption_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextOption", "QTextOption",
        &Sbk_QTextOption_Type, &Shiboken::callCppDestructor< ::QTextOption >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextOption_Type,
        QTextOption_PythonToCpp_QTextOption_PTR,
        is_QTextOption_PythonToCpp_QTextOption_PTR_Convertible,
        QTextOption_PTR_CppToPython_QTextOption,
        QTextOption_COPY_CppToPython_QTextOption);

    Shiboken::Conversions::registerConverterName(converter, "QTextOption");
    Shiboken::Conversions::registerConverterName(converter, "QTextOption*");
    Shiboken::Conversions::registerConverterName(converter, "QTextOption&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextOption).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextOption_PythonToCpp_QTextOption_COPY,
        is_QTextOption_PythonToCpp_QTextOption_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_QFlags_Qt_AlignmentFlag__PythonToCpp_QTextOption,
        is_PySide_QtCore_QFlags_Qt_AlignmentFlag__PythonToCpp_QTextOption_Convertible);

    // Initialization of enums.

    // Initialization of enum 'TabType'.
    SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextOption_Type,
        "TabType",
        "PySide.QtGui.QTextOption.TabType",
        "QTextOption::TabType");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX],
        &Sbk_QTextOption_Type, "LeftTab", (long) QTextOption::LeftTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX],
        &Sbk_QTextOption_Type, "RightTab", (long) QTextOption::RightTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX],
        &Sbk_QTextOption_Type, "CenterTab", (long) QTextOption::CenterTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX],
        &Sbk_QTextOption_Type, "DelimiterTab", (long) QTextOption::DelimiterTab))
        return ;
    // Register converter for enum 'QTextOption::TabType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX],
            QTextOption_TabType_CppToPython_QTextOption_TabType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextOption_TabType_PythonToCpp_QTextOption_TabType,
            is_QTextOption_TabType_PythonToCpp_QTextOption_TabType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextOption::TabType");
        Shiboken::Conversions::registerConverterName(converter, "TabType");
    }
    // End of 'TabType' enum.

    // Initialization of enum 'WrapMode'.
    SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextOption_Type,
        "WrapMode",
        "PySide.QtGui.QTextOption.WrapMode",
        "QTextOption::WrapMode");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX],
        &Sbk_QTextOption_Type, "NoWrap", (long) QTextOption::NoWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX],
        &Sbk_QTextOption_Type, "WordWrap", (long) QTextOption::WordWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX],
        &Sbk_QTextOption_Type, "ManualWrap", (long) QTextOption::ManualWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX],
        &Sbk_QTextOption_Type, "WrapAnywhere", (long) QTextOption::WrapAnywhere))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX],
        &Sbk_QTextOption_Type, "WrapAtWordBoundaryOrAnywhere", (long) QTextOption::WrapAtWordBoundaryOrAnywhere))
        return ;
    // Register converter for enum 'QTextOption::WrapMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX],
            QTextOption_WrapMode_CppToPython_QTextOption_WrapMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextOption_WrapMode_PythonToCpp_QTextOption_WrapMode,
            is_QTextOption_WrapMode_PythonToCpp_QTextOption_WrapMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextOption::WrapMode");
        Shiboken::Conversions::registerConverterName(converter, "WrapMode");
    }
    // End of 'WrapMode' enum.

    // Initialization of enum 'Flag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX] = PySide::QFlags::create("Flags", &SbkPySide_QtGui_QTextOption_Flag_as_number);
    SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextOption_Type,
        "Flag",
        "PySide.QtGui.QTextOption.Flag",
        "QTextOption::Flag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX],
        &Sbk_QTextOption_Type, "ShowTabsAndSpaces", (long) QTextOption::ShowTabsAndSpaces))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX],
        &Sbk_QTextOption_Type, "ShowLineAndParagraphSeparators", (long) QTextOption::ShowLineAndParagraphSeparators))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX],
        &Sbk_QTextOption_Type, "AddSpaceForLineAndParagraphSeparators", (long) QTextOption::AddSpaceForLineAndParagraphSeparators))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX],
        &Sbk_QTextOption_Type, "SuppressColors", (long) QTextOption::SuppressColors))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX],
        &Sbk_QTextOption_Type, "IncludeTrailingSpaces", (long) QTextOption::IncludeTrailingSpaces))
        return ;
    // Register converter for enum 'QTextOption::Flag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX],
            QTextOption_Flag_CppToPython_QTextOption_Flag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextOption_Flag_PythonToCpp_QTextOption_Flag,
            is_QTextOption_Flag_PythonToCpp_QTextOption_Flag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextOption::Flag");
        Shiboken::Conversions::registerConverterName(converter, "Flag");
    }
    // Register converter for flag 'QFlags<QTextOption::Flag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX],
            QFlags_QTextOption_Flag__CppToPython_QFlags_QTextOption_Flag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextOption_Flag_PythonToCpp_QFlags_QTextOption_Flag_,
            is_QTextOption_Flag_PythonToCpp_QFlags_QTextOption_Flag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextOption_Flag__PythonToCpp_QFlags_QTextOption_Flag_,
            is_QFlags_QTextOption_Flag__PythonToCpp_QFlags_QTextOption_Flag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextOption_Flag_,
            is_number_PythonToCpp_QFlags_QTextOption_Flag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextOption::Flag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Flag>");
    }
    // End of 'Flag' enum/flags.


    qRegisterMetaType< ::QTextOption >("QTextOption");
    qRegisterMetaType< ::QTextOption::TabType >("QTextOption::TabType");
    qRegisterMetaType< ::QTextOption::WrapMode >("QTextOption::WrapMode");
    qRegisterMetaType< ::QTextOption::Flag >("QTextOption::Flag");
    qRegisterMetaType< ::QTextOption::Flags >("QTextOption::Flags");
}
