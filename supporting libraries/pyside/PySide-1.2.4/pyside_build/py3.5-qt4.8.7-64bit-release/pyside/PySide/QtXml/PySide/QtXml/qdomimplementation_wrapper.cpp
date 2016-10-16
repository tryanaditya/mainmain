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
#include "pyside_qtxml_python.h"

#include "qdomimplementation_wrapper.h"

// Extra includes
#include <qdom.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomImplementation_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomImplementation >()))
        return -1;

    ::QDomImplementation* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomImplementation", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomImplementation()
    // 1: QDomImplementation(QDomImplementation)
    if (numArgs == 0) {
        overloadId = 0; // QDomImplementation()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomImplementation(QDomImplementation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomImplementation_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomImplementation()
        {

            if (!PyErr_Occurred()) {
                // QDomImplementation()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomImplementation();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomImplementation(const QDomImplementation & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomImplementation cppArg0_local = ::QDomImplementation();
            ::QDomImplementation* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomImplementation(QDomImplementation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomImplementation(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomImplementation >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomImplementation_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomImplementation_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomImplementation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomImplementation", overloads);
        return -1;
}

static PyObject* Sbk_QDomImplementationFunc_createDocument(PyObject* self, PyObject* args)
{
    ::QDomImplementation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDocument", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createDocument(QString,QString,QDomDocumentType)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTTYPE_IDX], (pyArgs[2])))) {
        overloadId = 0; // createDocument(QString,QString,QDomDocumentType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomImplementationFunc_createDocument_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QDomDocumentType cppArg2_local = ::QDomDocumentType();
        ::QDomDocumentType* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTTYPE_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // createDocument(QString,QString,QDomDocumentType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocument cppResult = cppSelf->createDocument(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomImplementationFunc_createDocument_TypeError:
        const char* overloads[] = {"unicode, unicode, PySide.QtXml.QDomDocumentType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomImplementation.createDocument", overloads);
        return 0;
}

static PyObject* Sbk_QDomImplementationFunc_createDocumentType(PyObject* self, PyObject* args)
{
    ::QDomImplementation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDocumentType", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createDocumentType(QString,QString,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // createDocumentType(QString,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomImplementationFunc_createDocumentType_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createDocumentType(QString,QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocumentType cppResult = cppSelf->createDocumentType(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTTYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomImplementationFunc_createDocumentType_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomImplementation.createDocumentType", overloads);
        return 0;
}

static PyObject* Sbk_QDomImplementationFunc_hasFeature(PyObject* self, PyObject* args)
{
    ::QDomImplementation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "hasFeature", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hasFeature(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // hasFeature(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomImplementationFunc_hasFeature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // hasFeature(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomImplementation*>(cppSelf)->hasFeature(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomImplementationFunc_hasFeature_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomImplementation.hasFeature", overloads);
        return 0;
}

static PyObject* Sbk_QDomImplementationFunc_invalidDataPolicy(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidDataPolicy()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomImplementation::InvalidDataPolicy cppResult = ::QDomImplementation::invalidDataPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomImplementationFunc_isNull(PyObject* self)
{
    ::QDomImplementation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->isNull();
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

static PyObject* Sbk_QDomImplementationFunc_setInvalidDataPolicy(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInvalidDataPolicy(QDomImplementation::InvalidDataPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setInvalidDataPolicy(QDomImplementation::InvalidDataPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomImplementationFunc_setInvalidDataPolicy_TypeError;

    // Call function/method
    {
        ::QDomImplementation::InvalidDataPolicy cppArg0 = ((::QDomImplementation::InvalidDataPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInvalidDataPolicy(QDomImplementation::InvalidDataPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QDomImplementation::setInvalidDataPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomImplementationFunc_setInvalidDataPolicy_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomImplementation.InvalidDataPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomImplementation.setInvalidDataPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QDomImplementation___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomImplementation& cppSelf = *(((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomImplementation_methods[] = {
    {"createDocument", (PyCFunction)Sbk_QDomImplementationFunc_createDocument, METH_VARARGS},
    {"createDocumentType", (PyCFunction)Sbk_QDomImplementationFunc_createDocumentType, METH_VARARGS},
    {"hasFeature", (PyCFunction)Sbk_QDomImplementationFunc_hasFeature, METH_VARARGS},
    {"invalidDataPolicy", (PyCFunction)Sbk_QDomImplementationFunc_invalidDataPolicy, METH_NOARGS|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QDomImplementationFunc_isNull, METH_NOARGS},
    {"setInvalidDataPolicy", (PyCFunction)Sbk_QDomImplementationFunc_setInvalidDataPolicy, METH_O|METH_STATIC},

    {"__copy__", (PyCFunction)Sbk_QDomImplementation___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QDomImplementation_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomImplementation& cppSelf = *(((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (pyArg)))) {
                // operator!=(const QDomImplementation & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomImplementation cppArg0_local = ::QDomImplementation();
                ::QDomImplementation* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (pyArg)))) {
                // operator==(const QDomImplementation & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomImplementation cppArg0_local = ::QDomImplementation();
                ::QDomImplementation* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], pythonToCpp))
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
            goto Sbk_QDomImplementation_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDomImplementation_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QDomImplementation_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomImplementation_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDomImplementation_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomImplementation",
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
    /*tp_traverse*/         Sbk_QDomImplementation_traverse,
    /*tp_clear*/            Sbk_QDomImplementation_clear,
    /*tp_richcompare*/      Sbk_QDomImplementation_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomImplementation_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomImplementation_Init,
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
static void QDomImplementation_InvalidDataPolicy_PythonToCpp_QDomImplementation_InvalidDataPolicy(PyObject* pyIn, void* cppOut) {
    *((::QDomImplementation::InvalidDataPolicy*)cppOut) = (::QDomImplementation::InvalidDataPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDomImplementation_InvalidDataPolicy_PythonToCpp_QDomImplementation_InvalidDataPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX]))
        return QDomImplementation_InvalidDataPolicy_PythonToCpp_QDomImplementation_InvalidDataPolicy;
    return 0;
}
static PyObject* QDomImplementation_InvalidDataPolicy_CppToPython_QDomImplementation_InvalidDataPolicy(const void* cppIn) {
    int castCppIn = *((::QDomImplementation::InvalidDataPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDomImplementation_PythonToCpp_QDomImplementation_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomImplementation_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomImplementation_PythonToCpp_QDomImplementation_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomImplementation_Type))
        return QDomImplementation_PythonToCpp_QDomImplementation_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomImplementation_PTR_CppToPython_QDomImplementation(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomImplementation*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomImplementation_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomImplementation_COPY_CppToPython_QDomImplementation(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomImplementation_Type, new ::QDomImplementation(*((::QDomImplementation*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomImplementation_PythonToCpp_QDomImplementation_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomImplementation*)cppOut) = *((::QDomImplementation*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomImplementation_PythonToCpp_QDomImplementation_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomImplementation_Type))
        return QDomImplementation_PythonToCpp_QDomImplementation_COPY;
    return 0;
}

void init_QDomImplementation(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomImplementation_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomImplementation", "QDomImplementation",
        &Sbk_QDomImplementation_Type, &Shiboken::callCppDestructor< ::QDomImplementation >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomImplementation_Type,
        QDomImplementation_PythonToCpp_QDomImplementation_PTR,
        is_QDomImplementation_PythonToCpp_QDomImplementation_PTR_Convertible,
        QDomImplementation_PTR_CppToPython_QDomImplementation,
        QDomImplementation_COPY_CppToPython_QDomImplementation);

    Shiboken::Conversions::registerConverterName(converter, "QDomImplementation");
    Shiboken::Conversions::registerConverterName(converter, "QDomImplementation*");
    Shiboken::Conversions::registerConverterName(converter, "QDomImplementation&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomImplementation).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomImplementation_PythonToCpp_QDomImplementation_COPY,
        is_QDomImplementation_PythonToCpp_QDomImplementation_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'InvalidDataPolicy'.
    SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDomImplementation_Type,
        "InvalidDataPolicy",
        "PySide.QtXml.QDomImplementation.InvalidDataPolicy",
        "QDomImplementation::InvalidDataPolicy");
    if (!SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX],
        &Sbk_QDomImplementation_Type, "AcceptInvalidChars", (long) QDomImplementation::AcceptInvalidChars))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX],
        &Sbk_QDomImplementation_Type, "DropInvalidChars", (long) QDomImplementation::DropInvalidChars))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX],
        &Sbk_QDomImplementation_Type, "ReturnNullNode", (long) QDomImplementation::ReturnNullNode))
        return ;
    // Register converter for enum 'QDomImplementation::InvalidDataPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX],
            QDomImplementation_InvalidDataPolicy_CppToPython_QDomImplementation_InvalidDataPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDomImplementation_InvalidDataPolicy_PythonToCpp_QDomImplementation_InvalidDataPolicy,
            is_QDomImplementation_InvalidDataPolicy_PythonToCpp_QDomImplementation_InvalidDataPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_INVALIDDATAPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDomImplementation::InvalidDataPolicy");
        Shiboken::Conversions::registerConverterName(converter, "InvalidDataPolicy");
    }
    // End of 'InvalidDataPolicy' enum.


    qRegisterMetaType< ::QDomImplementation >("QDomImplementation");
    qRegisterMetaType< ::QDomImplementation::InvalidDataPolicy >("QDomImplementation::InvalidDataPolicy");
}
