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

#include "qxmlschemavalidator_wrapper.h"

// Extra includes
#include <qabstractmessagehandler.h>
#include <qabstracturiresolver.h>
#include <qbytearray.h>
#include <qiodevice.h>
#include <qurl.h>
#include <qxmlnamepool.h>
#include <qxmlschema.h>
#include <qxmlschemavalidator.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlSchemaValidator_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlSchemaValidator >()))
        return -1;

    ::QXmlSchemaValidator* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlSchemaValidator", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlSchemaValidator()
    // 1: QXmlSchemaValidator(QXmlSchema)
    if (numArgs == 0) {
        overloadId = 0; // QXmlSchemaValidator()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMA_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlSchemaValidator(QXmlSchema)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSchemaValidator_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlSchemaValidator()
        {

            if (!PyErr_Occurred()) {
                // QXmlSchemaValidator()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlSchemaValidator();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlSchemaValidator(const QXmlSchema & schema)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlSchema* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QXmlSchemaValidator(QXmlSchema)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlSchemaValidator(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlSchemaValidator >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlSchemaValidator_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlSchemaValidator_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXmlPatterns.QXmlSchema", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlSchemaValidator", overloads);
        return -1;
}

static PyObject* Sbk_QXmlSchemaValidatorFunc_messageHandler(PyObject* self)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // messageHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractMessageHandler * cppResult = const_cast<const ::QXmlSchemaValidator*>(cppSelf)->messageHandler();
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

static PyObject* Sbk_QXmlSchemaValidatorFunc_namePool(PyObject* self)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namePool()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNamePool cppResult = const_cast<const ::QXmlSchemaValidator*>(cppSelf)->namePool();
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

static PyObject* Sbk_QXmlSchemaValidatorFunc_schema(PyObject* self)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // schema()const
            // Begin code injection

            QXmlSchema* cppResult = new QXmlSchema(cppSelf->schema());
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMA_IDX], cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlSchemaValidatorFunc_setMessageHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMessageHandler(QAbstractMessageHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTMESSAGEHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setMessageHandler(QAbstractMessageHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSchemaValidatorFunc_setMessageHandler_TypeError;

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

    Sbk_QXmlSchemaValidatorFunc_setMessageHandler_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QAbstractMessageHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlSchemaValidator.setMessageHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSchemaValidatorFunc_setSchema(PyObject* self, PyObject* pyArg)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSchema(QXmlSchema)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMA_IDX], (pyArg)))) {
        overloadId = 0; // setSchema(QXmlSchema)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSchemaValidatorFunc_setSchema_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlSchema* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSchema(QXmlSchema)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSchema(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSchemaValidatorFunc_setSchema_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlSchema", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlSchemaValidator.setSchema", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSchemaValidatorFunc_setUriResolver(PyObject* self, PyObject* pyArg)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUriResolver(const QAbstractUriResolver*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTURIRESOLVER_IDX], (pyArg)))) {
        overloadId = 0; // setUriResolver(const QAbstractUriResolver*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSchemaValidatorFunc_setUriResolver_TypeError;

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

    Sbk_QXmlSchemaValidatorFunc_setUriResolver_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QAbstractUriResolver", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QXmlSchemaValidator.setUriResolver", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSchemaValidatorFunc_uriResolver(PyObject* self)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uriResolver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QAbstractUriResolver * cppResult = const_cast<const ::QXmlSchemaValidator*>(cppSelf)->uriResolver();
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

static PyObject* Sbk_QXmlSchemaValidatorFunc_validate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlSchemaValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSchemaValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlSchemaValidator.validate(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlSchemaValidator.validate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:validate", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: validate(QIODevice*,QUrl)const
    // 1: validate(QByteArray,QUrl)const
    // 2: validate(QUrl)const
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        overloadId = 2; // validate(QUrl)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // validate(QByteArray,QUrl)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            overloadId = 1; // validate(QByteArray,QUrl)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // validate(QIODevice*,QUrl)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            overloadId = 0; // validate(QIODevice*,QUrl)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSchemaValidatorFunc_validate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // validate(QIODevice * source, const QUrl & documentUri) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "documentUri");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlSchemaValidator.validate(): got multiple values for keyword argument 'documentUri'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1]))))
                        goto Sbk_QXmlSchemaValidatorFunc_validate_TypeError;
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
                // validate(QIODevice*,QUrl)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlSchemaValidator*>(cppSelf)->validate(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // validate(const QByteArray & data, const QUrl & documentUri) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "documentUri");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QXmlSchemaValidator.validate(): got multiple values for keyword argument 'documentUri'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1]))))
                        goto Sbk_QXmlSchemaValidatorFunc_validate_TypeError;
                }
            }
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
            ::QUrl cppArg1_local = QUrl();
            ::QUrl* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // validate(QByteArray,QUrl)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlSchemaValidator*>(cppSelf)->validate(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // validate(const QUrl & source) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // validate(QUrl)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlSchemaValidator*>(cppSelf)->validate(*cppArg0);
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

    Sbk_QXmlSchemaValidatorFunc_validate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, PySide.QtCore.QUrl = QUrl()", "PySide.QtCore.QByteArray, PySide.QtCore.QUrl = QUrl()", "PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlSchemaValidator.validate", overloads);
        return 0;
}

static PyMethodDef Sbk_QXmlSchemaValidator_methods[] = {
    {"messageHandler", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_messageHandler, METH_NOARGS},
    {"namePool", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_namePool, METH_NOARGS},
    {"schema", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_schema, METH_NOARGS},
    {"setMessageHandler", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_setMessageHandler, METH_O},
    {"setSchema", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_setSchema, METH_O},
    {"setUriResolver", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_setUriResolver, METH_O},
    {"uriResolver", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_uriResolver, METH_NOARGS},
    {"validate", (PyCFunction)Sbk_QXmlSchemaValidatorFunc_validate, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlSchemaValidator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlSchemaValidator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlSchemaValidator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QXmlSchemaValidator",
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
    /*tp_traverse*/         Sbk_QXmlSchemaValidator_traverse,
    /*tp_clear*/            Sbk_QXmlSchemaValidator_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlSchemaValidator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlSchemaValidator_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QXmlSchemaValidator_PythonToCpp_QXmlSchemaValidator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlSchemaValidator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlSchemaValidator_PythonToCpp_QXmlSchemaValidator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlSchemaValidator_Type))
        return QXmlSchemaValidator_PythonToCpp_QXmlSchemaValidator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlSchemaValidator_PTR_CppToPython_QXmlSchemaValidator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlSchemaValidator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlSchemaValidator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlSchemaValidator(PyObject* module)
{
    SbkPySide_QtXmlPatternsTypes[SBK_QXMLSCHEMAVALIDATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlSchemaValidator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlSchemaValidator", "QXmlSchemaValidator*",
        &Sbk_QXmlSchemaValidator_Type, &Shiboken::callCppDestructor< ::QXmlSchemaValidator >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlSchemaValidator_Type,
        QXmlSchemaValidator_PythonToCpp_QXmlSchemaValidator_PTR,
        is_QXmlSchemaValidator_PythonToCpp_QXmlSchemaValidator_PTR_Convertible,
        QXmlSchemaValidator_PTR_CppToPython_QXmlSchemaValidator);

    Shiboken::Conversions::registerConverterName(converter, "QXmlSchemaValidator");
    Shiboken::Conversions::registerConverterName(converter, "QXmlSchemaValidator*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlSchemaValidator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlSchemaValidator).name());



}
