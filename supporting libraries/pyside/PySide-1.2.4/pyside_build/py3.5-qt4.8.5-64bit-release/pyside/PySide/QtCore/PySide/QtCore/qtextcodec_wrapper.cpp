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
#include "pyside_qtcore_python.h"

#include "qtextcodec_wrapper.h"
#include "qtextcodec_converterstate_wrapper.h"

// Extra includes
#include <QList>
#include <QTextCodec>
#include <qbytearray.h>
#include <qtextcodec.h>


// Native ---------------------------------------------------------

QTextCodecWrapper::QTextCodecWrapper() : QTextCodec() {
    // ... middle
}

QList<QByteArray > QTextCodecWrapper::aliases() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QByteArray >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "aliases"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTextCodec::aliases();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QByteArray >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextCodec.aliases", "list", pyResult->ob_type->tp_name);
        return ::QList<QByteArray >();
    }
    ::QList<QByteArray > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QByteArray QTextCodecWrapper::convertFromUnicode(const QChar * in, int length, QTextCodec::ConverterState * state) const
{
    return ::QByteArray();
}

QString QTextCodecWrapper::convertToUnicode(const char * in, int length, QTextCodec::ConverterState * state) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "convertToUnicode"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QTextCodec.convertToUnicode()' not implemented.");
        return ::QString();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiN)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), in),
        length,
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], state)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextCodec.convertToUnicode", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QTextCodecWrapper::mibEnum() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mibEnum"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QTextCodec.mibEnum()' not implemented.");
        return ((int)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextCodec.mibEnum", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QByteArray QTextCodecWrapper::name() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QByteArray();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "name"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QTextCodec.name()' not implemented.");
        return ::QByteArray();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QByteArray();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTextCodec.name", Shiboken::SbkType< QByteArray >()->tp_name, pyResult->ob_type->tp_name);
        return ::QByteArray();
    }
    ::QByteArray cppResult = ::QByteArray();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QTextCodecWrapper::~QTextCodecWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextCodec_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QTextCodec' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextCodec >()))
        return -1;

    ::QTextCodecWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QTextCodec()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QTextCodecWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextCodec >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QTextCodecFunc_aliases(PyObject* self)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // aliases()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTextCodec*>(cppSelf)->::QTextCodec::aliases() : const_cast<const ::QTextCodec*>(cppSelf)->aliases();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_availableCodecs(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableCodecs()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = ::QTextCodec::availableCodecs();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_availableMibs(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableMibs()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = ::QTextCodec::availableMibs();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_canEncode(PyObject* self, PyObject* pyArg)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: canEncode(QChar)const
    // 1: canEncode(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // canEncode(QString)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // canEncode(QChar)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_canEncode_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // canEncode(QChar arg__1) const
        {
            ::QChar cppArg0 = ::QChar();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // canEncode(QChar)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QTextCodec*>(cppSelf)->canEncode(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // canEncode(const QString & arg__1) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // canEncode(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QTextCodec*>(cppSelf)->canEncode(cppArg0);
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

    Sbk_QTextCodecFunc_canEncode_TypeError:
        const char* overloads[] = {"1-unicode", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.canEncode", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_codecForCStrings(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // codecForCStrings()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCodec * cppResult = ::QTextCodec::codecForCStrings();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_codecForHtml(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "codecForHtml", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: codecForHtml(QByteArray)
    // 1: codecForHtml(QByteArray,QTextCodec*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // codecForHtml(QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArgs[1])))) {
            overloadId = 1; // codecForHtml(QByteArray,QTextCodec*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_codecForHtml_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // codecForHtml(const QByteArray & ba)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // codecForHtml(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCodec * cppResult = ::QTextCodec::codecForHtml(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            }
            break;
        }
        case 1: // codecForHtml(const QByteArray & ba, QTextCodec * defaultCodec)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextCodec* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // codecForHtml(QByteArray,QTextCodec*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCodec * cppResult = ::QTextCodec::codecForHtml(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_codecForHtml_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "PySide.QtCore.QByteArray, PySide.QtCore.QTextCodec", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextCodec.codecForHtml", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_codecForLocale(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // codecForLocale()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCodec * cppResult = ::QTextCodec::codecForLocale();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_codecForMib(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: codecForMib(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // codecForMib(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_codecForMib_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // codecForMib(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCodec * cppResult = ::QTextCodec::codecForMib(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_codecForMib_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.codecForMib", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_codecForName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: codecForName(QByteArray)
    // 1: codecForName(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 1; // codecForName(const char*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // codecForName(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_codecForName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // codecForName(const QByteArray & name)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // codecForName(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCodec * cppResult = ::QTextCodec::codecForName(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            }
            break;
        }
        case 1: // codecForName(const char * name)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // codecForName(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCodec * cppResult = ::QTextCodec::codecForName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_codecForName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.codecForName", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_codecForTr(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // codecForTr()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCodec * cppResult = ::QTextCodec::codecForTr();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_codecForUtfText(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "codecForUtfText", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: codecForUtfText(QByteArray)
    // 1: codecForUtfText(QByteArray,QTextCodec*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // codecForUtfText(QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArgs[1])))) {
            overloadId = 1; // codecForUtfText(QByteArray,QTextCodec*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_codecForUtfText_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // codecForUtfText(const QByteArray & ba)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // codecForUtfText(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCodec * cppResult = ::QTextCodec::codecForUtfText(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            }
            break;
        }
        case 1: // codecForUtfText(const QByteArray & ba, QTextCodec * defaultCodec)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextCodec* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // codecForUtfText(QByteArray,QTextCodec*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextCodec * cppResult = ::QTextCodec::codecForUtfText(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_codecForUtfText_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "PySide.QtCore.QByteArray, PySide.QtCore.QTextCodec", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextCodec.codecForUtfText", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_convertToUnicode(PyObject* self, PyObject* args)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "convertToUnicode", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: convertToUnicode(const char*,int,QTextCodec::ConverterState*)const
    if (numArgs == 3
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (pyArgs[2])))) {
        overloadId = 0; // convertToUnicode(const char*,int,QTextCodec::ConverterState*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_convertToUnicode_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QTextCodec::ConverterState* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // convertToUnicode(const char*,int,QTextCodec::ConverterState*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QTextCodec.convertToUnicode()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextCodec*>(cppSelf)->convertToUnicode(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_convertToUnicode_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int, PySide.QtCore.QTextCodec::ConverterState", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextCodec.convertToUnicode", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_fromUnicode(PyObject* self, PyObject* pyArg)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromUnicode(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromUnicode(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_fromUnicode_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromUnicode(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QTextCodec*>(cppSelf)->fromUnicode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_fromUnicode_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.fromUnicode", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_makeDecoder(PyObject* self, PyObject* args)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "makeDecoder", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: makeDecoder()const
    // 1: makeDecoder(QFlags<QTextCodec::ConversionFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // makeDecoder()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 1; // makeDecoder(QFlags<QTextCodec::ConversionFlag>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_makeDecoder_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // makeDecoder() const
        {

            if (!PyErr_Occurred()) {
                // makeDecoder()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextDecoder * cppResult = const_cast<const ::QTextCodec*>(cppSelf)->makeDecoder();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTDECODER_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // makeDecoder(QFlags<QTextCodec::ConversionFlag> flags) const
        {
            ::QFlags<QTextCodec::ConversionFlag> cppArg0 = ((::QFlags<QTextCodec::ConversionFlag>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // makeDecoder(QFlags<QTextCodec::ConversionFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextDecoder * cppResult = const_cast<const ::QTextCodec*>(cppSelf)->makeDecoder(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTDECODER_IDX], cppResult);
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

    Sbk_QTextCodecFunc_makeDecoder_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QTextCodec.ConversionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextCodec.makeDecoder", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_makeEncoder(PyObject* self, PyObject* args)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "makeEncoder", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: makeEncoder()const
    // 1: makeEncoder(QFlags<QTextCodec::ConversionFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // makeEncoder()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 1; // makeEncoder(QFlags<QTextCodec::ConversionFlag>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_makeEncoder_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // makeEncoder() const
        {

            if (!PyErr_Occurred()) {
                // makeEncoder()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextEncoder * cppResult = const_cast<const ::QTextCodec*>(cppSelf)->makeEncoder();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTENCODER_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // makeEncoder(QFlags<QTextCodec::ConversionFlag> flags) const
        {
            ::QFlags<QTextCodec::ConversionFlag> cppArg0 = ((::QFlags<QTextCodec::ConversionFlag>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // makeEncoder(QFlags<QTextCodec::ConversionFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextEncoder * cppResult = const_cast<const ::QTextCodec*>(cppSelf)->makeEncoder(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTENCODER_IDX], cppResult);
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

    Sbk_QTextCodecFunc_makeEncoder_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QTextCodec.ConversionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextCodec.makeEncoder", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_mibEnum(PyObject* self)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mibEnum()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QTextCodec.mibEnum()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCodec*>(cppSelf)->mibEnum();
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

static PyObject* Sbk_QTextCodecFunc_name(PyObject* self)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QTextCodec.name()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QTextCodec*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCodecFunc_setCodecForCStrings(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCodecForCStrings(QTextCodec*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArg)))) {
        overloadId = 0; // setCodecForCStrings(QTextCodec*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_setCodecForCStrings_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCodec* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCodecForCStrings(QTextCodec*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTextCodec::setCodecForCStrings(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCodecFunc_setCodecForCStrings_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.setCodecForCStrings", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_setCodecForLocale(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCodecForLocale(QTextCodec*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArg)))) {
        overloadId = 0; // setCodecForLocale(QTextCodec*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_setCodecForLocale_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCodec* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCodecForLocale(QTextCodec*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTextCodec::setCodecForLocale(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCodecFunc_setCodecForLocale_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.setCodecForLocale", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_setCodecForTr(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCodecForTr(QTextCodec*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArg)))) {
        overloadId = 0; // setCodecForTr(QTextCodec*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_setCodecForTr_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCodec* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCodecForTr(QTextCodec*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTextCodec::setCodecForTr(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCodecFunc_setCodecForTr_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextCodec.setCodecForTr", overloads);
        return 0;
}

static PyObject* Sbk_QTextCodecFunc_toUnicode(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextCodec* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextCodec.toUnicode(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextCodec.toUnicode(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:toUnicode", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: toUnicode(QByteArray)const
    // 1: toUnicode(const char*)const
    // 2: toUnicode(const char*,int,QTextCodec::ConverterState*)const
    if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // toUnicode(const char*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // toUnicode(const char*,int,QTextCodec::ConverterState*)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (pyArgs[2])))) {
                overloadId = 2; // toUnicode(const char*,int,QTextCodec::ConverterState*)const
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 0; // toUnicode(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodecFunc_toUnicode_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toUnicode(const QByteArray & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // toUnicode(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTextCodec*>(cppSelf)->toUnicode(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // toUnicode(const char * chars) const
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toUnicode(const char*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTextCodec*>(cppSelf)->toUnicode(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 2: // toUnicode(const char * in, int length, QTextCodec::ConverterState * state) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "state");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextCodec.toUnicode(): got multiple values for keyword argument 'state'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (pyArgs[2]))))
                        goto Sbk_QTextCodecFunc_toUnicode_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTextCodec::ConverterState* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // toUnicode(const char*,int,QTextCodec::ConverterState*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTextCodec*>(cppSelf)->toUnicode(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCodecFunc_toUnicode_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "" SBK_STR_NAME "", "" SBK_STR_NAME ", int, PySide.QtCore.QTextCodec::ConverterState = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextCodec.toUnicode", overloads);
        return 0;
}

static PyMethodDef Sbk_QTextCodec_methods[] = {
    {"aliases", (PyCFunction)Sbk_QTextCodecFunc_aliases, METH_NOARGS},
    {"availableCodecs", (PyCFunction)Sbk_QTextCodecFunc_availableCodecs, METH_NOARGS|METH_STATIC},
    {"availableMibs", (PyCFunction)Sbk_QTextCodecFunc_availableMibs, METH_NOARGS|METH_STATIC},
    {"canEncode", (PyCFunction)Sbk_QTextCodecFunc_canEncode, METH_O},
    {"codecForCStrings", (PyCFunction)Sbk_QTextCodecFunc_codecForCStrings, METH_NOARGS|METH_STATIC},
    {"codecForHtml", (PyCFunction)Sbk_QTextCodecFunc_codecForHtml, METH_VARARGS|METH_STATIC},
    {"codecForLocale", (PyCFunction)Sbk_QTextCodecFunc_codecForLocale, METH_NOARGS|METH_STATIC},
    {"codecForMib", (PyCFunction)Sbk_QTextCodecFunc_codecForMib, METH_O|METH_STATIC},
    {"codecForName", (PyCFunction)Sbk_QTextCodecFunc_codecForName, METH_O|METH_STATIC},
    {"codecForTr", (PyCFunction)Sbk_QTextCodecFunc_codecForTr, METH_NOARGS|METH_STATIC},
    {"codecForUtfText", (PyCFunction)Sbk_QTextCodecFunc_codecForUtfText, METH_VARARGS|METH_STATIC},
    {"convertToUnicode", (PyCFunction)Sbk_QTextCodecFunc_convertToUnicode, METH_VARARGS},
    {"fromUnicode", (PyCFunction)Sbk_QTextCodecFunc_fromUnicode, METH_O},
    {"makeDecoder", (PyCFunction)Sbk_QTextCodecFunc_makeDecoder, METH_VARARGS},
    {"makeEncoder", (PyCFunction)Sbk_QTextCodecFunc_makeEncoder, METH_VARARGS},
    {"mibEnum", (PyCFunction)Sbk_QTextCodecFunc_mibEnum, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QTextCodecFunc_name, METH_NOARGS},
    {"setCodecForCStrings", (PyCFunction)Sbk_QTextCodecFunc_setCodecForCStrings, METH_O|METH_STATIC},
    {"setCodecForLocale", (PyCFunction)Sbk_QTextCodecFunc_setCodecForLocale, METH_O|METH_STATIC},
    {"setCodecForTr", (PyCFunction)Sbk_QTextCodecFunc_setCodecForTr, METH_O|METH_STATIC},
    {"toUnicode", (PyCFunction)Sbk_QTextCodecFunc_toUnicode, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextCodec_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextCodec_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextCodec_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTextCodec",
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
    /*tp_traverse*/         Sbk_QTextCodec_traverse,
    /*tp_clear*/            Sbk_QTextCodec_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextCodec_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextCodec_Init,
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

PyObject* SbkPySide_QtCore_QTextCodec_ConversionFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextCodec::ConversionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextCodec::ConversionFlags)PyLong_AsLong(self);
    cppArg = (QTextCodec::ConversionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextCodec::ConversionFlags)PyInt_AsLong(self);
    cppArg = (QTextCodec::ConversionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextCodec_ConversionFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextCodec::ConversionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextCodec::ConversionFlags)PyLong_AsLong(self);
    cppArg = (QTextCodec::ConversionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextCodec::ConversionFlags)PyInt_AsLong(self);
    cppArg = (QTextCodec::ConversionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextCodec_ConversionFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextCodec::ConversionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextCodec::ConversionFlags)PyLong_AsLong(self);
    cppArg = (QTextCodec::ConversionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextCodec::ConversionFlags)PyInt_AsLong(self);
    cppArg = (QTextCodec::ConversionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextCodec_ConversionFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextCodec::ConversionFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), self, &cppSelf);
    ::QTextCodec::ConversionFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QTextCodec_ConversionFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QTextCodec_ConversionFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QTextCodec_ConversionFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QTextCodec_ConversionFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QTextCodec_ConversionFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QTextCodec_ConversionFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QTextCodec_ConversionFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QTextCodec_ConversionFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QTextCodec_ConversionFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QTextCodec_ConversionFlag_long,
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
static void QTextCodec_ConversionFlag_PythonToCpp_QTextCodec_ConversionFlag(PyObject* pyIn, void* cppOut) {
    *((::QTextCodec::ConversionFlag*)cppOut) = (::QTextCodec::ConversionFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextCodec_ConversionFlag_PythonToCpp_QTextCodec_ConversionFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX]))
        return QTextCodec_ConversionFlag_PythonToCpp_QTextCodec_ConversionFlag;
    return 0;
}
static PyObject* QTextCodec_ConversionFlag_CppToPython_QTextCodec_ConversionFlag(const void* cppIn) {
    int castCppIn = *((::QTextCodec::ConversionFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX], castCppIn);

}

static void QFlags_QTextCodec_ConversionFlag__PythonToCpp_QFlags_QTextCodec_ConversionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextCodec::ConversionFlag>*)cppOut) = ::QFlags<QTextCodec::ConversionFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextCodec_ConversionFlag__PythonToCpp_QFlags_QTextCodec_ConversionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]))
        return QFlags_QTextCodec_ConversionFlag__PythonToCpp_QFlags_QTextCodec_ConversionFlag_;
    return 0;
}
static PyObject* QFlags_QTextCodec_ConversionFlag__CppToPython_QFlags_QTextCodec_ConversionFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextCodec::ConversionFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]));

}

static void QTextCodec_ConversionFlag_PythonToCpp_QFlags_QTextCodec_ConversionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextCodec::ConversionFlag>*)cppOut) = ::QFlags<QTextCodec::ConversionFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextCodec_ConversionFlag_PythonToCpp_QFlags_QTextCodec_ConversionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX]))
        return QTextCodec_ConversionFlag_PythonToCpp_QFlags_QTextCodec_ConversionFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextCodec_ConversionFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextCodec::ConversionFlag>*)cppOut) = ::QFlags<QTextCodec::ConversionFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextCodec_ConversionFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextCodec_ConversionFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextCodec_PythonToCpp_QTextCodec_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextCodec_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextCodec_PythonToCpp_QTextCodec_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextCodec_Type))
        return QTextCodec_PythonToCpp_QTextCodec_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextCodec_PTR_CppToPython_QTextCodec(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextCodec*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextCodec_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTextCodec(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextCodec_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextCodec", "QTextCodec*",
        &Sbk_QTextCodec_Type, &Shiboken::callCppDestructor< ::QTextCodec >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextCodec_Type,
        QTextCodec_PythonToCpp_QTextCodec_PTR,
        is_QTextCodec_PythonToCpp_QTextCodec_PTR_Convertible,
        QTextCodec_PTR_CppToPython_QTextCodec);

    Shiboken::Conversions::registerConverterName(converter, "QTextCodec");
    Shiboken::Conversions::registerConverterName(converter, "QTextCodec*");
    Shiboken::Conversions::registerConverterName(converter, "QTextCodec&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextCodec).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextCodecWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ConversionFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX] = PySide::QFlags::create("ConversionFlags", &SbkPySide_QtCore_QTextCodec_ConversionFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextCodec_Type,
        "ConversionFlag",
        "PySide.QtCore.QTextCodec.ConversionFlag",
        "QTextCodec::ConversionFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX],
        &Sbk_QTextCodec_Type, "DefaultConversion", (long) QTextCodec::DefaultConversion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX],
        &Sbk_QTextCodec_Type, "ConvertInvalidToNull", (long) QTextCodec::ConvertInvalidToNull))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX],
        &Sbk_QTextCodec_Type, "IgnoreHeader", (long) QTextCodec::IgnoreHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX],
        &Sbk_QTextCodec_Type, "FreeFunction", (long) QTextCodec::FreeFunction))
        return ;
    // Register converter for enum 'QTextCodec::ConversionFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX],
            QTextCodec_ConversionFlag_CppToPython_QTextCodec_ConversionFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCodec_ConversionFlag_PythonToCpp_QTextCodec_ConversionFlag,
            is_QTextCodec_ConversionFlag_PythonToCpp_QTextCodec_ConversionFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERSIONFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextCodec::ConversionFlag");
        Shiboken::Conversions::registerConverterName(converter, "ConversionFlag");
    }
    // Register converter for flag 'QFlags<QTextCodec::ConversionFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX],
            QFlags_QTextCodec_ConversionFlag__CppToPython_QFlags_QTextCodec_ConversionFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCodec_ConversionFlag_PythonToCpp_QFlags_QTextCodec_ConversionFlag_,
            is_QTextCodec_ConversionFlag_PythonToCpp_QFlags_QTextCodec_ConversionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextCodec_ConversionFlag__PythonToCpp_QFlags_QTextCodec_ConversionFlag_,
            is_QFlags_QTextCodec_ConversionFlag__PythonToCpp_QFlags_QTextCodec_ConversionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextCodec_ConversionFlag_,
            is_number_PythonToCpp_QFlags_QTextCodec_ConversionFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextCodec::ConversionFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ConversionFlag>");
    }
    // End of 'ConversionFlag' enum/flags.


    qRegisterMetaType< ::QTextCodec::ConversionFlag >("QTextCodec::ConversionFlag");
    qRegisterMetaType< ::QTextCodec::ConversionFlags >("QTextCodec::ConversionFlags");
}
