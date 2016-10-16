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
#include "pyside_qtwebkit_python.h"

#include "qwebelement_wrapper.h"

// Extra includes
#include <qpainter.h>
#include <qrect.h>
#include <qwebelement.h>
#include <qwebframe.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebElement_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebElement >()))
        return -1;

    ::QWebElement* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QWebElement", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QWebElement()
    // 1: QWebElement(QWebElement)
    if (numArgs == 0) {
        overloadId = 0; // QWebElement()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QWebElement(QWebElement)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElement_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QWebElement()
        {

            if (!PyErr_Occurred()) {
                // QWebElement()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebElement();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QWebElement(const QWebElement & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QWebElement(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebElement(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebElement >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebElement_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebElement_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement", overloads);
        return -1;
}

static PyObject* Sbk_QWebElementFunc_addClass(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addClass(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addClass(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_addClass_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addClass(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addClass(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_addClass_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.addClass", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_appendInside(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendInside(QString)
    // 1: appendInside(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // appendInside(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // appendInside(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_appendInside_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // appendInside(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // appendInside(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendInside(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // appendInside(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // appendInside(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendInside(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_appendInside_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.appendInside", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_appendOutside(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendOutside(QString)
    // 1: appendOutside(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // appendOutside(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // appendOutside(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_appendOutside_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // appendOutside(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // appendOutside(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendOutside(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // appendOutside(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // appendOutside(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendOutside(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_appendOutside_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.appendOutside", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_attribute(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attribute(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attribute(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:attribute", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: attribute(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // attribute(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // attribute(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_attribute_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defaultValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attribute(): got multiple values for keyword argument 'defaultValue'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QWebElementFunc_attribute_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // attribute(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->attribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_attribute_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.attribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_attributeNS(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attributeNS(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attributeNS(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:attributeNS", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: attributeNS(QString,QString,QString)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // attributeNS(QString,QString,QString)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // attributeNS(QString,QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_attributeNS_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defaultValue");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attributeNS(): got multiple values for keyword argument 'defaultValue'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QWebElementFunc_attributeNS_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // attributeNS(QString,QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->attributeNS(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_attributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.attributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_attributeNames(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attributeNames(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:attributeNames", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: attributeNames(QString)const
    if (numArgs == 0) {
        overloadId = 0; // attributeNames(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // attributeNames(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_attributeNames_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "namespaceUri");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebElement.attributeNames(): got multiple values for keyword argument 'namespaceUri'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QWebElementFunc_attributeNames_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // attributeNames(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QWebElement*>(cppSelf)->attributeNames(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_attributeNames_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.attributeNames", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_classes(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // classes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QWebElement*>(cppSelf)->classes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_clone(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clone()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->clone();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_document(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // document()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->document();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_encloseContentsWith(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: encloseContentsWith(QString)
    // 1: encloseContentsWith(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // encloseContentsWith(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // encloseContentsWith(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_encloseContentsWith_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // encloseContentsWith(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // encloseContentsWith(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->encloseContentsWith(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // encloseContentsWith(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // encloseContentsWith(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->encloseContentsWith(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_encloseContentsWith_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.encloseContentsWith", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_encloseWith(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: encloseWith(QString)
    // 1: encloseWith(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // encloseWith(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // encloseWith(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_encloseWith_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // encloseWith(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // encloseWith(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->encloseWith(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // encloseWith(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // encloseWith(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->encloseWith(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_encloseWith_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.encloseWith", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_evaluateJavaScript(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: evaluateJavaScript(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // evaluateJavaScript(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_evaluateJavaScript_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // evaluateJavaScript(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = cppSelf->evaluateJavaScript(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_evaluateJavaScript_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.evaluateJavaScript", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_findAll(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findAll(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // findAll(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_findAll_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findAll(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElementCollection cppResult = const_cast<const ::QWebElement*>(cppSelf)->findAll(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_findAll_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.findAll", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_findFirst(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findFirst(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // findFirst(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_findFirst_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findFirst(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->findFirst(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_findFirst_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.findFirst", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_firstChild(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstChild()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->firstChild();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_geometry(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometry()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QWebElement*>(cppSelf)->geometry();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_hasAttribute(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasAttribute(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasAttribute(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_hasAttribute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasAttribute(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebElement*>(cppSelf)->hasAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_hasAttribute_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.hasAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_hasAttributeNS(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "hasAttributeNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hasAttributeNS(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // hasAttributeNS(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_hasAttributeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // hasAttributeNS(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebElement*>(cppSelf)->hasAttributeNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_hasAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.hasAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_hasAttributes(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAttributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebElement*>(cppSelf)->hasAttributes();
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

static PyObject* Sbk_QWebElementFunc_hasClass(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasClass(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasClass(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_hasClass_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasClass(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebElement*>(cppSelf)->hasClass(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_hasClass_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.hasClass", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_hasFocus(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFocus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebElement*>(cppSelf)->hasFocus();
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

static PyObject* Sbk_QWebElementFunc_isNull(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebElement*>(cppSelf)->isNull();
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

static PyObject* Sbk_QWebElementFunc_lastChild(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastChild()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->lastChild();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_localName(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->localName();
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

static PyObject* Sbk_QWebElementFunc_namespaceUri(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namespaceUri()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->namespaceUri();
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

static PyObject* Sbk_QWebElementFunc_nextSibling(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nextSibling()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->nextSibling();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_parent(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->parent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_prefix(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->prefix();
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

static PyObject* Sbk_QWebElementFunc_prependInside(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prependInside(QString)
    // 1: prependInside(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // prependInside(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // prependInside(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_prependInside_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // prependInside(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // prependInside(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->prependInside(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // prependInside(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // prependInside(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->prependInside(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_prependInside_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.prependInside", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_prependOutside(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prependOutside(QString)
    // 1: prependOutside(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // prependOutside(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // prependOutside(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_prependOutside_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // prependOutside(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // prependOutside(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->prependOutside(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // prependOutside(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // prependOutside(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->prependOutside(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_prependOutside_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.prependOutside", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_previousSibling(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // previousSibling()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElement*>(cppSelf)->previousSibling();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_removeAllChildren(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeAllChildren()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAllChildren();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebElementFunc_removeAttribute(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAttribute(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeAttribute(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_removeAttribute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAttribute(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_removeAttribute_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.removeAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_removeAttributeNS(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "removeAttributeNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removeAttributeNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // removeAttributeNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_removeAttributeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeAttributeNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAttributeNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_removeAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.removeAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_removeClass(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeClass(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeClass(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_removeClass_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeClass(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeClass(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_removeClass_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.removeClass", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_removeFromDocument(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeFromDocument()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeFromDocument();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebElementFunc_render(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "render", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: render(QPainter*)
    // 1: render(QPainter*,QRect)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // render(QPainter*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // render(QPainter*,QRect)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_render_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // render(QPainter * painter)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // render(QPainter*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->render(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // render(QPainter * painter, const QRect & clipRect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRect cppArg1_local = ::QRect();
            ::QRect* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // render(QPainter*,QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->render(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_render_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter", "PySide.QtGui.QPainter, PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.render", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_replace(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: replace(QString)
    // 1: replace(QWebElement)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
        overloadId = 1; // replace(QWebElement)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // replace(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_replace_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // replace(const QString & markup)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // replace(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->replace(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // replace(const QWebElement & element)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // replace(QWebElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->replace(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_replace_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtWebKit.QWebElement", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.replace", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_setAttribute(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttribute", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAttribute(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setAttribute(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_setAttribute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAttribute(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_setAttribute_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.setAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_setAttributeNS(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttributeNS", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeNS(QString,QString,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // setAttributeNS(QString,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_setAttributeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setAttributeNS(QString,QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_setAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.setAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_setFocus(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setFocus()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFocus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebElementFunc_setInnerXml(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInnerXml(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setInnerXml(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_setInnerXml_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInnerXml(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInnerXml(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_setInnerXml_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.setInnerXml", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_setOuterXml(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOuterXml(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOuterXml(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_setOuterXml_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOuterXml(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOuterXml(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_setOuterXml_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.setOuterXml", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_setPlainText(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPlainText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPlainText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_setPlainText_TypeError;

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

    Sbk_QWebElementFunc_setPlainText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.setPlainText", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_setStyleProperty(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setStyleProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStyleProperty(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setStyleProperty(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_setStyleProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setStyleProperty(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyleProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_setStyleProperty_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.setStyleProperty", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_styleProperty(PyObject* self, PyObject* args)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "styleProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: styleProperty(QString,QWebElement::StyleResolveStrategy)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX]), (pyArgs[1])))) {
        overloadId = 0; // styleProperty(QString,QWebElement::StyleResolveStrategy)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_styleProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QWebElement::StyleResolveStrategy cppArg1 = ((::QWebElement::StyleResolveStrategy)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // styleProperty(QString,QWebElement::StyleResolveStrategy)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->styleProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementFunc_styleProperty_TypeError:
        const char* overloads[] = {"unicode, PySide.QtWebKit.QWebElement.StyleResolveStrategy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElement.styleProperty", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_tagName(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tagName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->tagName();
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

static PyObject* Sbk_QWebElementFunc_takeFromDocument(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // takeFromDocument()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement & cppResult = cppSelf->takeFromDocument();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementFunc_toInnerXml(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toInnerXml()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->toInnerXml();
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

static PyObject* Sbk_QWebElementFunc_toOuterXml(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toOuterXml()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->toOuterXml();
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

static PyObject* Sbk_QWebElementFunc_toPlainText(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPlainText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebElement*>(cppSelf)->toPlainText();
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

static PyObject* Sbk_QWebElementFunc_toggleClass(PyObject* self, PyObject* pyArg)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toggleClass(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toggleClass(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementFunc_toggleClass_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toggleClass(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toggleClass(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementFunc_toggleClass_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElement.toggleClass", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementFunc_webFrame(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // webFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebElement*>(cppSelf)->webFrame();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElement___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebElement& cppSelf = *(((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebElement_methods[] = {
    {"addClass", (PyCFunction)Sbk_QWebElementFunc_addClass, METH_O},
    {"appendInside", (PyCFunction)Sbk_QWebElementFunc_appendInside, METH_O},
    {"appendOutside", (PyCFunction)Sbk_QWebElementFunc_appendOutside, METH_O},
    {"attribute", (PyCFunction)Sbk_QWebElementFunc_attribute, METH_VARARGS|METH_KEYWORDS},
    {"attributeNS", (PyCFunction)Sbk_QWebElementFunc_attributeNS, METH_VARARGS|METH_KEYWORDS},
    {"attributeNames", (PyCFunction)Sbk_QWebElementFunc_attributeNames, METH_VARARGS|METH_KEYWORDS},
    {"classes", (PyCFunction)Sbk_QWebElementFunc_classes, METH_NOARGS},
    {"clone", (PyCFunction)Sbk_QWebElementFunc_clone, METH_NOARGS},
    {"document", (PyCFunction)Sbk_QWebElementFunc_document, METH_NOARGS},
    {"encloseContentsWith", (PyCFunction)Sbk_QWebElementFunc_encloseContentsWith, METH_O},
    {"encloseWith", (PyCFunction)Sbk_QWebElementFunc_encloseWith, METH_O},
    {"evaluateJavaScript", (PyCFunction)Sbk_QWebElementFunc_evaluateJavaScript, METH_O},
    {"findAll", (PyCFunction)Sbk_QWebElementFunc_findAll, METH_O},
    {"findFirst", (PyCFunction)Sbk_QWebElementFunc_findFirst, METH_O},
    {"firstChild", (PyCFunction)Sbk_QWebElementFunc_firstChild, METH_NOARGS},
    {"geometry", (PyCFunction)Sbk_QWebElementFunc_geometry, METH_NOARGS},
    {"hasAttribute", (PyCFunction)Sbk_QWebElementFunc_hasAttribute, METH_O},
    {"hasAttributeNS", (PyCFunction)Sbk_QWebElementFunc_hasAttributeNS, METH_VARARGS},
    {"hasAttributes", (PyCFunction)Sbk_QWebElementFunc_hasAttributes, METH_NOARGS},
    {"hasClass", (PyCFunction)Sbk_QWebElementFunc_hasClass, METH_O},
    {"hasFocus", (PyCFunction)Sbk_QWebElementFunc_hasFocus, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QWebElementFunc_isNull, METH_NOARGS},
    {"lastChild", (PyCFunction)Sbk_QWebElementFunc_lastChild, METH_NOARGS},
    {"localName", (PyCFunction)Sbk_QWebElementFunc_localName, METH_NOARGS},
    {"namespaceUri", (PyCFunction)Sbk_QWebElementFunc_namespaceUri, METH_NOARGS},
    {"nextSibling", (PyCFunction)Sbk_QWebElementFunc_nextSibling, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QWebElementFunc_parent, METH_NOARGS},
    {"prefix", (PyCFunction)Sbk_QWebElementFunc_prefix, METH_NOARGS},
    {"prependInside", (PyCFunction)Sbk_QWebElementFunc_prependInside, METH_O},
    {"prependOutside", (PyCFunction)Sbk_QWebElementFunc_prependOutside, METH_O},
    {"previousSibling", (PyCFunction)Sbk_QWebElementFunc_previousSibling, METH_NOARGS},
    {"removeAllChildren", (PyCFunction)Sbk_QWebElementFunc_removeAllChildren, METH_NOARGS},
    {"removeAttribute", (PyCFunction)Sbk_QWebElementFunc_removeAttribute, METH_O},
    {"removeAttributeNS", (PyCFunction)Sbk_QWebElementFunc_removeAttributeNS, METH_VARARGS},
    {"removeClass", (PyCFunction)Sbk_QWebElementFunc_removeClass, METH_O},
    {"removeFromDocument", (PyCFunction)Sbk_QWebElementFunc_removeFromDocument, METH_NOARGS},
    {"render", (PyCFunction)Sbk_QWebElementFunc_render, METH_VARARGS},
    {"replace", (PyCFunction)Sbk_QWebElementFunc_replace, METH_O},
    {"setAttribute", (PyCFunction)Sbk_QWebElementFunc_setAttribute, METH_VARARGS},
    {"setAttributeNS", (PyCFunction)Sbk_QWebElementFunc_setAttributeNS, METH_VARARGS},
    {"setFocus", (PyCFunction)Sbk_QWebElementFunc_setFocus, METH_NOARGS},
    {"setInnerXml", (PyCFunction)Sbk_QWebElementFunc_setInnerXml, METH_O},
    {"setOuterXml", (PyCFunction)Sbk_QWebElementFunc_setOuterXml, METH_O},
    {"setPlainText", (PyCFunction)Sbk_QWebElementFunc_setPlainText, METH_O},
    {"setStyleProperty", (PyCFunction)Sbk_QWebElementFunc_setStyleProperty, METH_VARARGS},
    {"styleProperty", (PyCFunction)Sbk_QWebElementFunc_styleProperty, METH_VARARGS},
    {"tagName", (PyCFunction)Sbk_QWebElementFunc_tagName, METH_NOARGS},
    {"takeFromDocument", (PyCFunction)Sbk_QWebElementFunc_takeFromDocument, METH_NOARGS},
    {"toInnerXml", (PyCFunction)Sbk_QWebElementFunc_toInnerXml, METH_NOARGS},
    {"toOuterXml", (PyCFunction)Sbk_QWebElementFunc_toOuterXml, METH_NOARGS},
    {"toPlainText", (PyCFunction)Sbk_QWebElementFunc_toPlainText, METH_NOARGS},
    {"toggleClass", (PyCFunction)Sbk_QWebElementFunc_toggleClass, METH_O},
    {"webFrame", (PyCFunction)Sbk_QWebElementFunc_webFrame, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QWebElement___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QWebElement___nb_bool(PyObject* self)
{
    ::QWebElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QWebElement_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebElement& cppSelf = *(((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
                // operator!=(const QWebElement & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QWebElement cppArg0_local = ::QWebElement();
                ::QWebElement* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArg)))) {
                // operator==(const QWebElement & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QWebElement cppArg0_local = ::QWebElement();
                ::QWebElement* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp))
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
            goto Sbk_QWebElement_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QWebElement_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QWebElement_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebElement_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QWebElement_TypeAsNumber;

static SbkObjectType Sbk_QWebElement_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebElement",
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
    /*tp_traverse*/         Sbk_QWebElement_traverse,
    /*tp_clear*/            Sbk_QWebElement_clear,
    /*tp_richcompare*/      Sbk_QWebElement_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebElement_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebElement_Init,
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
static void QWebElement_StyleResolveStrategy_PythonToCpp_QWebElement_StyleResolveStrategy(PyObject* pyIn, void* cppOut) {
    *((::QWebElement::StyleResolveStrategy*)cppOut) = (::QWebElement::StyleResolveStrategy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebElement_StyleResolveStrategy_PythonToCpp_QWebElement_StyleResolveStrategy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX]))
        return QWebElement_StyleResolveStrategy_PythonToCpp_QWebElement_StyleResolveStrategy;
    return 0;
}
static PyObject* QWebElement_StyleResolveStrategy_CppToPython_QWebElement_StyleResolveStrategy(const void* cppIn) {
    int castCppIn = *((::QWebElement::StyleResolveStrategy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWebElement_PythonToCpp_QWebElement_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebElement_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebElement_PythonToCpp_QWebElement_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebElement_Type))
        return QWebElement_PythonToCpp_QWebElement_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebElement_PTR_CppToPython_QWebElement(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebElement*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebElement_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QWebElement_COPY_CppToPython_QWebElement(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebElement_Type, new ::QWebElement(*((::QWebElement*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QWebElement_PythonToCpp_QWebElement_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebElement*)cppOut) = *((::QWebElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QWebElement_PythonToCpp_QWebElement_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebElement_Type))
        return QWebElement_PythonToCpp_QWebElement_COPY;
    return 0;
}

void init_QWebElement(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QWebElement_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QWebElement_TypeAsNumber) = Sbk_QWebElement___nb_bool;
    Sbk_QWebElement_Type.super.ht_type.tp_as_number = &Sbk_QWebElement_TypeAsNumber;

    SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebElement_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebElement", "QWebElement",
        &Sbk_QWebElement_Type, &Shiboken::callCppDestructor< ::QWebElement >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebElement_Type,
        QWebElement_PythonToCpp_QWebElement_PTR,
        is_QWebElement_PythonToCpp_QWebElement_PTR_Convertible,
        QWebElement_PTR_CppToPython_QWebElement,
        QWebElement_COPY_CppToPython_QWebElement);

    Shiboken::Conversions::registerConverterName(converter, "QWebElement");
    Shiboken::Conversions::registerConverterName(converter, "QWebElement*");
    Shiboken::Conversions::registerConverterName(converter, "QWebElement&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebElement).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QWebElement_PythonToCpp_QWebElement_COPY,
        is_QWebElement_PythonToCpp_QWebElement_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StyleResolveStrategy'.
    SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebElement_Type,
        "StyleResolveStrategy",
        "PySide.QtWebKit.QWebElement.StyleResolveStrategy",
        "QWebElement::StyleResolveStrategy");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX],
        &Sbk_QWebElement_Type, "InlineStyle", (long) QWebElement::InlineStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX],
        &Sbk_QWebElement_Type, "CascadedStyle", (long) QWebElement::CascadedStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX],
        &Sbk_QWebElement_Type, "ComputedStyle", (long) QWebElement::ComputedStyle))
        return ;
    // Register converter for enum 'QWebElement::StyleResolveStrategy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX],
            QWebElement_StyleResolveStrategy_CppToPython_QWebElement_StyleResolveStrategy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebElement_StyleResolveStrategy_PythonToCpp_QWebElement_StyleResolveStrategy,
            is_QWebElement_StyleResolveStrategy_PythonToCpp_QWebElement_StyleResolveStrategy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_STYLERESOLVESTRATEGY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebElement::StyleResolveStrategy");
        Shiboken::Conversions::registerConverterName(converter, "StyleResolveStrategy");
    }
    // End of 'StyleResolveStrategy' enum.


    qRegisterMetaType< ::QWebElement >("QWebElement");
    qRegisterMetaType< ::QWebElement::StyleResolveStrategy >("QWebElement::StyleResolveStrategy");
}
