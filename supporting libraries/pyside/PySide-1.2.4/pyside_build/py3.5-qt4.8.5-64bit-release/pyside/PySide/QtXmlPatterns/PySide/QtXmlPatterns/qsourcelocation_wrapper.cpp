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

#include "qsourcelocation_wrapper.h"

// Extra includes
#include <qsourcelocation.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSourceLocation_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSourceLocation >()))
        return -1;

    ::QSourceLocation* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QSourceLocation(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QSourceLocation", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QSourceLocation()
    // 1: QSourceLocation(QSourceLocation)
    // 2: QSourceLocation(QUrl,int,int)
    if (numArgs == 0) {
        overloadId = 0; // QSourceLocation()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QSourceLocation(QUrl,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QSourceLocation(QUrl,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 2; // QSourceLocation(QUrl,int,int)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSourceLocation(QSourceLocation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSourceLocation_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSourceLocation()
        {

            if (!PyErr_Occurred()) {
                // QSourceLocation()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSourceLocation();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSourceLocation(const QSourceLocation & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSourceLocation cppArg0_local = ::QSourceLocation();
            ::QSourceLocation* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSourceLocation(QSourceLocation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSourceLocation(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSourceLocation(const QUrl & uri, int line, int column)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "line");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QSourceLocation(): got multiple values for keyword argument 'line'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QSourceLocation_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "column");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QSourceLocation(): got multiple values for keyword argument 'column'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QSourceLocation_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1 = -1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QSourceLocation(QUrl,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSourceLocation(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSourceLocation >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSourceLocation_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSourceLocation_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXmlPatterns.QSourceLocation", "PySide.QtCore.QUrl, int = -1, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QSourceLocation", overloads);
        return -1;
}

static PyObject* Sbk_QSourceLocationFunc_column(PyObject* self)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // column()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QSourceLocation*>(cppSelf)->column();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSourceLocationFunc_isNull(PyObject* self)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSourceLocation*>(cppSelf)->isNull();
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

static PyObject* Sbk_QSourceLocationFunc_line(PyObject* self)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // line()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QSourceLocation*>(cppSelf)->line();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSourceLocationFunc_setColumn(PyObject* self, PyObject* pyArg)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColumn(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setColumn(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSourceLocationFunc_setColumn_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColumn(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSourceLocationFunc_setColumn_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QSourceLocation.setColumn", overloads);
        return 0;
}

static PyObject* Sbk_QSourceLocationFunc_setLine(PyObject* self, PyObject* pyArg)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLine(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setLine(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSourceLocationFunc_setLine_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLine(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLine(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSourceLocationFunc_setLine_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QSourceLocation.setLine", overloads);
        return 0;
}

static PyObject* Sbk_QSourceLocationFunc_setUri(PyObject* self, PyObject* pyArg)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUri(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUri(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSourceLocationFunc_setUri_TypeError;

    // Call function/method
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
            // setUri(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUri(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSourceLocationFunc_setUri_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QSourceLocation.setUri", overloads);
        return 0;
}

static PyObject* Sbk_QSourceLocationFunc_uri(PyObject* self)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uri()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QSourceLocation*>(cppSelf)->uri();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSourceLocation___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSourceLocation& cppSelf = *(((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSourceLocation_methods[] = {
    {"column", (PyCFunction)Sbk_QSourceLocationFunc_column, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSourceLocationFunc_isNull, METH_NOARGS},
    {"line", (PyCFunction)Sbk_QSourceLocationFunc_line, METH_NOARGS},
    {"setColumn", (PyCFunction)Sbk_QSourceLocationFunc_setColumn, METH_O},
    {"setLine", (PyCFunction)Sbk_QSourceLocationFunc_setLine, METH_O},
    {"setUri", (PyCFunction)Sbk_QSourceLocationFunc_setUri, METH_O},
    {"uri", (PyCFunction)Sbk_QSourceLocationFunc_uri, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSourceLocation___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QSourceLocation___nb_bool(PyObject* self)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QSourceLocation_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSourceLocation& cppSelf = *(((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (pyArg)))) {
                // operator!=(const QSourceLocation & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSourceLocation cppArg0_local = ::QSourceLocation();
                ::QSourceLocation* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (pyArg)))) {
                // operator==(const QSourceLocation & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSourceLocation cppArg0_local = ::QSourceLocation();
                ::QSourceLocation* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], pythonToCpp))
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
            goto Sbk_QSourceLocation_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSourceLocation_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSourceLocation_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSourceLocation_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSourceLocation__repr__(PyObject* self)
{
    ::QSourceLocation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QSourceLocation_TypeAsNumber;

static SbkObjectType Sbk_QSourceLocation_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QSourceLocation",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSourceLocation__repr__,
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
    /*tp_traverse*/         Sbk_QSourceLocation_traverse,
    /*tp_clear*/            Sbk_QSourceLocation_clear,
    /*tp_richcompare*/      Sbk_QSourceLocation_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSourceLocation_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSourceLocation_Init,
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
static void QSourceLocation_PythonToCpp_QSourceLocation_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSourceLocation_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSourceLocation_PythonToCpp_QSourceLocation_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSourceLocation_Type))
        return QSourceLocation_PythonToCpp_QSourceLocation_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSourceLocation_PTR_CppToPython_QSourceLocation(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSourceLocation*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSourceLocation_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSourceLocation_COPY_CppToPython_QSourceLocation(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSourceLocation_Type, new ::QSourceLocation(*((::QSourceLocation*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSourceLocation_PythonToCpp_QSourceLocation_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSourceLocation*)cppOut) = *((::QSourceLocation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSourceLocation_PythonToCpp_QSourceLocation_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSourceLocation_Type))
        return QSourceLocation_PythonToCpp_QSourceLocation_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQUrlREF_PythonToCpp_QSourceLocation(PyObject* pyIn, void* cppOut) {
    *((::QSourceLocation*)cppOut) = ::QSourceLocation(*((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_constQUrlREF_PythonToCpp_QSourceLocation_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return PySide_QtCore_constQUrlREF_PythonToCpp_QSourceLocation;
    return 0;
}

void init_QSourceLocation(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSourceLocation_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QSourceLocation_TypeAsNumber) = Sbk_QSourceLocation___nb_bool;
    Sbk_QSourceLocation_Type.super.ht_type.tp_as_number = &Sbk_QSourceLocation_TypeAsNumber;

    SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSourceLocation_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSourceLocation", "QSourceLocation",
        &Sbk_QSourceLocation_Type, &Shiboken::callCppDestructor< ::QSourceLocation >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSourceLocation_Type,
        QSourceLocation_PythonToCpp_QSourceLocation_PTR,
        is_QSourceLocation_PythonToCpp_QSourceLocation_PTR_Convertible,
        QSourceLocation_PTR_CppToPython_QSourceLocation,
        QSourceLocation_COPY_CppToPython_QSourceLocation);

    Shiboken::Conversions::registerConverterName(converter, "QSourceLocation");
    Shiboken::Conversions::registerConverterName(converter, "QSourceLocation*");
    Shiboken::Conversions::registerConverterName(converter, "QSourceLocation&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSourceLocation).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSourceLocation_PythonToCpp_QSourceLocation_COPY,
        is_QSourceLocation_PythonToCpp_QSourceLocation_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQUrlREF_PythonToCpp_QSourceLocation,
        is_PySide_QtCore_constQUrlREF_PythonToCpp_QSourceLocation_Convertible);


    qRegisterMetaType< ::QSourceLocation >("QSourceLocation");
}
