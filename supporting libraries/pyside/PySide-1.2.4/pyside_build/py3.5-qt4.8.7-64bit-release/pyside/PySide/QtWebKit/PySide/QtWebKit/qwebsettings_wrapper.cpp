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
#include "pyside_qtwebkit_python.h"

#include "qwebsettings_wrapper.h"

// Extra includes
#include <qicon.h>
#include <qpixmap.h>
#include <qurl.h>
#include <qwebsettings.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QWebSettingsFunc_clearIconDatabase(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearIconDatabase()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::clearIconDatabase();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebSettingsFunc_clearMemoryCaches(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMemoryCaches()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::clearMemoryCaches();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebSettingsFunc_defaultTextEncoding(PyObject* self)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultTextEncoding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebSettings*>(cppSelf)->defaultTextEncoding();
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

static PyObject* Sbk_QWebSettingsFunc_enablePersistentStorage(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebSettings.enablePersistentStorage(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:enablePersistentStorage", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: enablePersistentStorage(QString)
    if (numArgs == 0) {
        overloadId = 0; // enablePersistentStorage(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // enablePersistentStorage(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_enablePersistentStorage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "path");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebSettings.enablePersistentStorage(): got multiple values for keyword argument 'path'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QWebSettingsFunc_enablePersistentStorage_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // enablePersistentStorage(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::enablePersistentStorage(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_enablePersistentStorage_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSettings.enablePersistentStorage", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_fontFamily(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fontFamily(QWebSettings::FontFamily)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX]), (pyArg)))) {
        overloadId = 0; // fontFamily(QWebSettings::FontFamily)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_fontFamily_TypeError;

    // Call function/method
    {
        ::QWebSettings::FontFamily cppArg0 = ((::QWebSettings::FontFamily)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fontFamily(QWebSettings::FontFamily)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebSettings*>(cppSelf)->fontFamily(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebSettingsFunc_fontFamily_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.FontFamily", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.fontFamily", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_fontSize(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fontSize(QWebSettings::FontSize)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX]), (pyArg)))) {
        overloadId = 0; // fontSize(QWebSettings::FontSize)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_fontSize_TypeError;

    // Call function/method
    {
        ::QWebSettings::FontSize cppArg0 = ((::QWebSettings::FontSize)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fontSize(QWebSettings::FontSize)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWebSettings*>(cppSelf)->fontSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebSettingsFunc_fontSize_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.FontSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.fontSize", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_globalSettings(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalSettings()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebSettings * cppResult = ::QWebSettings::globalSettings();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebSettingsFunc_iconDatabasePath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconDatabasePath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QWebSettings::iconDatabasePath();
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

static PyObject* Sbk_QWebSettingsFunc_iconForUrl(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: iconForUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // iconForUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_iconForUrl_TypeError;

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
            // iconForUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = ::QWebSettings::iconForUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebSettingsFunc_iconForUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.iconForUrl", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_localStoragePath(PyObject* self)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localStoragePath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebSettings*>(cppSelf)->localStoragePath();
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

static PyObject* Sbk_QWebSettingsFunc_maximumPagesInCache(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumPagesInCache()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QWebSettings::maximumPagesInCache();
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

static PyObject* Sbk_QWebSettingsFunc_offlineStorageDefaultQuota(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // offlineStorageDefaultQuota()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = ::QWebSettings::offlineStorageDefaultQuota();
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

static PyObject* Sbk_QWebSettingsFunc_offlineStoragePath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // offlineStoragePath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QWebSettings::offlineStoragePath();
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

static PyObject* Sbk_QWebSettingsFunc_offlineWebApplicationCachePath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // offlineWebApplicationCachePath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QWebSettings::offlineWebApplicationCachePath();
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

static PyObject* Sbk_QWebSettingsFunc_offlineWebApplicationCacheQuota(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // offlineWebApplicationCacheQuota()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = ::QWebSettings::offlineWebApplicationCacheQuota();
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

static PyObject* Sbk_QWebSettingsFunc_resetAttribute(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resetAttribute(QWebSettings::WebAttribute)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX]), (pyArg)))) {
        overloadId = 0; // resetAttribute(QWebSettings::WebAttribute)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_resetAttribute_TypeError;

    // Call function/method
    {
        ::QWebSettings::WebAttribute cppArg0 = ((::QWebSettings::WebAttribute)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resetAttribute(QWebSettings::WebAttribute)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_resetAttribute_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.WebAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.resetAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_resetFontFamily(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resetFontFamily(QWebSettings::FontFamily)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX]), (pyArg)))) {
        overloadId = 0; // resetFontFamily(QWebSettings::FontFamily)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_resetFontFamily_TypeError;

    // Call function/method
    {
        ::QWebSettings::FontFamily cppArg0 = ((::QWebSettings::FontFamily)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resetFontFamily(QWebSettings::FontFamily)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetFontFamily(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_resetFontFamily_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.FontFamily", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.resetFontFamily", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_resetFontSize(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resetFontSize(QWebSettings::FontSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX]), (pyArg)))) {
        overloadId = 0; // resetFontSize(QWebSettings::FontSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_resetFontSize_TypeError;

    // Call function/method
    {
        ::QWebSettings::FontSize cppArg0 = ((::QWebSettings::FontSize)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resetFontSize(QWebSettings::FontSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetFontSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_resetFontSize_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.FontSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.resetFontSize", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setAttribute(PyObject* self, PyObject* args)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttribute", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAttribute(QWebSettings::WebAttribute,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // setAttribute(QWebSettings::WebAttribute,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setAttribute_TypeError;

    // Call function/method
    {
        ::QWebSettings::WebAttribute cppArg0 = ((::QWebSettings::WebAttribute)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAttribute(QWebSettings::WebAttribute,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setAttribute_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.WebAttribute, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSettings.setAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setDefaultTextEncoding(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultTextEncoding(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultTextEncoding(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setDefaultTextEncoding_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultTextEncoding(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultTextEncoding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setDefaultTextEncoding_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setDefaultTextEncoding", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setFontFamily(PyObject* self, PyObject* args)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFontFamily", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFontFamily(QWebSettings::FontFamily,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setFontFamily(QWebSettings::FontFamily,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setFontFamily_TypeError;

    // Call function/method
    {
        ::QWebSettings::FontFamily cppArg0 = ((::QWebSettings::FontFamily)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFontFamily(QWebSettings::FontFamily,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontFamily(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setFontFamily_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.FontFamily, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSettings.setFontFamily", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setFontSize(PyObject* self, PyObject* args)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFontSize", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFontSize(QWebSettings::FontSize,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setFontSize(QWebSettings::FontSize,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setFontSize_TypeError;

    // Call function/method
    {
        ::QWebSettings::FontSize cppArg0 = ((::QWebSettings::FontSize)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFontSize(QWebSettings::FontSize,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontSize(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setFontSize_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.FontSize, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSettings.setFontSize", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setIconDatabasePath(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconDatabasePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setIconDatabasePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setIconDatabasePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconDatabasePath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setIconDatabasePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setIconDatabasePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setIconDatabasePath", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setLocalStoragePath(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLocalStoragePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setLocalStoragePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setLocalStoragePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLocalStoragePath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLocalStoragePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setLocalStoragePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setLocalStoragePath", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setMaximumPagesInCache(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumPagesInCache(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setMaximumPagesInCache(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setMaximumPagesInCache_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaximumPagesInCache(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setMaximumPagesInCache(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setMaximumPagesInCache_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setMaximumPagesInCache", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setObjectCacheCapacities(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setObjectCacheCapacities", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setObjectCacheCapacities(int,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // setObjectCacheCapacities(int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setObjectCacheCapacities_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setObjectCacheCapacities(int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setObjectCacheCapacities(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setObjectCacheCapacities_TypeError:
        const char* overloads[] = {"int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSettings.setObjectCacheCapacities", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setOfflineStorageDefaultQuota(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOfflineStorageDefaultQuota(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setOfflineStorageDefaultQuota(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setOfflineStorageDefaultQuota_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOfflineStorageDefaultQuota(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setOfflineStorageDefaultQuota(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setOfflineStorageDefaultQuota_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setOfflineStorageDefaultQuota", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setOfflineStoragePath(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOfflineStoragePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOfflineStoragePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setOfflineStoragePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOfflineStoragePath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setOfflineStoragePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setOfflineStoragePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setOfflineStoragePath", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setOfflineWebApplicationCachePath(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOfflineWebApplicationCachePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOfflineWebApplicationCachePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setOfflineWebApplicationCachePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOfflineWebApplicationCachePath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setOfflineWebApplicationCachePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setOfflineWebApplicationCachePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setOfflineWebApplicationCachePath", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setOfflineWebApplicationCacheQuota(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOfflineWebApplicationCacheQuota(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setOfflineWebApplicationCacheQuota(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setOfflineWebApplicationCacheQuota_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOfflineWebApplicationCacheQuota(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setOfflineWebApplicationCacheQuota(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setOfflineWebApplicationCacheQuota_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setOfflineWebApplicationCacheQuota", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setUserStyleSheetUrl(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUserStyleSheetUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUserStyleSheetUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setUserStyleSheetUrl_TypeError;

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
            // setUserStyleSheetUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUserStyleSheetUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setUserStyleSheetUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.setUserStyleSheetUrl", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_setWebGraphic(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setWebGraphic", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setWebGraphic(QWebSettings::WebGraphic,QPixmap)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        overloadId = 0; // setWebGraphic(QWebSettings::WebGraphic,QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_setWebGraphic_TypeError;

    // Call function/method
    {
        ::QWebSettings::WebGraphic cppArg0 = ((::QWebSettings::WebGraphic)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPixmap cppArg1_local = ::QPixmap();
        ::QPixmap* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setWebGraphic(QWebSettings::WebGraphic,QPixmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSettings::setWebGraphic(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSettingsFunc_setWebGraphic_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.WebGraphic, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSettings.setWebGraphic", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_testAttribute(PyObject* self, PyObject* pyArg)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testAttribute(QWebSettings::WebAttribute)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX]), (pyArg)))) {
        overloadId = 0; // testAttribute(QWebSettings::WebAttribute)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_testAttribute_TypeError;

    // Call function/method
    {
        ::QWebSettings::WebAttribute cppArg0 = ((::QWebSettings::WebAttribute)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testAttribute(QWebSettings::WebAttribute)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebSettings*>(cppSelf)->testAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebSettingsFunc_testAttribute_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.WebAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.testAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QWebSettingsFunc_userStyleSheetUrl(PyObject* self)
{
    ::QWebSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userStyleSheetUrl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebSettings*>(cppSelf)->userStyleSheetUrl();
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

static PyObject* Sbk_QWebSettingsFunc_webGraphic(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: webGraphic(QWebSettings::WebGraphic)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX]), (pyArg)))) {
        overloadId = 0; // webGraphic(QWebSettings::WebGraphic)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSettingsFunc_webGraphic_TypeError;

    // Call function/method
    {
        ::QWebSettings::WebGraphic cppArg0 = ((::QWebSettings::WebGraphic)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // webGraphic(QWebSettings::WebGraphic)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = ::QWebSettings::webGraphic(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebSettingsFunc_webGraphic_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSettings.WebGraphic", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSettings.webGraphic", overloads);
        return 0;
}

static PyMethodDef Sbk_QWebSettings_methods[] = {
    {"clearIconDatabase", (PyCFunction)Sbk_QWebSettingsFunc_clearIconDatabase, METH_NOARGS|METH_STATIC},
    {"clearMemoryCaches", (PyCFunction)Sbk_QWebSettingsFunc_clearMemoryCaches, METH_NOARGS|METH_STATIC},
    {"defaultTextEncoding", (PyCFunction)Sbk_QWebSettingsFunc_defaultTextEncoding, METH_NOARGS},
    {"enablePersistentStorage", (PyCFunction)Sbk_QWebSettingsFunc_enablePersistentStorage, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fontFamily", (PyCFunction)Sbk_QWebSettingsFunc_fontFamily, METH_O},
    {"fontSize", (PyCFunction)Sbk_QWebSettingsFunc_fontSize, METH_O},
    {"globalSettings", (PyCFunction)Sbk_QWebSettingsFunc_globalSettings, METH_NOARGS|METH_STATIC},
    {"iconDatabasePath", (PyCFunction)Sbk_QWebSettingsFunc_iconDatabasePath, METH_NOARGS|METH_STATIC},
    {"iconForUrl", (PyCFunction)Sbk_QWebSettingsFunc_iconForUrl, METH_O|METH_STATIC},
    {"localStoragePath", (PyCFunction)Sbk_QWebSettingsFunc_localStoragePath, METH_NOARGS},
    {"maximumPagesInCache", (PyCFunction)Sbk_QWebSettingsFunc_maximumPagesInCache, METH_NOARGS|METH_STATIC},
    {"offlineStorageDefaultQuota", (PyCFunction)Sbk_QWebSettingsFunc_offlineStorageDefaultQuota, METH_NOARGS|METH_STATIC},
    {"offlineStoragePath", (PyCFunction)Sbk_QWebSettingsFunc_offlineStoragePath, METH_NOARGS|METH_STATIC},
    {"offlineWebApplicationCachePath", (PyCFunction)Sbk_QWebSettingsFunc_offlineWebApplicationCachePath, METH_NOARGS|METH_STATIC},
    {"offlineWebApplicationCacheQuota", (PyCFunction)Sbk_QWebSettingsFunc_offlineWebApplicationCacheQuota, METH_NOARGS|METH_STATIC},
    {"resetAttribute", (PyCFunction)Sbk_QWebSettingsFunc_resetAttribute, METH_O},
    {"resetFontFamily", (PyCFunction)Sbk_QWebSettingsFunc_resetFontFamily, METH_O},
    {"resetFontSize", (PyCFunction)Sbk_QWebSettingsFunc_resetFontSize, METH_O},
    {"setAttribute", (PyCFunction)Sbk_QWebSettingsFunc_setAttribute, METH_VARARGS},
    {"setDefaultTextEncoding", (PyCFunction)Sbk_QWebSettingsFunc_setDefaultTextEncoding, METH_O},
    {"setFontFamily", (PyCFunction)Sbk_QWebSettingsFunc_setFontFamily, METH_VARARGS},
    {"setFontSize", (PyCFunction)Sbk_QWebSettingsFunc_setFontSize, METH_VARARGS},
    {"setIconDatabasePath", (PyCFunction)Sbk_QWebSettingsFunc_setIconDatabasePath, METH_O|METH_STATIC},
    {"setLocalStoragePath", (PyCFunction)Sbk_QWebSettingsFunc_setLocalStoragePath, METH_O},
    {"setMaximumPagesInCache", (PyCFunction)Sbk_QWebSettingsFunc_setMaximumPagesInCache, METH_O|METH_STATIC},
    {"setObjectCacheCapacities", (PyCFunction)Sbk_QWebSettingsFunc_setObjectCacheCapacities, METH_VARARGS|METH_STATIC},
    {"setOfflineStorageDefaultQuota", (PyCFunction)Sbk_QWebSettingsFunc_setOfflineStorageDefaultQuota, METH_O|METH_STATIC},
    {"setOfflineStoragePath", (PyCFunction)Sbk_QWebSettingsFunc_setOfflineStoragePath, METH_O|METH_STATIC},
    {"setOfflineWebApplicationCachePath", (PyCFunction)Sbk_QWebSettingsFunc_setOfflineWebApplicationCachePath, METH_O|METH_STATIC},
    {"setOfflineWebApplicationCacheQuota", (PyCFunction)Sbk_QWebSettingsFunc_setOfflineWebApplicationCacheQuota, METH_O|METH_STATIC},
    {"setUserStyleSheetUrl", (PyCFunction)Sbk_QWebSettingsFunc_setUserStyleSheetUrl, METH_O},
    {"setWebGraphic", (PyCFunction)Sbk_QWebSettingsFunc_setWebGraphic, METH_VARARGS|METH_STATIC},
    {"testAttribute", (PyCFunction)Sbk_QWebSettingsFunc_testAttribute, METH_O},
    {"userStyleSheetUrl", (PyCFunction)Sbk_QWebSettingsFunc_userStyleSheetUrl, METH_NOARGS},
    {"webGraphic", (PyCFunction)Sbk_QWebSettingsFunc_webGraphic, METH_O|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWebSettings_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebSettings_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebSettings_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebSettings",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          SbkDeallocWrapperWithPrivateDtor,
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
    /*tp_traverse*/         Sbk_QWebSettings_traverse,
    /*tp_clear*/            Sbk_QWebSettings_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebSettings_methods,
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
static void QWebSettings_FontFamily_PythonToCpp_QWebSettings_FontFamily(PyObject* pyIn, void* cppOut) {
    *((::QWebSettings::FontFamily*)cppOut) = (::QWebSettings::FontFamily) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebSettings_FontFamily_PythonToCpp_QWebSettings_FontFamily_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX]))
        return QWebSettings_FontFamily_PythonToCpp_QWebSettings_FontFamily;
    return 0;
}
static PyObject* QWebSettings_FontFamily_CppToPython_QWebSettings_FontFamily(const void* cppIn) {
    int castCppIn = *((::QWebSettings::FontFamily*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX], castCppIn);

}

static void QWebSettings_WebAttribute_PythonToCpp_QWebSettings_WebAttribute(PyObject* pyIn, void* cppOut) {
    *((::QWebSettings::WebAttribute*)cppOut) = (::QWebSettings::WebAttribute) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebSettings_WebAttribute_PythonToCpp_QWebSettings_WebAttribute_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX]))
        return QWebSettings_WebAttribute_PythonToCpp_QWebSettings_WebAttribute;
    return 0;
}
static PyObject* QWebSettings_WebAttribute_CppToPython_QWebSettings_WebAttribute(const void* cppIn) {
    int castCppIn = *((::QWebSettings::WebAttribute*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX], castCppIn);

}

static void QWebSettings_WebGraphic_PythonToCpp_QWebSettings_WebGraphic(PyObject* pyIn, void* cppOut) {
    *((::QWebSettings::WebGraphic*)cppOut) = (::QWebSettings::WebGraphic) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebSettings_WebGraphic_PythonToCpp_QWebSettings_WebGraphic_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX]))
        return QWebSettings_WebGraphic_PythonToCpp_QWebSettings_WebGraphic;
    return 0;
}
static PyObject* QWebSettings_WebGraphic_CppToPython_QWebSettings_WebGraphic(const void* cppIn) {
    int castCppIn = *((::QWebSettings::WebGraphic*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX], castCppIn);

}

static void QWebSettings_FontSize_PythonToCpp_QWebSettings_FontSize(PyObject* pyIn, void* cppOut) {
    *((::QWebSettings::FontSize*)cppOut) = (::QWebSettings::FontSize) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebSettings_FontSize_PythonToCpp_QWebSettings_FontSize_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX]))
        return QWebSettings_FontSize_PythonToCpp_QWebSettings_FontSize;
    return 0;
}
static PyObject* QWebSettings_FontSize_CppToPython_QWebSettings_FontSize(const void* cppIn) {
    int castCppIn = *((::QWebSettings::FontSize*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWebSettings_PythonToCpp_QWebSettings_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebSettings_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebSettings_PythonToCpp_QWebSettings_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebSettings_Type))
        return QWebSettings_PythonToCpp_QWebSettings_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebSettings_PTR_CppToPython_QWebSettings(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebSettings*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebSettings_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QWebSettings(PyObject* module)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebSettings_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebSettings", "QWebSettings*",
        &Sbk_QWebSettings_Type)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebSettings_Type,
        QWebSettings_PythonToCpp_QWebSettings_PTR,
        is_QWebSettings_PythonToCpp_QWebSettings_PTR_Convertible,
        QWebSettings_PTR_CppToPython_QWebSettings);

    Shiboken::Conversions::registerConverterName(converter, "QWebSettings");
    Shiboken::Conversions::registerConverterName(converter, "QWebSettings*");
    Shiboken::Conversions::registerConverterName(converter, "QWebSettings&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebSettings).name());


    // Initialization of enums.

    // Initialization of enum 'FontFamily'.
    SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebSettings_Type,
        "FontFamily",
        "PySide.QtWebKit.QWebSettings.FontFamily",
        "QWebSettings::FontFamily");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
        &Sbk_QWebSettings_Type, "StandardFont", (long) QWebSettings::StandardFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
        &Sbk_QWebSettings_Type, "FixedFont", (long) QWebSettings::FixedFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
        &Sbk_QWebSettings_Type, "SerifFont", (long) QWebSettings::SerifFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
        &Sbk_QWebSettings_Type, "SansSerifFont", (long) QWebSettings::SansSerifFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
        &Sbk_QWebSettings_Type, "CursiveFont", (long) QWebSettings::CursiveFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
        &Sbk_QWebSettings_Type, "FantasyFont", (long) QWebSettings::FantasyFont))
        return ;
    // Register converter for enum 'QWebSettings::FontFamily'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX],
            QWebSettings_FontFamily_CppToPython_QWebSettings_FontFamily);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebSettings_FontFamily_PythonToCpp_QWebSettings_FontFamily,
            is_QWebSettings_FontFamily_PythonToCpp_QWebSettings_FontFamily_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTFAMILY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebSettings::FontFamily");
        Shiboken::Conversions::registerConverterName(converter, "FontFamily");
    }
    // End of 'FontFamily' enum.

    // Initialization of enum 'WebAttribute'.
    SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebSettings_Type,
        "WebAttribute",
        "PySide.QtWebKit.QWebSettings.WebAttribute",
        "QWebSettings::WebAttribute");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "AutoLoadImages", (long) QWebSettings::AutoLoadImages))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "JavascriptEnabled", (long) QWebSettings::JavascriptEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "JavaEnabled", (long) QWebSettings::JavaEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "PluginsEnabled", (long) QWebSettings::PluginsEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "PrivateBrowsingEnabled", (long) QWebSettings::PrivateBrowsingEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "JavascriptCanOpenWindows", (long) QWebSettings::JavascriptCanOpenWindows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "JavascriptCanAccessClipboard", (long) QWebSettings::JavascriptCanAccessClipboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "DeveloperExtrasEnabled", (long) QWebSettings::DeveloperExtrasEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "LinksIncludedInFocusChain", (long) QWebSettings::LinksIncludedInFocusChain))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "ZoomTextOnly", (long) QWebSettings::ZoomTextOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "PrintElementBackgrounds", (long) QWebSettings::PrintElementBackgrounds))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "OfflineStorageDatabaseEnabled", (long) QWebSettings::OfflineStorageDatabaseEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "OfflineWebApplicationCacheEnabled", (long) QWebSettings::OfflineWebApplicationCacheEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "LocalStorageEnabled", (long) QWebSettings::LocalStorageEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "LocalStorageDatabaseEnabled", (long) QWebSettings::LocalStorageDatabaseEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "LocalContentCanAccessRemoteUrls", (long) QWebSettings::LocalContentCanAccessRemoteUrls))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "DnsPrefetchEnabled", (long) QWebSettings::DnsPrefetchEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "XSSAuditingEnabled", (long) QWebSettings::XSSAuditingEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "AcceleratedCompositingEnabled", (long) QWebSettings::AcceleratedCompositingEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "SpatialNavigationEnabled", (long) QWebSettings::SpatialNavigationEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "LocalContentCanAccessFileUrls", (long) QWebSettings::LocalContentCanAccessFileUrls))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "TiledBackingStoreEnabled", (long) QWebSettings::TiledBackingStoreEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "FrameFlatteningEnabled", (long) QWebSettings::FrameFlatteningEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "SiteSpecificQuirksEnabled", (long) QWebSettings::SiteSpecificQuirksEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "JavascriptCanCloseWindows", (long) QWebSettings::JavascriptCanCloseWindows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "WebGLEnabled", (long) QWebSettings::WebGLEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "CSSRegionsEnabled", (long) QWebSettings::CSSRegionsEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "HyperlinkAuditingEnabled", (long) QWebSettings::HyperlinkAuditingEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "CSSGridLayoutEnabled", (long) QWebSettings::CSSGridLayoutEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "ScrollAnimatorEnabled", (long) QWebSettings::ScrollAnimatorEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "CaretBrowsingEnabled", (long) QWebSettings::CaretBrowsingEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
        &Sbk_QWebSettings_Type, "NotificationsEnabled", (long) QWebSettings::NotificationsEnabled))
        return ;
    // Register converter for enum 'QWebSettings::WebAttribute'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX],
            QWebSettings_WebAttribute_CppToPython_QWebSettings_WebAttribute);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebSettings_WebAttribute_PythonToCpp_QWebSettings_WebAttribute,
            is_QWebSettings_WebAttribute_PythonToCpp_QWebSettings_WebAttribute_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBATTRIBUTE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebSettings::WebAttribute");
        Shiboken::Conversions::registerConverterName(converter, "WebAttribute");
    }
    // End of 'WebAttribute' enum.

    // Initialization of enum 'WebGraphic'.
    SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebSettings_Type,
        "WebGraphic",
        "PySide.QtWebKit.QWebSettings.WebGraphic",
        "QWebSettings::WebGraphic");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "MissingImageGraphic", (long) QWebSettings::MissingImageGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "MissingPluginGraphic", (long) QWebSettings::MissingPluginGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "DefaultFrameIconGraphic", (long) QWebSettings::DefaultFrameIconGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "TextAreaSizeGripCornerGraphic", (long) QWebSettings::TextAreaSizeGripCornerGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "DeleteButtonGraphic", (long) QWebSettings::DeleteButtonGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "InputSpeechButtonGraphic", (long) QWebSettings::InputSpeechButtonGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "SearchCancelButtonGraphic", (long) QWebSettings::SearchCancelButtonGraphic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
        &Sbk_QWebSettings_Type, "SearchCancelButtonPressedGraphic", (long) QWebSettings::SearchCancelButtonPressedGraphic))
        return ;
    // Register converter for enum 'QWebSettings::WebGraphic'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX],
            QWebSettings_WebGraphic_CppToPython_QWebSettings_WebGraphic);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebSettings_WebGraphic_PythonToCpp_QWebSettings_WebGraphic,
            is_QWebSettings_WebGraphic_PythonToCpp_QWebSettings_WebGraphic_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_WEBGRAPHIC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebSettings::WebGraphic");
        Shiboken::Conversions::registerConverterName(converter, "WebGraphic");
    }
    // End of 'WebGraphic' enum.

    // Initialization of enum 'FontSize'.
    SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebSettings_Type,
        "FontSize",
        "PySide.QtWebKit.QWebSettings.FontSize",
        "QWebSettings::FontSize");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX],
        &Sbk_QWebSettings_Type, "MinimumFontSize", (long) QWebSettings::MinimumFontSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX],
        &Sbk_QWebSettings_Type, "MinimumLogicalFontSize", (long) QWebSettings::MinimumLogicalFontSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX],
        &Sbk_QWebSettings_Type, "DefaultFontSize", (long) QWebSettings::DefaultFontSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX],
        &Sbk_QWebSettings_Type, "DefaultFixedFontSize", (long) QWebSettings::DefaultFixedFontSize))
        return ;
    // Register converter for enum 'QWebSettings::FontSize'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX],
            QWebSettings_FontSize_CppToPython_QWebSettings_FontSize);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebSettings_FontSize_PythonToCpp_QWebSettings_FontSize,
            is_QWebSettings_FontSize_PythonToCpp_QWebSettings_FontSize_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_FONTSIZE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebSettings::FontSize");
        Shiboken::Conversions::registerConverterName(converter, "FontSize");
    }
    // End of 'FontSize' enum.


    qRegisterMetaType< ::QWebSettings::FontFamily >("QWebSettings::FontFamily");
    qRegisterMetaType< ::QWebSettings::WebAttribute >("QWebSettings::WebAttribute");
    qRegisterMetaType< ::QWebSettings::WebGraphic >("QWebSettings::WebGraphic");
    qRegisterMetaType< ::QWebSettings::FontSize >("QWebSettings::FontSize");
}
