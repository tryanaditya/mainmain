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

#include "phonon_addoninterface_wrapper.h"

// Extra includes
#include <QList>

using namespace Phonon;

// Native ---------------------------------------------------------

AddonInterfaceWrapper::AddonInterfaceWrapper() : Phonon::AddonInterface() {
    // ... middle
}

bool AddonInterfaceWrapper::hasInterface(Phonon::AddonInterface::Interface iface) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasInterface"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'AddonInterface.hasInterface()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX]), &iface)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "AddonInterface.hasInterface", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant AddonInterfaceWrapper::interfaceCall(Phonon::AddonInterface::Interface iface, int command, const QList<QVariant > & arguments)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "interfaceCall"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'AddonInterface.interfaceCall()' not implemented.");
        return ::QVariant();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX]), &iface),
        command,
        Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], &arguments)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "AddonInterface.interfaceCall", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

AddonInterfaceWrapper::~AddonInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_AddonInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::AddonInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::AddonInterface >()))
        return -1;

    ::AddonInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // AddonInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::AddonInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::AddonInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_AddonInterfaceFunc_hasInterface(PyObject* self, PyObject* pyArg)
{
    ::Phonon::AddonInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::AddonInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasInterface(Phonon::AddonInterface::Interface)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX]), (pyArg)))) {
        overloadId = 0; // hasInterface(Phonon::AddonInterface::Interface)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_AddonInterfaceFunc_hasInterface_TypeError;

    // Call function/method
    {
        ::Phonon::AddonInterface::Interface cppArg0 = ((::Phonon::AddonInterface::Interface)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasInterface(Phonon::AddonInterface::Interface)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'AddonInterface.hasInterface()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::AddonInterface*>(cppSelf)->hasInterface(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_AddonInterfaceFunc_hasInterface_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::AddonInterface.Interface", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.AddonInterface.hasInterface", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_AddonInterfaceFunc_interfaceCall(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Phonon::AddonInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::AddonInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.AddonInterface.interfaceCall(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.AddonInterface.interfaceCall(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:interfaceCall", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: interfaceCall(Phonon::AddonInterface::Interface,int,QList<QVariant>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // interfaceCall(Phonon::AddonInterface::Interface,int,QList<QVariant>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], (pyArgs[2])))) {
            overloadId = 0; // interfaceCall(Phonon::AddonInterface::Interface,int,QList<QVariant>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_AddonInterfaceFunc_interfaceCall_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arguments");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.AddonInterface.interfaceCall(): got multiple values for keyword argument 'arguments'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], (pyArgs[2]))))
                    goto Sbk_Phonon_AddonInterfaceFunc_interfaceCall_TypeError;
            }
        }
        ::Phonon::AddonInterface::Interface cppArg0 = ((::Phonon::AddonInterface::Interface)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QList<QVariant > cppArg2;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // interfaceCall(Phonon::AddonInterface::Interface,int,QList<QVariant>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'AddonInterface.interfaceCall()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = cppSelf->interfaceCall(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_AddonInterfaceFunc_interfaceCall_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::AddonInterface.Interface, int, list = QList< QVariant >()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.AddonInterface.interfaceCall", overloads);
        return 0;
}

static PyMethodDef Sbk_Phonon_AddonInterface_methods[] = {
    {"hasInterface", (PyCFunction)Sbk_Phonon_AddonInterfaceFunc_hasInterface, METH_O},
    {"interfaceCall", (PyCFunction)Sbk_Phonon_AddonInterfaceFunc_interfaceCall, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_AddonInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_AddonInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_AddonInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.AddonInterface",
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
    /*tp_traverse*/         Sbk_Phonon_AddonInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_AddonInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_AddonInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_AddonInterface_Init,
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
static void Phonon_AddonInterface_Interface_PythonToCpp_Phonon_AddonInterface_Interface(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::Interface*)cppOut) = (::Phonon::AddonInterface::Interface) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_Interface_PythonToCpp_Phonon_AddonInterface_Interface_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX]))
        return Phonon_AddonInterface_Interface_PythonToCpp_Phonon_AddonInterface_Interface;
    return 0;
}
static PyObject* Phonon_AddonInterface_Interface_CppToPython_Phonon_AddonInterface_Interface(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::Interface*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX], castCppIn);

}

static void Phonon_AddonInterface_NavigationCommand_PythonToCpp_Phonon_AddonInterface_NavigationCommand(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::NavigationCommand*)cppOut) = (::Phonon::AddonInterface::NavigationCommand) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_NavigationCommand_PythonToCpp_Phonon_AddonInterface_NavigationCommand_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX]))
        return Phonon_AddonInterface_NavigationCommand_PythonToCpp_Phonon_AddonInterface_NavigationCommand;
    return 0;
}
static PyObject* Phonon_AddonInterface_NavigationCommand_CppToPython_Phonon_AddonInterface_NavigationCommand(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::NavigationCommand*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX], castCppIn);

}

static void Phonon_AddonInterface_ChapterCommand_PythonToCpp_Phonon_AddonInterface_ChapterCommand(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::ChapterCommand*)cppOut) = (::Phonon::AddonInterface::ChapterCommand) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_ChapterCommand_PythonToCpp_Phonon_AddonInterface_ChapterCommand_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX]))
        return Phonon_AddonInterface_ChapterCommand_PythonToCpp_Phonon_AddonInterface_ChapterCommand;
    return 0;
}
static PyObject* Phonon_AddonInterface_ChapterCommand_CppToPython_Phonon_AddonInterface_ChapterCommand(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::ChapterCommand*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX], castCppIn);

}

static void Phonon_AddonInterface_AngleCommand_PythonToCpp_Phonon_AddonInterface_AngleCommand(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::AngleCommand*)cppOut) = (::Phonon::AddonInterface::AngleCommand) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_AngleCommand_PythonToCpp_Phonon_AddonInterface_AngleCommand_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX]))
        return Phonon_AddonInterface_AngleCommand_PythonToCpp_Phonon_AddonInterface_AngleCommand;
    return 0;
}
static PyObject* Phonon_AddonInterface_AngleCommand_CppToPython_Phonon_AddonInterface_AngleCommand(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::AngleCommand*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX], castCppIn);

}

static void Phonon_AddonInterface_TitleCommand_PythonToCpp_Phonon_AddonInterface_TitleCommand(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::TitleCommand*)cppOut) = (::Phonon::AddonInterface::TitleCommand) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_TitleCommand_PythonToCpp_Phonon_AddonInterface_TitleCommand_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX]))
        return Phonon_AddonInterface_TitleCommand_PythonToCpp_Phonon_AddonInterface_TitleCommand;
    return 0;
}
static PyObject* Phonon_AddonInterface_TitleCommand_CppToPython_Phonon_AddonInterface_TitleCommand(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::TitleCommand*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX], castCppIn);

}

static void Phonon_AddonInterface_SubtitleCommand_PythonToCpp_Phonon_AddonInterface_SubtitleCommand(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::SubtitleCommand*)cppOut) = (::Phonon::AddonInterface::SubtitleCommand) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_SubtitleCommand_PythonToCpp_Phonon_AddonInterface_SubtitleCommand_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX]))
        return Phonon_AddonInterface_SubtitleCommand_PythonToCpp_Phonon_AddonInterface_SubtitleCommand;
    return 0;
}
static PyObject* Phonon_AddonInterface_SubtitleCommand_CppToPython_Phonon_AddonInterface_SubtitleCommand(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::SubtitleCommand*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX], castCppIn);

}

static void Phonon_AddonInterface_AudioChannelCommand_PythonToCpp_Phonon_AddonInterface_AudioChannelCommand(PyObject* pyIn, void* cppOut) {
    *((::Phonon::AddonInterface::AudioChannelCommand*)cppOut) = (::Phonon::AddonInterface::AudioChannelCommand) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_AddonInterface_AudioChannelCommand_PythonToCpp_Phonon_AddonInterface_AudioChannelCommand_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX]))
        return Phonon_AddonInterface_AudioChannelCommand_PythonToCpp_Phonon_AddonInterface_AudioChannelCommand;
    return 0;
}
static PyObject* Phonon_AddonInterface_AudioChannelCommand_CppToPython_Phonon_AddonInterface_AudioChannelCommand(const void* cppIn) {
    int castCppIn = *((::Phonon::AddonInterface::AudioChannelCommand*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void AddonInterface_PythonToCpp_AddonInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_AddonInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_AddonInterface_PythonToCpp_AddonInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_AddonInterface_Type))
        return AddonInterface_PythonToCpp_AddonInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* AddonInterface_PTR_CppToPython_AddonInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::AddonInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_AddonInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_AddonInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_AddonInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "AddonInterface", "Phonon::AddonInterface*",
        &Sbk_Phonon_AddonInterface_Type, &Shiboken::callCppDestructor< ::Phonon::AddonInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_AddonInterface_Type,
        AddonInterface_PythonToCpp_AddonInterface_PTR,
        is_AddonInterface_PythonToCpp_AddonInterface_PTR_Convertible,
        AddonInterface_PTR_CppToPython_AddonInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface&");
    Shiboken::Conversions::registerConverterName(converter, "AddonInterface");
    Shiboken::Conversions::registerConverterName(converter, "AddonInterface*");
    Shiboken::Conversions::registerConverterName(converter, "AddonInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::AddonInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::AddonInterfaceWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'Interface'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "Interface",
        "PySide.phonon.Phonon.AddonInterface.Interface",
        "Phonon::AddonInterface::Interface");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
        &Sbk_Phonon_AddonInterface_Type, "NavigationInterface", (long) Phonon::AddonInterface::NavigationInterface))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
        &Sbk_Phonon_AddonInterface_Type, "ChapterInterface", (long) Phonon::AddonInterface::ChapterInterface))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
        &Sbk_Phonon_AddonInterface_Type, "AngleInterface", (long) Phonon::AddonInterface::AngleInterface))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
        &Sbk_Phonon_AddonInterface_Type, "TitleInterface", (long) Phonon::AddonInterface::TitleInterface))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
        &Sbk_Phonon_AddonInterface_Type, "SubtitleInterface", (long) Phonon::AddonInterface::SubtitleInterface))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
        &Sbk_Phonon_AddonInterface_Type, "AudioChannelInterface", (long) Phonon::AddonInterface::AudioChannelInterface))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::Interface'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX],
            Phonon_AddonInterface_Interface_CppToPython_Phonon_AddonInterface_Interface);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_Interface_PythonToCpp_Phonon_AddonInterface_Interface,
            is_Phonon_AddonInterface_Interface_PythonToCpp_Phonon_AddonInterface_Interface_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_INTERFACE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::Interface");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::Interface");
        Shiboken::Conversions::registerConverterName(converter, "Interface");
    }
    // End of 'Interface' enum.

    // Initialization of enum 'NavigationCommand'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "NavigationCommand",
        "PySide.phonon.Phonon.AddonInterface.NavigationCommand",
        "Phonon::AddonInterface::NavigationCommand");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "availableMenus", (long) Phonon::AddonInterface::availableMenus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setMenu", (long) Phonon::AddonInterface::setMenu))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::NavigationCommand'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX],
            Phonon_AddonInterface_NavigationCommand_CppToPython_Phonon_AddonInterface_NavigationCommand);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_NavigationCommand_PythonToCpp_Phonon_AddonInterface_NavigationCommand,
            is_Phonon_AddonInterface_NavigationCommand_PythonToCpp_Phonon_AddonInterface_NavigationCommand_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_NAVIGATIONCOMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::NavigationCommand");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::NavigationCommand");
        Shiboken::Conversions::registerConverterName(converter, "NavigationCommand");
    }
    // End of 'NavigationCommand' enum.

    // Initialization of enum 'ChapterCommand'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "ChapterCommand",
        "PySide.phonon.Phonon.AddonInterface.ChapterCommand",
        "Phonon::AddonInterface::ChapterCommand");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "availableChapters", (long) Phonon::AddonInterface::availableChapters))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "chapter", (long) Phonon::AddonInterface::chapter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setChapter", (long) Phonon::AddonInterface::setChapter))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::ChapterCommand'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX],
            Phonon_AddonInterface_ChapterCommand_CppToPython_Phonon_AddonInterface_ChapterCommand);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_ChapterCommand_PythonToCpp_Phonon_AddonInterface_ChapterCommand,
            is_Phonon_AddonInterface_ChapterCommand_PythonToCpp_Phonon_AddonInterface_ChapterCommand_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_CHAPTERCOMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::ChapterCommand");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::ChapterCommand");
        Shiboken::Conversions::registerConverterName(converter, "ChapterCommand");
    }
    // End of 'ChapterCommand' enum.

    // Initialization of enum 'AngleCommand'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "AngleCommand",
        "PySide.phonon.Phonon.AddonInterface.AngleCommand",
        "Phonon::AddonInterface::AngleCommand");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "availableAngles", (long) Phonon::AddonInterface::availableAngles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "angle", (long) Phonon::AddonInterface::angle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setAngle", (long) Phonon::AddonInterface::setAngle))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::AngleCommand'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX],
            Phonon_AddonInterface_AngleCommand_CppToPython_Phonon_AddonInterface_AngleCommand);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_AngleCommand_PythonToCpp_Phonon_AddonInterface_AngleCommand,
            is_Phonon_AddonInterface_AngleCommand_PythonToCpp_Phonon_AddonInterface_AngleCommand_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_ANGLECOMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::AngleCommand");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::AngleCommand");
        Shiboken::Conversions::registerConverterName(converter, "AngleCommand");
    }
    // End of 'AngleCommand' enum.

    // Initialization of enum 'TitleCommand'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "TitleCommand",
        "PySide.phonon.Phonon.AddonInterface.TitleCommand",
        "Phonon::AddonInterface::TitleCommand");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "availableTitles", (long) Phonon::AddonInterface::availableTitles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "title", (long) Phonon::AddonInterface::title))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setTitle", (long) Phonon::AddonInterface::setTitle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "autoplayTitles", (long) Phonon::AddonInterface::autoplayTitles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setAutoplayTitles", (long) Phonon::AddonInterface::setAutoplayTitles))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::TitleCommand'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX],
            Phonon_AddonInterface_TitleCommand_CppToPython_Phonon_AddonInterface_TitleCommand);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_TitleCommand_PythonToCpp_Phonon_AddonInterface_TitleCommand,
            is_Phonon_AddonInterface_TitleCommand_PythonToCpp_Phonon_AddonInterface_TitleCommand_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_TITLECOMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::TitleCommand");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::TitleCommand");
        Shiboken::Conversions::registerConverterName(converter, "TitleCommand");
    }
    // End of 'TitleCommand' enum.

    // Initialization of enum 'SubtitleCommand'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "SubtitleCommand",
        "PySide.phonon.Phonon.AddonInterface.SubtitleCommand",
        "Phonon::AddonInterface::SubtitleCommand");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "availableSubtitles", (long) Phonon::AddonInterface::availableSubtitles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "currentSubtitle", (long) Phonon::AddonInterface::currentSubtitle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setCurrentSubtitle", (long) Phonon::AddonInterface::setCurrentSubtitle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setCurrentSubtitleFile", (long) Phonon::AddonInterface::setCurrentSubtitleFile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "subtitleAutodetect", (long) Phonon::AddonInterface::subtitleAutodetect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setSubtitleAutodetect", (long) Phonon::AddonInterface::setSubtitleAutodetect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "subtitleEncoding", (long) Phonon::AddonInterface::subtitleEncoding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setSubtitleEncoding", (long) Phonon::AddonInterface::setSubtitleEncoding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "subtitleFont", (long) Phonon::AddonInterface::subtitleFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setSubtitleFont", (long) Phonon::AddonInterface::setSubtitleFont))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::SubtitleCommand'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX],
            Phonon_AddonInterface_SubtitleCommand_CppToPython_Phonon_AddonInterface_SubtitleCommand);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_SubtitleCommand_PythonToCpp_Phonon_AddonInterface_SubtitleCommand,
            is_Phonon_AddonInterface_SubtitleCommand_PythonToCpp_Phonon_AddonInterface_SubtitleCommand_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_SUBTITLECOMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::SubtitleCommand");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::SubtitleCommand");
        Shiboken::Conversions::registerConverterName(converter, "SubtitleCommand");
    }
    // End of 'SubtitleCommand' enum.

    // Initialization of enum 'AudioChannelCommand'.
    SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_AddonInterface_Type,
        "AudioChannelCommand",
        "PySide.phonon.Phonon.AddonInterface.AudioChannelCommand",
        "Phonon::AddonInterface::AudioChannelCommand");
    if (!SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "availableAudioChannels", (long) Phonon::AddonInterface::availableAudioChannels))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "currentAudioChannel", (long) Phonon::AddonInterface::currentAudioChannel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX],
        &Sbk_Phonon_AddonInterface_Type, "setCurrentAudioChannel", (long) Phonon::AddonInterface::setCurrentAudioChannel))
        return ;
    // Register converter for enum 'Phonon::AddonInterface::AudioChannelCommand'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX],
            Phonon_AddonInterface_AudioChannelCommand_CppToPython_Phonon_AddonInterface_AudioChannelCommand);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_AddonInterface_AudioChannelCommand_PythonToCpp_Phonon_AddonInterface_AudioChannelCommand,
            is_Phonon_AddonInterface_AudioChannelCommand_PythonToCpp_Phonon_AddonInterface_AudioChannelCommand_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_ADDONINTERFACE_AUDIOCHANNELCOMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::AddonInterface::AudioChannelCommand");
        Shiboken::Conversions::registerConverterName(converter, "AddonInterface::AudioChannelCommand");
        Shiboken::Conversions::registerConverterName(converter, "AudioChannelCommand");
    }
    // End of 'AudioChannelCommand' enum.


    qRegisterMetaType< ::Phonon::AddonInterface::Interface >("AddonInterface::Interface");
    qRegisterMetaType< ::Phonon::AddonInterface::Interface >("Phonon::AddonInterface::Interface");
    qRegisterMetaType< ::Phonon::AddonInterface::NavigationCommand >("AddonInterface::NavigationCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::NavigationCommand >("Phonon::AddonInterface::NavigationCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::ChapterCommand >("AddonInterface::ChapterCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::ChapterCommand >("Phonon::AddonInterface::ChapterCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::AngleCommand >("AddonInterface::AngleCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::AngleCommand >("Phonon::AddonInterface::AngleCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::TitleCommand >("AddonInterface::TitleCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::TitleCommand >("Phonon::AddonInterface::TitleCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::SubtitleCommand >("AddonInterface::SubtitleCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::SubtitleCommand >("Phonon::AddonInterface::SubtitleCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::AudioChannelCommand >("AddonInterface::AudioChannelCommand");
    qRegisterMetaType< ::Phonon::AddonInterface::AudioChannelCommand >("Phonon::AddonInterface::AudioChannelCommand");
}
