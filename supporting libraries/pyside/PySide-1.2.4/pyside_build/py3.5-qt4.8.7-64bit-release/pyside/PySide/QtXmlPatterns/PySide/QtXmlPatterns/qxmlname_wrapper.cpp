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
#include "pyside_qtxmlpatterns_python.h"

#include "qxmlname_wrapper.h"

// Extra includes
#include <qxmlname.h>
#include <qxmlnamepool.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlName_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlName >()))
        return -1;

    ::QXmlName* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlName(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QXmlName", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlName()
    // 1: QXmlName(QXmlNamePool&,QString,QString,QString)
    // 2: QXmlName(QXmlName)
    if (numArgs == 0) {
        overloadId = 0; // QXmlName()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArgs[0])))) {
        overloadId = 2; // QXmlName(QXmlName)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QXmlName(QXmlNamePool&,QString,QString,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // QXmlName(QXmlNamePool&,QString,QString,QString)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                overloadId = 1; // QXmlName(QXmlNamePool&,QString,QString,QString)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlName_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlName()
        {

            if (!PyErr_Occurred()) {
                // QXmlName()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlName();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlName(QXmlNamePool & namePool, const QString & localName, const QString & namespaceURI, const QString & prefix)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "namespaceURI");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlName(): got multiple values for keyword argument 'namespaceURI'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_QXmlName_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "prefix");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlName(): got multiple values for keyword argument 'prefix'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QXmlName_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
            ::QXmlNamePool* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QString();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QXmlName(QXmlNamePool&,QString,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlName(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QXmlName(const QXmlName & QXmlName)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlName cppArg0_local = ::QXmlName();
            ::QXmlName* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlName(QXmlName)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlName(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlName >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlName_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlName_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXmlPatterns.QXmlNamePool, unicode, unicode = QString(), unicode = QString()", "PySide.QtXmlPatterns.QXmlName", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlName", overloads);
        return -1;
}

static PyObject* Sbk_QXmlNameFunc_fromClarkName(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fromClarkName", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromClarkName(QString,QXmlNamePool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArgs[1])))) {
        overloadId = 0; // fromClarkName(QString,QXmlNamePool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNameFunc_fromClarkName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QXmlNamePool cppArg1_local = ::QXmlNamePool();
        ::QXmlNamePool* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // fromClarkName(QString,QXmlNamePool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlName cppResult = ::QXmlName::fromClarkName(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNameFunc_fromClarkName_TypeError:
        const char* overloads[] = {"unicode, PySide.QtXmlPatterns.QXmlNamePool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlName.fromClarkName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNameFunc_isNCName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isNCName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isNCName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNameFunc_isNCName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isNCName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QXmlName::isNCName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNameFunc_isNCName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlName.isNCName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNameFunc_isNull(PyObject* self)
{
    ::QXmlName* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlName*>(cppSelf)->isNull();
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

static PyObject* Sbk_QXmlNameFunc_localName(PyObject* self, PyObject* pyArg)
{
    ::QXmlName* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: localName(QXmlNamePool)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArg)))) {
        overloadId = 0; // localName(QXmlNamePool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNameFunc_localName_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
        ::QXmlNamePool* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // localName(QXmlNamePool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlName*>(cppSelf)->localName(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNameFunc_localName_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNamePool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlName.localName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNameFunc_namespaceUri(PyObject* self, PyObject* pyArg)
{
    ::QXmlName* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: namespaceUri(QXmlNamePool)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArg)))) {
        overloadId = 0; // namespaceUri(QXmlNamePool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNameFunc_namespaceUri_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
        ::QXmlNamePool* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // namespaceUri(QXmlNamePool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlName*>(cppSelf)->namespaceUri(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNameFunc_namespaceUri_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNamePool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlName.namespaceUri", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNameFunc_prefix(PyObject* self, PyObject* pyArg)
{
    ::QXmlName* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prefix(QXmlNamePool)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArg)))) {
        overloadId = 0; // prefix(QXmlNamePool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNameFunc_prefix_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
        ::QXmlNamePool* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // prefix(QXmlNamePool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlName*>(cppSelf)->prefix(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNameFunc_prefix_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNamePool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlName.prefix", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNameFunc_toClarkName(PyObject* self, PyObject* pyArg)
{
    ::QXmlName* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toClarkName(QXmlNamePool)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArg)))) {
        overloadId = 0; // toClarkName(QXmlNamePool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNameFunc_toClarkName_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
        ::QXmlNamePool* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // toClarkName(QXmlNamePool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlName*>(cppSelf)->toClarkName(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNameFunc_toClarkName_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNamePool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlName.toClarkName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlName___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlName& cppSelf = *(((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlName_methods[] = {
    {"fromClarkName", (PyCFunction)Sbk_QXmlNameFunc_fromClarkName, METH_VARARGS|METH_STATIC},
    {"isNCName", (PyCFunction)Sbk_QXmlNameFunc_isNCName, METH_O|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QXmlNameFunc_isNull, METH_NOARGS},
    {"localName", (PyCFunction)Sbk_QXmlNameFunc_localName, METH_O},
    {"namespaceUri", (PyCFunction)Sbk_QXmlNameFunc_namespaceUri, METH_O},
    {"prefix", (PyCFunction)Sbk_QXmlNameFunc_prefix, METH_O},
    {"toClarkName", (PyCFunction)Sbk_QXmlNameFunc_toClarkName, METH_O},

    {"__copy__", (PyCFunction)Sbk_QXmlName___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QXmlName___nb_bool(PyObject* self)
{
    ::QXmlName* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QXmlName_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlName& cppSelf = *(((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
                // operator!=(const QXmlName & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlName cppArg0_local = ::QXmlName();
                ::QXmlName* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
                // operator==(const QXmlName & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlName cppArg0_local = ::QXmlName();
                ::QXmlName* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp))
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
            goto Sbk_QXmlName_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QXmlName_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QXmlName_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlName_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QXmlName_TypeAsNumber;

static SbkObjectType Sbk_QXmlName_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QXmlName",
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
    /*tp_traverse*/         Sbk_QXmlName_traverse,
    /*tp_clear*/            Sbk_QXmlName_clear,
    /*tp_richcompare*/      Sbk_QXmlName_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlName_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlName_Init,
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
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QXmlName_PythonToCpp_QXmlName_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlName_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlName_PythonToCpp_QXmlName_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlName_Type))
        return QXmlName_PythonToCpp_QXmlName_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlName_PTR_CppToPython_QXmlName(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlName*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlName_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlName_COPY_CppToPython_QXmlName(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlName_Type, new ::QXmlName(*((::QXmlName*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlName_PythonToCpp_QXmlName_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlName*)cppOut) = *((::QXmlName*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlName_PythonToCpp_QXmlName_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlName_Type))
        return QXmlName_PythonToCpp_QXmlName_COPY;
    return 0;
}

void init_QXmlName(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QXmlName_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QXmlName_TypeAsNumber) = Sbk_QXmlName___nb_bool;
    Sbk_QXmlName_Type.super.ht_type.tp_as_number = &Sbk_QXmlName_TypeAsNumber;

    SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlName_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlName", "QXmlName",
        &Sbk_QXmlName_Type, &Shiboken::callCppDestructor< ::QXmlName >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlName_Type,
        QXmlName_PythonToCpp_QXmlName_PTR,
        is_QXmlName_PythonToCpp_QXmlName_PTR_Convertible,
        QXmlName_PTR_CppToPython_QXmlName,
        QXmlName_COPY_CppToPython_QXmlName);

    Shiboken::Conversions::registerConverterName(converter, "QXmlName");
    Shiboken::Conversions::registerConverterName(converter, "QXmlName*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlName&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlName).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlName_PythonToCpp_QXmlName_COPY,
        is_QXmlName_PythonToCpp_QXmlName_COPY_Convertible);

    // Initialization of enums.


    qRegisterMetaType< ::QXmlName >("QXmlName");
}
