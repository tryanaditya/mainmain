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
#include "pyside_qtcore_python.h"

#include "qabstractfileengine_wrapper.h"

// Extra includes
#include <QDateTime>
#include <qabstractfileengine.h>
#include <qdatetime.h>


// Native ---------------------------------------------------------

QAbstractFileEngineWrapper::QAbstractFileEngineWrapper() : QAbstractFileEngine() {
    // ... middle
}

QAbstractFileEngineIterator * QAbstractFileEngineWrapper::beginEntryList(QFlags<QDir::Filter> filters, const QStringList & filterNames)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QAbstractFileEngineIterator*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "beginEntryList"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::beginEntryList(filters, filterNames);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &filters),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &filterNames)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QAbstractFileEngineIterator*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINEITERATOR_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.beginEntryList", Shiboken::SbkType< QAbstractFileEngineIterator >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QAbstractFileEngineIterator*)0);
    }
    ::QAbstractFileEngineIterator* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::caseSensitive() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "caseSensitive"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::caseSensitive();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.caseSensitive", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::close();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.close", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::copy(const QString & newName)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "copy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::copy(newName);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &newName)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.copy", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QStringList QAbstractFileEngineWrapper::entryList(QFlags<QDir::Filter> filters, const QStringList & filterNames) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "entryList"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::entryList(filters, filterNames);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &filters),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &filterNames)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QStringList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.entryList", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<QAbstractFileEngine::FileFlag> QAbstractFileEngineWrapper::fileFlags(QFlags<QAbstractFileEngine::FileFlag> type) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<QAbstractFileEngine::FileFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fileFlags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::fileFlags(type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<QAbstractFileEngine::FileFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.fileFlags", Shiboken::SbkType< QFlags<QAbstractFileEngine::FileFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<QAbstractFileEngine::FileFlag>)0);
    }
    ::QFlags<QAbstractFileEngine::FileFlag> cppResult = ((::QFlags<QAbstractFileEngine::FileFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QAbstractFileEngineWrapper::fileName(QAbstractFileEngine::FileName file) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fileName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::fileName(file);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX]), &file)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.fileName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QDateTime QAbstractFileEngineWrapper::fileTime(QAbstractFileEngine::FileTime time) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QDateTime();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fileTime"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::fileTime(time);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX]), &time)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QDateTime();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.fileTime", Shiboken::SbkType< QDateTime >()->tp_name, pyResult->ob_type->tp_name);
        return ::QDateTime();
    }
    ::QDateTime cppResult = ::QDateTime();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::flush()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "flush"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::flush();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.flush", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QAbstractFileEngineWrapper::handle() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "handle"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::handle();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.handle", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::isRelativePath() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isRelativePath"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::isRelativePath();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.isRelativePath", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::isSequential() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isSequential"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::isSequential();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.isSequential", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::link(const QString & newName)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "link"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::link(newName);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &newName)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.link", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::mkdir(const QString & dirName, bool createParentDirectories) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mkdir"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::mkdir(dirName, createParentDirectories);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &dirName),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &createParentDirectories)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.mkdir", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::open(QFlags<QIODevice::OpenModeFlag> openMode)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "open"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::open(openMode);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), &openMode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QAbstractFileEngineWrapper::owner(QAbstractFileEngine::FileOwner arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "owner"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::owner(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.owner", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

uint QAbstractFileEngineWrapper::ownerId(QAbstractFileEngine::FileOwner arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((uint)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "ownerId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::ownerId(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((uint)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.ownerId", "uint", pyResult->ob_type->tp_name);
        return ((uint)0);
    }
    uint cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractFileEngineWrapper::pos() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pos"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::pos();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.pos", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractFileEngineWrapper::read(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "read"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QAbstractFileEngine::read(data, maxlen);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        maxlen
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Begin code injection

    qint64 cppResult;
    if (!Shiboken::String::check(pyResult)) {
        cppResult = -1;
    } else {
        cppResult = PyBytes_GET_SIZE((PyObject*)pyResult);
        memcpy(data, PyBytes_AS_STRING((PyObject*)pyResult), cppResult);
    }

    // End of code injection

    return cppResult;
}

qint64 QAbstractFileEngineWrapper::readLine(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readLine"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QAbstractFileEngine::readLine(data, maxlen);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        maxlen
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Begin code injection

    qint64 cppResult;
    if (!Shiboken::String::check(pyResult)) {
        cppResult = -1;
    } else {
        cppResult = PyBytes_GET_SIZE((PyObject*)pyResult);
        memcpy(data, PyBytes_AS_STRING((PyObject*)pyResult), cppResult);
    }

    // End of code injection

    return cppResult;
}

bool QAbstractFileEngineWrapper::remove()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "remove"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::remove();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.remove", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::rename(const QString & newName)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rename"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::rename(newName);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &newName)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.rename", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::rmdir(const QString & dirName, bool recurseParentDirectories) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rmdir"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::rmdir(dirName, recurseParentDirectories);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &dirName),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &recurseParentDirectories)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.rmdir", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::seek(qint64 pos)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "seek"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::seek(pos);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        pos
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.seek", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractFileEngineWrapper::setFileName(const QString & file)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setFileName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::setFileName(file);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &file)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QAbstractFileEngineWrapper::setPermissions(uint perms)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setPermissions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::setPermissions(perms);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(I)",
        perms
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.setPermissions", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::setSize(qint64 size)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::setSize(size);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        size
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.setSize", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractFileEngineWrapper::size() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "size"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::size();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.size", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractFileEngineWrapper::supportsExtension(QAbstractFileEngine::Extension extension) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportsExtension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::supportsExtension(extension);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX]), &extension)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.supportsExtension", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractFileEngineWrapper::write(const char * data, qint64 len)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "write"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractFileEngine::write(data, len);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NL)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), data),
        len
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractFileEngine.write", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAbstractFileEngineWrapper::~QAbstractFileEngineWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractFileEngine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractFileEngine >()))
        return -1;

    ::QAbstractFileEngineWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QAbstractFileEngine()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QAbstractFileEngineWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractFileEngine >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QAbstractFileEngineFunc_atEnd(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractFileEngine*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QAbstractFileEngineFunc_beginEntryList(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "beginEntryList", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: beginEntryList(QFlags<QDir::Filter>,QStringList)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
        overloadId = 0; // beginEntryList(QFlags<QDir::Filter>,QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_beginEntryList_TypeError;

    // Call function/method
    {
        ::QFlags<QDir::Filter> cppArg0 = ((::QFlags<QDir::Filter>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QStringList cppArg1 = ::QStringList();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // beginEntryList(QFlags<QDir::Filter>,QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractFileEngineIterator * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::beginEntryList(cppArg0, cppArg1) : cppSelf->beginEntryList(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINEITERATOR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_beginEntryList_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.beginEntryList", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_caseSensitive(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // caseSensitive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::caseSensitive() : const_cast<const ::QAbstractFileEngine*>(cppSelf)->caseSensitive();
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

static PyObject* Sbk_QAbstractFileEngineFunc_close(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::close() : cppSelf->close();
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

static PyObject* Sbk_QAbstractFileEngineFunc_copy(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: copy(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // copy(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_copy_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // copy(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::copy(cppArg0) : cppSelf->copy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_copy_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.copy", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_create(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: create(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // create(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_create_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // create(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractFileEngine * cppResult = ::QAbstractFileEngine::create(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_create_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.create", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_entryList(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "entryList", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: entryList(QFlags<QDir::Filter>,QStringList)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
        overloadId = 0; // entryList(QFlags<QDir::Filter>,QStringList)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_entryList_TypeError;

    // Call function/method
    {
        ::QFlags<QDir::Filter> cppArg0 = ((::QFlags<QDir::Filter>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QStringList cppArg1 = ::QStringList();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // entryList(QFlags<QDir::Filter>,QStringList)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::entryList(cppArg0, cppArg1) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->entryList(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_entryList_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.entryList", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_error(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFile::FileError cppResult = const_cast<const ::QAbstractFileEngine*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractFileEngineFunc_errorString(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAbstractFileEngine*>(cppSelf)->errorString();
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

static PyObject* Sbk_QAbstractFileEngineFunc_fileFlags(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractFileEngine.fileFlags(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:fileFlags", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: fileFlags(QFlags<QAbstractFileEngine::FileFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // fileFlags(QFlags<QAbstractFileEngine::FileFlag>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 0; // fileFlags(QFlags<QAbstractFileEngine::FileFlag>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_fileFlags_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractFileEngine.fileFlags(): got multiple values for keyword argument 'type'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), (pyArgs[0]))))
                    goto Sbk_QAbstractFileEngineFunc_fileFlags_TypeError;
            }
        }
        ::QFlags<QAbstractFileEngine::FileFlag> cppArg0 = QAbstractFileEngine::FileInfoAll;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // fileFlags(QFlags<QAbstractFileEngine::FileFlag>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QAbstractFileEngine::FileFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::fileFlags(cppArg0) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->fileFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_fileFlags_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractFileEngine.FileFlags = QAbstractFileEngine.FileInfoAll", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.fileFlags", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_fileName(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractFileEngine.fileName(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:fileName", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: fileName(QAbstractFileEngine::FileName)const
    if (numArgs == 0) {
        overloadId = 0; // fileName(QAbstractFileEngine::FileName)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX]), (pyArgs[0])))) {
        overloadId = 0; // fileName(QAbstractFileEngine::FileName)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_fileName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "file");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractFileEngine.fileName(): got multiple values for keyword argument 'file'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX]), (pyArgs[0]))))
                    goto Sbk_QAbstractFileEngineFunc_fileName_TypeError;
            }
        }
        ::QAbstractFileEngine::FileName cppArg0 = QAbstractFileEngine::DefaultName;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // fileName(QAbstractFileEngine::FileName)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::fileName(cppArg0) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->fileName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_fileName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractFileEngine.FileName = DefaultName", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.fileName", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_fileTime(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fileTime(QAbstractFileEngine::FileTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX]), (pyArg)))) {
        overloadId = 0; // fileTime(QAbstractFileEngine::FileTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_fileTime_TypeError;

    // Call function/method
    {
        ::QAbstractFileEngine::FileTime cppArg0 = ((::QAbstractFileEngine::FileTime)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fileTime(QAbstractFileEngine::FileTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::fileTime(cppArg0) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->fileTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_fileTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractFileEngine.FileTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.fileTime", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_flush(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flush()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::flush() : cppSelf->flush();
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

static PyObject* Sbk_QAbstractFileEngineFunc_handle(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::handle() : const_cast<const ::QAbstractFileEngine*>(cppSelf)->handle();
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

static PyObject* Sbk_QAbstractFileEngineFunc_isRelativePath(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRelativePath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::isRelativePath() : const_cast<const ::QAbstractFileEngine*>(cppSelf)->isRelativePath();
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

static PyObject* Sbk_QAbstractFileEngineFunc_isSequential(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSequential()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::isSequential() : const_cast<const ::QAbstractFileEngine*>(cppSelf)->isSequential();
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

static PyObject* Sbk_QAbstractFileEngineFunc_link(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: link(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // link(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_link_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // link(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::link(cppArg0) : cppSelf->link(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_link_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.link", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_map(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "map", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: map(qint64,qint64,QFile::MemoryMapFlags)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX]), (pyArgs[2])))) {
        overloadId = 0; // map(qint64,qint64,QFile::MemoryMapFlags)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_map_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFile::MemoryMapFlags cppArg2 = ((::QFile::MemoryMapFlags)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // map(qint64,qint64,QFile::MemoryMapFlags)
            // Begin code injection

            pyResult = Shiboken::Buffer::newObject(cppSelf->map(cppArg0, cppArg1, cppArg2), cppArg1, Shiboken::Buffer::ReadWrite);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_map_TypeError:
        const char* overloads[] = {"long long, long long, PySide.QtCore.QFile.MemoryMapFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.map", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_mkdir(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mkdir", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mkdir(QString,bool)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // mkdir(QString,bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_mkdir_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mkdir(QString,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::mkdir(cppArg0, cppArg1) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->mkdir(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_mkdir_TypeError:
        const char* overloads[] = {"unicode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.mkdir", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_open(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: open(QFlags<QIODevice::OpenModeFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // open(QFlags<QIODevice::OpenModeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_open_TypeError;

    // Call function/method
    {
        ::QFlags<QIODevice::OpenModeFlag> cppArg0 = ((::QFlags<QIODevice::OpenModeFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // open(QFlags<QIODevice::OpenModeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::open(cppArg0) : cppSelf->open(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_open_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice.OpenMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.open", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_owner(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: owner(QAbstractFileEngine::FileOwner)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX]), (pyArg)))) {
        overloadId = 0; // owner(QAbstractFileEngine::FileOwner)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_owner_TypeError;

    // Call function/method
    {
        ::QAbstractFileEngine::FileOwner cppArg0 = ((::QAbstractFileEngine::FileOwner)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // owner(QAbstractFileEngine::FileOwner)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::owner(cppArg0) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->owner(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_owner_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractFileEngine.FileOwner", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.owner", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_ownerId(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ownerId(QAbstractFileEngine::FileOwner)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX]), (pyArg)))) {
        overloadId = 0; // ownerId(QAbstractFileEngine::FileOwner)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_ownerId_TypeError;

    // Call function/method
    {
        ::QAbstractFileEngine::FileOwner cppArg0 = ((::QAbstractFileEngine::FileOwner)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // ownerId(QAbstractFileEngine::FileOwner)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::ownerId(cppArg0) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->ownerId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_ownerId_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractFileEngine.FileOwner", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.ownerId", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_pos(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::pos() : const_cast<const ::QAbstractFileEngine*>(cppSelf)->pos();
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

static PyObject* Sbk_QAbstractFileEngineFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(char*,qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // read(char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_read_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::read(ba.data(), ba.size()) : cppSelf->read(ba.data(), ba.size()));
            pyResult = PyBytes_FromStringAndSize(ba.constData(), ba.size());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_read_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.read", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_readLine(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: readLine(char*,qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // readLine(char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_readLine_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readLine(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::readLine(ba.data(), ba.size()) : cppSelf->readLine(ba.data(), ba.size()));
            pyResult = PyBytes_FromStringAndSize(ba.constData(), ba.size());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_readLine_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.readLine", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_remove(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // remove()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::remove() : cppSelf->remove();
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

static PyObject* Sbk_QAbstractFileEngineFunc_rename(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rename(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // rename(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_rename_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rename(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::rename(cppArg0) : cppSelf->rename(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_rename_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.rename", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_rmdir(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rmdir", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: rmdir(QString,bool)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // rmdir(QString,bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_rmdir_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // rmdir(QString,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::rmdir(cppArg0, cppArg1) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->rmdir(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_rmdir_TypeError:
        const char* overloads[] = {"unicode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.rmdir", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_seek(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: seek(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // seek(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_seek_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seek(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::seek(cppArg0) : cppSelf->seek(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_seek_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.seek", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_setError(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setError", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setError(QFile::FileError,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setError(QFile::FileError,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_setError_TypeError;

    // Call function/method
    {
        ::QFile::FileError cppArg0 = ((::QFile::FileError)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setError(QFile::FileError,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setError(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractFileEngineFunc_setError_TypeError:
        const char* overloads[] = {"PySide.QtCore.QFile.FileError, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.setError", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_setFileName(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFileName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFileName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_setFileName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFileName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::setFileName(cppArg0) : cppSelf->setFileName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractFileEngineFunc_setFileName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.setFileName", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_setPermissions(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPermissions(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArg)))) {
        overloadId = 0; // setPermissions(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_setPermissions_TypeError;

    // Call function/method
    {
        uint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPermissions(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::setPermissions(cppArg0) : cppSelf->setPermissions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_setPermissions_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.setPermissions", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_setSize(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSize(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setSize(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_setSize_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSize(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::setSize(cppArg0) : cppSelf->setSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_setSize_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.setSize", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_size(PyObject* self)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::size() : const_cast<const ::QAbstractFileEngine*>(cppSelf)->size();
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

static PyObject* Sbk_QAbstractFileEngineFunc_supportsExtension(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsExtension(QAbstractFileEngine::Extension)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX]), (pyArg)))) {
        overloadId = 0; // supportsExtension(QAbstractFileEngine::Extension)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_supportsExtension_TypeError;

    // Call function/method
    {
        ::QAbstractFileEngine::Extension cppArg0 = ((::QAbstractFileEngine::Extension)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsExtension(QAbstractFileEngine::Extension)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractFileEngine*>(cppSelf)->::QAbstractFileEngine::supportsExtension(cppArg0) : const_cast<const ::QAbstractFileEngine*>(cppSelf)->supportsExtension(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_supportsExtension_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractFileEngine.Extension", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.supportsExtension", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_unmap(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unmap(uchar*)
    if (Shiboken::Buffer::checkType(pyArg)) {
        overloadId = 0; // unmap(uchar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_unmap_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unmap(uchar*)
            // Begin code injection

            uchar* ptr = (uchar*)Shiboken::Buffer::getPointer(pyArg);
            bool cppResult = cppSelf->unmap(ptr);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_unmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.uchar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractFileEngine.unmap", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractFileEngineFunc_write(PyObject* self, PyObject* args)
{
    ::QAbstractFileEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractFileEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "write", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: write(const char*,qint64)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))) {
        overloadId = 0; // write(const char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractFileEngineFunc_write_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // write(const char*,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractFileEngine::write(cppArg0, cppArg1) : cppSelf->write(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractFileEngineFunc_write_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractFileEngine.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QAbstractFileEngine_methods[] = {
    {"atEnd", (PyCFunction)Sbk_QAbstractFileEngineFunc_atEnd, METH_NOARGS},
    {"beginEntryList", (PyCFunction)Sbk_QAbstractFileEngineFunc_beginEntryList, METH_VARARGS},
    {"caseSensitive", (PyCFunction)Sbk_QAbstractFileEngineFunc_caseSensitive, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QAbstractFileEngineFunc_close, METH_NOARGS},
    {"copy", (PyCFunction)Sbk_QAbstractFileEngineFunc_copy, METH_O},
    {"create", (PyCFunction)Sbk_QAbstractFileEngineFunc_create, METH_O|METH_STATIC},
    {"entryList", (PyCFunction)Sbk_QAbstractFileEngineFunc_entryList, METH_VARARGS},
    {"error", (PyCFunction)Sbk_QAbstractFileEngineFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QAbstractFileEngineFunc_errorString, METH_NOARGS},
    {"fileFlags", (PyCFunction)Sbk_QAbstractFileEngineFunc_fileFlags, METH_VARARGS|METH_KEYWORDS},
    {"fileName", (PyCFunction)Sbk_QAbstractFileEngineFunc_fileName, METH_VARARGS|METH_KEYWORDS},
    {"fileTime", (PyCFunction)Sbk_QAbstractFileEngineFunc_fileTime, METH_O},
    {"flush", (PyCFunction)Sbk_QAbstractFileEngineFunc_flush, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QAbstractFileEngineFunc_handle, METH_NOARGS},
    {"isRelativePath", (PyCFunction)Sbk_QAbstractFileEngineFunc_isRelativePath, METH_NOARGS},
    {"isSequential", (PyCFunction)Sbk_QAbstractFileEngineFunc_isSequential, METH_NOARGS},
    {"link", (PyCFunction)Sbk_QAbstractFileEngineFunc_link, METH_O},
    {"map", (PyCFunction)Sbk_QAbstractFileEngineFunc_map, METH_VARARGS},
    {"mkdir", (PyCFunction)Sbk_QAbstractFileEngineFunc_mkdir, METH_VARARGS},
    {"open", (PyCFunction)Sbk_QAbstractFileEngineFunc_open, METH_O},
    {"owner", (PyCFunction)Sbk_QAbstractFileEngineFunc_owner, METH_O},
    {"ownerId", (PyCFunction)Sbk_QAbstractFileEngineFunc_ownerId, METH_O},
    {"pos", (PyCFunction)Sbk_QAbstractFileEngineFunc_pos, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QAbstractFileEngineFunc_read, METH_O},
    {"readLine", (PyCFunction)Sbk_QAbstractFileEngineFunc_readLine, METH_O},
    {"remove", (PyCFunction)Sbk_QAbstractFileEngineFunc_remove, METH_NOARGS},
    {"rename", (PyCFunction)Sbk_QAbstractFileEngineFunc_rename, METH_O},
    {"rmdir", (PyCFunction)Sbk_QAbstractFileEngineFunc_rmdir, METH_VARARGS},
    {"seek", (PyCFunction)Sbk_QAbstractFileEngineFunc_seek, METH_O},
    {"setError", (PyCFunction)Sbk_QAbstractFileEngineFunc_setError, METH_VARARGS},
    {"setFileName", (PyCFunction)Sbk_QAbstractFileEngineFunc_setFileName, METH_O},
    {"setPermissions", (PyCFunction)Sbk_QAbstractFileEngineFunc_setPermissions, METH_O},
    {"setSize", (PyCFunction)Sbk_QAbstractFileEngineFunc_setSize, METH_O},
    {"size", (PyCFunction)Sbk_QAbstractFileEngineFunc_size, METH_NOARGS},
    {"supportsExtension", (PyCFunction)Sbk_QAbstractFileEngineFunc_supportsExtension, METH_O},
    {"unmap", (PyCFunction)Sbk_QAbstractFileEngineFunc_unmap, METH_O},
    {"write", (PyCFunction)Sbk_QAbstractFileEngineFunc_write, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractFileEngine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractFileEngine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractFileEngine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QAbstractFileEngine",
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
    /*tp_traverse*/         Sbk_QAbstractFileEngine_traverse,
    /*tp_clear*/            Sbk_QAbstractFileEngine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractFileEngine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractFileEngine_Init,
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

PyObject* SbkPySide_QtCore_QAbstractFileEngine_FileFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine::FileFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractFileEngine::FileFlags)PyLong_AsLong(self);
    cppArg = (QAbstractFileEngine::FileFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractFileEngine::FileFlags)PyInt_AsLong(self);
    cppArg = (QAbstractFileEngine::FileFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QAbstractFileEngine_FileFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine::FileFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractFileEngine::FileFlags)PyLong_AsLong(self);
    cppArg = (QAbstractFileEngine::FileFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractFileEngine::FileFlags)PyInt_AsLong(self);
    cppArg = (QAbstractFileEngine::FileFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QAbstractFileEngine_FileFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine::FileFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractFileEngine::FileFlags)PyLong_AsLong(self);
    cppArg = (QAbstractFileEngine::FileFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractFileEngine::FileFlags)PyInt_AsLong(self);
    cppArg = (QAbstractFileEngine::FileFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QAbstractFileEngine_FileFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractFileEngine::FileFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), self, &cppSelf);
    ::QAbstractFileEngine::FileFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QAbstractFileEngine_FileFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QAbstractFileEngine_FileFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QAbstractFileEngine_FileFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtCore_QAbstractFileEngine_FileFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QAbstractFileEngine_FileFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QAbstractFileEngine_FileFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QAbstractFileEngine_FileFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QAbstractFileEngine_FileFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QAbstractFileEngine_FileFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QAbstractFileEngine_FileFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QAbstractFileEngine_FileFlag_PythonToCpp_QAbstractFileEngine_FileFlag(PyObject* pyIn, void* cppOut) {
    *((::QAbstractFileEngine::FileFlag*)cppOut) = (::QAbstractFileEngine::FileFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractFileEngine_FileFlag_PythonToCpp_QAbstractFileEngine_FileFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX]))
        return QAbstractFileEngine_FileFlag_PythonToCpp_QAbstractFileEngine_FileFlag;
    return 0;
}
static PyObject* QAbstractFileEngine_FileFlag_CppToPython_QAbstractFileEngine_FileFlag(const void* cppIn) {
    int castCppIn = *((::QAbstractFileEngine::FileFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX], castCppIn);

}

static void QFlags_QAbstractFileEngine_FileFlag__PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QAbstractFileEngine::FileFlag>*)cppOut) = ::QFlags<QAbstractFileEngine::FileFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QAbstractFileEngine_FileFlag__PythonToCpp_QFlags_QAbstractFileEngine_FileFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]))
        return QFlags_QAbstractFileEngine_FileFlag__PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_;
    return 0;
}
static PyObject* QFlags_QAbstractFileEngine_FileFlag__CppToPython_QFlags_QAbstractFileEngine_FileFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QAbstractFileEngine::FileFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]));

}

static void QAbstractFileEngine_FileFlag_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QAbstractFileEngine::FileFlag>*)cppOut) = ::QFlags<QAbstractFileEngine::FileFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QAbstractFileEngine_FileFlag_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX]))
        return QAbstractFileEngine_FileFlag_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QAbstractFileEngine::FileFlag>*)cppOut) = ::QFlags<QAbstractFileEngine::FileFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_;
    return 0;
}
static void QAbstractFileEngine_FileName_PythonToCpp_QAbstractFileEngine_FileName(PyObject* pyIn, void* cppOut) {
    *((::QAbstractFileEngine::FileName*)cppOut) = (::QAbstractFileEngine::FileName) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractFileEngine_FileName_PythonToCpp_QAbstractFileEngine_FileName_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX]))
        return QAbstractFileEngine_FileName_PythonToCpp_QAbstractFileEngine_FileName;
    return 0;
}
static PyObject* QAbstractFileEngine_FileName_CppToPython_QAbstractFileEngine_FileName(const void* cppIn) {
    int castCppIn = *((::QAbstractFileEngine::FileName*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX], castCppIn);

}

static void QAbstractFileEngine_FileOwner_PythonToCpp_QAbstractFileEngine_FileOwner(PyObject* pyIn, void* cppOut) {
    *((::QAbstractFileEngine::FileOwner*)cppOut) = (::QAbstractFileEngine::FileOwner) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractFileEngine_FileOwner_PythonToCpp_QAbstractFileEngine_FileOwner_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX]))
        return QAbstractFileEngine_FileOwner_PythonToCpp_QAbstractFileEngine_FileOwner;
    return 0;
}
static PyObject* QAbstractFileEngine_FileOwner_CppToPython_QAbstractFileEngine_FileOwner(const void* cppIn) {
    int castCppIn = *((::QAbstractFileEngine::FileOwner*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX], castCppIn);

}

static void QAbstractFileEngine_FileTime_PythonToCpp_QAbstractFileEngine_FileTime(PyObject* pyIn, void* cppOut) {
    *((::QAbstractFileEngine::FileTime*)cppOut) = (::QAbstractFileEngine::FileTime) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractFileEngine_FileTime_PythonToCpp_QAbstractFileEngine_FileTime_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX]))
        return QAbstractFileEngine_FileTime_PythonToCpp_QAbstractFileEngine_FileTime;
    return 0;
}
static PyObject* QAbstractFileEngine_FileTime_CppToPython_QAbstractFileEngine_FileTime(const void* cppIn) {
    int castCppIn = *((::QAbstractFileEngine::FileTime*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX], castCppIn);

}

static void QAbstractFileEngine_Extension_PythonToCpp_QAbstractFileEngine_Extension(PyObject* pyIn, void* cppOut) {
    *((::QAbstractFileEngine::Extension*)cppOut) = (::QAbstractFileEngine::Extension) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractFileEngine_Extension_PythonToCpp_QAbstractFileEngine_Extension_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX]))
        return QAbstractFileEngine_Extension_PythonToCpp_QAbstractFileEngine_Extension;
    return 0;
}
static PyObject* QAbstractFileEngine_Extension_CppToPython_QAbstractFileEngine_Extension(const void* cppIn) {
    int castCppIn = *((::QAbstractFileEngine::Extension*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractFileEngine_PythonToCpp_QAbstractFileEngine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractFileEngine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractFileEngine_PythonToCpp_QAbstractFileEngine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractFileEngine_Type))
        return QAbstractFileEngine_PythonToCpp_QAbstractFileEngine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractFileEngine_PTR_CppToPython_QAbstractFileEngine(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAbstractFileEngine*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAbstractFileEngine_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QAbstractFileEngine(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractFileEngine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractFileEngine", "QAbstractFileEngine*",
        &Sbk_QAbstractFileEngine_Type, &Shiboken::callCppDestructor< ::QAbstractFileEngine >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractFileEngine_Type,
        QAbstractFileEngine_PythonToCpp_QAbstractFileEngine_PTR,
        is_QAbstractFileEngine_PythonToCpp_QAbstractFileEngine_PTR_Convertible,
        QAbstractFileEngine_PTR_CppToPython_QAbstractFileEngine);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractFileEngine).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractFileEngineWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'FileFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX] = PySide::QFlags::create("FileFlags", &SbkPySide_QtCore_QAbstractFileEngine_FileFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractFileEngine_Type,
        "FileFlag",
        "PySide.QtCore.QAbstractFileEngine.FileFlag",
        "QAbstractFileEngine::FileFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ReadOwnerPerm", (long) QAbstractFileEngine::ReadOwnerPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "WriteOwnerPerm", (long) QAbstractFileEngine::WriteOwnerPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ExeOwnerPerm", (long) QAbstractFileEngine::ExeOwnerPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ReadUserPerm", (long) QAbstractFileEngine::ReadUserPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "WriteUserPerm", (long) QAbstractFileEngine::WriteUserPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ExeUserPerm", (long) QAbstractFileEngine::ExeUserPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ReadGroupPerm", (long) QAbstractFileEngine::ReadGroupPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "WriteGroupPerm", (long) QAbstractFileEngine::WriteGroupPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ExeGroupPerm", (long) QAbstractFileEngine::ExeGroupPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ReadOtherPerm", (long) QAbstractFileEngine::ReadOtherPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "WriteOtherPerm", (long) QAbstractFileEngine::WriteOtherPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ExeOtherPerm", (long) QAbstractFileEngine::ExeOtherPerm))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "LinkType", (long) QAbstractFileEngine::LinkType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "FileType", (long) QAbstractFileEngine::FileType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "DirectoryType", (long) QAbstractFileEngine::DirectoryType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "BundleType", (long) QAbstractFileEngine::BundleType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "HiddenFlag", (long) QAbstractFileEngine::HiddenFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "LocalDiskFlag", (long) QAbstractFileEngine::LocalDiskFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "ExistsFlag", (long) QAbstractFileEngine::ExistsFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "RootFlag", (long) QAbstractFileEngine::RootFlag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "Refresh", (long) QAbstractFileEngine::Refresh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "PermsMask", (long) QAbstractFileEngine::PermsMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "TypesMask", (long) QAbstractFileEngine::TypesMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "FlagsMask", (long) QAbstractFileEngine::FlagsMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
        &Sbk_QAbstractFileEngine_Type, "FileInfoAll", (long) QAbstractFileEngine::FileInfoAll))
        return ;
    // Register converter for enum 'QAbstractFileEngine::FileFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX],
            QAbstractFileEngine_FileFlag_CppToPython_QAbstractFileEngine_FileFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractFileEngine_FileFlag_PythonToCpp_QAbstractFileEngine_FileFlag,
            is_QAbstractFileEngine_FileFlag_PythonToCpp_QAbstractFileEngine_FileFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine::FileFlag");
        Shiboken::Conversions::registerConverterName(converter, "FileFlag");
    }
    // Register converter for flag 'QFlags<QAbstractFileEngine::FileFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX],
            QFlags_QAbstractFileEngine_FileFlag__CppToPython_QFlags_QAbstractFileEngine_FileFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractFileEngine_FileFlag_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_,
            is_QAbstractFileEngine_FileFlag_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QAbstractFileEngine_FileFlag__PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_,
            is_QFlags_QAbstractFileEngine_FileFlag__PythonToCpp_QFlags_QAbstractFileEngine_FileFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag_,
            is_number_PythonToCpp_QFlags_QAbstractFileEngine_FileFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QABSTRACTFILEENGINE_FILEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QAbstractFileEngine::FileFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FileFlag>");
    }
    // End of 'FileFlag' enum/flags.

    // Initialization of enum 'FileName'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractFileEngine_Type,
        "FileName",
        "PySide.QtCore.QAbstractFileEngine.FileName",
        "QAbstractFileEngine::FileName");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "DefaultName", (long) QAbstractFileEngine::DefaultName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "BaseName", (long) QAbstractFileEngine::BaseName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "PathName", (long) QAbstractFileEngine::PathName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "AbsoluteName", (long) QAbstractFileEngine::AbsoluteName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "AbsolutePathName", (long) QAbstractFileEngine::AbsolutePathName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "LinkName", (long) QAbstractFileEngine::LinkName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "CanonicalName", (long) QAbstractFileEngine::CanonicalName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "CanonicalPathName", (long) QAbstractFileEngine::CanonicalPathName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "BundleName", (long) QAbstractFileEngine::BundleName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
        &Sbk_QAbstractFileEngine_Type, "NFileNames", (long) QAbstractFileEngine::NFileNames))
        return ;
    // Register converter for enum 'QAbstractFileEngine::FileName'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX],
            QAbstractFileEngine_FileName_CppToPython_QAbstractFileEngine_FileName);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractFileEngine_FileName_PythonToCpp_QAbstractFileEngine_FileName,
            is_QAbstractFileEngine_FileName_PythonToCpp_QAbstractFileEngine_FileName_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILENAME_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine::FileName");
        Shiboken::Conversions::registerConverterName(converter, "FileName");
    }
    // End of 'FileName' enum.

    // Initialization of enum 'FileOwner'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractFileEngine_Type,
        "FileOwner",
        "PySide.QtCore.QAbstractFileEngine.FileOwner",
        "QAbstractFileEngine::FileOwner");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX],
        &Sbk_QAbstractFileEngine_Type, "OwnerUser", (long) QAbstractFileEngine::OwnerUser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX],
        &Sbk_QAbstractFileEngine_Type, "OwnerGroup", (long) QAbstractFileEngine::OwnerGroup))
        return ;
    // Register converter for enum 'QAbstractFileEngine::FileOwner'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX],
            QAbstractFileEngine_FileOwner_CppToPython_QAbstractFileEngine_FileOwner);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractFileEngine_FileOwner_PythonToCpp_QAbstractFileEngine_FileOwner,
            is_QAbstractFileEngine_FileOwner_PythonToCpp_QAbstractFileEngine_FileOwner_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILEOWNER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine::FileOwner");
        Shiboken::Conversions::registerConverterName(converter, "FileOwner");
    }
    // End of 'FileOwner' enum.

    // Initialization of enum 'FileTime'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractFileEngine_Type,
        "FileTime",
        "PySide.QtCore.QAbstractFileEngine.FileTime",
        "QAbstractFileEngine::FileTime");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX],
        &Sbk_QAbstractFileEngine_Type, "CreationTime", (long) QAbstractFileEngine::CreationTime))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX],
        &Sbk_QAbstractFileEngine_Type, "ModificationTime", (long) QAbstractFileEngine::ModificationTime))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX],
        &Sbk_QAbstractFileEngine_Type, "AccessTime", (long) QAbstractFileEngine::AccessTime))
        return ;
    // Register converter for enum 'QAbstractFileEngine::FileTime'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX],
            QAbstractFileEngine_FileTime_CppToPython_QAbstractFileEngine_FileTime);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractFileEngine_FileTime_PythonToCpp_QAbstractFileEngine_FileTime,
            is_QAbstractFileEngine_FileTime_PythonToCpp_QAbstractFileEngine_FileTime_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_FILETIME_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine::FileTime");
        Shiboken::Conversions::registerConverterName(converter, "FileTime");
    }
    // End of 'FileTime' enum.

    // Initialization of enum 'Extension'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractFileEngine_Type,
        "Extension",
        "PySide.QtCore.QAbstractFileEngine.Extension",
        "QAbstractFileEngine::Extension");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX],
        &Sbk_QAbstractFileEngine_Type, "AtEndExtension", (long) QAbstractFileEngine::AtEndExtension))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX],
        &Sbk_QAbstractFileEngine_Type, "FastReadLineExtension", (long) QAbstractFileEngine::FastReadLineExtension))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX],
        &Sbk_QAbstractFileEngine_Type, "MapExtension", (long) QAbstractFileEngine::MapExtension))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX],
        &Sbk_QAbstractFileEngine_Type, "UnMapExtension", (long) QAbstractFileEngine::UnMapExtension))
        return ;
    // Register converter for enum 'QAbstractFileEngine::Extension'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX],
            QAbstractFileEngine_Extension_CppToPython_QAbstractFileEngine_Extension);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractFileEngine_Extension_PythonToCpp_QAbstractFileEngine_Extension,
            is_QAbstractFileEngine_Extension_PythonToCpp_QAbstractFileEngine_Extension_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_EXTENSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractFileEngine::Extension");
        Shiboken::Conversions::registerConverterName(converter, "Extension");
    }
    // End of 'Extension' enum.


    qRegisterMetaType< ::QAbstractFileEngine::FileFlag >("QAbstractFileEngine::FileFlag");
    qRegisterMetaType< ::QAbstractFileEngine::FileFlags >("QAbstractFileEngine::FileFlags");
    qRegisterMetaType< ::QAbstractFileEngine::FileName >("QAbstractFileEngine::FileName");
    qRegisterMetaType< ::QAbstractFileEngine::FileOwner >("QAbstractFileEngine::FileOwner");
    qRegisterMetaType< ::QAbstractFileEngine::FileTime >("QAbstractFileEngine::FileTime");
    qRegisterMetaType< ::QAbstractFileEngine::Extension >("QAbstractFileEngine::Extension");
}
