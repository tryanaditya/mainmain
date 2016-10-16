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
#include "pyside_qtnetwork_python.h"

#include "qurlinfo_wrapper.h"

// Extra includes
#include <qdatetime.h>
#include <qurl.h>
#include <qurlinfo.h>


// Native ---------------------------------------------------------

QUrlInfoWrapper::QUrlInfoWrapper() : QUrlInfo() {
    // ... middle
}

QUrlInfoWrapper::QUrlInfoWrapper(const QString & name, int permissions, const QString & owner, const QString & group, qint64 size, const QDateTime & lastModified, const QDateTime & lastRead, bool isDir, bool isFile, bool isSymLink, bool isWritable, bool isReadable, bool isExecutable) : QUrlInfo(name, permissions, owner, group, size, lastModified, lastRead, isDir, isFile, isSymLink, isWritable, isReadable, isExecutable) {
    // ... middle
}

QUrlInfoWrapper::QUrlInfoWrapper(const QUrl & url, int permissions, const QString & owner, const QString & group, qint64 size, const QDateTime & lastModified, const QDateTime & lastRead, bool isDir, bool isFile, bool isSymLink, bool isWritable, bool isReadable, bool isExecutable) : QUrlInfo(url, permissions, owner, group, size, lastModified, lastRead, isDir, isFile, isSymLink, isWritable, isReadable, isExecutable) {
    // ... middle
}

void QUrlInfoWrapper::setDir(bool b)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setDir"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setDir(b);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &b)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setFile(bool b)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setFile"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setFile(b);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &b)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setGroup(const QString & s)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGroup"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setGroup(s);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &s)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setLastModified(const QDateTime & dt)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setLastModified"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setLastModified(dt);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &dt)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setName(const QString & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setName"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setName(name);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setOwner(const QString & s)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setOwner"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setOwner(s);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &s)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setPermissions(int p)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setPermissions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setPermissions(p);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        p
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setReadable(bool b)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setReadable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setReadable(b);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &b)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setSize(qint64 size)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setSize(size);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        size
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setSymLink(bool b)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSymLink"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setSymLink(b);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &b)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QUrlInfoWrapper::setWritable(bool b)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setWritable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QUrlInfo::setWritable(b);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &b)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QUrlInfoWrapper::~QUrlInfoWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QUrlInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QUrlInfo >()))
        return -1;

    ::QUrlInfoWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3 || numArgs == 4 || numArgs == 5 || numArgs == 6 || numArgs == 7 || numArgs == 8 || numArgs == 9 || numArgs == 10 || numArgs == 11 || numArgs == 12)
        goto Sbk_QUrlInfo_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QUrlInfo", 0, 13, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9]), &(pyArgs[10]), &(pyArgs[11]), &(pyArgs[12])))
        return -1;


    // Overloaded function decisor
    // 0: QUrlInfo()
    // 1: QUrlInfo(QString,int,QString,QString,qint64,QDateTime,QDateTime,bool,bool,bool,bool,bool,bool)
    // 2: QUrlInfo(QUrl,int,QString,QString,qint64,QDateTime,QDateTime,bool,bool,bool,bool,bool,bool)
    // 3: QUrlInfo(QUrlInfo)
    if (numArgs == 0) {
        overloadId = 0; // QUrlInfo()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[0])))) {
        overloadId = 3; // QUrlInfo(QUrlInfo)
    } else if (numArgs == 13
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[8])))
        && (pythonToCpp[9] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[9])))
        && (pythonToCpp[10] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[10])))
        && (pythonToCpp[11] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[11])))
        && (pythonToCpp[12] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[12])))) {
        overloadId = 1; // QUrlInfo(QString,int,QString,QString,qint64,QDateTime,QDateTime,bool,bool,bool,bool,bool,bool)
    } else if (numArgs == 13
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[8])))
        && (pythonToCpp[9] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[9])))
        && (pythonToCpp[10] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[10])))
        && (pythonToCpp[11] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[11])))
        && (pythonToCpp[12] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[12])))) {
        overloadId = 2; // QUrlInfo(QUrl,int,QString,QString,qint64,QDateTime,QDateTime,bool,bool,bool,bool,bool,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfo_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QUrlInfo()
        {

            if (!PyErr_Occurred()) {
                // QUrlInfo()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrlInfoWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QUrlInfo(const QString & name, int permissions, const QString & owner, const QString & group, qint64 size, const QDateTime & lastModified, const QDateTime & lastRead, bool isDir, bool isFile, bool isSymLink, bool isWritable, bool isReadable, bool isExecutable)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = ::QString();
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qint64 cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return -1;
            ::QDateTime cppArg5_local = ::QDateTime();
            ::QDateTime* cppArg5 = &cppArg5_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[5]))
                pythonToCpp[5](pyArgs[5], &cppArg5_local);
            else
                pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!Shiboken::Object::isValid(pyArgs[6]))
                return -1;
            ::QDateTime cppArg6_local = ::QDateTime();
            ::QDateTime* cppArg6 = &cppArg6_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[6]))
                pythonToCpp[6](pyArgs[6], &cppArg6_local);
            else
                pythonToCpp[6](pyArgs[6], &cppArg6);

            bool cppArg7;
            pythonToCpp[7](pyArgs[7], &cppArg7);
            bool cppArg8;
            pythonToCpp[8](pyArgs[8], &cppArg8);
            bool cppArg9;
            pythonToCpp[9](pyArgs[9], &cppArg9);
            bool cppArg10;
            pythonToCpp[10](pyArgs[10], &cppArg10);
            bool cppArg11;
            pythonToCpp[11](pyArgs[11], &cppArg11);
            bool cppArg12;
            pythonToCpp[12](pyArgs[12], &cppArg12);

            if (!PyErr_Occurred()) {
                // QUrlInfo(QString,int,QString,QString,qint64,QDateTime,QDateTime,bool,bool,bool,bool,bool,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrlInfoWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, *cppArg5, *cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QUrlInfo(const QUrl & url, int permissions, const QString & owner, const QString & group, qint64 size, const QDateTime & lastModified, const QDateTime & lastRead, bool isDir, bool isFile, bool isSymLink, bool isWritable, bool isReadable, bool isExecutable)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = ::QString();
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qint64 cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return -1;
            ::QDateTime cppArg5_local = ::QDateTime();
            ::QDateTime* cppArg5 = &cppArg5_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[5]))
                pythonToCpp[5](pyArgs[5], &cppArg5_local);
            else
                pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!Shiboken::Object::isValid(pyArgs[6]))
                return -1;
            ::QDateTime cppArg6_local = ::QDateTime();
            ::QDateTime* cppArg6 = &cppArg6_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[6]))
                pythonToCpp[6](pyArgs[6], &cppArg6_local);
            else
                pythonToCpp[6](pyArgs[6], &cppArg6);

            bool cppArg7;
            pythonToCpp[7](pyArgs[7], &cppArg7);
            bool cppArg8;
            pythonToCpp[8](pyArgs[8], &cppArg8);
            bool cppArg9;
            pythonToCpp[9](pyArgs[9], &cppArg9);
            bool cppArg10;
            pythonToCpp[10](pyArgs[10], &cppArg10);
            bool cppArg11;
            pythonToCpp[11](pyArgs[11], &cppArg11);
            bool cppArg12;
            pythonToCpp[12](pyArgs[12], &cppArg12);

            if (!PyErr_Occurred()) {
                // QUrlInfo(QUrl,int,QString,QString,qint64,QDateTime,QDateTime,bool,bool,bool,bool,bool,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrlInfoWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, *cppArg5, *cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QUrlInfo(const QUrlInfo & ui)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrlInfo cppArg0_local = ::QUrlInfo();
            ::QUrlInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QUrlInfo(QUrlInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrlInfoWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QUrlInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QUrlInfo_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QUrlInfo_Init_TypeError:
        const char* overloads[] = {"", "unicode, int, unicode, unicode, long long, PySide.QtCore.QDateTime, PySide.QtCore.QDateTime, bool, bool, bool, bool, bool, bool", "PySide.QtCore.QUrl, int, unicode, unicode, long long, PySide.QtCore.QDateTime, PySide.QtCore.QDateTime, bool, bool, bool, bool, bool, bool", "PySide.QtNetwork.QUrlInfo", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QUrlInfo", overloads);
        return -1;
}

static PyObject* Sbk_QUrlInfoFunc_equal(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "equal", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: equal(QUrlInfo,QUrlInfo,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // equal(QUrlInfo,QUrlInfo,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_equal_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QUrlInfo cppArg0_local = ::QUrlInfo();
        ::QUrlInfo* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrlInfo cppArg1_local = ::QUrlInfo();
        ::QUrlInfo* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // equal(QUrlInfo,QUrlInfo,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QUrlInfo::equal(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlInfoFunc_equal_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QUrlInfo, PySide.QtNetwork.QUrlInfo, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QUrlInfo.equal", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_greaterThan(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "greaterThan", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: greaterThan(QUrlInfo,QUrlInfo,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // greaterThan(QUrlInfo,QUrlInfo,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_greaterThan_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QUrlInfo cppArg0_local = ::QUrlInfo();
        ::QUrlInfo* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrlInfo cppArg1_local = ::QUrlInfo();
        ::QUrlInfo* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // greaterThan(QUrlInfo,QUrlInfo,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QUrlInfo::greaterThan(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlInfoFunc_greaterThan_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QUrlInfo, PySide.QtNetwork.QUrlInfo, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QUrlInfo.greaterThan", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_group(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // group()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->group();
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

static PyObject* Sbk_QUrlInfoFunc_isDir(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDir()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isDir();
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

static PyObject* Sbk_QUrlInfoFunc_isExecutable(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isExecutable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isExecutable();
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

static PyObject* Sbk_QUrlInfoFunc_isFile(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFile()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isFile();
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

static PyObject* Sbk_QUrlInfoFunc_isReadable(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isReadable();
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

static PyObject* Sbk_QUrlInfoFunc_isSymLink(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSymLink()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isSymLink();
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

static PyObject* Sbk_QUrlInfoFunc_isValid(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isValid();
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

static PyObject* Sbk_QUrlInfoFunc_isWritable(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWritable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->isWritable();
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

static PyObject* Sbk_QUrlInfoFunc_lastModified(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastModified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->lastModified();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlInfoFunc_lastRead(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastRead()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->lastRead();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlInfoFunc_lessThan(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "lessThan", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: lessThan(QUrlInfo,QUrlInfo,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // lessThan(QUrlInfo,QUrlInfo,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_lessThan_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QUrlInfo cppArg0_local = ::QUrlInfo();
        ::QUrlInfo* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrlInfo cppArg1_local = ::QUrlInfo();
        ::QUrlInfo* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // lessThan(QUrlInfo,QUrlInfo,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QUrlInfo::lessThan(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlInfoFunc_lessThan_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QUrlInfo, PySide.QtNetwork.QUrlInfo, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QUrlInfo.lessThan", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_name(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->name();
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

static PyObject* Sbk_QUrlInfoFunc_owner(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // owner()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->owner();
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

static PyObject* Sbk_QUrlInfoFunc_permissions(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // permissions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->permissions();
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

static PyObject* Sbk_QUrlInfoFunc_setDir(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDir(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDir(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setDir_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDir(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setDir(cppArg0) : cppSelf->setDir(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setDir_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setDir", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setFile(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFile(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFile(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setFile_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFile(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setFile(cppArg0) : cppSelf->setFile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setFile_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setFile", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setGroup(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGroup(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setGroup(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setGroup_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGroup(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setGroup(cppArg0) : cppSelf->setGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setGroup_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setGroup", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setLastModified(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastModified(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setLastModified(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setLastModified_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setLastModified(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setLastModified(*cppArg0) : cppSelf->setLastModified(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setLastModified_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setLastModified", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setLastRead(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastRead(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setLastRead(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setLastRead_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setLastRead(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastRead(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setLastRead_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setLastRead", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setName(cppArg0) : cppSelf->setName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setName", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setOwner(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOwner(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOwner(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setOwner_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOwner(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setOwner(cppArg0) : cppSelf->setOwner(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setOwner_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setOwner", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setPermissions(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPermissions(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPermissions(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setPermissions_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPermissions(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setPermissions(cppArg0) : cppSelf->setPermissions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setPermissions_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setPermissions", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setReadable(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setReadable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setReadable(cppArg0) : cppSelf->setReadable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setReadable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setReadable", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setSize(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSize(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setSize(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setSize_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSize(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setSize(cppArg0) : cppSelf->setSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setSize_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setSize", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setSymLink(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSymLink(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSymLink(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setSymLink_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSymLink(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setSymLink(cppArg0) : cppSelf->setSymLink(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setSymLink_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setSymLink", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_setWritable(PyObject* self, PyObject* pyArg)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWritable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setWritable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlInfoFunc_setWritable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWritable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QUrlInfo::setWritable(cppArg0) : cppSelf->setWritable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlInfoFunc_setWritable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QUrlInfo.setWritable", overloads);
        return 0;
}

static PyObject* Sbk_QUrlInfoFunc_size(PyObject* self)
{
    ::QUrlInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QUrlInfo*>(cppSelf)->size();
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

static PyObject* Sbk_QUrlInfo___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QUrlInfo& cppSelf = *(((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QUrlInfo_methods[] = {
    {"equal", (PyCFunction)Sbk_QUrlInfoFunc_equal, METH_VARARGS|METH_STATIC},
    {"greaterThan", (PyCFunction)Sbk_QUrlInfoFunc_greaterThan, METH_VARARGS|METH_STATIC},
    {"group", (PyCFunction)Sbk_QUrlInfoFunc_group, METH_NOARGS},
    {"isDir", (PyCFunction)Sbk_QUrlInfoFunc_isDir, METH_NOARGS},
    {"isExecutable", (PyCFunction)Sbk_QUrlInfoFunc_isExecutable, METH_NOARGS},
    {"isFile", (PyCFunction)Sbk_QUrlInfoFunc_isFile, METH_NOARGS},
    {"isReadable", (PyCFunction)Sbk_QUrlInfoFunc_isReadable, METH_NOARGS},
    {"isSymLink", (PyCFunction)Sbk_QUrlInfoFunc_isSymLink, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QUrlInfoFunc_isValid, METH_NOARGS},
    {"isWritable", (PyCFunction)Sbk_QUrlInfoFunc_isWritable, METH_NOARGS},
    {"lastModified", (PyCFunction)Sbk_QUrlInfoFunc_lastModified, METH_NOARGS},
    {"lastRead", (PyCFunction)Sbk_QUrlInfoFunc_lastRead, METH_NOARGS},
    {"lessThan", (PyCFunction)Sbk_QUrlInfoFunc_lessThan, METH_VARARGS|METH_STATIC},
    {"name", (PyCFunction)Sbk_QUrlInfoFunc_name, METH_NOARGS},
    {"owner", (PyCFunction)Sbk_QUrlInfoFunc_owner, METH_NOARGS},
    {"permissions", (PyCFunction)Sbk_QUrlInfoFunc_permissions, METH_NOARGS},
    {"setDir", (PyCFunction)Sbk_QUrlInfoFunc_setDir, METH_O},
    {"setFile", (PyCFunction)Sbk_QUrlInfoFunc_setFile, METH_O},
    {"setGroup", (PyCFunction)Sbk_QUrlInfoFunc_setGroup, METH_O},
    {"setLastModified", (PyCFunction)Sbk_QUrlInfoFunc_setLastModified, METH_O},
    {"setLastRead", (PyCFunction)Sbk_QUrlInfoFunc_setLastRead, METH_O},
    {"setName", (PyCFunction)Sbk_QUrlInfoFunc_setName, METH_O},
    {"setOwner", (PyCFunction)Sbk_QUrlInfoFunc_setOwner, METH_O},
    {"setPermissions", (PyCFunction)Sbk_QUrlInfoFunc_setPermissions, METH_O},
    {"setReadable", (PyCFunction)Sbk_QUrlInfoFunc_setReadable, METH_O},
    {"setSize", (PyCFunction)Sbk_QUrlInfoFunc_setSize, METH_O},
    {"setSymLink", (PyCFunction)Sbk_QUrlInfoFunc_setSymLink, METH_O},
    {"setWritable", (PyCFunction)Sbk_QUrlInfoFunc_setWritable, METH_O},
    {"size", (PyCFunction)Sbk_QUrlInfoFunc_size, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QUrlInfo___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QUrlInfo_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QUrlInfo& cppSelf = *(((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArg)))) {
                // operator!=(const QUrlInfo & i) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUrlInfo cppArg0_local = ::QUrlInfo();
                ::QUrlInfo* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (pyArg)))) {
                // operator==(const QUrlInfo & i) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUrlInfo cppArg0_local = ::QUrlInfo();
                ::QUrlInfo* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], pythonToCpp))
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
            goto Sbk_QUrlInfo_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QUrlInfo_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QUrlInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QUrlInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QUrlInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QUrlInfo",
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
    /*tp_traverse*/         Sbk_QUrlInfo_traverse,
    /*tp_clear*/            Sbk_QUrlInfo_clear,
    /*tp_richcompare*/      Sbk_QUrlInfo_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QUrlInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QUrlInfo_Init,
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
static void QUrlInfo_PermissionSpec_PythonToCpp_QUrlInfo_PermissionSpec(PyObject* pyIn, void* cppOut) {
    *((::QUrlInfo::PermissionSpec*)cppOut) = (::QUrlInfo::PermissionSpec) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QUrlInfo_PermissionSpec_PythonToCpp_QUrlInfo_PermissionSpec_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX]))
        return QUrlInfo_PermissionSpec_PythonToCpp_QUrlInfo_PermissionSpec;
    return 0;
}
static PyObject* QUrlInfo_PermissionSpec_CppToPython_QUrlInfo_PermissionSpec(const void* cppIn) {
    int castCppIn = *((::QUrlInfo::PermissionSpec*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QUrlInfo_PythonToCpp_QUrlInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QUrlInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QUrlInfo_PythonToCpp_QUrlInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QUrlInfo_Type))
        return QUrlInfo_PythonToCpp_QUrlInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QUrlInfo_PTR_CppToPython_QUrlInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QUrlInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QUrlInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QUrlInfo_COPY_CppToPython_QUrlInfo(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QUrlInfo_Type, new ::QUrlInfoWrapper(*((::QUrlInfo*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QUrlInfo_PythonToCpp_QUrlInfo_COPY(PyObject* pyIn, void* cppOut) {
    *((::QUrlInfo*)cppOut) = *((::QUrlInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QUrlInfo_PythonToCpp_QUrlInfo_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QUrlInfo_Type))
        return QUrlInfo_PythonToCpp_QUrlInfo_COPY;
    return 0;
}

void init_QUrlInfo(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QURLINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QUrlInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QUrlInfo", "QUrlInfo",
        &Sbk_QUrlInfo_Type, &Shiboken::callCppDestructor< ::QUrlInfoWrapper >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QUrlInfo_Type,
        QUrlInfo_PythonToCpp_QUrlInfo_PTR,
        is_QUrlInfo_PythonToCpp_QUrlInfo_PTR_Convertible,
        QUrlInfo_PTR_CppToPython_QUrlInfo,
        QUrlInfo_COPY_CppToPython_QUrlInfo);

    Shiboken::Conversions::registerConverterName(converter, "QUrlInfo");
    Shiboken::Conversions::registerConverterName(converter, "QUrlInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QUrlInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QUrlInfo).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QUrlInfoWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QUrlInfo_PythonToCpp_QUrlInfo_COPY,
        is_QUrlInfo_PythonToCpp_QUrlInfo_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'PermissionSpec'.
    SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QUrlInfo_Type,
        "PermissionSpec",
        "PySide.QtNetwork.QUrlInfo.PermissionSpec",
        "QUrlInfo::PermissionSpec");
    if (!SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "ReadOwner", (long) QUrlInfo::ReadOwner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "WriteOwner", (long) QUrlInfo::WriteOwner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "ExeOwner", (long) QUrlInfo::ExeOwner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "ReadGroup", (long) QUrlInfo::ReadGroup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "WriteGroup", (long) QUrlInfo::WriteGroup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "ExeGroup", (long) QUrlInfo::ExeGroup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "ReadOther", (long) QUrlInfo::ReadOther))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "WriteOther", (long) QUrlInfo::WriteOther))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
        &Sbk_QUrlInfo_Type, "ExeOther", (long) QUrlInfo::ExeOther))
        return ;
    // Register converter for enum 'QUrlInfo::PermissionSpec'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX],
            QUrlInfo_PermissionSpec_CppToPython_QUrlInfo_PermissionSpec);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QUrlInfo_PermissionSpec_PythonToCpp_QUrlInfo_PermissionSpec,
            is_QUrlInfo_PermissionSpec_PythonToCpp_QUrlInfo_PermissionSpec_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QURLINFO_PERMISSIONSPEC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QUrlInfo::PermissionSpec");
        Shiboken::Conversions::registerConverterName(converter, "PermissionSpec");
    }
    // End of 'PermissionSpec' enum.


    qRegisterMetaType< ::QUrlInfo >("QUrlInfo");
    qRegisterMetaType< ::QUrlInfo::PermissionSpec >("QUrlInfo::PermissionSpec");
}
