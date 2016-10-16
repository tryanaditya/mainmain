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


#include <sbkpython.h>
#include <shiboken.h>
#include <algorithm>
#include <pyside.h>
#include "pyside_qtcore_python.h"

#include <qbytearray.h>
#include <qmath.h>
#include <qnumeric.h>
#include <qglobal.h>


// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtCoreTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtCoreTypeConverters;
    // Begin code injection

    bool py2kStrCheck(PyObject* obj)
    {
    #ifdef IS_PY3K
        return false;
    #else
        return PyString_Check(obj);
    #endif
    }


    static const char* QVariant_resolveMetaType(PyTypeObject* type, int* typeId)
    {
        if (PyObject_TypeCheck(type, &SbkObjectType_Type)) {
            SbkObjectType* sbkType = (SbkObjectType*)type;
            const char* typeName = Shiboken::ObjectType::getOriginalName(sbkType);
            if (!typeName)
                return 0;
            bool valueType = '*' != typeName[qstrlen(typeName) - 1];
            // Do not convert user type of value
            if (valueType & Shiboken::ObjectType::isUserType(type))
                return 0;
            int obTypeId = QMetaType::type(typeName);
            if (obTypeId) {
                *typeId = obTypeId;
                return typeName;
            }
            // Do not resolve types to value type
            if (valueType)
                return 0;
            // find in base types
            if (type->tp_base) {
                return QVariant_resolveMetaType(type->tp_base, typeId);
            } else if (type->tp_bases) {
                for(int i = 0; i < PyTuple_GET_SIZE(type->tp_bases); ++i) {
                    const char* derivedName = QVariant_resolveMetaType((PyTypeObject*)PyTuple_GET_ITEM(type->tp_bases, i), typeId);
                    if (derivedName)
                        return derivedName;
                }
            }
        }
        *typeId = 0;
        return 0;
    }
    static QVariant QVariant_convertToValueList(PyObject* list)
    {
        if (PySequence_Size(list) < 1)
            return QVariant();
        Shiboken::AutoDecRef element(PySequence_GetItem(list, 0));
        int typeId;
        const char* typeName = QVariant_resolveMetaType(element.cast<PyTypeObject*>(), &typeId);
        if (typeName) {
            QByteArray listTypeName("QList<");
            listTypeName += typeName;
            listTypeName += '>';
            typeId = QMetaType::type(listTypeName);
            if (typeId > 0) {
                Shiboken::Conversions::SpecificConverter converter(listTypeName);
                if (converter) {
                    QVariant var(typeId, (void*)0);
                    converter.toCpp(list, &var);
                    return var;
                }
                qWarning() << "Type converter for :" << listTypeName << "not registered.";
            }
        }
        return QVariant();
    }
    static bool QVariant_isStringList(PyObject *list)
    {
        bool allString = true;
        Shiboken::AutoDecRef fast(PySequence_Fast(list, "Failed to convert QVariantList"));
        Py_ssize_t size = PySequence_Fast_GET_SIZE(fast.object());
        for(int i = 0; i < size; ++i) {
            PyObject* item = PySequence_Fast_GET_ITEM(fast.object(), i);
            if (!Shiboken::String::check(item)) {
                allString = false;
                break;
            }
        }
        return allString;
    }
    static QVariant QVariant_convertToVariantMap(PyObject* map)
    {
        Py_ssize_t pos = 0;
        Shiboken::AutoDecRef keys(PyDict_Keys(map));
        if (!QVariant_isStringList(keys))
            return QVariant();
        PyObject* key;
        PyObject* value;
        QMap<QString,QVariant> ret;
        while (PyDict_Next(map, &pos, &key, &value)) {
            ::QString cppKey = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
            ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
            ret.insert(cppKey, cppValue);
        }
        return QVariant(ret);
    }
    static QVariant QVariant_convertToVariantList(PyObject* list)
    {
        if (QVariant_isStringList(list)) {
            ::QList<QString > lst = ::QList<QString >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QSTRING_IDX], list, &(lst));
            return QVariant(QStringList(lst));
        }
        QVariant valueList = QVariant_convertToValueList(list);
        if (valueList.isValid())
            return valueList;
        QList<QVariant> lst;
        Shiboken::AutoDecRef fast(PySequence_Fast(list, "Failed to convert QVariantList"));
        Py_ssize_t size = PySequence_Fast_GET_SIZE(fast.object());
        for (int i = 0; i < size; ++i) {
            PyObject* pyItem = PySequence_Fast_GET_ITEM(fast.object(), i);
            ::QVariant item = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyItem, &(item));
            lst.append(item);
        }
        return QVariant(lst);
    }


    static bool QVariantType_isStringList(PyObject* list)
    {
        bool allString = true;
        Shiboken::AutoDecRef fast(PySequence_Fast(list, "Failed to convert QVariantList"));
        Py_ssize_t size = PySequence_Fast_GET_SIZE(fast.object());
        for(int i=0; i < size; i++) {
            PyObject* item = PySequence_Fast_GET_ITEM(fast.object(), i);
            if (!Shiboken::String::check(item)) {
                allString = false;
                break;
            }
        }
        return allString;
    }
    static bool QVariantType_checkAllStringKeys(PyObject* dict)
    {
        Shiboken::AutoDecRef keys(PyDict_Keys(dict));
        return QVariantType_isStringList(keys);
    }


    namespace PySide {
    static QStack<PyObject*> globalPostRoutineFunctions;
    void globalPostRoutineCallback()
    {
        foreach(PyObject* callback, globalPostRoutineFunctions) {
            Shiboken::AutoDecRef result(PyObject_CallObject(callback, NULL));
            Py_DECREF(callback);
        }
        globalPostRoutineFunctions.clear();
    }
    void addPostRoutine(PyObject* callback)
    {
        if (PyCallable_Check(callback)) {
            globalPostRoutineFunctions << callback;
            Py_INCREF(callback);
        } else {
            PyErr_SetString(PyExc_TypeError, "qAddPostRoutine: The argument must be a callable object.");
        }
    }
    } // namespace


    #include <pyside.h>


    // Define a global variable to handle qInstallMsgHandler callback
    static PyObject* qtmsghandler = 0;

    static void msgHandlerCallback(QtMsgType type, const char* msg)
    {
        Shiboken::GilState state;
        Shiboken::AutoDecRef arglist(PyTuple_New(2));
        PyTuple_SET_ITEM(arglist, 0, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX]), &type));
        PyTuple_SET_ITEM(arglist, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), msg));
        Shiboken::AutoDecRef ret(PyObject_CallObject(qtmsghandler, arglist));
    }
    static void QtCoreModuleExit()
    {
        PySide::SignalManager::instance().clear();
    }


    extern bool
    qRegisterResourceData(int,
                        const unsigned char *,
                        const unsigned char *,
                        const unsigned char *);

    extern bool
    qUnregisterResourceData(int,
                            const unsigned char *,
                            const unsigned char *,
                            const unsigned char *);

    // End of code injection

void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtCore_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtCoreTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------
static PyObject* SbkQtCoreModule_QT_TRANSLATE_NOOP(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QT_TRANSLATE_NOOP", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: QT_TRANSLATE_NOOP(PyObject,PyObject)
    if (numArgs == 2
        && PyObject_Check(pyArgs[0])
        && PyObject_Check(pyArgs[1])) {
        overloadId = 0; // QT_TRANSLATE_NOOP(PyObject,PyObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_QT_TRANSLATE_NOOP_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QT_TRANSLATE_NOOP(PyObject,PyObject)
            // Begin code injection

            // TEMPLATE - return_argument - START
              Py_INCREF(pyArgs[2-1]);
              pyResult = pyArgs[2-1];
            // TEMPLATE - return_argument - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_QT_TRANSLATE_NOOP_TypeError:
        const char* overloads[] = {"object, object", 0};
        Shiboken::setErrorAboutWrongArguments(args, "QT_TRANSLATE_NOOP", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_QT_TRANSLATE_NOOP3(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QT_TRANSLATE_NOOP3", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: QT_TRANSLATE_NOOP3(PyObject,PyObject,PyObject)
    if (numArgs == 3
        && PyObject_Check(pyArgs[0])
        && PyObject_Check(pyArgs[1])
        && PyObject_Check(pyArgs[2])) {
        overloadId = 0; // QT_TRANSLATE_NOOP3(PyObject,PyObject,PyObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_QT_TRANSLATE_NOOP3_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QT_TRANSLATE_NOOP3(PyObject,PyObject,PyObject)
            // Begin code injection

            // TEMPLATE - return_argument - START
              Py_INCREF(pyArgs[2-1]);
              pyResult = pyArgs[2-1];
            // TEMPLATE - return_argument - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_QT_TRANSLATE_NOOP3_TypeError:
        const char* overloads[] = {"object, object, object", 0};
        Shiboken::setErrorAboutWrongArguments(args, "QT_TRANSLATE_NOOP3", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_QT_TRANSLATE_NOOP_UTF8(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QT_TRANSLATE_NOOP_UTF8(PyObject)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // QT_TRANSLATE_NOOP_UTF8(PyObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_QT_TRANSLATE_NOOP_UTF8_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QT_TRANSLATE_NOOP_UTF8(PyObject)
            // Begin code injection

            // TEMPLATE - return_argument - START
              Py_INCREF(pyArg);
              pyResult = pyArg;
            // TEMPLATE - return_argument - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_QT_TRANSLATE_NOOP_UTF8_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "QT_TRANSLATE_NOOP_UTF8", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_QT_TR_NOOP(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QT_TR_NOOP(PyObject)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // QT_TR_NOOP(PyObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_QT_TR_NOOP_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QT_TR_NOOP(PyObject)
            // Begin code injection

            // TEMPLATE - return_argument - START
              Py_INCREF(pyArg);
              pyResult = pyArg;
            // TEMPLATE - return_argument - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_QT_TR_NOOP_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "QT_TR_NOOP", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_QT_TR_NOOP_UTF8(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QT_TR_NOOP_UTF8(PyObject)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // QT_TR_NOOP_UTF8(PyObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_QT_TR_NOOP_UTF8_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QT_TR_NOOP_UTF8(PyObject)
            // Begin code injection

            // TEMPLATE - return_argument - START
              Py_INCREF(pyArg);
              pyResult = pyArg;
            // TEMPLATE - return_argument - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_QT_TR_NOOP_UTF8_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "QT_TR_NOOP_UTF8", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_SIGNAL(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SIGNAL(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // SIGNAL(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_SIGNAL_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // SIGNAL(const char*)
            // Begin code injection

            pyResult = Shiboken::String::fromFormat("2%s", QMetaObject::normalizedSignature(cppArg0).constData());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_SIGNAL_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "SIGNAL", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_SLOT(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SLOT(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // SLOT(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_SLOT_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // SLOT(const char*)
            // Begin code injection

            pyResult = Shiboken::String::fromFormat("1%s", QMetaObject::normalizedSignature(cppArg0).constData());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_SLOT_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "SLOT", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule___moduleShutdown(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __moduleShutdown()
            // Begin code injection

            PySide::runCleanupFunctions();

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* SbkQtCoreModule_qAbs(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qAbs(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // qAbs(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qAbs_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qAbs(double)
            // Begin code injection

            double _abs = qAbs(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &_abs);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qAbs_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qAbs", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qAcos(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qAcos(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qAcos(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qAcos_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qAcos(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qAcos(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qAcos_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qAcos", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qAddPostRoutine(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qAddPostRoutine(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // qAddPostRoutine(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qAddPostRoutine_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // qAddPostRoutine(PyObject*)
            // Begin code injection

            PySide::addPostRoutine(pyArg);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkQtCoreModule_qAddPostRoutine_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qAddPostRoutine", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qAsin(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qAsin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qAsin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qAsin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qAsin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qAsin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qAsin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qAsin", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qAtan(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qAtan(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qAtan(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qAtan_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qAtan(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qAtan(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qAtan_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qAtan", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qAtan2(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qAtan2", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: qAtan2(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // qAtan2(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qAtan2_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // qAtan2(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qAtan2(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qAtan2_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qAtan2", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qChecksum(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qChecksum", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: qChecksum(const char*,uint)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[1])))) {
        overloadId = 0; // qChecksum(const char*,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qChecksum_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        uint cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // qChecksum(const char*,uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint16 cppResult = qChecksum(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qChecksum_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qChecksum", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qCritical(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qCritical(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // qCritical(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qCritical_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qCritical(const char*)
            // Begin code injection

            // TEMPLATE - use_stream_for_format_security - START
            // Uses the stream version for security reasons
            // see gcc man page at -Wformat-security
            qCritical() << cppArg0;
            // TEMPLATE - use_stream_for_format_security - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkQtCoreModule_qCritical_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qCritical", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qDebug(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qDebug(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // qDebug(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qDebug_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qDebug(const char*)
            // Begin code injection

            // TEMPLATE - use_stream_for_format_security - START
            // Uses the stream version for security reasons
            // see gcc man page at -Wformat-security
            qDebug() << cppArg0;
            // TEMPLATE - use_stream_for_format_security - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkQtCoreModule_qDebug_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qDebug", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qExp(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qExp(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qExp(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qExp_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qExp(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qExp(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qExp_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qExp", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qFabs(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qFabs(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qFabs(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qFabs_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qFabs(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qFabs(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qFabs_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qFabs", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qFastCos(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qFastCos(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qFastCos(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qFastCos_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qFastCos(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qFastCos(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qFastCos_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qFastCos", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qFastSin(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qFastSin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qFastSin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qFastSin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qFastSin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qFastSin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qFastSin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qFastSin", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qFatal(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qFatal(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // qFatal(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qFatal_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qFatal(const char*)
            // Begin code injection

            // qFatal doesn't have a stream version, so we do a
            // qWarning call followed by a qFatal() call using a
            // literal.
            qWarning() << cppArg0;
            qFatal("[A qFatal() call was made from Python code]");

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkQtCoreModule_qFatal_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qFatal", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qFuzzyCompare(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qFuzzyCompare", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: qFuzzyCompare(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // qFuzzyCompare(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qFuzzyCompare_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // qFuzzyCompare(double,double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qFuzzyCompare(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qFuzzyCompare_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qFuzzyCompare", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qFuzzyIsNull(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qFuzzyIsNull(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // qFuzzyIsNull(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qFuzzyIsNull_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qFuzzyIsNull(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qFuzzyIsNull(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qFuzzyIsNull_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qFuzzyIsNull", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qInstallMsgHandler(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qInstallMsgHandler(PyObject)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // qInstallMsgHandler(PyObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qInstallMsgHandler_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // qInstallMsgHandler(PyObject)
            // Begin code injection

            if (pyArg == Py_None) {
              qInstallMsgHandler(0);
              pyResult = qtmsghandler ? qtmsghandler : Py_None;
              qtmsghandler = 0;
            } else if (!PyCallable_Check(pyArg)) {
              PyErr_SetString(PyExc_TypeError, "parameter must be callable");
            } else {
              pyResult = qtmsghandler ? qtmsghandler : Py_None;
              Py_INCREF(pyArg);
              qtmsghandler = pyArg;
              qInstallMsgHandler(msgHandlerCallback);
            }

            if (pyResult == Py_None)
              Py_INCREF(pyResult);


            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qInstallMsgHandler_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qInstallMsgHandler", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qIsFinite(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qIsFinite(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // qIsFinite(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qIsFinite_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qIsFinite(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qIsFinite(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qIsFinite_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qIsFinite", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qIsInf(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qIsInf(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // qIsInf(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qIsInf_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qIsInf(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qIsInf(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qIsInf_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qIsInf", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qIsNaN(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qIsNaN(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // qIsNaN(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qIsNaN_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qIsNaN(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qIsNaN(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qIsNaN_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qIsNaN", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qIsNull(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qIsNull(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // qIsNull(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qIsNull_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qIsNull(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qIsNull(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qIsNull_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qIsNull", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qRegisterResourceData(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qRegisterResourceData", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: qRegisterResourceData(int,PyBytes,PyBytes,PyBytes)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PyBytes_Check(pyArgs[1])
        && PyBytes_Check(pyArgs[2])
        && PyBytes_Check(pyArgs[3])) {
        overloadId = 0; // qRegisterResourceData(int,PyBytes,PyBytes,PyBytes)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qRegisterResourceData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qRegisterResourceData(int,PyBytes,PyBytes,PyBytes)
            // Begin code injection

            bool cppResult = qRegisterResourceData(cppArg0, (uchar*)PyBytes_AS_STRING(pyArgs[2-1]),
                                                 (uchar*)PyBytes_AS_STRING(pyArgs[3-1]),
                                                 (uchar*)PyBytes_AS_STRING(pyArgs[4-1]));
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qRegisterResourceData_TypeError:
        const char* overloads[] = {"int, " SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qRegisterResourceData", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qRound(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qRound(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qRound(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qRound_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qRound(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = qRound(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qRound_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qRound", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qTan(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qTan(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // qTan(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qTan_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qTan(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = qTan(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qTan_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qTan", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qUnregisterResourceData(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qUnregisterResourceData", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: qUnregisterResourceData(int,PyBytes,PyBytes,PyBytes)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && PyBytes_Check(pyArgs[1])
        && PyBytes_Check(pyArgs[2])
        && PyBytes_Check(pyArgs[3])) {
        overloadId = 0; // qUnregisterResourceData(int,PyBytes,PyBytes,PyBytes)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qUnregisterResourceData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qUnregisterResourceData(int,PyBytes,PyBytes,PyBytes)
            // Begin code injection

            bool cppResult = qUnregisterResourceData(cppArg0, (uchar*)PyBytes_AS_STRING(pyArgs[2-1]),
                                                 (uchar*)PyBytes_AS_STRING(pyArgs[3-1]),
                                                 (uchar*)PyBytes_AS_STRING(pyArgs[4-1]));
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qUnregisterResourceData_TypeError:
        const char* overloads[] = {"int, " SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qUnregisterResourceData", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qVersion(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // qVersion()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = qVersion();
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

static PyObject* SbkQtCoreModule_qWarning(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qWarning(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // qWarning(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qWarning_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // qWarning(const char*)
            // Begin code injection

            // TEMPLATE - use_stream_for_format_security - START
            // Uses the stream version for security reasons
            // see gcc man page at -Wformat-security
            qWarning() << cppArg0;
            // TEMPLATE - use_stream_for_format_security - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkQtCoreModule_qWarning_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qWarning", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qrand(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // qrand()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = qrand();
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

static PyObject* SbkQtCoreModule_qsrand(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qsrand(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArg)))) {
        overloadId = 0; // qsrand(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qsrand_TypeError;

    // Call function/method
    {
        uint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qsrand(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qsrand(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    SbkQtCoreModule_qsrand_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qsrand", overloads);
        return 0;
}

static PyObject* SbkQtCoreModule_qtTrId(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "qtTrId(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "qtTrId(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:qtTrId", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: qtTrId(const char*,int)
    if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // qtTrId(const char*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // qtTrId(const char*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtCoreModule_qtTrId_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "n");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "qtTrId(): got multiple values for keyword argument 'n'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto SbkQtCoreModule_qtTrId_TypeError;
            }
        }
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // qtTrId(const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = qtTrId(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtCoreModule_qtTrId_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qtTrId", overloads);
        return 0;
}


static PyMethodDef QtCore_methods[] = {
    {"QT_TRANSLATE_NOOP", (PyCFunction)SbkQtCoreModule_QT_TRANSLATE_NOOP, METH_VARARGS},
    {"QT_TRANSLATE_NOOP3", (PyCFunction)SbkQtCoreModule_QT_TRANSLATE_NOOP3, METH_VARARGS},
    {"QT_TRANSLATE_NOOP_UTF8", (PyCFunction)SbkQtCoreModule_QT_TRANSLATE_NOOP_UTF8, METH_O},
    {"QT_TR_NOOP", (PyCFunction)SbkQtCoreModule_QT_TR_NOOP, METH_O},
    {"QT_TR_NOOP_UTF8", (PyCFunction)SbkQtCoreModule_QT_TR_NOOP_UTF8, METH_O},
    {"SIGNAL", (PyCFunction)SbkQtCoreModule_SIGNAL, METH_O},
    {"SLOT", (PyCFunction)SbkQtCoreModule_SLOT, METH_O},
    {"__moduleShutdown", (PyCFunction)SbkQtCoreModule___moduleShutdown, METH_NOARGS},
    {"qAbs", (PyCFunction)SbkQtCoreModule_qAbs, METH_O},
    {"qAcos", (PyCFunction)SbkQtCoreModule_qAcos, METH_O},
    {"qAddPostRoutine", (PyCFunction)SbkQtCoreModule_qAddPostRoutine, METH_O},
    {"qAsin", (PyCFunction)SbkQtCoreModule_qAsin, METH_O},
    {"qAtan", (PyCFunction)SbkQtCoreModule_qAtan, METH_O},
    {"qAtan2", (PyCFunction)SbkQtCoreModule_qAtan2, METH_VARARGS},
    {"qChecksum", (PyCFunction)SbkQtCoreModule_qChecksum, METH_VARARGS},
    {"qCritical", (PyCFunction)SbkQtCoreModule_qCritical, METH_O},
    {"qDebug", (PyCFunction)SbkQtCoreModule_qDebug, METH_O},
    {"qExp", (PyCFunction)SbkQtCoreModule_qExp, METH_O},
    {"qFabs", (PyCFunction)SbkQtCoreModule_qFabs, METH_O},
    {"qFastCos", (PyCFunction)SbkQtCoreModule_qFastCos, METH_O},
    {"qFastSin", (PyCFunction)SbkQtCoreModule_qFastSin, METH_O},
    {"qFatal", (PyCFunction)SbkQtCoreModule_qFatal, METH_O},
    {"qFuzzyCompare", (PyCFunction)SbkQtCoreModule_qFuzzyCompare, METH_VARARGS},
    {"qFuzzyIsNull", (PyCFunction)SbkQtCoreModule_qFuzzyIsNull, METH_O},
    {"qInstallMsgHandler", (PyCFunction)SbkQtCoreModule_qInstallMsgHandler, METH_O},
    {"qIsFinite", (PyCFunction)SbkQtCoreModule_qIsFinite, METH_O},
    {"qIsInf", (PyCFunction)SbkQtCoreModule_qIsInf, METH_O},
    {"qIsNaN", (PyCFunction)SbkQtCoreModule_qIsNaN, METH_O},
    {"qIsNull", (PyCFunction)SbkQtCoreModule_qIsNull, METH_O},
    {"qRegisterResourceData", (PyCFunction)SbkQtCoreModule_qRegisterResourceData, METH_VARARGS},
    {"qRound", (PyCFunction)SbkQtCoreModule_qRound, METH_O},
    {"qTan", (PyCFunction)SbkQtCoreModule_qTan, METH_O},
    {"qUnregisterResourceData", (PyCFunction)SbkQtCoreModule_qUnregisterResourceData, METH_VARARGS},
    {"qVersion", (PyCFunction)SbkQtCoreModule_qVersion, METH_NOARGS},
    {"qWarning", (PyCFunction)SbkQtCoreModule_qWarning, METH_O},
    {"qrand", (PyCFunction)SbkQtCoreModule_qrand, METH_NOARGS},
    {"qsrand", (PyCFunction)SbkQtCoreModule_qsrand, METH_O},
    {"qtTrId", (PyCFunction)SbkQtCoreModule_qtTrId, METH_VARARGS|METH_KEYWORDS},
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QSysInfo(PyObject* module);
void init_QGenericArgument(PyObject* module);
void init_QGenericReturnArgument(PyObject* module);
void init_QMetaMethod(PyObject* module);
void init_QByteArray(PyObject* module);
void init_QUrl(PyObject* module);
void init_QEvent(PyObject* module);
void init_QTimerEvent(PyObject* module);
void init_QChildEvent(PyObject* module);
void init_QDynamicPropertyChangeEvent(PyObject* module);
void init_QDataStream(PyObject* module);
void init_QMutex(PyObject* module);
void init_QMutexLocker(PyObject* module);
void init_QReadWriteLock(PyObject* module);
void init_QReadLocker(PyObject* module);
void init_QWriteLocker(PyObject* module);
void init_QSemaphore(PyObject* module);
void init_QWaitCondition(PyObject* module);
void init_QXmlStreamAttribute(PyObject* module);
void init_QXmlStreamAttributes(PyObject* module);
void init_QXmlStreamNamespaceDeclaration(PyObject* module);
void init_QXmlStreamNotationDeclaration(PyObject* module);
void init_QXmlStreamEntityDeclaration(PyObject* module);
void init_QXmlStreamEntityResolver(PyObject* module);
void init_QXmlStreamReader(PyObject* module);
void init_QXmlStreamWriter(PyObject* module);
void init_QRunnable(PyObject* module);
void init_QSystemLocale(PyObject* module);
void init_QLocale(PyObject* module);
void init_QResource(PyObject* module);
void init_QTextStreamManipulator(PyObject* module);
void init_QBasicTimer(PyObject* module);
void init_QMetaEnum(PyObject* module);
void init_QMetaProperty(PyObject* module);
void init_QMetaClassInfo(PyObject* module);
void init_QSystemSemaphore(PyObject* module);
void init_QFactoryInterface(PyObject* module);
void init_QUuid(PyObject* module);
void init_QLibraryInfo(PyObject* module);
void init_QTextCodec(PyObject* module);
void init_QTextCodec_ConverterState(PyObject* module);
void init_QTextEncoder(PyObject* module);
void init_QTextDecoder(PyObject* module);
void init_QFileInfo(PyObject* module);
void init_QDir(PyObject* module);
void init_QDirIterator(PyObject* module);
void init_QAbstractFileEngine(PyObject* module);
void init_QFSFileEngine(PyObject* module);
void init_QAbstractFileEngineHandler(PyObject* module);
void init_QAbstractFileEngineIterator(PyObject* module);
void init_QProcessEnvironment(PyObject* module);
void init_QEasingCurve(PyObject* module);
void init_QBitArray(PyObject* module);
void init_QByteArrayMatcher(PyObject* module);
void init_QCryptographicHash(PyObject* module);
void init_QElapsedTimer(PyObject* module);
void init_QPoint(PyObject* module);
void init_QPointF(PyObject* module);
void init_QLine(PyObject* module);
void init_QLineF(PyObject* module);
void init_QMargins(PyObject* module);
void init_QSize(PyObject* module);
void init_QSizeF(PyObject* module);
void init_QRect(PyObject* module);
void init_QRectF(PyObject* module);
void init_QTextBoundaryFinder(PyObject* module);
void init_Qt(PyObject* module);
void init_QRegExp(PyObject* module);
void init_QModelIndex(PyObject* module);
void init_QPersistentModelIndex(PyObject* module);
void init_QDate(PyObject* module);
void init_QTime(PyObject* module);
void init_QDateTime(PyObject* module);
void init_QMetaObject(PyObject* module);
void init_QObject(PyObject* module);
void init_QSocketNotifier(PyObject* module);
void init_QTimer(PyObject* module);
void init_QTimeLine(PyObject* module);
void init_QTranslator(PyObject* module);
void init_QThread(PyObject* module);
void init_QPluginLoader(PyObject* module);
void init_QAbstractState(PyObject* module);
void init_QFinalState(PyObject* module);
void init_QHistoryState(PyObject* module);
void init_QState(PyObject* module);
void init_QStateMachine(PyObject* module);
void init_QStateMachine_SignalEvent(PyObject* module);
void init_QStateMachine_WrappedEvent(PyObject* module);
void init_QThreadPool(PyObject* module);
void init_QAbstractTransition(PyObject* module);
void init_QEventTransition(PyObject* module);
void init_QSignalTransition(PyObject* module);
void init_QEventLoop(PyObject* module);
void init_QCoreApplication(PyObject* module);
void init_QAbstractEventDispatcher(PyObject* module);
void init_QFileSystemWatcher(PyObject* module);
void init_QAbstractItemModel(PyObject* module);
void init_QAbstractListModel(PyObject* module);
void init_QAbstractTableModel(PyObject* module);
void init_QSettings(PyObject* module);
void init_QIODevice(PyObject* module);
void init_QBuffer(PyObject* module);
void init_QProcess(PyObject* module);
void init_QTextStream(PyObject* module);
void init_QFile(PyObject* module);
void init_QTemporaryFile(PyObject* module);
void init_QAbstractAnimation(PyObject* module);
void init_QAnimationGroup(PyObject* module);
void init_QParallelAnimationGroup(PyObject* module);
void init_QSequentialAnimationGroup(PyObject* module);
void init_QPauseAnimation(PyObject* module);
void init_QVariantAnimation(PyObject* module);
void init_QPropertyAnimation(PyObject* module);
void init_QMimeData(PyObject* module);
void init_QSignalMapper(PyObject* module);
void init_QtConcurrent(PyObject* module);

// Enum definitions ------------------------------------------------------------
static void QtMsgType_PythonToCpp_QtMsgType(PyObject* pyIn, void* cppOut) {
    *((::QtMsgType*)cppOut) = (::QtMsgType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QtMsgType_PythonToCpp_QtMsgType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX]))
        return QtMsgType_PythonToCpp_QtMsgType;
    return 0;
}
static PyObject* QtMsgType_CppToPython_QtMsgType(const void* cppIn) {
    int castCppIn = *((::QtMsgType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX], castCppIn);

}



// Module initialization ------------------------------------------------------------

// Primitive Type converters.

// C++ to Python conversion for type 'QString'.
static PyObject* QString_CppToPython_QString(const void* cppIn) {
    ::QString& cppInRef = *((::QString*)cppIn);

            const int N = cppInRef.length();
            wchar_t* str = new wchar_t[N];
            cppInRef.toWCharArray(str);
            PyObject* pyOut = PyUnicode_FromWideChar(str, N);
            delete[] str;
            return pyOut;

}
// Python to C++ conversions for type 'QString'.
static void PyUnicode_PythonToCpp_QString(PyObject* pyIn, void* cppOut) {

    Py_UNICODE* unicode = PyUnicode_AS_UNICODE(pyIn);
    #if defined(Py_UNICODE_WIDE)
    // cast as Py_UNICODE can be a different type
    *((::QString*)cppOut) = QString::fromUcs4((const uint*)unicode);
    #else
    *((::QString*)cppOut) = QString::fromUtf16((const ushort*)unicode, PyUnicode_GET_SIZE(pyIn));
    #endif

}
static PythonToCppFunc is_PyUnicode_PythonToCpp_QString_Convertible(PyObject* pyIn) {
    if (PyUnicode_Check(pyIn))
        return PyUnicode_PythonToCpp_QString;
    return 0;
}
static void PyString_PythonToCpp_QString(PyObject* pyIn, void* cppOut) {

    #ifndef IS_PY3K
    const char* str;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), pyIn, &(str));
    *((::QString*)cppOut) = QString(str);
    #endif

}
static PythonToCppFunc is_PyString_PythonToCpp_QString_Convertible(PyObject* pyIn) {
    if (py2kStrCheck(pyIn))
        return PyString_PythonToCpp_QString;
    return 0;
}
static void Py_None_PythonToCpp_QString(PyObject* pyIn, void* cppOut) {

    *((::QString*)cppOut) = QString();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QString_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QString;
    return 0;
}

// C++ to Python conversion for type 'QVariant'.
static PyObject* QVariant_CppToPython_QVariant(const void* cppIn) {
    ::QVariant& cppInRef = *((::QVariant*)cppIn);

            if (!cppInRef.isValid())
                Py_RETURN_NONE;

            if (qstrcmp(cppInRef.typeName(), "QVariantList") == 0) {
                QList<QVariant> var = cppInRef.value<QVariantList>();
                return Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX], &var);
            }

            if (qstrcmp(cppInRef.typeName(), "QStringList") == 0) {
                QStringList var = cppInRef.value<QStringList>();
                return Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QSTRING_IDX], &var);
            }

            if (qstrcmp(cppInRef.typeName(), "QVariantMap") == 0) {
                QMap<QString, QVariant> var = cppInRef.value<QVariantMap>();
                return Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_QSTRING_QVARIANT_IDX], &var);
            }

            Shiboken::Conversions::SpecificConverter converter(cppInRef.typeName());
            if (converter) {
               void* ptr = cppInRef.data();
               return converter.toPython(ptr);
            }
            PyErr_Format(PyExc_RuntimeError, "Can't find converter for '%s'.", cppInRef.typeName());
            return 0;

}
// Python to C++ conversions for type 'QVariant'.
static void PyBool_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    *((::QVariant*)cppOut) = QVariant(pyIn == Py_True);

}
static PythonToCppFunc is_PyBool_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyBool_Check(pyIn))
        return PyBool_PythonToCpp_QVariant;
    return 0;
}
static void Py_None_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    *((::QVariant*)cppOut) = QVariant();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QVariant;
    return 0;
}
static void QString_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    ::QString in = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &(in));
    *((::QVariant*)cppOut) = QVariant(in);

}
static PythonToCppFunc is_QString_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return QString_PythonToCpp_QVariant;
    return 0;
}
static void QByteArray_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    ::QByteArray in = ::QByteArray();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyIn, &(in));
    *((::QVariant*)cppOut) = QVariant(in);

}
static PythonToCppFunc is_QByteArray_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]))
        return QByteArray_PythonToCpp_QVariant;
    return 0;
}
static void PyFloat_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    double in;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), pyIn, &(in));
    *((::QVariant*)cppOut) = QVariant(in);

}
static PythonToCppFunc is_PyFloat_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyFloat_CheckExact(pyIn))
        return PyFloat_PythonToCpp_QVariant;
    return 0;
}
static void PyInt_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    int in;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &(in));
    *((::QVariant*)cppOut) = QVariant(in);

}
static PythonToCppFunc is_PyInt_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PyInt_PythonToCpp_QVariant;
    return 0;
}
static void PyLong_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    qlonglong in;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), pyIn, &(in));
    *((::QVariant*)cppOut) = QVariant(in);

}
static PythonToCppFunc is_PyLong_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyLong_CheckExact(pyIn))
        return PyLong_PythonToCpp_QVariant;
    return 0;
}
static void SbkEnumType_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    int in;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &(in));
    *((::QVariant*)cppOut) = QVariant(in);

}
static PythonToCppFunc is_SbkEnumType_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (Shiboken::isShibokenEnum(pyIn))
        return SbkEnumType_PythonToCpp_QVariant;
    return 0;
}
static void SbkObject_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    // a class supported by QVariant?
    int typeCode;
    const char* typeName = QVariant_resolveMetaType(pyIn->ob_type, &typeCode);
    if (!typeCode || !typeName)
        return;
    QVariant var(typeCode, (void*)0);
    Shiboken::Conversions::SpecificConverter converter(typeName);
    converter.toCpp(pyIn, var.data());
    *((::QVariant*)cppOut) = var;

}
static PythonToCppFunc is_SbkObject_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (Shiboken::Object::checkType(pyIn))
        return SbkObject_PythonToCpp_QVariant;
    return 0;
}
static void PyDict_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    QVariant ret = QVariant_convertToVariantMap(pyIn);
    *((::QVariant*)cppOut) = ret.isValid() ? ret : QVariant::fromValue<PySide::PyObjectWrapper>(pyIn);

}
static PythonToCppFunc is_PyDict_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyDict_Check(pyIn))
        return PyDict_PythonToCpp_QVariant;
    return 0;
}
static void PySequence_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    *((::QVariant*)cppOut) = QVariant_convertToVariantList(pyIn);

}
static PythonToCppFunc is_PySequence_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PySequence_Check(pyIn))
        return PySequence_PythonToCpp_QVariant;
    return 0;
}
static void PyObject_PythonToCpp_QVariant(PyObject* pyIn, void* cppOut) {

    // Is a shiboken type not known by Qt
    *((::QVariant*)cppOut) = QVariant::fromValue<PySide::PyObjectWrapper>(pyIn);

}
static PythonToCppFunc is_PyObject_PythonToCpp_QVariant_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, &PyBaseObject_Type))
        return PyObject_PythonToCpp_QVariant;
    return 0;
}

// C++ to Python conversion for type 'QBool'.
static PyObject* QBool_CppToPython_QBool(const void* cppIn) {
    ::QBool& cppInRef = *((::QBool*)cppIn);

            return PyBool_FromLong((bool)cppInRef);

}
// Python to C++ conversions for type 'QBool'.
static void PyBool_PythonToCpp_QBool(PyObject* pyIn, void* cppOut) {

    *((::QBool*)cppOut) = QBool(pyIn == Py_True);

}
static PythonToCppFunc is_PyBool_PythonToCpp_QBool_Convertible(PyObject* pyIn) {
    if (PyBool_Check(pyIn))
        return PyBool_PythonToCpp_QBool;
    return 0;
}

// C++ to Python conversion for type 'QVariant::Type'.
static PyObject* QVariant_Type_CppToPython_QVariant_Type(const void* cppIn) {
    ::QVariant::Type& cppInRef = *((::QVariant::Type*)cppIn);

            const char* typeName = QVariant::typeToName(cppInRef);
            PyObject* pyOut;
            PyTypeObject* pyType = 0;
            if (typeName)
                pyType = Shiboken::Conversions::getPythonTypeObject(typeName);
            pyOut = pyType ? ((PyObject*)pyType) : Py_None;
            Py_INCREF(pyOut);
            return pyOut;

}
// Python to C++ conversions for type 'QVariant::Type'.
static void Py_None_PythonToCpp_QVariant_Type(PyObject* pyIn, void* cppOut) {

    *((::QVariant::Type*)cppOut) = QVariant::Invalid;

}
static PythonToCppFunc is_Py_None_PythonToCpp_QVariant_Type_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QVariant_Type;
    return 0;
}
static void PyTypeObject_PythonToCpp_QVariant_Type(PyObject* pyIn, void* cppOut) {

    const char* typeName;
    if (Shiboken::String::checkType((PyTypeObject*)pyIn))
        typeName = "QString";
    else if (pyIn == (PyObject*)&PyFloat_Type)
        typeName = "double"; // float is a UserType in QVariant.
    else if (pyIn == (PyObject*)&PyLong_Type)
        typeName = "int";    // long is a UserType in QVariant.
    else if (pyIn->ob_type == &SbkObjectType_Type)
        typeName = Shiboken::ObjectType::getOriginalName((SbkObjectType*)pyIn);
    else
        typeName = ((PyTypeObject*)pyIn)->tp_name;
    *((::QVariant::Type*)cppOut) = QVariant::nameToType(typeName);

}
static PythonToCppFunc is_PyTypeObject_PythonToCpp_QVariant_Type_Convertible(PyObject* pyIn) {
    if (PyType_Check(pyIn))
        return PyTypeObject_PythonToCpp_QVariant_Type;
    return 0;
}
static void PyString_PythonToCpp_QVariant_Type(PyObject* pyIn, void* cppOut) {

    *((::QVariant::Type*)cppOut) = QVariant::nameToType(Shiboken::String::toCString(pyIn));

}
static PythonToCppFunc is_PyString_PythonToCpp_QVariant_Type_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PyString_PythonToCpp_QVariant_Type;
    return 0;
}
static void PyDict_PythonToCpp_QVariant_Type(PyObject* pyIn, void* cppOut) {

    *((::QVariant::Type*)cppOut) = QVariant::nameToType("QVariantMap");

}
static PythonToCppFunc is_PyDict_PythonToCpp_QVariant_Type_Convertible(PyObject* pyIn) {
    if (PyDict_Check(pyIn) && QVariantType_checkAllStringKeys(pyIn))
        return PyDict_PythonToCpp_QVariant_Type;
    return 0;
}
static void PySequence_PythonToCpp_QVariant_Type(PyObject* pyIn, void* cppOut) {

    const char* typeName;
    if (QVariantType_isStringList(pyIn))
        typeName = "QStringList";
    else
        typeName = "QVariantList";
    *((::QVariant::Type*)cppOut) = QVariant::nameToType(typeName);

}
static PythonToCppFunc is_PySequence_PythonToCpp_QVariant_Type_Convertible(PyObject* pyIn) {
    if (PySequence_Check(pyIn))
        return PySequence_PythonToCpp_QVariant_Type;
    return 0;
}

// C++ to Python conversion for type 'QStringRef'.
static PyObject* QStringRef_CppToPython_QStringRef(const void* cppIn) {
    ::QStringRef& cppInRef = *((::QStringRef*)cppIn);

            const int N = cppInRef.toString().length();
            wchar_t* str = new wchar_t[N];
            cppInRef.toString().toWCharArray(str);
            PyObject* pyOut = PyUnicode_FromWideChar(str, N);
            delete[] str;
            return pyOut;

}
// Python to C++ conversions for type 'QStringRef'.
static void PyObject_PythonToCpp_QStringRef(PyObject* pyIn, void* cppOut) {

    *((::QStringRef*)cppOut) = QStringRef();

}
static PythonToCppFunc is_PyObject_PythonToCpp_QStringRef_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn) || pyIn == Py_None)
        return PyObject_PythonToCpp_QStringRef;
    return 0;
}

// C++ to Python conversion for type 'QStringList'.
static PyObject* QStringList_CppToPython_QStringList(const void* cppIn) {
    ::QStringList& cppInRef = *((::QStringList*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QStringList::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            QString cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
// Python to C++ conversions for type 'QStringList'.
static void PySequence_PythonToCpp_QStringList(PyObject* pyIn, void* cppOut) {

    // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
    ::QString cppItem = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
    *((::QStringList*)cppOut) << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_PySequence_PythonToCpp_QStringList_Convertible(PyObject* pyIn) {
    if (PySequence_Check(pyIn))
        return PySequence_PythonToCpp_QStringList;
    return 0;
}

// C++ to Python conversion for type 'QModelIndexList'.
static PyObject* QModelIndexList_CppToPython_QModelIndexList(const void* cppIn) {
    ::QModelIndexList& cppInRef = *((::QModelIndexList*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QModelIndexList::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            QModelIndex cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
// Python to C++ conversions for type 'QModelIndexList'.
static void PySequence_PythonToCpp_QModelIndexList(PyObject* pyIn, void* cppOut) {

    // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
    Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
    ::QModelIndex cppItem = ::QModelIndex();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pyItem, &(cppItem));
    *((::QModelIndexList*)cppOut) << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_PySequence_PythonToCpp_QModelIndexList_Convertible(PyObject* pyIn) {
    if (PySequence_Check(pyIn))
        return PySequence_PythonToCpp_QModelIndexList;
    return 0;
}

// C++ to Python conversion for type 'QChar'.
static PyObject* QChar_CppToPython_QChar(const void* cppIn) {
    ::QChar& cppInRef = *((::QChar*)cppIn);

            wchar_t c = (wchar_t)cppInRef.unicode();
            return PyUnicode_FromWideChar(&c, 1);

}
// Python to C++ conversions for type 'QChar'.
static void PyString_PythonToCpp_QChar(PyObject* pyIn, void* cppOut) {

    char c;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<char>(), pyIn, &(c));
    *((::QChar*)cppOut) = QChar(c);

}
static PythonToCppFunc is_PyString_PythonToCpp_QChar_Convertible(PyObject* pyIn) {
    if (Shiboken::String::checkChar(pyIn))
        return PyString_PythonToCpp_QChar;
    return 0;
}
static void PyInt_PythonToCpp_QChar(PyObject* pyIn, void* cppOut) {

    int i;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &(i));
    *((::QChar*)cppOut) = QChar(i);

}
static PythonToCppFunc is_PyInt_PythonToCpp_QChar_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PyInt_PythonToCpp_QChar;
    return 0;
}
static void Py_None_PythonToCpp_QChar(PyObject* pyIn, void* cppOut) {

    *((::QChar*)cppOut) = QChar();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QChar_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QChar;
    return 0;
}


// Container Type converters.

// C++ to Python conversion for type 'QList<QFileInfo >'.
static PyObject* QList_QFileInfo__CppToPython_QList_QFileInfo_(const void* cppIn) {
    ::QList<QFileInfo >& cppInRef = *((::QList<QFileInfo >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QFileInfo >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QFileInfo cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QFileInfo__PythonToCpp_QList_QFileInfo_(PyObject* pyIn, void* cppOut) {
    ::QList<QFileInfo >& cppOutRef = *((::QList<QFileInfo >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QFileInfo cppItem = ::QFileInfo();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QFileInfo__PythonToCpp_QList_QFileInfo__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], pyIn))
        return QList_QFileInfo__PythonToCpp_QList_QFileInfo_;
    return 0;
}

// C++ to Python conversion for type 'QList<QByteArray >'.
static PyObject* QList_QByteArray__CppToPython_QList_QByteArray_(const void* cppIn) {
    ::QList<QByteArray >& cppInRef = *((::QList<QByteArray >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QByteArray >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QByteArray cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QByteArray__PythonToCpp_QList_QByteArray_(PyObject* pyIn, void* cppOut) {
    ::QList<QByteArray >& cppOutRef = *((::QList<QByteArray >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QByteArray cppItem = ::QByteArray();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QByteArray__PythonToCpp_QList_QByteArray__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyIn))
        return QList_QByteArray__PythonToCpp_QList_QByteArray_;
    return 0;
}

// C++ to Python conversion for type 'QList<int >'.
static PyObject* QList_int__CppToPython_QList_int_(const void* cppIn) {
    ::QList<int >& cppInRef = *((::QList<int >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<int >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            int cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_int__PythonToCpp_QList_int_(PyObject* pyIn, void* cppOut) {
    ::QList<int >& cppOutRef = *((::QList<int >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        int cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_int__PythonToCpp_QList_int__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn))
        return QList_int__PythonToCpp_QList_int_;
    return 0;
}

// C++ to Python conversion for type 'QList<QLocale::Country >'.
static PyObject* QList_QLocale_Country__CppToPython_QList_QLocale_Country_(const void* cppIn) {
    ::QList<QLocale::Country >& cppInRef = *((::QList<QLocale::Country >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QLocale::Country >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QLocale::Country cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QLocale_Country__PythonToCpp_QList_QLocale_Country_(PyObject* pyIn, void* cppOut) {
    ::QList<QLocale::Country >& cppOutRef = *((::QList<QLocale::Country >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QLocale::Country cppItem = ((::QLocale::Country)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QLocale_Country__PythonToCpp_QList_QLocale_Country__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), pyIn))
        return QList_QLocale_Country__PythonToCpp_QList_QLocale_Country_;
    return 0;
}

// C++ to Python conversion for type 'QList<QLocale >'.
static PyObject* QList_QLocale__CppToPython_QList_QLocale_(const void* cppIn) {
    ::QList<QLocale >& cppInRef = *((::QList<QLocale >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QLocale >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QLocale cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QLocale__PythonToCpp_QList_QLocale_(PyObject* pyIn, void* cppOut) {
    ::QList<QLocale >& cppOutRef = *((::QList<QLocale >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QLocale cppItem = ::QLocale();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QLocale__PythonToCpp_QList_QLocale__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pyIn))
        return QList_QLocale__PythonToCpp_QList_QLocale_;
    return 0;
}

// C++ to Python conversion for type 'QList<Qt::DayOfWeek >'.
static PyObject* QList_Qt_DayOfWeek__CppToPython_QList_Qt_DayOfWeek_(const void* cppIn) {
    ::QList<Qt::DayOfWeek >& cppInRef = *((::QList<Qt::DayOfWeek >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Qt::DayOfWeek >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Qt::DayOfWeek cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_Qt_DayOfWeek__PythonToCpp_QList_Qt_DayOfWeek_(PyObject* pyIn, void* cppOut) {
    ::QList<Qt::DayOfWeek >& cppOutRef = *((::QList<Qt::DayOfWeek >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Qt::DayOfWeek cppItem = ((::Qt::DayOfWeek)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_Qt_DayOfWeek__PythonToCpp_QList_Qt_DayOfWeek__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX]), pyIn))
        return QList_Qt_DayOfWeek__PythonToCpp_QList_Qt_DayOfWeek_;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QXmlStreamNamespaceDeclaration > &'.
static PyObject* constQVector_QXmlStreamNamespaceDeclaration_REF_CppToPython_constQVector_QXmlStreamNamespaceDeclaration_REF(const void* cppIn) {
    ::QVector<QXmlStreamNamespaceDeclaration >& cppInRef = *((::QVector<QXmlStreamNamespaceDeclaration >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QXmlStreamNamespaceDeclaration >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QXmlStreamNamespaceDeclaration >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QXmlStreamNamespaceDeclaration cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void constQVector_QXmlStreamNamespaceDeclaration_REF_PythonToCpp_constQVector_QXmlStreamNamespaceDeclaration_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QXmlStreamNamespaceDeclaration >& cppOutRef = *((::QVector<QXmlStreamNamespaceDeclaration >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QXmlStreamNamespaceDeclaration cppItem = ::QXmlStreamNamespaceDeclaration();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is_constQVector_QXmlStreamNamespaceDeclaration_REF_PythonToCpp_constQVector_QXmlStreamNamespaceDeclaration_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], pyIn))
        return constQVector_QXmlStreamNamespaceDeclaration_REF_PythonToCpp_constQVector_QXmlStreamNamespaceDeclaration_REF;
    return 0;
}

// C++ to Python conversion for type 'QVector<QXmlStreamEntityDeclaration >'.
static PyObject* QVector_QXmlStreamEntityDeclaration__CppToPython_QVector_QXmlStreamEntityDeclaration_(const void* cppIn) {
    ::QVector<QXmlStreamEntityDeclaration >& cppInRef = *((::QVector<QXmlStreamEntityDeclaration >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QXmlStreamEntityDeclaration >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QXmlStreamEntityDeclaration >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QXmlStreamEntityDeclaration cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void QVector_QXmlStreamEntityDeclaration__PythonToCpp_QVector_QXmlStreamEntityDeclaration_(PyObject* pyIn, void* cppOut) {
    ::QVector<QXmlStreamEntityDeclaration >& cppOutRef = *((::QVector<QXmlStreamEntityDeclaration >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QXmlStreamEntityDeclaration cppItem = ::QXmlStreamEntityDeclaration();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is_QVector_QXmlStreamEntityDeclaration__PythonToCpp_QVector_QXmlStreamEntityDeclaration__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], pyIn))
        return QVector_QXmlStreamEntityDeclaration__PythonToCpp_QVector_QXmlStreamEntityDeclaration_;
    return 0;
}

// C++ to Python conversion for type 'QVector<QXmlStreamNotationDeclaration >'.
static PyObject* QVector_QXmlStreamNotationDeclaration__CppToPython_QVector_QXmlStreamNotationDeclaration_(const void* cppIn) {
    ::QVector<QXmlStreamNotationDeclaration >& cppInRef = *((::QVector<QXmlStreamNotationDeclaration >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QXmlStreamNotationDeclaration >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QXmlStreamNotationDeclaration >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QXmlStreamNotationDeclaration cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void QVector_QXmlStreamNotationDeclaration__PythonToCpp_QVector_QXmlStreamNotationDeclaration_(PyObject* pyIn, void* cppOut) {
    ::QVector<QXmlStreamNotationDeclaration >& cppOutRef = *((::QVector<QXmlStreamNotationDeclaration >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QXmlStreamNotationDeclaration cppItem = ::QXmlStreamNotationDeclaration();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is_QVector_QXmlStreamNotationDeclaration__PythonToCpp_QVector_QXmlStreamNotationDeclaration__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], pyIn))
        return QVector_QXmlStreamNotationDeclaration__PythonToCpp_QVector_QXmlStreamNotationDeclaration_;
    return 0;
}

// C++ to Python conversion for type 'QVector<QXmlStreamAttribute > &'.
static PyObject* QVector_QXmlStreamAttribute_REF_CppToPython_QVector_QXmlStreamAttribute_REF(const void* cppIn) {
    ::QVector<QXmlStreamAttribute >& cppInRef = *((::QVector<QXmlStreamAttribute >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QXmlStreamAttribute >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QXmlStreamAttribute >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QXmlStreamAttribute cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void QVector_QXmlStreamAttribute_REF_PythonToCpp_QVector_QXmlStreamAttribute_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QXmlStreamAttribute >& cppOutRef = *((::QVector<QXmlStreamAttribute >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QXmlStreamAttribute cppItem = ::QXmlStreamAttribute();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is_QVector_QXmlStreamAttribute_REF_PythonToCpp_QVector_QXmlStreamAttribute_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pyIn))
        return QVector_QXmlStreamAttribute_REF_PythonToCpp_QVector_QXmlStreamAttribute_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QXmlStreamAttribute > &'.
static PyObject* constQList_QXmlStreamAttribute_REF_CppToPython_constQList_QXmlStreamAttribute_REF(const void* cppIn) {
    ::QList<QXmlStreamAttribute >& cppInRef = *((::QList<QXmlStreamAttribute >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QXmlStreamAttribute >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QXmlStreamAttribute cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void constQList_QXmlStreamAttribute_REF_PythonToCpp_constQList_QXmlStreamAttribute_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QXmlStreamAttribute >& cppOutRef = *((::QList<QXmlStreamAttribute >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QXmlStreamAttribute cppItem = ::QXmlStreamAttribute();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_constQList_QXmlStreamAttribute_REF_PythonToCpp_constQList_QXmlStreamAttribute_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pyIn))
        return constQList_QXmlStreamAttribute_REF_PythonToCpp_constQList_QXmlStreamAttribute_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QObject * > &'.
static PyObject* constQList_QObjectPTR_REF_CppToPython_constQList_QObjectPTR_REF(const void* cppIn) {
    ::QList<QObject * >& cppInRef = *((::QList<QObject * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QObject * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QObject* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void constQList_QObjectPTR_REF_PythonToCpp_constQList_QObjectPTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QObject * >& cppOutRef = *((::QList<QObject * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QObject* cppItem = ((::QObject*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_constQList_QObjectPTR_REF_PythonToCpp_constQList_QObjectPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyIn))
        return constQList_QObjectPTR_REF_PythonToCpp_constQList_QObjectPTR_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QUrl > &'.
static PyObject* constQList_QUrl_REF_CppToPython_constQList_QUrl_REF(const void* cppIn) {
    ::QList<QUrl >& cppInRef = *((::QList<QUrl >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QUrl >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QUrl cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void constQList_QUrl_REF_PythonToCpp_constQList_QUrl_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QUrl >& cppOutRef = *((::QList<QUrl >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QUrl cppItem = ::QUrl();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_constQList_QUrl_REF_PythonToCpp_constQList_QUrl_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return constQList_QUrl_REF_PythonToCpp_constQList_QUrl_REF;
    return 0;
}

// C++ to Python conversion for type 'QPair<qreal, QVariant >'.
static PyObject* QPair_qreal_QVariant__CppToPython_QPair_qreal_QVariant_(const void* cppIn) {
    ::QPair<qreal, QVariant >& cppInRef = *((::QPair<qreal, QVariant >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppInRef.second));
            return pyOut;

}
static void QPair_qreal_QVariant__PythonToCpp_QPair_qreal_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QPair<qreal, QVariant >& cppOutRef = *((::QPair<qreal, QVariant >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is_QPair_qreal_QVariant__PythonToCpp_QPair_qreal_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return QPair_qreal_QVariant__PythonToCpp_QPair_qreal_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'QVector<QPair<qreal, QVariant > >'.
static PyObject* QVector_QPair_qreal_QVariant___CppToPython_QVector_QPair_qreal_QVariant__(const void* cppIn) {
    ::QVector<QPair<qreal, QVariant > >& cppInRef = *((::QVector<QPair<qreal, QVariant > >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QPair<qreal, QVariant > >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QPair<qreal, QVariant > >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QPair<qreal, QVariant > cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QREAL_QVARIANT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void QVector_QPair_qreal_QVariant___PythonToCpp_QVector_QPair_qreal_QVariant__(PyObject* pyIn, void* cppOut) {
    ::QVector<QPair<qreal, QVariant > >& cppOutRef = *((::QVector<QPair<qreal, QVariant > >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QPair<qreal, QVariant > cppItem = ::QPair<qreal, QVariant >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QREAL_QVARIANT_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is_QVector_QPair_qreal_QVariant___PythonToCpp_QVector_QPair_qreal_QVariant___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QREAL_QVARIANT_IDX], pyIn))
        return QVector_QPair_qreal_QVariant___PythonToCpp_QVector_QPair_qreal_QVariant__;
    return 0;
}

// C++ to Python conversion for type 'QMap<int, QVariant >'.
static PyObject* QMap_int_QVariant__CppToPython_QMap_int_QVariant_(const void* cppIn) {
    ::QMap<int, QVariant >& cppInRef = *((::QMap<int, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMap<int, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            int key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void QMap_int_QVariant__PythonToCpp_QMap_int_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QMap<int, QVariant >& cppOutRef = *((::QMap<int, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        int cppKey;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is_QMap_int_QVariant__PythonToCpp_QMap_int_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return QMap_int_QVariant__PythonToCpp_QMap_int_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'const QHash<int, QByteArray > &'.
static PyObject* constQHash_int_QByteArray_REF_CppToPython_constQHash_int_QByteArray_REF(const void* cppIn) {
    ::QHash<int, QByteArray >& cppInRef = *((::QHash<int, QByteArray >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QHash<int, QByteArray >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            int key = it.key();
            ::QByteArray value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void constQHash_int_QByteArray_REF_PythonToCpp_constQHash_int_QByteArray_REF(PyObject* pyIn, void* cppOut) {
    ::QHash<int, QByteArray >& cppOutRef = *((::QHash<int, QByteArray >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        int cppKey;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), key, &(cppKey));
        ::QByteArray cppValue = ::QByteArray();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is_constQHash_int_QByteArray_REF_PythonToCpp_constQHash_int_QByteArray_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, pyIn))
        return constQHash_int_QByteArray_REF_PythonToCpp_constQHash_int_QByteArray_REF;
    return 0;
}

// C++ to Python conversion for type 'QPair<int, int >'.
static PyObject* QPair_int_int__CppToPython_QPair_int_int_(const void* cppIn) {
    ::QPair<int, int >& cppInRef = *((::QPair<int, int >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppInRef.second));
            return pyOut;

}
static void QPair_int_int__PythonToCpp_QPair_int_int_(PyObject* pyIn, void* cppOut) {
    ::QPair<int, int >& cppOutRef = *((::QPair<int, int >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is_QPair_int_int__PythonToCpp_QPair_int_int__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, pyIn))
        return QPair_int_int__PythonToCpp_QPair_int_int_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<int, int > >'.
static PyObject* QList_QPair_int_int___CppToPython_QList_QPair_int_int__(const void* cppIn) {
    ::QList<QPair<int, int > >& cppInRef = *((::QList<QPair<int, int > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<int, int > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<int, int > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_INT_INT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QPair_int_int___PythonToCpp_QList_QPair_int_int__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<int, int > >& cppOutRef = *((::QList<QPair<int, int > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<int, int > cppItem = ::QPair<int, int >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_INT_INT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QPair_int_int___PythonToCpp_QList_QPair_int_int___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_INT_INT_IDX], pyIn))
        return QList_QPair_int_int___PythonToCpp_QList_QPair_int_int__;
    return 0;
}

// C++ to Python conversion for type 'QList<QAbstractAnimation * >'.
static PyObject* QList_QAbstractAnimationPTR__CppToPython_QList_QAbstractAnimationPTR_(const void* cppIn) {
    ::QList<QAbstractAnimation * >& cppInRef = *((::QList<QAbstractAnimation * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAbstractAnimation * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAbstractAnimation* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QAbstractAnimationPTR__PythonToCpp_QList_QAbstractAnimationPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QAbstractAnimation * >& cppOutRef = *((::QList<QAbstractAnimation * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAbstractAnimation* cppItem = ((::QAbstractAnimation*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QAbstractAnimationPTR__PythonToCpp_QList_QAbstractAnimationPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], pyIn))
        return QList_QAbstractAnimationPTR__PythonToCpp_QList_QAbstractAnimationPTR_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QAbstractState * > &'.
static PyObject* constQList_QAbstractStatePTR_REF_CppToPython_constQList_QAbstractStatePTR_REF(const void* cppIn) {
    ::QList<QAbstractState * >& cppInRef = *((::QList<QAbstractState * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAbstractState * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAbstractState* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void constQList_QAbstractStatePTR_REF_PythonToCpp_constQList_QAbstractStatePTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QAbstractState * >& cppOutRef = *((::QList<QAbstractState * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAbstractState* cppItem = ((::QAbstractState*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_constQList_QAbstractStatePTR_REF_PythonToCpp_constQList_QAbstractStatePTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], pyIn))
        return constQList_QAbstractStatePTR_REF_PythonToCpp_constQList_QAbstractStatePTR_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QAbstractTransition * >'.
static PyObject* QList_QAbstractTransitionPTR__CppToPython_QList_QAbstractTransitionPTR_(const void* cppIn) {
    ::QList<QAbstractTransition * >& cppInRef = *((::QList<QAbstractTransition * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAbstractTransition * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAbstractTransition* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QAbstractTransitionPTR__PythonToCpp_QList_QAbstractTransitionPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QAbstractTransition * >& cppOutRef = *((::QList<QAbstractTransition * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAbstractTransition* cppItem = ((::QAbstractTransition*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QAbstractTransitionPTR__PythonToCpp_QList_QAbstractTransitionPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX], pyIn))
        return QList_QAbstractTransitionPTR__PythonToCpp_QList_QAbstractTransitionPTR_;
    return 0;
}

// C++ to Python conversion for type 'QSet<QAbstractState * >'.
static PyObject* QSet_QAbstractStatePTR__CppToPython_QSet_QAbstractStatePTR_(const void* cppIn) {
    ::QSet<QAbstractState * >& cppInRef = *((::QSet<QAbstractState * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QSet<QAbstractState * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAbstractState* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QSet_QAbstractStatePTR__PythonToCpp_QSet_QAbstractStatePTR_(PyObject* pyIn, void* cppOut) {
    ::QSet<QAbstractState * >& cppOutRef = *((::QSet<QAbstractState * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAbstractState* cppItem = ((::QAbstractState*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QSet_QAbstractStatePTR__PythonToCpp_QSet_QAbstractStatePTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], pyIn))
        return QSet_QAbstractStatePTR__PythonToCpp_QSet_QAbstractStatePTR_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QVariant > &'.
static PyObject* constQList_QVariant_REF_CppToPython_constQList_QVariant_REF(const void* cppIn) {
    ::QList<QVariant >& cppInRef = *((::QList<QVariant >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QVariant >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QVariant cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void constQList_QVariant_REF_PythonToCpp_constQList_QVariant_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QVariant >& cppOutRef = *((::QList<QVariant >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QVariant cppItem = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_constQList_QVariant_REF_PythonToCpp_constQList_QVariant_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn))
        return constQList_QVariant_REF_PythonToCpp_constQList_QVariant_REF;
    return 0;
}

// C++ to Python conversion for type 'QPair<QByteArray, QByteArray >'.
static PyObject* QPair_QByteArray_QByteArray__CppToPython_QPair_QByteArray_QByteArray_(const void* cppIn) {
    ::QPair<QByteArray, QByteArray >& cppInRef = *((::QPair<QByteArray, QByteArray >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppInRef.second));
            return pyOut;

}
static void QPair_QByteArray_QByteArray__PythonToCpp_QPair_QByteArray_QByteArray_(PyObject* pyIn, void* cppOut) {
    ::QPair<QByteArray, QByteArray >& cppOutRef = *((::QPair<QByteArray, QByteArray >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is_QPair_QByteArray_QByteArray__PythonToCpp_QPair_QByteArray_QByteArray__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, pyIn))
        return QPair_QByteArray_QByteArray__PythonToCpp_QPair_QByteArray_QByteArray_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<QByteArray, QByteArray > >'.
static PyObject* QList_QPair_QByteArray_QByteArray___CppToPython_QList_QPair_QByteArray_QByteArray__(const void* cppIn) {
    ::QList<QPair<QByteArray, QByteArray > >& cppInRef = *((::QList<QPair<QByteArray, QByteArray > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<QByteArray, QByteArray > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<QByteArray, QByteArray > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QPair_QByteArray_QByteArray___PythonToCpp_QList_QPair_QByteArray_QByteArray__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<QByteArray, QByteArray > >& cppOutRef = *((::QList<QPair<QByteArray, QByteArray > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<QByteArray, QByteArray > cppItem = ::QPair<QByteArray, QByteArray >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QPair_QByteArray_QByteArray___PythonToCpp_QList_QPair_QByteArray_QByteArray___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], pyIn))
        return QList_QPair_QByteArray_QByteArray___PythonToCpp_QList_QPair_QByteArray_QByteArray__;
    return 0;
}

// C++ to Python conversion for type 'QPair<QString, QString >'.
static PyObject* QPair_QString_QString__CppToPython_QPair_QString_QString_(const void* cppIn) {
    ::QPair<QString, QString >& cppInRef = *((::QPair<QString, QString >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.second));
            return pyOut;

}
static void QPair_QString_QString__PythonToCpp_QPair_QString_QString_(PyObject* pyIn, void* cppOut) {
    ::QPair<QString, QString >& cppOutRef = *((::QPair<QString, QString >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is_QPair_QString_QString__PythonToCpp_QPair_QString_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return QPair_QString_QString__PythonToCpp_QPair_QString_QString_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<QString, QString > >'.
static PyObject* QList_QPair_QString_QString___CppToPython_QList_QPair_QString_QString__(const void* cppIn) {
    ::QList<QPair<QString, QString > >& cppInRef = *((::QList<QPair<QString, QString > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<QString, QString > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<QString, QString > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QSTRING_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QPair_QString_QString___PythonToCpp_QList_QPair_QString_QString__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<QString, QString > >& cppOutRef = *((::QList<QPair<QString, QString > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<QString, QString > cppItem = ::QPair<QString, QString >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QSTRING_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QPair_QString_QString___PythonToCpp_QList_QPair_QString_QString___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QSTRING_QSTRING_IDX], pyIn))
        return QList_QPair_QString_QString___PythonToCpp_QList_QPair_QString_QString__;
    return 0;
}

// C++ to Python conversion for type 'QList<QString >'.
static PyObject* QList_QString__CppToPython_QList_QString_(const void* cppIn) {
    ::QList<QString >& cppInRef = *((::QList<QString >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QString >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QString cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void QList_QString__PythonToCpp_QList_QString_(PyObject* pyIn, void* cppOut) {
    ::QList<QString >& cppOutRef = *((::QList<QString >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QString cppItem = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_QList_QString__PythonToCpp_QList_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return QList_QString__PythonToCpp_QList_QString_;
    return 0;
}

// C++ to Python conversion for type 'QMap<QString, QVariant >'.
static PyObject* QMap_QString_QVariant__CppToPython_QMap_QString_QVariant_(const void* cppIn) {
    ::QMap<QString, QVariant >& cppInRef = *((::QMap<QString, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMap<QString, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QString key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void QMap_QString_QVariant__PythonToCpp_QMap_QString_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QMap<QString, QVariant >& cppOutRef = *((::QMap<QString, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is_QMap_QString_QVariant__PythonToCpp_QMap_QString_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return QMap_QString_QVariant__PythonToCpp_QMap_QString_QVariant_;
    return 0;
}


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
    /* m_name     */ "QtCore",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtCore_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtCore)

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtCore_IDX_COUNT];
    SbkPySide_QtCoreTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtCore_CONVERTERS_IDX_COUNT];
    SbkPySide_QtCoreTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtCore", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtCore", QtCore_methods);
#endif

    // Initialize classes in the type system
    init_QSysInfo(module);
    init_QGenericArgument(module);
    init_QGenericReturnArgument(module);
    init_QMetaMethod(module);
    init_QByteArray(module);
    init_QUrl(module);
    init_QEvent(module);
    init_QTimerEvent(module);
    init_QChildEvent(module);
    init_QDynamicPropertyChangeEvent(module);
    init_QDataStream(module);
    init_QMutex(module);
    init_QMutexLocker(module);
    init_QReadWriteLock(module);
    init_QReadLocker(module);
    init_QWriteLocker(module);
    init_QSemaphore(module);
    init_QWaitCondition(module);
    init_QXmlStreamAttribute(module);
    init_QXmlStreamAttributes(module);
    init_QXmlStreamNamespaceDeclaration(module);
    init_QXmlStreamNotationDeclaration(module);
    init_QXmlStreamEntityDeclaration(module);
    init_QXmlStreamEntityResolver(module);
    init_QXmlStreamReader(module);
    init_QXmlStreamWriter(module);
    init_QRunnable(module);
    init_QSystemLocale(module);
    init_QLocale(module);
    init_QResource(module);
    init_QTextStreamManipulator(module);
    init_QBasicTimer(module);
    init_QMetaEnum(module);
    init_QMetaProperty(module);
    init_QMetaClassInfo(module);
    init_QSystemSemaphore(module);
    init_QFactoryInterface(module);
    init_QUuid(module);
    init_QLibraryInfo(module);
    init_QTextCodec(module);
    init_QTextCodec_ConverterState(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX]->tp_dict);
    init_QTextEncoder(module);
    init_QTextDecoder(module);
    init_QFileInfo(module);
    init_QDir(module);
    init_QDirIterator(module);
    init_QAbstractFileEngine(module);
    init_QFSFileEngine(module);
    init_QAbstractFileEngineHandler(module);
    init_QAbstractFileEngineIterator(module);
    init_QProcessEnvironment(module);
    init_QEasingCurve(module);
    init_QBitArray(module);
    init_QByteArrayMatcher(module);
    init_QCryptographicHash(module);
    init_QElapsedTimer(module);
    init_QPoint(module);
    init_QPointF(module);
    init_QLine(module);
    init_QLineF(module);
    init_QMargins(module);
    init_QSize(module);
    init_QSizeF(module);
    init_QRect(module);
    init_QRectF(module);
    init_QTextBoundaryFinder(module);
    init_Qt(module);
    init_QRegExp(module);
    init_QModelIndex(module);
    init_QPersistentModelIndex(module);
    init_QDate(module);
    init_QTime(module);
    init_QDateTime(module);
    init_QMetaObject(module);
    init_QObject(module);
    init_QSocketNotifier(module);
    init_QTimer(module);
    init_QTimeLine(module);
    init_QTranslator(module);
    init_QThread(module);
    init_QPluginLoader(module);
    init_QAbstractState(module);
    init_QFinalState(module);
    init_QHistoryState(module);
    init_QState(module);
    init_QStateMachine(module);
    init_QStateMachine_SignalEvent(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX]->tp_dict);
    init_QStateMachine_WrappedEvent(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX]->tp_dict);
    init_QThreadPool(module);
    init_QAbstractTransition(module);
    init_QEventTransition(module);
    init_QSignalTransition(module);
    init_QEventLoop(module);
    init_QCoreApplication(module);
    init_QAbstractEventDispatcher(module);
    init_QFileSystemWatcher(module);
    init_QAbstractItemModel(module);
    init_QAbstractListModel(module);
    init_QAbstractTableModel(module);
    init_QSettings(module);
    init_QIODevice(module);
    init_QBuffer(module);
    init_QProcess(module);
    init_QTextStream(module);
    init_QFile(module);
    init_QTemporaryFile(module);
    init_QAbstractAnimation(module);
    init_QAnimationGroup(module);
    init_QParallelAnimationGroup(module);
    init_QSequentialAnimationGroup(module);
    init_QPauseAnimation(module);
    init_QVariantAnimation(module);
    init_QPropertyAnimation(module);
    init_QMimeData(module);
    init_QSignalMapper(module);
    init_QtConcurrent(module);

    // Register converter for type 'PySide.QtCore.QString'.
    SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyUnicode_Type, QString_CppToPython_QString);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], "QString");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX],
        PyUnicode_PythonToCpp_QString,
        is_PyUnicode_PythonToCpp_QString_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX],
        PyString_PythonToCpp_QString,
        is_PyString_PythonToCpp_QString_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX],
        Py_None_PythonToCpp_QString,
        is_Py_None_PythonToCpp_QString_Convertible);

    // Register converter for type 'PySide.QtCore.QVariant'.
    SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyBaseObject_Type, QVariant_CppToPython_QVariant);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], "QVariant");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PyBool_PythonToCpp_QVariant,
        is_PyBool_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        Py_None_PythonToCpp_QVariant,
        is_Py_None_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        QString_PythonToCpp_QVariant,
        is_QString_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        QByteArray_PythonToCpp_QVariant,
        is_QByteArray_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PyFloat_PythonToCpp_QVariant,
        is_PyFloat_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PyInt_PythonToCpp_QVariant,
        is_PyInt_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PyLong_PythonToCpp_QVariant,
        is_PyLong_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        SbkEnumType_PythonToCpp_QVariant,
        is_SbkEnumType_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        SbkObject_PythonToCpp_QVariant,
        is_SbkObject_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PyDict_PythonToCpp_QVariant,
        is_PyDict_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PySequence_PythonToCpp_QVariant,
        is_PySequence_PythonToCpp_QVariant_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX],
        PyObject_PythonToCpp_QVariant,
        is_PyObject_PythonToCpp_QVariant_Convertible);

    // Register converter for type 'PySide.QtCore.QBool'.
    SbkPySide_QtCoreTypeConverters[SBK_QBOOL_IDX] = Shiboken::Conversions::createConverter(&PyBool_Type, QBool_CppToPython_QBool);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QBOOL_IDX], "QBool");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QBOOL_IDX],
        PyBool_PythonToCpp_QBool,
        is_PyBool_PythonToCpp_QBool_Convertible);

    // Register converter for type 'PySide.QtCore.QVariant::Type'.
    SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX] = Shiboken::Conversions::createConverter(0, QVariant_Type_CppToPython_QVariant_Type);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], "QVariant::Type");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX],
        Py_None_PythonToCpp_QVariant_Type,
        is_Py_None_PythonToCpp_QVariant_Type_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX],
        PyTypeObject_PythonToCpp_QVariant_Type,
        is_PyTypeObject_PythonToCpp_QVariant_Type_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX],
        PyString_PythonToCpp_QVariant_Type,
        is_PyString_PythonToCpp_QVariant_Type_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX],
        PyDict_PythonToCpp_QVariant_Type,
        is_PyDict_PythonToCpp_QVariant_Type_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX],
        PySequence_PythonToCpp_QVariant_Type,
        is_PySequence_PythonToCpp_QVariant_Type_Convertible);

    // Register converter for type 'PySide.QtCore.QStringRef'.
    SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX] = Shiboken::Conversions::createConverter(0, QStringRef_CppToPython_QStringRef);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], "QStringRef");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX],
        PyObject_PythonToCpp_QStringRef,
        is_PyObject_PythonToCpp_QStringRef_Convertible);

    // Register converter for type 'PySide.QtCore.QStringList'.
    SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX] = Shiboken::Conversions::createConverter(0, QStringList_CppToPython_QStringList);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], "QStringList");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX],
        PySequence_PythonToCpp_QStringList,
        is_PySequence_PythonToCpp_QStringList_Convertible);

    // Register converter for type 'PySide.QtCore.QModelIndexList'.
    SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX] = Shiboken::Conversions::createConverter(0, QModelIndexList_CppToPython_QModelIndexList);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], "QModelIndexList");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX],
        PySequence_PythonToCpp_QModelIndexList,
        is_PySequence_PythonToCpp_QModelIndexList_Convertible);

    // Register converter for type 'PySide.QtCore.QChar'.
    SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX] = Shiboken::Conversions::createConverter(0, QChar_CppToPython_QChar);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], "QChar");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX],
        PyString_PythonToCpp_QChar,
        is_PyString_PythonToCpp_QChar_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX],
        PyInt_PythonToCpp_QChar,
        is_PyInt_PythonToCpp_QChar_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX],
        Py_None_PythonToCpp_QChar,
        is_Py_None_PythonToCpp_QChar_Convertible);


    // Register converter for type 'QList<QFileInfo>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QFILEINFO_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QFileInfo__CppToPython_QList_QFileInfo_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QFILEINFO_IDX], "QList<QFileInfo>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QFILEINFO_IDX],
        QList_QFileInfo__PythonToCpp_QList_QFileInfo_,
        is_QList_QFileInfo__PythonToCpp_QList_QFileInfo__Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QByteArray__CppToPython_QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX],
        QList_QByteArray__PythonToCpp_QList_QByteArray_,
        is_QList_QByteArray__PythonToCpp_QList_QByteArray__Convertible);

    // Register converter for type 'QList<int>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_int__CppToPython_QList_int_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_INT_IDX], "QList<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_INT_IDX],
        QList_int__PythonToCpp_QList_int_,
        is_QList_int__PythonToCpp_QList_int__Convertible);

    // Register converter for type 'QList<QLocale::Country>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_COUNTRY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QLocale_Country__CppToPython_QList_QLocale_Country_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_COUNTRY_IDX], "QList<QLocale::Country>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_COUNTRY_IDX],
        QList_QLocale_Country__PythonToCpp_QList_QLocale_Country_,
        is_QList_QLocale_Country__PythonToCpp_QList_QLocale_Country__Convertible);

    // Register converter for type 'QList<QLocale>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QLocale__CppToPython_QList_QLocale_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_IDX], "QList<QLocale>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_IDX],
        QList_QLocale__PythonToCpp_QList_QLocale_,
        is_QList_QLocale__PythonToCpp_QList_QLocale__Convertible);

    // Register converter for type 'QList<Qt::DayOfWeek>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QT_DAYOFWEEK_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_Qt_DayOfWeek__CppToPython_QList_Qt_DayOfWeek_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QT_DAYOFWEEK_IDX], "QList<Qt::DayOfWeek>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QT_DAYOFWEEK_IDX],
        QList_Qt_DayOfWeek__PythonToCpp_QList_Qt_DayOfWeek_,
        is_QList_Qt_DayOfWeek__PythonToCpp_QList_Qt_DayOfWeek__Convertible);

    // Register converter for type 'const QVector<QXmlStreamNamespaceDeclaration>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNAMESPACEDECLARATION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, constQVector_QXmlStreamNamespaceDeclaration_REF_CppToPython_constQVector_QXmlStreamNamespaceDeclaration_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNAMESPACEDECLARATION_IDX], "const QVector<QXmlStreamNamespaceDeclaration>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNAMESPACEDECLARATION_IDX], "QVector<QXmlStreamNamespaceDeclaration>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNAMESPACEDECLARATION_IDX],
        constQVector_QXmlStreamNamespaceDeclaration_REF_PythonToCpp_constQVector_QXmlStreamNamespaceDeclaration_REF,
        is_constQVector_QXmlStreamNamespaceDeclaration_REF_PythonToCpp_constQVector_QXmlStreamNamespaceDeclaration_REF_Convertible);

    // Register converter for type 'QVector<QXmlStreamEntityDeclaration>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMENTITYDECLARATION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QVector_QXmlStreamEntityDeclaration__CppToPython_QVector_QXmlStreamEntityDeclaration_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMENTITYDECLARATION_IDX], "QVector<QXmlStreamEntityDeclaration>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMENTITYDECLARATION_IDX],
        QVector_QXmlStreamEntityDeclaration__PythonToCpp_QVector_QXmlStreamEntityDeclaration_,
        is_QVector_QXmlStreamEntityDeclaration__PythonToCpp_QVector_QXmlStreamEntityDeclaration__Convertible);

    // Register converter for type 'QVector<QXmlStreamNotationDeclaration>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNOTATIONDECLARATION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QVector_QXmlStreamNotationDeclaration__CppToPython_QVector_QXmlStreamNotationDeclaration_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNOTATIONDECLARATION_IDX], "QVector<QXmlStreamNotationDeclaration>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNOTATIONDECLARATION_IDX],
        QVector_QXmlStreamNotationDeclaration__PythonToCpp_QVector_QXmlStreamNotationDeclaration_,
        is_QVector_QXmlStreamNotationDeclaration__PythonToCpp_QVector_QXmlStreamNotationDeclaration__Convertible);

    // Register converter for type 'QVector<QXmlStreamAttribute>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QVector_QXmlStreamAttribute_REF_CppToPython_QVector_QXmlStreamAttribute_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], "QVector<QXmlStreamAttribute>&");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX],
        QVector_QXmlStreamAttribute_REF_PythonToCpp_QVector_QXmlStreamAttribute_REF,
        is_QVector_QXmlStreamAttribute_REF_PythonToCpp_QVector_QXmlStreamAttribute_REF_Convertible);

    // Register converter for type 'const QList<QXmlStreamAttribute>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QXMLSTREAMATTRIBUTE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, constQList_QXmlStreamAttribute_REF_CppToPython_constQList_QXmlStreamAttribute_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QXMLSTREAMATTRIBUTE_IDX], "const QList<QXmlStreamAttribute>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QXMLSTREAMATTRIBUTE_IDX], "QList<QXmlStreamAttribute>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QXMLSTREAMATTRIBUTE_IDX],
        constQList_QXmlStreamAttribute_REF_PythonToCpp_constQList_QXmlStreamAttribute_REF,
        is_constQList_QXmlStreamAttribute_REF_PythonToCpp_constQList_QXmlStreamAttribute_REF_Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, constQList_QObjectPTR_REF_CppToPython_constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QOBJECTPTR_IDX],
        constQList_QObjectPTR_REF_PythonToCpp_constQList_QObjectPTR_REF,
        is_constQList_QObjectPTR_REF_PythonToCpp_constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'const QList<QUrl>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QURL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, constQList_QUrl_REF_CppToPython_constQList_QUrl_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QURL_IDX], "const QList<QUrl>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QURL_IDX], "QList<QUrl>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QURL_IDX],
        constQList_QUrl_REF_PythonToCpp_constQList_QUrl_REF,
        is_constQList_QUrl_REF_PythonToCpp_constQList_QUrl_REF_Convertible);

    // Register converter for type 'QPair<qreal,QVariant>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QREAL_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QPair_qreal_QVariant__CppToPython_QPair_qreal_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QREAL_QVARIANT_IDX], "QPair<qreal,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QREAL_QVARIANT_IDX],
        QPair_qreal_QVariant__PythonToCpp_QPair_qreal_QVariant_,
        is_QPair_qreal_QVariant__PythonToCpp_QPair_qreal_QVariant__Convertible);

    // Register converter for type 'QVector<QPair<qreal,QVariant>>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QPAIR_QREAL_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QVector_QPair_qreal_QVariant___CppToPython_QVector_QPair_qreal_QVariant__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QPAIR_QREAL_QVARIANT_IDX], "QVector<QPair<qreal,QVariant>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QPAIR_QREAL_QVARIANT_IDX],
        QVector_QPair_qreal_QVariant___PythonToCpp_QVector_QPair_qreal_QVariant__,
        is_QVector_QPair_qreal_QVariant___PythonToCpp_QVector_QPair_qreal_QVariant___Convertible);

    // Register converter for type 'QMap<int,QVariant>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_INT_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, QMap_int_QVariant__CppToPython_QMap_int_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_INT_QVARIANT_IDX], "QMap<int,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_INT_QVARIANT_IDX],
        QMap_int_QVariant__PythonToCpp_QMap_int_QVariant_,
        is_QMap_int_QVariant__PythonToCpp_QMap_int_QVariant__Convertible);

    // Register converter for type 'const QHash<int,QByteArray>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QHASH_INT_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, constQHash_int_QByteArray_REF_CppToPython_constQHash_int_QByteArray_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QHASH_INT_QBYTEARRAY_IDX], "const QHash<int,QByteArray>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QHASH_INT_QBYTEARRAY_IDX], "QHash<int,QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QHASH_INT_QBYTEARRAY_IDX],
        constQHash_int_QByteArray_REF_PythonToCpp_constQHash_int_QByteArray_REF,
        is_constQHash_int_QByteArray_REF_PythonToCpp_constQHash_int_QByteArray_REF_Convertible);

    // Register converter for type 'QPair<int,int>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_INT_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QPair_int_int__CppToPython_QPair_int_int_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_INT_INT_IDX], "QPair<int,int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_INT_INT_IDX],
        QPair_int_int__PythonToCpp_QPair_int_int_,
        is_QPair_int_int__PythonToCpp_QPair_int_int__Convertible);

    // Register converter for type 'QList<QPair<int,int>>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_INT_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QPair_int_int___CppToPython_QList_QPair_int_int__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_INT_INT_IDX], "QList<QPair<int,int>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_INT_INT_IDX],
        QList_QPair_int_int___PythonToCpp_QList_QPair_int_int__,
        is_QList_QPair_int_int___PythonToCpp_QList_QPair_int_int___Convertible);

    // Register converter for type 'QList<QAbstractAnimation*>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTANIMATIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QAbstractAnimationPTR__CppToPython_QList_QAbstractAnimationPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTANIMATIONPTR_IDX], "QList<QAbstractAnimation*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTANIMATIONPTR_IDX],
        QList_QAbstractAnimationPTR__PythonToCpp_QList_QAbstractAnimationPTR_,
        is_QList_QAbstractAnimationPTR__PythonToCpp_QList_QAbstractAnimationPTR__Convertible);

    // Register converter for type 'const QList<QAbstractState*>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTSTATEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, constQList_QAbstractStatePTR_REF_CppToPython_constQList_QAbstractStatePTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTSTATEPTR_IDX], "const QList<QAbstractState*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTSTATEPTR_IDX], "QList<QAbstractState*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTSTATEPTR_IDX],
        constQList_QAbstractStatePTR_REF_PythonToCpp_constQList_QAbstractStatePTR_REF,
        is_constQList_QAbstractStatePTR_REF_PythonToCpp_constQList_QAbstractStatePTR_REF_Convertible);

    // Register converter for type 'QList<QAbstractTransition*>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTTRANSITIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QAbstractTransitionPTR__CppToPython_QList_QAbstractTransitionPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTTRANSITIONPTR_IDX], "QList<QAbstractTransition*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTTRANSITIONPTR_IDX],
        QList_QAbstractTransitionPTR__PythonToCpp_QList_QAbstractTransitionPTR_,
        is_QList_QAbstractTransitionPTR__PythonToCpp_QList_QAbstractTransitionPTR__Convertible);

    // Register converter for type 'QSet<QAbstractState*>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QSET_QABSTRACTSTATEPTR_IDX] = Shiboken::Conversions::createConverter(&PySet_Type, QSet_QAbstractStatePTR__CppToPython_QSet_QAbstractStatePTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QSET_QABSTRACTSTATEPTR_IDX], "QSet<QAbstractState*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QSET_QABSTRACTSTATEPTR_IDX],
        QSet_QAbstractStatePTR__PythonToCpp_QSet_QAbstractStatePTR_,
        is_QSet_QAbstractStatePTR__PythonToCpp_QSet_QAbstractStatePTR__Convertible);

    // Register converter for type 'const QList<QVariant>&'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, constQList_QVariant_REF_CppToPython_constQList_QVariant_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX], "const QList<QVariant>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX],
        constQList_QVariant_REF_PythonToCpp_constQList_QVariant_REF,
        is_constQList_QVariant_REF_PythonToCpp_constQList_QVariant_REF_Convertible);

    // Register converter for type 'QPair<QByteArray,QByteArray>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QPair_QByteArray_QByteArray__CppToPython_QPair_QByteArray_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], "QPair<QByteArray,QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX],
        QPair_QByteArray_QByteArray__PythonToCpp_QPair_QByteArray_QByteArray_,
        is_QPair_QByteArray_QByteArray__PythonToCpp_QPair_QByteArray_QByteArray__Convertible);

    // Register converter for type 'QList<QPair<QByteArray,QByteArray>>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QPair_QByteArray_QByteArray___CppToPython_QList_QPair_QByteArray_QByteArray__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], "QList<QPair<QByteArray,QByteArray>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX],
        QList_QPair_QByteArray_QByteArray___PythonToCpp_QList_QPair_QByteArray_QByteArray__,
        is_QList_QPair_QByteArray_QByteArray___PythonToCpp_QList_QPair_QByteArray_QByteArray___Convertible);

    // Register converter for type 'QPair<QString,QString>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QPair_QString_QString__CppToPython_QPair_QString_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QSTRING_QSTRING_IDX], "QPair<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QPAIR_QSTRING_QSTRING_IDX],
        QPair_QString_QString__PythonToCpp_QPair_QString_QString_,
        is_QPair_QString_QString__PythonToCpp_QPair_QString_QString__Convertible);

    // Register converter for type 'QList<QPair<QString,QString>>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QPair_QString_QString___CppToPython_QList_QPair_QString_QString__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QSTRING_QSTRING_IDX], "QList<QPair<QString,QString>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QSTRING_QSTRING_IDX],
        QList_QPair_QString_QString___PythonToCpp_QList_QPair_QString_QString__,
        is_QList_QPair_QString_QString___PythonToCpp_QList_QPair_QString_QString___Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, QList_QString__CppToPython_QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QSTRING_IDX],
        QList_QString__PythonToCpp_QList_QString_,
        is_QList_QString__PythonToCpp_QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, QMap_QString_QVariant__CppToPython_QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_QSTRING_QVARIANT_IDX],
        QMap_QString_QVariant__PythonToCpp_QMap_QString_QVariant_,
        is_QMap_QString_QVariant__PythonToCpp_QMap_QString_QVariant__Convertible);

    // Initialization of enums.

    // Initialization of enum 'QtMsgType'.
    SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX] = Shiboken::Enum::createGlobalEnum(module,
        "QtMsgType",
        "PySide.QtCore.QtMsgType",
        "QtMsgType");
    if (!SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX])
        return SBK_MODULE_INIT_ERROR;

    if (!Shiboken::Enum::createGlobalEnumItem(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX],
        module, "QtDebugMsg", (long) QtDebugMsg))
        return SBK_MODULE_INIT_ERROR;
    if (!Shiboken::Enum::createGlobalEnumItem(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX],
        module, "QtWarningMsg", (long) QtWarningMsg))
        return SBK_MODULE_INIT_ERROR;
    if (!Shiboken::Enum::createGlobalEnumItem(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX],
        module, "QtCriticalMsg", (long) QtCriticalMsg))
        return SBK_MODULE_INIT_ERROR;
    if (!Shiboken::Enum::createGlobalEnumItem(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX],
        module, "QtFatalMsg", (long) QtFatalMsg))
        return SBK_MODULE_INIT_ERROR;
    if (!Shiboken::Enum::createGlobalEnumItem(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX],
        module, "QtSystemMsg", (long) QtSystemMsg))
        return SBK_MODULE_INIT_ERROR;
    // Register converter for enum 'QtMsgType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX],
            QtMsgType_CppToPython_QtMsgType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QtMsgType_PythonToCpp_QtMsgType,
            is_QtMsgType_PythonToCpp_QtMsgType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QtMsgType");
    }
    // End of 'QtMsgType' enum.

    // Register primitive types converters.
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned short int>(), "ushort");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long long>(), "qulonglong");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long long>(), "quint64");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), "quint32");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned short>(), "quint16");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<double>(), "qreal");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned char>(), "uchar");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<long long>(), "qlonglong");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned char>(), "quint8");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), "uint");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<signed char>(), "qint8");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long int>(), "ulong");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<short>(), "qint16");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<int>(), "qint32");
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<long long>(), "qint64");

    Shiboken::Module::registerTypes(module, SbkPySide_QtCoreTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtCoreTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtCore");
    }
    // Begin code injection

    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QMAP_QSTRING_QVARIANT_IDX], "QVariantMap");


    qAddPostRoutine(PySide::globalPostRoutineCallback);


    QList<QByteArray> version = QByteArray(qVersion()).split('.');
    PyObject* pyQtVersion = PyTuple_New(3);
    for (int i = 0; i < 3; ++i)
        PyTuple_SET_ITEM(pyQtVersion, i, PyInt_FromLong(version[i].toInt()));
    PyModule_AddObject(module, "__version_info__", pyQtVersion);
    PyModule_AddStringConstant(module, "__version__", qVersion());


    { // Avoid name clash
        Shiboken::AutoDecRef regFunc((PyObject*)NULL);
        Shiboken::AutoDecRef atexit(Shiboken::Module::import("atexit"));
        if (atexit.isNull()) {
            qWarning() << "Module atexit not found for registering __moduleShutdown";
            PyErr_Clear();
        }else{
            regFunc = PyObject_GetAttrString(atexit, "register");
            if (regFunc.isNull()) {
                qWarning() << "Function atexit.register not found for registering __moduleShutdown";
                PyErr_Clear();
            }
        }
        if (!atexit.isNull() && !regFunc.isNull()){
            PyObject* shutDownFunc = PyObject_GetAttrString(module, "__moduleShutdown");
            Shiboken::AutoDecRef args(PyTuple_New(1));
            PyTuple_SET_ITEM(args, 0, shutDownFunc);
            Shiboken::AutoDecRef retval(PyObject_Call(regFunc, args, 0));
            Q_ASSERT(!retval.isNull());
        }
    }


    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], "unicode");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], "str");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX], "QVariantList");

    PySide::init(module);
    Py_AtExit(QtCoreModuleExit);

    // End of code injection


    qRegisterMetaType< ::QtMsgType >("QtMsgType");
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
