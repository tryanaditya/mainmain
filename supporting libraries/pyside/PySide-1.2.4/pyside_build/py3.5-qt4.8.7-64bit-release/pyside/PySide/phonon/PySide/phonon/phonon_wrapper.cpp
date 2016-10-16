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


// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include "pyside_phonon_python.h"

#include "phonon_wrapper.h"
#include "phonon_backendcapabilities_wrapper.h"
#include "phonon_volumeslider_wrapper.h"
#include "phonon_volumefaderinterface_wrapper.h"
#include "phonon_videowidgetinterface_wrapper.h"
#include "phonon_videoplayer_wrapper.h"
#include "phonon_streaminterface_wrapper.h"
#include "phonon_seekslider_wrapper.h"
#include "phonon_platformplugin_wrapper.h"
#include "phonon_effectdescriptionmodel_wrapper.h"
#include "phonon_audiooutputdevicemodel_wrapper.h"
#include "phonon_mediaobjectinterface_wrapper.h"
#include "phonon_mediasource_wrapper.h"
#include "phonon_mediacontroller_wrapper.h"
#include "phonon_effectwidget_wrapper.h"
#include "phonon_effectparameter_wrapper.h"
#include "phonon_effectinterface_wrapper.h"
#include "phonon_backendinterface_wrapper.h"
#include "phonon_addoninterface_wrapper.h"
#include "phonon_abstractmediastream_wrapper.h"
#include "phonon_medianode_wrapper.h"
#include "phonon_mediaobject_wrapper.h"
#include "phonon_effect_wrapper.h"
#include "phonon_volumefadereffect_wrapper.h"
#include "phonon_abstractvideooutput_wrapper.h"
#include "phonon_videowidget_wrapper.h"
#include "phonon_abstractaudiooutput_wrapper.h"
#include "phonon_audiooutput_wrapper.h"
#include "phonon_path_wrapper.h"
#include "phonon_audiooutputdevice_wrapper.h"
#include "phonon_audiocapturedevice_wrapper.h"
#include "phonon_subtitledescription_wrapper.h"
#include "phonon_videocapturedevice_wrapper.h"
#include "phonon_effectdescription_wrapper.h"
#include "phonon_audiochanneldescription_wrapper.h"

// Extra includes
#include <effectparameter.h>
#include <medianode.h>
#include <mediaobject.h>
#include <mediasource.h>
#include <path.h>
#include <phononnamespace.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_PhononFunc_categoryToString(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: categoryToString(Phonon::CaptureCategory)
    // 1: categoryToString(Phonon::Category)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX]), (pyArg)))) {
        overloadId = 1; // categoryToString(Phonon::Category)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX]), (pyArg)))) {
        overloadId = 0; // categoryToString(Phonon::CaptureCategory)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PhononFunc_categoryToString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // categoryToString(Phonon::CaptureCategory c)
        {
            ::Phonon::CaptureCategory cppArg0 = ((::Phonon::CaptureCategory)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // categoryToString(Phonon::CaptureCategory)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::Phonon::categoryToString(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // categoryToString(Phonon::Category c)
        {
            ::Phonon::Category cppArg0 = ((::Phonon::Category)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // categoryToString(Phonon::Category)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::Phonon::categoryToString(cppArg0);
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

    Sbk_PhononFunc_categoryToString_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon.CaptureCategory", "PySide.phonon.Phonon.Category", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.Phonon.categoryToString", overloads);
        return 0;
}

static PyObject* Sbk_PhononFunc_createPath(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createPath", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createPath(Phonon::MediaNode*,Phonon::MediaNode*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (pyArgs[1])))) {
        overloadId = 0; // createPath(Phonon::MediaNode*,Phonon::MediaNode*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PhononFunc_createPath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Phonon::MediaNode* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::Phonon::MediaNode* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createPath(Phonon::MediaNode*,Phonon::MediaNode*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::Path cppResult = ::Phonon::createPath(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PhononFunc_createPath_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaNode, PySide.phonon.Phonon::MediaNode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.Phonon.createPath", overloads);
        return 0;
}

static PyObject* Sbk_PhononFunc_createPlayer(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.Phonon.createPlayer(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.Phonon.createPlayer(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:createPlayer", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createPlayer(Phonon::Category,Phonon::MediaSource)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createPlayer(Phonon::Category,Phonon::MediaSource)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArgs[1])))) {
            overloadId = 0; // createPlayer(Phonon::Category,Phonon::MediaSource)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PhononFunc_createPlayer_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "source");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.Phonon.createPlayer(): got multiple values for keyword argument 'source'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArgs[1]))))
                    goto Sbk_PhononFunc_createPlayer_TypeError;
            }
        }
        ::Phonon::Category cppArg0 = ((::Phonon::Category)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::Phonon::MediaSource cppArg1_local = Phonon::MediaSource();
        ::Phonon::MediaSource* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // createPlayer(Phonon::Category,Phonon::MediaSource)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::MediaObject * cppResult = ::Phonon::createPlayer(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PhononFunc_createPlayer_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon.Category, PySide.phonon.Phonon::MediaSource = Phonon.MediaSource()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.Phonon.createPlayer", overloads);
        return 0;
}

static PyObject* Sbk_PhononFunc_phononVersion(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // phononVersion()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = ::Phonon::phononVersion();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_PhononFunc_qHash(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qHash(Phonon::EffectParameter)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (pyArg)))) {
        overloadId = 0; // qHash(Phonon::EffectParameter)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_PhononFunc_qHash_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Phonon::EffectParameter cppArg0_local = ::Phonon::EffectParameter();
        ::Phonon::EffectParameter* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // qHash(Phonon::EffectParameter)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = ::Phonon::qHash(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_PhononFunc_qHash_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::EffectParameter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.Phonon.qHash", overloads);
        return 0;
}

static PyObject* Sbk_PhononFunc_registerMetaTypes(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // registerMetaTypes()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::Phonon::registerMetaTypes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_Phonon_methods[] = {
    {"categoryToString", (PyCFunction)Sbk_PhononFunc_categoryToString, METH_O|METH_STATIC},
    {"createPath", (PyCFunction)Sbk_PhononFunc_createPath, METH_VARARGS|METH_STATIC},
    {"createPlayer", (PyCFunction)Sbk_PhononFunc_createPlayer, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"phononVersion", (PyCFunction)Sbk_PhononFunc_phononVersion, METH_NOARGS|METH_STATIC},
    {"qHash", (PyCFunction)Sbk_PhononFunc_qHash, METH_O|METH_STATIC},
    {"registerMetaTypes", (PyCFunction)Sbk_PhononFunc_registerMetaTypes, METH_NOARGS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_Phonon_traverse,
    /*tp_clear*/            Sbk_Phonon_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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
static void Phonon_ObjectDescriptionType_PythonToCpp_Phonon_ObjectDescriptionType(PyObject* pyIn, void* cppOut) {
    *((::Phonon::ObjectDescriptionType*)cppOut) = (::Phonon::ObjectDescriptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_ObjectDescriptionType_PythonToCpp_Phonon_ObjectDescriptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX]))
        return Phonon_ObjectDescriptionType_PythonToCpp_Phonon_ObjectDescriptionType;
    return 0;
}
static PyObject* Phonon_ObjectDescriptionType_CppToPython_Phonon_ObjectDescriptionType(const void* cppIn) {
    int castCppIn = *((::Phonon::ObjectDescriptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX], castCppIn);

}

static void Phonon_DiscType_PythonToCpp_Phonon_DiscType(PyObject* pyIn, void* cppOut) {
    *((::Phonon::DiscType*)cppOut) = (::Phonon::DiscType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_DiscType_PythonToCpp_Phonon_DiscType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX]))
        return Phonon_DiscType_PythonToCpp_Phonon_DiscType;
    return 0;
}
static PyObject* Phonon_DiscType_CppToPython_Phonon_DiscType(const void* cppIn) {
    int castCppIn = *((::Phonon::DiscType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX], castCppIn);

}

static void Phonon_MetaData_PythonToCpp_Phonon_MetaData(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MetaData*)cppOut) = (::Phonon::MetaData) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_MetaData_PythonToCpp_Phonon_MetaData_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX]))
        return Phonon_MetaData_PythonToCpp_Phonon_MetaData;
    return 0;
}
static PyObject* Phonon_MetaData_CppToPython_Phonon_MetaData(const void* cppIn) {
    int castCppIn = *((::Phonon::MetaData*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX], castCppIn);

}

static void Phonon_State_PythonToCpp_Phonon_State(PyObject* pyIn, void* cppOut) {
    *((::Phonon::State*)cppOut) = (::Phonon::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_State_PythonToCpp_Phonon_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_STATE_IDX]))
        return Phonon_State_PythonToCpp_Phonon_State;
    return 0;
}
static PyObject* Phonon_State_CppToPython_Phonon_State(const void* cppIn) {
    int castCppIn = *((::Phonon::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX], castCppIn);

}

static void Phonon_Category_PythonToCpp_Phonon_Category(PyObject* pyIn, void* cppOut) {
    *((::Phonon::Category*)cppOut) = (::Phonon::Category) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_Category_PythonToCpp_Phonon_Category_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX]))
        return Phonon_Category_PythonToCpp_Phonon_Category;
    return 0;
}
static PyObject* Phonon_Category_CppToPython_Phonon_Category(const void* cppIn) {
    int castCppIn = *((::Phonon::Category*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX], castCppIn);

}

static void Phonon_CaptureCategory_PythonToCpp_Phonon_CaptureCategory(PyObject* pyIn, void* cppOut) {
    *((::Phonon::CaptureCategory*)cppOut) = (::Phonon::CaptureCategory) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_CaptureCategory_PythonToCpp_Phonon_CaptureCategory_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX]))
        return Phonon_CaptureCategory_PythonToCpp_Phonon_CaptureCategory;
    return 0;
}
static PyObject* Phonon_CaptureCategory_CppToPython_Phonon_CaptureCategory(const void* cppIn) {
    int castCppIn = *((::Phonon::CaptureCategory*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX], castCppIn);

}

static void Phonon_ErrorType_PythonToCpp_Phonon_ErrorType(PyObject* pyIn, void* cppOut) {
    *((::Phonon::ErrorType*)cppOut) = (::Phonon::ErrorType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_ErrorType_PythonToCpp_Phonon_ErrorType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX]))
        return Phonon_ErrorType_PythonToCpp_Phonon_ErrorType;
    return 0;
}
static PyObject* Phonon_ErrorType_CppToPython_Phonon_ErrorType(const void* cppIn) {
    int castCppIn = *((::Phonon::ErrorType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX], castCppIn);

}

void init_Phonon(PyObject* module)
{
    SbkPySide_phononTypes[SBK_PHONON_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Phonon", "Phonon",
        &Sbk_Phonon_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'ObjectDescriptionType'.
    SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "ObjectDescriptionType",
        "PySide.phonon.Phonon.ObjectDescriptionType",
        "Phonon::ObjectDescriptionType");
    if (!SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
        &Sbk_Phonon_Type, "AudioOutputDeviceType", (long) Phonon::AudioOutputDeviceType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
        &Sbk_Phonon_Type, "EffectType", (long) Phonon::EffectType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
        &Sbk_Phonon_Type, "AudioChannelType", (long) Phonon::AudioChannelType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
        &Sbk_Phonon_Type, "SubtitleType", (long) Phonon::SubtitleType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
        &Sbk_Phonon_Type, "AudioCaptureDeviceType", (long) Phonon::AudioCaptureDeviceType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
        &Sbk_Phonon_Type, "VideoCaptureDeviceType", (long) Phonon::VideoCaptureDeviceType))
        return ;
    // Register converter for enum 'Phonon::ObjectDescriptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX],
            Phonon_ObjectDescriptionType_CppToPython_Phonon_ObjectDescriptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_ObjectDescriptionType_PythonToCpp_Phonon_ObjectDescriptionType,
            is_Phonon_ObjectDescriptionType_PythonToCpp_Phonon_ObjectDescriptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::ObjectDescriptionType");
        Shiboken::Conversions::registerConverterName(converter, "ObjectDescriptionType");
    }
    // End of 'ObjectDescriptionType' enum.

    // Initialization of enum 'DiscType'.
    SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "DiscType",
        "PySide.phonon.Phonon.DiscType",
        "Phonon::DiscType");
    if (!SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX],
        &Sbk_Phonon_Type, "NoDisc", (long) Phonon::NoDisc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX],
        &Sbk_Phonon_Type, "Cd", (long) Phonon::Cd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX],
        &Sbk_Phonon_Type, "Dvd", (long) Phonon::Dvd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX],
        &Sbk_Phonon_Type, "Vcd", (long) Phonon::Vcd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX],
        &Sbk_Phonon_Type, "BluRay", (long) Phonon::BluRay))
        return ;
    // Register converter for enum 'Phonon::DiscType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX],
            Phonon_DiscType_CppToPython_Phonon_DiscType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_DiscType_PythonToCpp_Phonon_DiscType,
            is_Phonon_DiscType_PythonToCpp_Phonon_DiscType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::DiscType");
        Shiboken::Conversions::registerConverterName(converter, "DiscType");
    }
    // End of 'DiscType' enum.

    // Initialization of enum 'MetaData'.
    SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "MetaData",
        "PySide.phonon.Phonon.MetaData",
        "Phonon::MetaData");
    if (!SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "ArtistMetaData", (long) Phonon::ArtistMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "AlbumMetaData", (long) Phonon::AlbumMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "TitleMetaData", (long) Phonon::TitleMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "DateMetaData", (long) Phonon::DateMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "GenreMetaData", (long) Phonon::GenreMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "TracknumberMetaData", (long) Phonon::TracknumberMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "DescriptionMetaData", (long) Phonon::DescriptionMetaData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
        &Sbk_Phonon_Type, "MusicBrainzDiscIdMetaData", (long) Phonon::MusicBrainzDiscIdMetaData))
        return ;
    // Register converter for enum 'Phonon::MetaData'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX],
            Phonon_MetaData_CppToPython_Phonon_MetaData);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_MetaData_PythonToCpp_Phonon_MetaData,
            is_Phonon_MetaData_PythonToCpp_Phonon_MetaData_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::MetaData");
        Shiboken::Conversions::registerConverterName(converter, "MetaData");
    }
    // End of 'MetaData' enum.

    // Initialization of enum 'State'.
    SbkPySide_phononTypes[SBK_PHONON_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "State",
        "PySide.phonon.Phonon.State",
        "Phonon::State");
    if (!SbkPySide_phononTypes[SBK_PHONON_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
        &Sbk_Phonon_Type, "LoadingState", (long) Phonon::LoadingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
        &Sbk_Phonon_Type, "StoppedState", (long) Phonon::StoppedState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
        &Sbk_Phonon_Type, "PlayingState", (long) Phonon::PlayingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
        &Sbk_Phonon_Type, "BufferingState", (long) Phonon::BufferingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
        &Sbk_Phonon_Type, "PausedState", (long) Phonon::PausedState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
        &Sbk_Phonon_Type, "ErrorState", (long) Phonon::ErrorState))
        return ;
    // Register converter for enum 'Phonon::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX],
            Phonon_State_CppToPython_Phonon_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_State_PythonToCpp_Phonon_State,
            is_Phonon_State_PythonToCpp_Phonon_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'Category'.
    SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "Category",
        "PySide.phonon.Phonon.Category",
        "Phonon::Category");
    if (!SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "NoCategory", (long) Phonon::NoCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "NotificationCategory", (long) Phonon::NotificationCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "MusicCategory", (long) Phonon::MusicCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "VideoCategory", (long) Phonon::VideoCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "CommunicationCategory", (long) Phonon::CommunicationCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "GameCategory", (long) Phonon::GameCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "AccessibilityCategory", (long) Phonon::AccessibilityCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
        &Sbk_Phonon_Type, "LastCategory", (long) Phonon::LastCategory))
        return ;
    // Register converter for enum 'Phonon::Category'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX],
            Phonon_Category_CppToPython_Phonon_Category);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_Category_PythonToCpp_Phonon_Category,
            is_Phonon_Category_PythonToCpp_Phonon_Category_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_CATEGORY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::Category");
        Shiboken::Conversions::registerConverterName(converter, "Category");
    }
    // End of 'Category' enum.

    // Initialization of enum 'CaptureCategory'.
    SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "CaptureCategory",
        "PySide.phonon.Phonon.CaptureCategory",
        "Phonon::CaptureCategory");
    if (!SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX],
        &Sbk_Phonon_Type, "NoCaptureCategory", (long) Phonon::NoCaptureCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX],
        &Sbk_Phonon_Type, "CommunicationCaptureCategory", (long) Phonon::CommunicationCaptureCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX],
        &Sbk_Phonon_Type, "RecordingCaptureCategory", (long) Phonon::RecordingCaptureCategory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX],
        &Sbk_Phonon_Type, "ControlCaptureCategory", (long) Phonon::ControlCaptureCategory))
        return ;
    // Register converter for enum 'Phonon::CaptureCategory'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX],
            Phonon_CaptureCategory_CppToPython_Phonon_CaptureCategory);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_CaptureCategory_PythonToCpp_Phonon_CaptureCategory,
            is_Phonon_CaptureCategory_PythonToCpp_Phonon_CaptureCategory_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::CaptureCategory");
        Shiboken::Conversions::registerConverterName(converter, "CaptureCategory");
    }
    // End of 'CaptureCategory' enum.

    // Initialization of enum 'ErrorType'.
    SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_Type,
        "ErrorType",
        "PySide.phonon.Phonon.ErrorType",
        "Phonon::ErrorType");
    if (!SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX],
        &Sbk_Phonon_Type, "NoError", (long) Phonon::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX],
        &Sbk_Phonon_Type, "NormalError", (long) Phonon::NormalError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX],
        &Sbk_Phonon_Type, "FatalError", (long) Phonon::FatalError))
        return ;
    // Register converter for enum 'Phonon::ErrorType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX],
            Phonon_ErrorType_CppToPython_Phonon_ErrorType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_ErrorType_PythonToCpp_Phonon_ErrorType,
            is_Phonon_ErrorType_PythonToCpp_Phonon_ErrorType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::ErrorType");
        Shiboken::Conversions::registerConverterName(converter, "ErrorType");
    }
    // End of 'ErrorType' enum.


    qRegisterMetaType< ::Phonon::ObjectDescriptionType >("Phonon::ObjectDescriptionType");
    qRegisterMetaType< ::Phonon::DiscType >("Phonon::DiscType");
    qRegisterMetaType< ::Phonon::MetaData >("Phonon::MetaData");
    qRegisterMetaType< ::Phonon::State >("Phonon::State");
    qRegisterMetaType< ::Phonon::Category >("Phonon::Category");
    qRegisterMetaType< ::Phonon::CaptureCategory >("Phonon::CaptureCategory");
    qRegisterMetaType< ::Phonon::ErrorType >("Phonon::ErrorType");
}
