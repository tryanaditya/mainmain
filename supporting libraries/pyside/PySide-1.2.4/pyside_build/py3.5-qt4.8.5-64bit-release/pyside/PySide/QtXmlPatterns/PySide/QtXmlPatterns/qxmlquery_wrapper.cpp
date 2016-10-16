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

#include "qxmlquery_wrapper.h"

// Extra includes
#include <qabstractmessagehandler.h>
#include <qabstracturiresolver.h>
#include <qabstractxmlnodemodel.h>
#include <qabstractxmlreceiver.h>
#include <qiodevice.h>
#include <qurl.h>
#include <qxmlname.h>
#include <qxmlnamepool.h>
#include <qxmlquery.h>
#include <qxmlresultitems.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlQuery_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlQuery >()))
        return -1;

    ::QXmlQuery* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QXmlQuery", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlQuery()
    // 1: QXmlQuery(QXmlQuery::QueryLanguage,QXmlNamePool)
    // 2: QXmlQuery(QXmlNamePool)
    // 3: QXmlQuery(QXmlQuery)
    if (numArgs == 0) {
        overloadId = 0; // QXmlQuery()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArgs[0])))) {
        overloadId = 2; // QXmlQuery(QXmlNamePool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QXmlQuery(QXmlQuery::QueryLanguage,QXmlNamePool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArgs[1])))) {
            overloadId = 1; // QXmlQuery(QXmlQuery::QueryLanguage,QXmlNamePool)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (pyArgs[0])))) {
        overloadId = 3; // QXmlQuery(QXmlQuery)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQuery_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlQuery()
        {

            if (!PyErr_Occurred()) {
                // QXmlQuery()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlQuery();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlQuery(QXmlQuery::QueryLanguage queryLanguage, const QXmlNamePool & np)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "np");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery(): got multiple values for keyword argument 'np'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArgs[1]))))
                        goto Sbk_QXmlQuery_Init_TypeError;
                }
            }
            ::QXmlQuery::QueryLanguage cppArg0 = ((::QXmlQuery::QueryLanguage)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QXmlNamePool cppArg1_local = QXmlNamePool();
            ::QXmlNamePool* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // QXmlQuery(QXmlQuery::QueryLanguage,QXmlNamePool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlQuery(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QXmlQuery(const QXmlNamePool & np)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
            ::QXmlNamePool* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlQuery(QXmlNamePool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlQuery(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QXmlQuery(const QXmlQuery & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlQuery cppArg0_local = ::QXmlQuery();
            ::QXmlQuery* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlQuery(QXmlQuery)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlQuery(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlQuery >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlQuery_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlQuery_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXmlPatterns.QXmlQuery.QueryLanguage, PySide.QtXmlPatterns.QXmlNamePool = QXmlNamePool()", "PySide.QtXmlPatterns.QXmlNamePool", "PySide.QtXmlPatterns.QXmlQuery", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlQuery", overloads);
        return -1;
}

static PyObject* Sbk_QXmlQueryFunc_bindVariable(PyObject* self, PyObject* args)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "bindVariable", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: bindVariable(QString,QIODevice*)
    // 1: bindVariable(QString,QXmlItem)
    // 2: bindVariable(QString,QXmlQuery)
    // 3: bindVariable(QXmlName,QIODevice*)
    // 4: bindVariable(QXmlName,QXmlItem)
    // 5: bindVariable(QXmlName,QXmlQuery)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (pyArgs[1])))) {
            overloadId = 5; // bindVariable(QXmlName,QXmlQuery)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (pyArgs[1])))) {
            overloadId = 4; // bindVariable(QXmlName,QXmlItem)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            overloadId = 3; // bindVariable(QXmlName,QIODevice*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (pyArgs[1])))) {
            overloadId = 2; // bindVariable(QString,QXmlQuery)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (pyArgs[1])))) {
            overloadId = 1; // bindVariable(QString,QXmlItem)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            overloadId = 0; // bindVariable(QString,QIODevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_bindVariable_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindVariable(const QString & localName, QIODevice * arg__2)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QIODevice* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // bindVariable(QString,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindVariable(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // bindVariable(const QString & localName, const QXmlItem & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QXmlItem cppArg1_local = ::QXmlItem();
            ::QXmlItem* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // bindVariable(QString,QXmlItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindVariable(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // bindVariable(const QString & localName, const QXmlQuery & query)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QXmlQuery cppArg1_local = ::QXmlQuery();
            ::QXmlQuery* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // bindVariable(QString,QXmlQuery)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindVariable(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // bindVariable(const QXmlName & name, QIODevice * arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlName cppArg0_local = ::QXmlName();
            ::QXmlName* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QIODevice* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // bindVariable(QXmlName,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindVariable(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // bindVariable(const QXmlName & name, const QXmlItem & value)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlName cppArg0_local = ::QXmlName();
            ::QXmlName* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QXmlItem cppArg1_local = ::QXmlItem();
            ::QXmlItem* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // bindVariable(QXmlName,QXmlItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindVariable(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // bindVariable(const QXmlName & name, const QXmlQuery & query)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlName cppArg0_local = ::QXmlName();
            ::QXmlName* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QXmlQuery cppArg1_local = ::QXmlQuery();
            ::QXmlQuery* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // bindVariable(QXmlName,QXmlQuery)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindVariable(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlQueryFunc_bindVariable_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice", "unicode, PySide.QtXmlPatterns.QXmlItem", "unicode, PySide.QtXmlPatterns.QXmlQuery", "PySide.QtXmlPatterns.QXmlName, PySide.QtCore.QIODevice", "PySide.QtXmlPatterns.QXmlName, PySide.QtXmlPatterns.QXmlItem", "PySide.QtXmlPatterns.QXmlName, PySide.QtXmlPatterns.QXmlQuery", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlQuery.bindVariable", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_evaluateTo(PyObject* self, PyObject* pyArg)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: evaluateTo(QAbstractXmlReceiver*)const
    // 1: evaluateTo(QIODevice*)const
    // 2: evaluateTo(QXmlResultItems*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLRESULTITEMS_IDX], (pyArg)))) {
        overloadId = 2; // evaluateTo(QXmlResultItems*)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 1; // evaluateTo(QIODevice*)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (pyArg)))) {
        overloadId = 0; // evaluateTo(QAbstractXmlReceiver*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_evaluateTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // evaluateTo(QAbstractXmlReceiver * callback) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QAbstractXmlReceiver* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // evaluateTo(QAbstractXmlReceiver*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->evaluateTo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // evaluateTo(QIODevice * target) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // evaluateTo(QIODevice*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->evaluateTo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // evaluateTo(QXmlResultItems * result) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QXmlResultItems* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // evaluateTo(QXmlResultItems*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const_cast<const ::QXmlQuery*>(cppSelf)->evaluateTo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlQueryFunc_evaluateTo_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QAbstractXmlReceiver", "PySide.QtCore.QIODevice", "PySide.QtXmlPatterns.QXmlResultItems", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlQuery.evaluateTo", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_initialTemplateName(PyObject* self)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initialTemplateName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlName cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->initialTemplateName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlQueryFunc_isValid(PyObject* self)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->isValid();
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

static PyObject* Sbk_QXmlQueryFunc_messageHandler(PyObject* self)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // messageHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractMessageHandler * cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->messageHandler();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTMESSAGEHANDLER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlQueryFunc_namePool(PyObject* self)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namePool()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNamePool cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->namePool();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlQueryFunc_queryLanguage(PyObject* self)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queryLanguage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlQuery::QueryLanguage cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->queryLanguage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlQueryFunc_setFocus(PyObject* self, PyObject* pyArg)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFocus(QIODevice*)
    // 1: setFocus(QString)
    // 2: setFocus(QUrl)
    // 3: setFocus(QXmlItem)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (pyArg)))) {
        overloadId = 3; // setFocus(QXmlItem)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setFocus(QIODevice*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setFocus(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 2; // setFocus(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_setFocus_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setFocus(QIODevice * document)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setFocus(QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setFocus(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // setFocus(const QString & focus)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setFocus(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setFocus(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // setFocus(const QUrl & documentURI)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setFocus(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setFocus(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 3: // setFocus(const QXmlItem & item)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QXmlItem cppArg0_local = ::QXmlItem();
            ::QXmlItem* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setFocus(QXmlItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFocus(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlQueryFunc_setFocus_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", "unicode", "PySide.QtCore.QUrl", "PySide.QtXmlPatterns.QXmlItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlQuery.setFocus", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_setInitialTemplateName(PyObject* self, PyObject* pyArg)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInitialTemplateName(QString)
    // 1: setInitialTemplateName(QXmlName)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
        overloadId = 1; // setInitialTemplateName(QXmlName)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setInitialTemplateName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_setInitialTemplateName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setInitialTemplateName(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setInitialTemplateName(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setInitialTemplateName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setInitialTemplateName(const QXmlName & name)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QXmlName cppArg0_local = ::QXmlName();
            ::QXmlName* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setInitialTemplateName(QXmlName)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setInitialTemplateName(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlQueryFunc_setInitialTemplateName_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtXmlPatterns.QXmlName", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlQuery.setInitialTemplateName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_setMessageHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMessageHandler(QAbstractMessageHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTMESSAGEHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setMessageHandler(QAbstractMessageHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_setMessageHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractMessageHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMessageHandler(QAbstractMessageHandler*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMessageHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlQueryFunc_setMessageHandler_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QAbstractMessageHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlQuery.setMessageHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_setQuery(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery.setQuery(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery.setQuery(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setQuery", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setQuery(QIODevice*,QUrl)
    // 1: setQuery(QString,QUrl)
    // 2: setQuery(QUrl,QUrl)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setQuery(QIODevice*,QUrl)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            overloadId = 0; // setQuery(QIODevice*,QUrl)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setQuery(QString,QUrl)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            overloadId = 1; // setQuery(QString,QUrl)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // setQuery(QUrl,QUrl)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            overloadId = 2; // setQuery(QUrl,QUrl)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_setQuery_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setQuery(QIODevice * sourceCode, const QUrl & documentURI)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "documentURI");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery.setQuery(): got multiple values for keyword argument 'documentURI'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1]))))
                        goto Sbk_QXmlQueryFunc_setQuery_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QUrl cppArg1_local = QUrl();
            ::QUrl* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // setQuery(QIODevice*,QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setQuery(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setQuery(const QString & sourceCode, const QUrl & documentURI)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "documentURI");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery.setQuery(): got multiple values for keyword argument 'documentURI'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1]))))
                        goto Sbk_QXmlQueryFunc_setQuery_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QUrl cppArg1_local = QUrl();
            ::QUrl* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // setQuery(QString,QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setQuery(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setQuery(const QUrl & queryURI, const QUrl & baseURI)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "baseURI");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlQuery.setQuery(): got multiple values for keyword argument 'baseURI'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1]))))
                        goto Sbk_QXmlQueryFunc_setQuery_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QUrl cppArg1_local = QUrl();
            ::QUrl* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // setQuery(QUrl,QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setQuery(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlQueryFunc_setQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, PySide.QtCore.QUrl = QUrl()", "unicode, PySide.QtCore.QUrl = QUrl()", "PySide.QtCore.QUrl, PySide.QtCore.QUrl = QUrl()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlQuery.setQuery", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_setUriResolver(PyObject* self, PyObject* pyArg)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUriResolver(const QAbstractUriResolver*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTURIRESOLVER_IDX], (pyArg)))) {
        overloadId = 0; // setUriResolver(const QAbstractUriResolver*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlQueryFunc_setUriResolver_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractUriResolver* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUriResolver(const QAbstractUriResolver*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUriResolver(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlQueryFunc_setUriResolver_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QAbstractUriResolver", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlQuery.setUriResolver", overloads);
        return 0;
}

static PyObject* Sbk_QXmlQueryFunc_uriResolver(PyObject* self)
{
    ::QXmlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uriResolver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QAbstractUriResolver * cppResult = const_cast<const ::QXmlQuery*>(cppSelf)->uriResolver();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTURIRESOLVER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlQuery___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlQuery& cppSelf = *(((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlQuery_methods[] = {
    {"bindVariable", (PyCFunction)Sbk_QXmlQueryFunc_bindVariable, METH_VARARGS},
    {"evaluateTo", (PyCFunction)Sbk_QXmlQueryFunc_evaluateTo, METH_O},
    {"initialTemplateName", (PyCFunction)Sbk_QXmlQueryFunc_initialTemplateName, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QXmlQueryFunc_isValid, METH_NOARGS},
    {"messageHandler", (PyCFunction)Sbk_QXmlQueryFunc_messageHandler, METH_NOARGS},
    {"namePool", (PyCFunction)Sbk_QXmlQueryFunc_namePool, METH_NOARGS},
    {"queryLanguage", (PyCFunction)Sbk_QXmlQueryFunc_queryLanguage, METH_NOARGS},
    {"setFocus", (PyCFunction)Sbk_QXmlQueryFunc_setFocus, METH_O},
    {"setInitialTemplateName", (PyCFunction)Sbk_QXmlQueryFunc_setInitialTemplateName, METH_O},
    {"setMessageHandler", (PyCFunction)Sbk_QXmlQueryFunc_setMessageHandler, METH_O},
    {"setQuery", (PyCFunction)Sbk_QXmlQueryFunc_setQuery, METH_VARARGS|METH_KEYWORDS},
    {"setUriResolver", (PyCFunction)Sbk_QXmlQueryFunc_setUriResolver, METH_O},
    {"uriResolver", (PyCFunction)Sbk_QXmlQueryFunc_uriResolver, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlQuery___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlQuery_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlQuery_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlQuery_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QXmlQuery",
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
    /*tp_traverse*/         Sbk_QXmlQuery_traverse,
    /*tp_clear*/            Sbk_QXmlQuery_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlQuery_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlQuery_Init,
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
static void QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_QueryLanguage(PyObject* pyIn, void* cppOut) {
    *((::QXmlQuery::QueryLanguage*)cppOut) = (::QXmlQuery::QueryLanguage) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_QueryLanguage_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX]))
        return QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_QueryLanguage;
    return 0;
}
static PyObject* QXmlQuery_QueryLanguage_CppToPython_QXmlQuery_QueryLanguage(const void* cppIn) {
    int castCppIn = *((::QXmlQuery::QueryLanguage*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QXmlQuery_PythonToCpp_QXmlQuery_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlQuery_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlQuery_PythonToCpp_QXmlQuery_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlQuery_Type))
        return QXmlQuery_PythonToCpp_QXmlQuery_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlQuery_PTR_CppToPython_QXmlQuery(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlQuery*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlQuery_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlQuery_COPY_CppToPython_QXmlQuery(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlQuery_Type, new ::QXmlQuery(*((::QXmlQuery*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlQuery_PythonToCpp_QXmlQuery_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlQuery*)cppOut) = *((::QXmlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlQuery_PythonToCpp_QXmlQuery_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlQuery_Type))
        return QXmlQuery_PythonToCpp_QXmlQuery_COPY;
    return 0;
}

// Implicit conversions.
static void QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery(PyObject* pyIn, void* cppOut) {
    ::QXmlQuery::QueryLanguage cppIn = ((::QXmlQuery::QueryLanguage)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX]), pyIn, &cppIn);
    *((::QXmlQuery*)cppOut) = ::QXmlQuery(cppIn);
}
static PythonToCppFunc is_QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX], pyIn))
        return QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery;
    return 0;
}

static void constQXmlNamePoolREF_PythonToCpp_QXmlQuery(PyObject* pyIn, void* cppOut) {
    *((::QXmlQuery*)cppOut) = ::QXmlQuery(*((::QXmlNamePool*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQXmlNamePoolREF_PythonToCpp_QXmlQuery_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pyIn))
        return constQXmlNamePoolREF_PythonToCpp_QXmlQuery;
    return 0;
}

void init_QXmlQuery(PyObject* module)
{
    SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlQuery_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlQuery", "QXmlQuery",
        &Sbk_QXmlQuery_Type, &Shiboken::callCppDestructor< ::QXmlQuery >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlQuery_Type,
        QXmlQuery_PythonToCpp_QXmlQuery_PTR,
        is_QXmlQuery_PythonToCpp_QXmlQuery_PTR_Convertible,
        QXmlQuery_PTR_CppToPython_QXmlQuery,
        QXmlQuery_COPY_CppToPython_QXmlQuery);

    Shiboken::Conversions::registerConverterName(converter, "QXmlQuery");
    Shiboken::Conversions::registerConverterName(converter, "QXmlQuery*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlQuery&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlQuery).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlQuery_PythonToCpp_QXmlQuery_COPY,
        is_QXmlQuery_PythonToCpp_QXmlQuery_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery,
        is_QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQXmlNamePoolREF_PythonToCpp_QXmlQuery,
        is_constQXmlNamePoolREF_PythonToCpp_QXmlQuery_Convertible);

    // Initialization of enums.

    // Initialization of enum 'QueryLanguage'.
    SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QXmlQuery_Type,
        "QueryLanguage",
        "PySide.QtXmlPatterns.QXmlQuery.QueryLanguage",
        "QXmlQuery::QueryLanguage");
    if (!SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX],
        &Sbk_QXmlQuery_Type, "XQuery10", (long) QXmlQuery::XQuery10))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX],
        &Sbk_QXmlQuery_Type, "XSLT20", (long) QXmlQuery::XSLT20))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX],
        &Sbk_QXmlQuery_Type, "XmlSchema11IdentityConstraintSelector", (long) QXmlQuery::XmlSchema11IdentityConstraintSelector))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX],
        &Sbk_QXmlQuery_Type, "XmlSchema11IdentityConstraintField", (long) QXmlQuery::XmlSchema11IdentityConstraintField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX],
        &Sbk_QXmlQuery_Type, "XPath20", (long) QXmlQuery::XPath20))
        return ;
    // Register converter for enum 'QXmlQuery::QueryLanguage'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX],
            QXmlQuery_QueryLanguage_CppToPython_QXmlQuery_QueryLanguage);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_QueryLanguage,
            is_QXmlQuery_QueryLanguage_PythonToCpp_QXmlQuery_QueryLanguage_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLQUERY_QUERYLANGUAGE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QXmlQuery::QueryLanguage");
        Shiboken::Conversions::registerConverterName(converter, "QueryLanguage");
    }
    // End of 'QueryLanguage' enum.


    qRegisterMetaType< ::QXmlQuery >("QXmlQuery");
    qRegisterMetaType< ::QXmlQuery::QueryLanguage >("QXmlQuery::QueryLanguage");
}
