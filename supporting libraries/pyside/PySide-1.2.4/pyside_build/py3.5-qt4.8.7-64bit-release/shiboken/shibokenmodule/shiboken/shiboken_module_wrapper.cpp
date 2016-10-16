
#include <sbkpython.h>
#include <shiboken.h>
#include <algorithm>
#include "shiboken_python.h"



// Extra includes
#include "sbkversion.h"

// Current module's type array.
PyTypeObject** SbkshibokenTypes;
// Current module's converter array.
SbkConverter** SbkshibokenTypeConverters;

// Global functions ------------------------------------------------------------
static PyObject* SbkshibokenModule_createdByPython(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createdByPython(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // createdByPython(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_createdByPython_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createdByPython(PyObject*)
            // Begin code injection

            if (Shiboken::Object::checkType(pyArg)) {
                bool wasCreatedByPython = Shiboken::Object::wasCreatedByPython((SbkObject*)pyArg);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &wasCreatedByPython);
            } else {
                PyErr_SetString(PyExc_TypeError, "You need a shiboken-based type.");
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkshibokenModule_createdByPython_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "createdByPython", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_delete(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: delete(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // delete(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_delete_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // delete(PyObject*)
            // Begin code injection

            if (Shiboken::Object::checkType(pyArg)) {
                Shiboken::Object::callCppDestructors((SbkObject*)pyArg);
            } else {
                PyErr_SetString(PyExc_TypeError, "You need a shiboken-based type.");
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkshibokenModule_delete_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "delete", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_dump(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dump(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // dump(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_dump_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dump(PyObject*)
            // Begin code injection

            if (!Shiboken::Object::checkType(pyArg)) {
                pyResult = Shiboken::String::fromCString("Ordinary Python type.");
            } else {
                std::string str = Shiboken::Object::info((SbkObject*)pyArg);
                pyResult = Shiboken::String::fromCString(str.c_str());
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkshibokenModule_dump_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "dump", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_getCppPointer(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getCppPointer(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // getCppPointer(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_getCppPointer_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCppPointer(PyObject*)
            // Begin code injection

            if (Shiboken::Object::checkType(pyArg)) {
                std::vector<void*> ptrs = Shiboken::Object::cppPointers((SbkObject*)pyArg);
                pyResult = PyTuple_New(ptrs.size());
                for (std::size_t i = 0; i < ptrs.size(); ++i)
                    PyTuple_SET_ITEM(pyResult, i, PyLong_FromVoidPtr(ptrs[i]));
            } else {
                PyErr_SetString(PyExc_TypeError, "You need a shiboken-based type.");
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkshibokenModule_getCppPointer_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "getCppPointer", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_invalidate(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: invalidate(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // invalidate(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_invalidate_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate(PyObject*)
            // Begin code injection

            Shiboken::Object::invalidate(pyArg);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkshibokenModule_invalidate_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "invalidate", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_isValid(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isValid(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // isValid(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_isValid_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid(PyObject*)
            // Begin code injection

            bool isValid = Shiboken::Object::isValid(pyArg, false);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &isValid);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkshibokenModule_isValid_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "isValid", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_ownedByPython(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ownedByPython(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // ownedByPython(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_ownedByPython_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownedByPython(PyObject*)
            // Begin code injection

            if (Shiboken::Object::checkType(pyArg)) {
                bool hasOwnership = Shiboken::Object::hasOwnership((SbkObject*)pyArg);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &hasOwnership);
            } else {
                PyErr_SetString(PyExc_TypeError, "You need a shiboken-based type.");
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkshibokenModule_ownedByPython_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "ownedByPython", overloads);
        return 0;
}

static PyObject* SbkshibokenModule_wrapInstance(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "wrapInstance", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: wrapInstance(unsigned long,PyType)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[0])))
        && PyType_Check(pyArgs[1])) {
        overloadId = 0; // wrapInstance(unsigned long,PyType)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkshibokenModule_wrapInstance_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // wrapInstance(unsigned long,PyType)
            // Begin code injection

            if (Shiboken::ObjectType::checkType((PyTypeObject*)pyArgs[1]))
                pyResult = Shiboken::Object::newObject((SbkObjectType*)pyArgs[1], (void*)cppArg0, false, true);
            else
                PyErr_SetString(PyExc_TypeError, "You need a shiboken-based type.");

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkshibokenModule_wrapInstance_TypeError:
        const char* overloads[] = {"unsigned long, PyType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "wrapInstance", overloads);
        return 0;
}


static PyMethodDef shiboken_methods[] = {
    {"createdByPython", (PyCFunction)SbkshibokenModule_createdByPython, METH_O},
    {"delete", (PyCFunction)SbkshibokenModule_delete, METH_O},
    {"dump", (PyCFunction)SbkshibokenModule_dump, METH_O},
    {"getCppPointer", (PyCFunction)SbkshibokenModule_getCppPointer, METH_O},
    {"invalidate", (PyCFunction)SbkshibokenModule_invalidate, METH_O},
    {"isValid", (PyCFunction)SbkshibokenModule_isValid, METH_O},
    {"ownedByPython", (PyCFunction)SbkshibokenModule_ownedByPython, METH_O},
    {"wrapInstance", (PyCFunction)SbkshibokenModule_wrapInstance, METH_VARARGS},
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------


// Module initialization ------------------------------------------------------------
#if defined _WIN32 || defined __CYGWIN__
    #define SBK_EXPORT_MODULE __declspec(dllexport)
#elif __GNUC__ >= 4
    #define SBK_EXPORT_MODULE __attribute__ ((visibility("default")))
#else
    #define SBK_EXPORT_MODULE
#endif

#ifdef IS_PY3K
static struct PyModuleDef moduledef = {
    /* m_base     */ PyModuleDef_HEAD_INIT,
    /* m_name     */ "shiboken",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ shiboken_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(shiboken)

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_shiboken_CONVERTERS_IDX_COUNT];
    SbkshibokenTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("shiboken", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("shiboken", shiboken_methods);
#endif

    // Initialize classes in the type system
    // Register primitive types converters.

    Shiboken::Module::registerTypeConverters(module, SbkshibokenTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module shiboken");
    }
    // Begin code injection

    // Add __version__ and __version_info__ attributes to the module
    PyObject* version = PyTuple_New(5);
    PyTuple_SET_ITEM(version, 0, PyInt_FromLong(SHIBOKEN_MAJOR_VERSION));
    PyTuple_SET_ITEM(version, 1, PyInt_FromLong(SHIBOKEN_MINOR_VERSION));
    PyTuple_SET_ITEM(version, 2, PyInt_FromLong(SHIBOKEN_MICRO_VERSION));
    PyTuple_SET_ITEM(version, 3, Shiboken::String::fromCString(SHIBOKEN_RELEASE_LEVEL));
    PyTuple_SET_ITEM(version, 4, PyInt_FromLong(SHIBOKEN_SERIAL));
    PyModule_AddObject(module, "__version_info__", version);
    PyModule_AddStringConstant(module, "__version__", SHIBOKEN_VERSION);

    // End of code injection


SBK_MODULE_INIT_FUNCTION_END
