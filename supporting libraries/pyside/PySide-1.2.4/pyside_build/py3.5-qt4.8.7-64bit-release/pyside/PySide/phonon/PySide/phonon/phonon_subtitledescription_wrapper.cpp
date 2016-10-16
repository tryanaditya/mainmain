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
#include "pyside_phonon_python.h"

#include "phonon_subtitledescription_wrapper.h"

// Extra includes
#include <QList>
#include <objectdescription.h>
#include <pysideconversions.h>
#include <qbytearray.h>

using namespace Phonon;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_SubtitleDescription_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::SubtitleDescription >()))
        return -1;

    ::Phonon::SubtitleDescription* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "SubtitleDescription", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: SubtitleDescription()
    // 1: SubtitleDescription(Phonon::SubtitleDescription)
    // 2: SubtitleDescription(int,QHash<QByteArray,QVariant>)
    if (numArgs == 0) {
        overloadId = 0; // SubtitleDescription()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 2; // SubtitleDescription(int,QHash<QByteArray,QVariant>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (pyArgs[0])))) {
        overloadId = 1; // SubtitleDescription(Phonon::SubtitleDescription)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_SubtitleDescription_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // SubtitleDescription()
        {

            if (!PyErr_Occurred()) {
                // SubtitleDescription()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::SubtitleDescription();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // SubtitleDescription(const Phonon::SubtitleDescription & SubtitleDescription)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::SubtitleDescription cppArg0_local = ::Phonon::SubtitleDescription();
            ::Phonon::SubtitleDescription* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // SubtitleDescription(Phonon::SubtitleDescription)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::SubtitleDescription(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // SubtitleDescription(int index, const QHash<QByteArray, QVariant > & properties)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QHash<QByteArray, QVariant > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // SubtitleDescription(int,QHash<QByteArray,QVariant>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::SubtitleDescription(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::SubtitleDescription >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_SubtitleDescription_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Phonon_SubtitleDescription_Init_TypeError:
        const char* overloads[] = {"", "PySide.phonon.Phonon::SubtitleDescription", "int, dict", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.SubtitleDescription", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_description(PyObject* self)
{
    ::Phonon::SubtitleDescription* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // description()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::SubtitleDescription*>(cppSelf)->description();
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

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_fromIndex(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // fromIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_SubtitleDescriptionFunc_fromIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromIndex(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::ObjectDescription<Phonon::SubtitleType > cppResult = ::Phonon::SubtitleDescription::fromIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_SUBTITLETYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_SubtitleDescriptionFunc_fromIndex_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.SubtitleDescription.fromIndex", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_index(PyObject* self)
{
    ::Phonon::SubtitleDescription* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // index()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::SubtitleDescription*>(cppSelf)->index();
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

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_isValid(PyObject* self)
{
    ::Phonon::SubtitleDescription* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::SubtitleDescription*>(cppSelf)->isValid();
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

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_name(PyObject* self)
{
    ::Phonon::SubtitleDescription* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::SubtitleDescription*>(cppSelf)->name();
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

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_property(PyObject* self, PyObject* pyArg)
{
    ::Phonon::SubtitleDescription* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // property(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_SubtitleDescriptionFunc_property_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::Phonon::SubtitleDescription*>(cppSelf)->property(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_SubtitleDescriptionFunc_property_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.SubtitleDescription.property", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_SubtitleDescriptionFunc_propertyNames(PyObject* self)
{
    ::Phonon::SubtitleDescription* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::Phonon::SubtitleDescription*>(cppSelf)->propertyNames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_SubtitleDescription___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::SubtitleDescription& cppSelf = *(((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_SubtitleDescription_methods[] = {
    {"description", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_description, METH_NOARGS},
    {"fromIndex", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_fromIndex, METH_O|METH_STATIC},
    {"index", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_index, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_isValid, METH_NOARGS},
    {"name", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_name, METH_NOARGS},
    {"property", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_property, METH_O},
    {"propertyNames", (PyCFunction)Sbk_Phonon_SubtitleDescriptionFunc_propertyNames, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_Phonon_SubtitleDescription___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_Phonon_SubtitleDescription_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::SubtitleDescription& cppSelf = *(((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (pyArg)))) {
                // operator!=(const Phonon::ObjectDescription & otherDescription) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::Phonon::SubtitleDescription cppArg0 = ::Phonon::SubtitleDescription();
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf != (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (pyArg)))) {
                // operator==(const Phonon::ObjectDescription & otherDescription) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::Phonon::SubtitleDescription cppArg0 = ::Phonon::SubtitleDescription();
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_Phonon_SubtitleDescription_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_Phonon_SubtitleDescription_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_Phonon_SubtitleDescription_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_SubtitleDescription_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_SubtitleDescription_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.SubtitleDescription",
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
    /*tp_traverse*/         Sbk_Phonon_SubtitleDescription_traverse,
    /*tp_clear*/            Sbk_Phonon_SubtitleDescription_clear,
    /*tp_richcompare*/      Sbk_Phonon_SubtitleDescription_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_SubtitleDescription_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_SubtitleDescription_Init,
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
static void SubtitleDescription_PythonToCpp_SubtitleDescription_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_SubtitleDescription_Type, pyIn, cppOut);
}
static PythonToCppFunc is_SubtitleDescription_PythonToCpp_SubtitleDescription_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_SubtitleDescription_Type))
        return SubtitleDescription_PythonToCpp_SubtitleDescription_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* SubtitleDescription_PTR_CppToPython_SubtitleDescription(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::SubtitleDescription*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_SubtitleDescription_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* SubtitleDescription_COPY_CppToPython_SubtitleDescription(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_Phonon_SubtitleDescription_Type, new ::Phonon::SubtitleDescription(*((::Phonon::SubtitleDescription*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void SubtitleDescription_PythonToCpp_SubtitleDescription_COPY(PyObject* pyIn, void* cppOut) {
    *((::Phonon::SubtitleDescription*)cppOut) = *((::Phonon::SubtitleDescription*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_SubtitleDescription_PythonToCpp_SubtitleDescription_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_SubtitleDescription_Type))
        return SubtitleDescription_PythonToCpp_SubtitleDescription_COPY;
    return 0;
}

void init_Phonon_SubtitleDescription(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_SubtitleDescription_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "SubtitleDescription", "Phonon::SubtitleDescription",
        &Sbk_Phonon_SubtitleDescription_Type, &Shiboken::callCppDestructor< ::Phonon::SubtitleDescription >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_SubtitleDescription_Type,
        SubtitleDescription_PythonToCpp_SubtitleDescription_PTR,
        is_SubtitleDescription_PythonToCpp_SubtitleDescription_PTR_Convertible,
        SubtitleDescription_PTR_CppToPython_SubtitleDescription,
        SubtitleDescription_COPY_CppToPython_SubtitleDescription);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::SubtitleDescription");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::SubtitleDescription*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::SubtitleDescription&");
    Shiboken::Conversions::registerConverterName(converter, "SubtitleDescription");
    Shiboken::Conversions::registerConverterName(converter, "SubtitleDescription*");
    Shiboken::Conversions::registerConverterName(converter, "SubtitleDescription&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::SubtitleDescription).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        SubtitleDescription_PythonToCpp_SubtitleDescription_COPY,
        is_SubtitleDescription_PythonToCpp_SubtitleDescription_COPY_Convertible);


    qRegisterMetaType< ::Phonon::SubtitleDescription >("SubtitleDescription");
    qRegisterMetaType< ::Phonon::SubtitleDescription >("Phonon::SubtitleDescription");
}
