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
#include "pyside_qtgui_python.h"

#include "qitemeditorfactory_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qitemeditorfactory.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QItemEditorFactoryWrapper::QItemEditorFactoryWrapper() : QItemEditorFactory() {
    // ... middle
}

QWidget * QItemEditorFactoryWrapper::createEditor(QVariant::Type type, QWidget * parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createEditor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QItemEditorFactory::createEditor(type, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], &type),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QWidget*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QItemEditorFactory.createEditor", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QByteArray QItemEditorFactoryWrapper::valuePropertyName(QVariant::Type type) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QByteArray();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "valuePropertyName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QItemEditorFactory::valuePropertyName(type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QByteArray();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QItemEditorFactory.valuePropertyName", Shiboken::SbkType< QByteArray >()->tp_name, pyResult->ob_type->tp_name);
        return ::QByteArray();
    }
    ::QByteArray cppResult = ::QByteArray();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QItemEditorFactoryWrapper::~QItemEditorFactoryWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QItemEditorFactory_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QItemEditorFactory >()))
        return -1;

    ::QItemEditorFactoryWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QItemEditorFactory()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QItemEditorFactoryWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QItemEditorFactory >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QItemEditorFactoryFunc_createEditor(PyObject* self, PyObject* args)
{
    ::QItemEditorFactory* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemEditorFactory*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMEDITORFACTORY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createEditor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createEditor(QVariant::Type,QWidget*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
        overloadId = 0; // createEditor(QVariant::Type,QWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemEditorFactoryFunc_createEditor_TypeError;

    // Call function/method
    {
        ::QVariant::Type cppArg0 = QVariant::Invalid;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createEditor(QVariant::Type,QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QItemEditorFactory*>(cppSelf)->::QItemEditorFactory::createEditor(cppArg0, cppArg1) : const_cast<const ::QItemEditorFactory*>(cppSelf)->createEditor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemEditorFactoryFunc_createEditor_TypeError:
        const char* overloads[] = {"QVariant::Type, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemEditorFactory.createEditor", overloads);
        return 0;
}

static PyObject* Sbk_QItemEditorFactoryFunc_defaultFactory(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultFactory()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QItemEditorFactory * cppResult = ::QItemEditorFactory::defaultFactory();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMEDITORFACTORY_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemEditorFactoryFunc_registerEditor(PyObject* self, PyObject* args)
{
    ::QItemEditorFactory* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemEditorFactory*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMEDITORFACTORY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "registerEditor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: registerEditor(QVariant::Type,QItemEditorCreatorBase*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMEDITORCREATORBASE_IDX], (pyArgs[1])))) {
        overloadId = 0; // registerEditor(QVariant::Type,QItemEditorCreatorBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemEditorFactoryFunc_registerEditor_TypeError;

    // Call function/method
    {
        ::QVariant::Type cppArg0 = QVariant::Invalid;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QItemEditorCreatorBase* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // registerEditor(QVariant::Type,QItemEditorCreatorBase*)
            // Begin code injection

            Shiboken::Object::releaseOwnership(pyArgs[2-1]);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->registerEditor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "registerEditor(QVariant::Type,QItemEditorCreatorBase*)2", pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemEditorFactoryFunc_registerEditor_TypeError:
        const char* overloads[] = {"QVariant::Type, PySide.QtGui.QItemEditorCreatorBase", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemEditorFactory.registerEditor", overloads);
        return 0;
}

static PyObject* Sbk_QItemEditorFactoryFunc_setDefaultFactory(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultFactory(QItemEditorFactory*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMEDITORFACTORY_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultFactory(QItemEditorFactory*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemEditorFactoryFunc_setDefaultFactory_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QItemEditorFactory* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultFactory(QItemEditorFactory*)
            // Begin code injection

            //this function is static we need keep ref to default value, to be able to call python virtual functions
            static PyObject* _defaultValue = 0;
            QItemEditorFactory::setDefaultFactory(cppArg0);
            Py_INCREF(pyArg);
            if (_defaultValue)
                Py_DECREF(_defaultValue);

            _defaultValue = pyArg;

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::releaseOwnership(pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemEditorFactoryFunc_setDefaultFactory_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemEditorFactory", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemEditorFactory.setDefaultFactory", overloads);
        return 0;
}

static PyObject* Sbk_QItemEditorFactoryFunc_valuePropertyName(PyObject* self, PyObject* pyArg)
{
    ::QItemEditorFactory* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemEditorFactory*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMEDITORFACTORY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: valuePropertyName(QVariant::Type)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArg)))) {
        overloadId = 0; // valuePropertyName(QVariant::Type)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemEditorFactoryFunc_valuePropertyName_TypeError;

    // Call function/method
    {
        ::QVariant::Type cppArg0 = QVariant::Invalid;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // valuePropertyName(QVariant::Type)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QItemEditorFactory*>(cppSelf)->::QItemEditorFactory::valuePropertyName(cppArg0) : const_cast<const ::QItemEditorFactory*>(cppSelf)->valuePropertyName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemEditorFactoryFunc_valuePropertyName_TypeError:
        const char* overloads[] = {"QVariant::Type", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemEditorFactory.valuePropertyName", overloads);
        return 0;
}

static PyMethodDef Sbk_QItemEditorFactory_methods[] = {
    {"createEditor", (PyCFunction)Sbk_QItemEditorFactoryFunc_createEditor, METH_VARARGS},
    {"defaultFactory", (PyCFunction)Sbk_QItemEditorFactoryFunc_defaultFactory, METH_NOARGS|METH_STATIC},
    {"registerEditor", (PyCFunction)Sbk_QItemEditorFactoryFunc_registerEditor, METH_VARARGS},
    {"setDefaultFactory", (PyCFunction)Sbk_QItemEditorFactoryFunc_setDefaultFactory, METH_O|METH_STATIC},
    {"valuePropertyName", (PyCFunction)Sbk_QItemEditorFactoryFunc_valuePropertyName, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QItemEditorFactory_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QItemEditorFactory_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QItemEditorFactory_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QItemEditorFactory",
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
    /*tp_traverse*/         Sbk_QItemEditorFactory_traverse,
    /*tp_clear*/            Sbk_QItemEditorFactory_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QItemEditorFactory_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QItemEditorFactory_Init,
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
static void QItemEditorFactory_PythonToCpp_QItemEditorFactory_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QItemEditorFactory_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QItemEditorFactory_PythonToCpp_QItemEditorFactory_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemEditorFactory_Type))
        return QItemEditorFactory_PythonToCpp_QItemEditorFactory_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QItemEditorFactory_PTR_CppToPython_QItemEditorFactory(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QItemEditorFactory*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QItemEditorFactory_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QItemEditorFactory(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QITEMEDITORFACTORY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QItemEditorFactory_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QItemEditorFactory", "QItemEditorFactory*",
        &Sbk_QItemEditorFactory_Type, &Shiboken::callCppDestructor< ::QItemEditorFactory >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QItemEditorFactory_Type,
        QItemEditorFactory_PythonToCpp_QItemEditorFactory_PTR,
        is_QItemEditorFactory_PythonToCpp_QItemEditorFactory_PTR_Convertible,
        QItemEditorFactory_PTR_CppToPython_QItemEditorFactory);

    Shiboken::Conversions::registerConverterName(converter, "QItemEditorFactory");
    Shiboken::Conversions::registerConverterName(converter, "QItemEditorFactory*");
    Shiboken::Conversions::registerConverterName(converter, "QItemEditorFactory&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemEditorFactory).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemEditorFactoryWrapper).name());



}
