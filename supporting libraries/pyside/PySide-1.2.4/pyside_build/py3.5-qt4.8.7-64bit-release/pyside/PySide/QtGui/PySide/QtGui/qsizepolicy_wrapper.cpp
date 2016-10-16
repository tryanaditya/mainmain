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

#include "qsizepolicy_wrapper.h"

// Extra includes
#include <qdatastream.h>
#include <qsizepolicy.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSizePolicy_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSizePolicy >()))
        return -1;

    ::QSizePolicy* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSizePolicy", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QSizePolicy()
    // 1: QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy)
    // 2: QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
    // 3: QSizePolicy(QSizePolicy)
    if (numArgs == 0) {
        overloadId = 0; // QSizePolicy()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (pyArgs[0])))) {
        overloadId = 3; // QSizePolicy(QSizePolicy)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[2])))) {
            overloadId = 2; // QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicy_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSizePolicy()
        {

            if (!PyErr_Occurred()) {
                // QSizePolicy()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSizePolicy();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical)
        {
            ::QSizePolicy::Policy cppArg0 = ((::QSizePolicy::Policy)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSizePolicy::Policy cppArg1 = ((::QSizePolicy::Policy)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSizePolicy(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical, QSizePolicy::ControlType type)
        {
            ::QSizePolicy::Policy cppArg0 = ((::QSizePolicy::Policy)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSizePolicy::Policy cppArg1 = ((::QSizePolicy::Policy)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QSizePolicy::ControlType cppArg2 = ((::QSizePolicy::ControlType)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSizePolicy(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QSizePolicy(const QSizePolicy & QSizePolicy)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSizePolicy cppArg0_local = ::QSizePolicy();
            ::QSizePolicy* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSizePolicy(QSizePolicy)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSizePolicy(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSizePolicy >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSizePolicy_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSizePolicy_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QSizePolicy.Policy, PySide.QtGui.QSizePolicy.Policy", "PySide.QtGui.QSizePolicy.Policy, PySide.QtGui.QSizePolicy.Policy, PySide.QtGui.QSizePolicy.ControlType", "PySide.QtGui.QSizePolicy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QSizePolicy", overloads);
        return -1;
}

static PyObject* Sbk_QSizePolicyFunc_controlType(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // controlType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizePolicy::ControlType cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->controlType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSizePolicyFunc_expandingDirections(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expandingDirections()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::Orientation> cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->expandingDirections();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSizePolicyFunc_hasHeightForWidth(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasHeightForWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->hasHeightForWidth();
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

static PyObject* Sbk_QSizePolicyFunc_hasWidthForHeight(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasWidthForHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->hasWidthForHeight();
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

static PyObject* Sbk_QSizePolicyFunc_horizontalPolicy(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizePolicy::Policy cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->horizontalPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSizePolicyFunc_horizontalStretch(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalStretch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->horizontalStretch();
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

static PyObject* Sbk_QSizePolicyFunc_setControlType(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setControlType(QSizePolicy::ControlType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setControlType(QSizePolicy::ControlType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setControlType_TypeError;

    // Call function/method
    {
        ::QSizePolicy::ControlType cppArg0 = ((::QSizePolicy::ControlType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setControlType(QSizePolicy::ControlType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setControlType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setControlType_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.ControlType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setControlType", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_setHeightForWidth(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHeightForWidth(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setHeightForWidth(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setHeightForWidth_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHeightForWidth(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHeightForWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setHeightForWidth_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setHeightForWidth", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_setHorizontalPolicy(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalPolicy(QSizePolicy::Policy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setHorizontalPolicy(QSizePolicy::Policy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setHorizontalPolicy_TypeError;

    // Call function/method
    {
        ::QSizePolicy::Policy cppArg0 = ((::QSizePolicy::Policy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHorizontalPolicy(QSizePolicy::Policy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setHorizontalPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.Policy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setHorizontalPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_setHorizontalStretch(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalStretch(uchar)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArg)))) {
        overloadId = 0; // setHorizontalStretch(uchar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setHorizontalStretch_TypeError;

    // Call function/method
    {
        uchar cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHorizontalStretch(uchar)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalStretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setHorizontalStretch_TypeError:
        const char* overloads[] = {"unsigned char", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setHorizontalStretch", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_setVerticalPolicy(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalPolicy(QSizePolicy::Policy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setVerticalPolicy(QSizePolicy::Policy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setVerticalPolicy_TypeError;

    // Call function/method
    {
        ::QSizePolicy::Policy cppArg0 = ((::QSizePolicy::Policy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalPolicy(QSizePolicy::Policy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setVerticalPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.Policy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setVerticalPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_setVerticalStretch(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalStretch(uchar)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArg)))) {
        overloadId = 0; // setVerticalStretch(uchar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setVerticalStretch_TypeError;

    // Call function/method
    {
        uchar cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalStretch(uchar)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalStretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setVerticalStretch_TypeError:
        const char* overloads[] = {"unsigned char", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setVerticalStretch", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_setWidthForHeight(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidthForHeight(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setWidthForHeight(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc_setWidthForHeight_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidthForHeight(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidthForHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSizePolicyFunc_setWidthForHeight_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.setWidthForHeight", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc_transpose(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transpose()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->transpose();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSizePolicyFunc_verticalPolicy(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizePolicy::Policy cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->verticalPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSizePolicyFunc_verticalStretch(PyObject* self)
{
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalStretch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSizePolicy*>(cppSelf)->verticalStretch();
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

static PyObject* Sbk_QSizePolicy___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSizePolicy& cppSelf = *(((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSizePolicy_methods[] = {
    {"controlType", (PyCFunction)Sbk_QSizePolicyFunc_controlType, METH_NOARGS},
    {"expandingDirections", (PyCFunction)Sbk_QSizePolicyFunc_expandingDirections, METH_NOARGS},
    {"hasHeightForWidth", (PyCFunction)Sbk_QSizePolicyFunc_hasHeightForWidth, METH_NOARGS},
    {"hasWidthForHeight", (PyCFunction)Sbk_QSizePolicyFunc_hasWidthForHeight, METH_NOARGS},
    {"horizontalPolicy", (PyCFunction)Sbk_QSizePolicyFunc_horizontalPolicy, METH_NOARGS},
    {"horizontalStretch", (PyCFunction)Sbk_QSizePolicyFunc_horizontalStretch, METH_NOARGS},
    {"setControlType", (PyCFunction)Sbk_QSizePolicyFunc_setControlType, METH_O},
    {"setHeightForWidth", (PyCFunction)Sbk_QSizePolicyFunc_setHeightForWidth, METH_O},
    {"setHorizontalPolicy", (PyCFunction)Sbk_QSizePolicyFunc_setHorizontalPolicy, METH_O},
    {"setHorizontalStretch", (PyCFunction)Sbk_QSizePolicyFunc_setHorizontalStretch, METH_O},
    {"setVerticalPolicy", (PyCFunction)Sbk_QSizePolicyFunc_setVerticalPolicy, METH_O},
    {"setVerticalStretch", (PyCFunction)Sbk_QSizePolicyFunc_setVerticalStretch, METH_O},
    {"setWidthForHeight", (PyCFunction)Sbk_QSizePolicyFunc_setWidthForHeight, METH_O},
    {"transpose", (PyCFunction)Sbk_QSizePolicyFunc_transpose, METH_NOARGS},
    {"verticalPolicy", (PyCFunction)Sbk_QSizePolicyFunc_verticalPolicy, METH_NOARGS},
    {"verticalStretch", (PyCFunction)Sbk_QSizePolicyFunc_verticalStretch, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSizePolicy___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QSizePolicyFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QSizePolicy)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QSizePolicy)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QSizePolicy) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSizePolicyFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QSizePolicyFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QSizePolicy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QSizePolicy&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QSizePolicy&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSizePolicyFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QSizePolicy&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSizePolicyFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSizePolicy.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QSizePolicy_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSizePolicy& cppSelf = *(((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (pyArg)))) {
                // operator!=(const QSizePolicy & s) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSizePolicy cppArg0_local = ::QSizePolicy();
                ::QSizePolicy* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (pyArg)))) {
                // operator==(const QSizePolicy & s) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSizePolicy cppArg0_local = ::QSizePolicy();
                ::QSizePolicy* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], pythonToCpp))
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
            goto Sbk_QSizePolicy_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSizePolicy_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSizePolicy_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSizePolicy_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QSizePolicy_TypeAsNumber;

static SbkObjectType Sbk_QSizePolicy_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QSizePolicy",
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
    /*tp_traverse*/         Sbk_QSizePolicy_traverse,
    /*tp_clear*/            Sbk_QSizePolicy_clear,
    /*tp_richcompare*/      Sbk_QSizePolicy_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSizePolicy_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSizePolicy_Init,
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

PyObject* SbkPySide_QtGui_QSizePolicy_ControlType___and__(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy::ControlTypes cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QSizePolicy::ControlTypes)PyLong_AsLong(self);
    cppArg = (QSizePolicy::ControlTypes)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QSizePolicy::ControlTypes)PyInt_AsLong(self);
    cppArg = (QSizePolicy::ControlTypes)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QSizePolicy_ControlType___or__(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy::ControlTypes cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QSizePolicy::ControlTypes)PyLong_AsLong(self);
    cppArg = (QSizePolicy::ControlTypes)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QSizePolicy::ControlTypes)PyInt_AsLong(self);
    cppArg = (QSizePolicy::ControlTypes)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QSizePolicy_ControlType___xor__(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy::ControlTypes cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QSizePolicy::ControlTypes)PyLong_AsLong(self);
    cppArg = (QSizePolicy::ControlTypes)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QSizePolicy::ControlTypes)PyInt_AsLong(self);
    cppArg = (QSizePolicy::ControlTypes)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QSizePolicy_ControlType___invert__(PyObject* self, PyObject* pyArg)
{
    ::QSizePolicy::ControlTypes cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), self, &cppSelf);
    ::QSizePolicy::ControlTypes cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QSizePolicy_ControlType_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QSizePolicy_ControlType__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QSizePolicy_ControlType_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QSizePolicy_ControlType__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QSizePolicy_ControlType___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QSizePolicy_ControlType___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QSizePolicy_ControlType___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QSizePolicy_ControlType___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QSizePolicy_ControlType_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QSizePolicy_ControlType_long,
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
static void QSizePolicy_PolicyFlag_PythonToCpp_QSizePolicy_PolicyFlag(PyObject* pyIn, void* cppOut) {
    *((::QSizePolicy::PolicyFlag*)cppOut) = (::QSizePolicy::PolicyFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSizePolicy_PolicyFlag_PythonToCpp_QSizePolicy_PolicyFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX]))
        return QSizePolicy_PolicyFlag_PythonToCpp_QSizePolicy_PolicyFlag;
    return 0;
}
static PyObject* QSizePolicy_PolicyFlag_CppToPython_QSizePolicy_PolicyFlag(const void* cppIn) {
    int castCppIn = *((::QSizePolicy::PolicyFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX], castCppIn);

}

static void QSizePolicy_Policy_PythonToCpp_QSizePolicy_Policy(PyObject* pyIn, void* cppOut) {
    *((::QSizePolicy::Policy*)cppOut) = (::QSizePolicy::Policy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSizePolicy_Policy_PythonToCpp_QSizePolicy_Policy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]))
        return QSizePolicy_Policy_PythonToCpp_QSizePolicy_Policy;
    return 0;
}
static PyObject* QSizePolicy_Policy_CppToPython_QSizePolicy_Policy(const void* cppIn) {
    int castCppIn = *((::QSizePolicy::Policy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX], castCppIn);

}

static void QSizePolicy_ControlType_PythonToCpp_QSizePolicy_ControlType(PyObject* pyIn, void* cppOut) {
    *((::QSizePolicy::ControlType*)cppOut) = (::QSizePolicy::ControlType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSizePolicy_ControlType_PythonToCpp_QSizePolicy_ControlType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]))
        return QSizePolicy_ControlType_PythonToCpp_QSizePolicy_ControlType;
    return 0;
}
static PyObject* QSizePolicy_ControlType_CppToPython_QSizePolicy_ControlType(const void* cppIn) {
    int castCppIn = *((::QSizePolicy::ControlType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX], castCppIn);

}

static void QFlags_QSizePolicy_ControlType__PythonToCpp_QFlags_QSizePolicy_ControlType_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QSizePolicy::ControlType>*)cppOut) = ::QFlags<QSizePolicy::ControlType>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QSizePolicy_ControlType__PythonToCpp_QFlags_QSizePolicy_ControlType__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]))
        return QFlags_QSizePolicy_ControlType__PythonToCpp_QFlags_QSizePolicy_ControlType_;
    return 0;
}
static PyObject* QFlags_QSizePolicy_ControlType__CppToPython_QFlags_QSizePolicy_ControlType_(const void* cppIn) {
    int castCppIn = *((::QFlags<QSizePolicy::ControlType>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]));

}

static void QSizePolicy_ControlType_PythonToCpp_QFlags_QSizePolicy_ControlType_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QSizePolicy::ControlType>*)cppOut) = ::QFlags<QSizePolicy::ControlType>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QSizePolicy_ControlType_PythonToCpp_QFlags_QSizePolicy_ControlType__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]))
        return QSizePolicy_ControlType_PythonToCpp_QFlags_QSizePolicy_ControlType_;
    return 0;
}
static void number_PythonToCpp_QFlags_QSizePolicy_ControlType_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QSizePolicy::ControlType>*)cppOut) = ::QFlags<QSizePolicy::ControlType>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QSizePolicy_ControlType__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QSizePolicy_ControlType_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSizePolicy_PythonToCpp_QSizePolicy_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSizePolicy_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSizePolicy_PythonToCpp_QSizePolicy_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSizePolicy_Type))
        return QSizePolicy_PythonToCpp_QSizePolicy_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSizePolicy_PTR_CppToPython_QSizePolicy(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSizePolicy*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSizePolicy_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSizePolicy_COPY_CppToPython_QSizePolicy(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSizePolicy_Type, new ::QSizePolicy(*((::QSizePolicy*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSizePolicy_PythonToCpp_QSizePolicy_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSizePolicy*)cppOut) = *((::QSizePolicy*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSizePolicy_PythonToCpp_QSizePolicy_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSizePolicy_Type))
        return QSizePolicy_PythonToCpp_QSizePolicy_COPY;
    return 0;
}

void init_QSizePolicy(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSizePolicy_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QSizePolicy_TypeAsNumber.nb_rshift = Sbk_QSizePolicyFunc___rshift__;
    Sbk_QSizePolicy_TypeAsNumber.nb_lshift = Sbk_QSizePolicyFunc___lshift__;
    Sbk_QSizePolicy_Type.super.ht_type.tp_as_number = &Sbk_QSizePolicy_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSizePolicy_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSizePolicy", "QSizePolicy",
        &Sbk_QSizePolicy_Type, &Shiboken::callCppDestructor< ::QSizePolicy >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSizePolicy_Type,
        QSizePolicy_PythonToCpp_QSizePolicy_PTR,
        is_QSizePolicy_PythonToCpp_QSizePolicy_PTR_Convertible,
        QSizePolicy_PTR_CppToPython_QSizePolicy,
        QSizePolicy_COPY_CppToPython_QSizePolicy);

    Shiboken::Conversions::registerConverterName(converter, "QSizePolicy");
    Shiboken::Conversions::registerConverterName(converter, "QSizePolicy*");
    Shiboken::Conversions::registerConverterName(converter, "QSizePolicy&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSizePolicy).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSizePolicy_PythonToCpp_QSizePolicy_COPY,
        is_QSizePolicy_PythonToCpp_QSizePolicy_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'PolicyFlag'.
    SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSizePolicy_Type,
        "PolicyFlag",
        "PySide.QtGui.QSizePolicy.PolicyFlag",
        "QSizePolicy::PolicyFlag");
    if (!SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX],
        &Sbk_QSizePolicy_Type, "GrowFlag", (long) QSizePolicy::GrowFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX],
        &Sbk_QSizePolicy_Type, "ExpandFlag", (long) QSizePolicy::ExpandFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX],
        &Sbk_QSizePolicy_Type, "ShrinkFlag", (long) QSizePolicy::ShrinkFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX],
        &Sbk_QSizePolicy_Type, "IgnoreFlag", (long) QSizePolicy::IgnoreFlag))
        return ;
    // Register converter for enum 'QSizePolicy::PolicyFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX],
            QSizePolicy_PolicyFlag_CppToPython_QSizePolicy_PolicyFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSizePolicy_PolicyFlag_PythonToCpp_QSizePolicy_PolicyFlag,
            is_QSizePolicy_PolicyFlag_PythonToCpp_QSizePolicy_PolicyFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICYFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSizePolicy::PolicyFlag");
        Shiboken::Conversions::registerConverterName(converter, "PolicyFlag");
    }
    // End of 'PolicyFlag' enum.

    // Initialization of enum 'Policy'.
    SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSizePolicy_Type,
        "Policy",
        "PySide.QtGui.QSizePolicy.Policy",
        "QSizePolicy::Policy");
    if (!SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "Fixed", (long) QSizePolicy::Fixed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "Minimum", (long) QSizePolicy::Minimum))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "Maximum", (long) QSizePolicy::Maximum))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "Preferred", (long) QSizePolicy::Preferred))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "MinimumExpanding", (long) QSizePolicy::MinimumExpanding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "Expanding", (long) QSizePolicy::Expanding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
        &Sbk_QSizePolicy_Type, "Ignored", (long) QSizePolicy::Ignored))
        return ;
    // Register converter for enum 'QSizePolicy::Policy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX],
            QSizePolicy_Policy_CppToPython_QSizePolicy_Policy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSizePolicy_Policy_PythonToCpp_QSizePolicy_Policy,
            is_QSizePolicy_Policy_PythonToCpp_QSizePolicy_Policy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSizePolicy::Policy");
        Shiboken::Conversions::registerConverterName(converter, "Policy");
    }
    // End of 'Policy' enum.

    // Initialization of enum 'ControlType'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX] = PySide::QFlags::create("ControlTypes", &SbkPySide_QtGui_QSizePolicy_ControlType_as_number);
    SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSizePolicy_Type,
        "ControlType",
        "PySide.QtGui.QSizePolicy.ControlType",
        "QSizePolicy::ControlType",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "DefaultType", (long) QSizePolicy::DefaultType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "ButtonBox", (long) QSizePolicy::ButtonBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "CheckBox", (long) QSizePolicy::CheckBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "ComboBox", (long) QSizePolicy::ComboBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "Frame", (long) QSizePolicy::Frame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "GroupBox", (long) QSizePolicy::GroupBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "Label", (long) QSizePolicy::Label))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "Line", (long) QSizePolicy::Line))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "LineEdit", (long) QSizePolicy::LineEdit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "PushButton", (long) QSizePolicy::PushButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "RadioButton", (long) QSizePolicy::RadioButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "Slider", (long) QSizePolicy::Slider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "SpinBox", (long) QSizePolicy::SpinBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "TabWidget", (long) QSizePolicy::TabWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
        &Sbk_QSizePolicy_Type, "ToolButton", (long) QSizePolicy::ToolButton))
        return ;
    // Register converter for enum 'QSizePolicy::ControlType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX],
            QSizePolicy_ControlType_CppToPython_QSizePolicy_ControlType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSizePolicy_ControlType_PythonToCpp_QSizePolicy_ControlType,
            is_QSizePolicy_ControlType_PythonToCpp_QSizePolicy_ControlType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSizePolicy::ControlType");
        Shiboken::Conversions::registerConverterName(converter, "ControlType");
    }
    // Register converter for flag 'QFlags<QSizePolicy::ControlType>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX],
            QFlags_QSizePolicy_ControlType__CppToPython_QFlags_QSizePolicy_ControlType_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSizePolicy_ControlType_PythonToCpp_QFlags_QSizePolicy_ControlType_,
            is_QSizePolicy_ControlType_PythonToCpp_QFlags_QSizePolicy_ControlType__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QSizePolicy_ControlType__PythonToCpp_QFlags_QSizePolicy_ControlType_,
            is_QFlags_QSizePolicy_ControlType__PythonToCpp_QFlags_QSizePolicy_ControlType__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QSizePolicy_ControlType_,
            is_number_PythonToCpp_QFlags_QSizePolicy_ControlType__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QSizePolicy::ControlType>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ControlType>");
    }
    // End of 'ControlType' enum/flags.


    qRegisterMetaType< ::QSizePolicy >("QSizePolicy");
    qRegisterMetaType< ::QSizePolicy::PolicyFlag >("QSizePolicy::PolicyFlag");
    qRegisterMetaType< ::QSizePolicy::Policy >("QSizePolicy::Policy");
    qRegisterMetaType< ::QSizePolicy::ControlType >("QSizePolicy::ControlType");
    qRegisterMetaType< ::QSizePolicy::ControlTypes >("QSizePolicy::ControlTypes");
}
