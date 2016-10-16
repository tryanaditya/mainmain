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

#include "qmetamethod_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qobject.h>
#include <qobjectdefs.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMetaMethod_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMetaMethod >()))
        return -1;

    ::QMetaMethod* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMetaMethod", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QMetaMethod()
    // 1: QMetaMethod(QMetaMethod)
    if (numArgs == 0) {
        overloadId = 0; // QMetaMethod()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (pyArgs[0])))) {
        overloadId = 1; // QMetaMethod(QMetaMethod)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaMethod_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMetaMethod()
        {

            if (!PyErr_Occurred()) {
                // QMetaMethod()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMetaMethod();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QMetaMethod(const QMetaMethod & QMetaMethod)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QMetaMethod cppArg0_local = ::QMetaMethod();
            ::QMetaMethod* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMetaMethod(QMetaMethod)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMetaMethod(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMetaMethod >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMetaMethod_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMetaMethod_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QMetaMethod", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaMethod", overloads);
        return -1;
}

static PyObject* Sbk_QMetaMethodFunc_access(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // access()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaMethod::Access cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->access();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaMethodFunc_enclosingMetaObject(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // enclosingMetaObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMetaObject * cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->enclosingMetaObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaMethodFunc_invoke(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 13) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOOOOOOO:invoke", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9]), &(pyArgs[10]), &(pyArgs[11]), &(pyArgs[12])))
        return 0;


    // Overloaded function decisor
    // 0: invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
    // 1: invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
    // 2: invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
    // 3: invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                            if (numArgs == 6) {
                                overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                                if (numArgs == 7) {
                                    overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                    if (numArgs == 8) {
                                        overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                    } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                        if (numArgs == 9) {
                                            overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                        } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                            if (numArgs == 10) {
                                                overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                            } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                                if (numArgs == 11) {
                                                    overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                    if (numArgs == 12) {
                                                        overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                    } else if ((pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12])))) {
                                                        overloadId = 3; // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                            if (numArgs == 6) {
                                overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                                if (numArgs == 7) {
                                    overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                    if (numArgs == 8) {
                                        overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                    } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                        if (numArgs == 9) {
                                            overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                        } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                            if (numArgs == 10) {
                                                overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                            } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                                if (numArgs == 11) {
                                                    overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                    overloadId = 2; // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                            if (numArgs == 6) {
                                overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                                if (numArgs == 7) {
                                    overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                    if (numArgs == 8) {
                                        overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                    } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                        if (numArgs == 9) {
                                            overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                        } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                            if (numArgs == 10) {
                                                overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                            } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                                if (numArgs == 11) {
                                                    overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                    overloadId = 1; // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                            if (numArgs == 6) {
                                overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                                if (numArgs == 7) {
                                    overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                    if (numArgs == 8) {
                                        overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                    } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                        if (numArgs == 9) {
                                            overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                        } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                            if (numArgs == 10) {
                                                overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                            } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                                overloadId = 0; // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaMethodFunc_invoke_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // invoke(QObject * object, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[1]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QGenericArgument cppArg1 = QGenericArgument(0);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QGenericArgument cppArg2 = QGenericArgument();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);

            if (!PyErr_Occurred()) {
                // invoke(QObject*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->invoke(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // invoke(QObject * object, QGenericReturnArgument returnValue, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QGenericReturnArgument cppArg1 = ::QGenericReturnArgument(((char*)0), ((void*)0));
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QGenericArgument cppArg2 = QGenericArgument(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);

            if (!PyErr_Occurred()) {
                // invoke(QObject*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->invoke(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // invoke(QObject * object, Qt::ConnectionType connectionType, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::ConnectionType cppArg1 = ((::Qt::ConnectionType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QGenericArgument cppArg2 = QGenericArgument(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);

            if (!PyErr_Occurred()) {
                // invoke(QObject*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->invoke(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 3: // invoke(QObject * object, Qt::ConnectionType connectionType, QGenericReturnArgument returnValue, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[12]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaMethod.invoke(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[12] = value;
                    if (!(pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12]))))
                        goto Sbk_QMetaMethodFunc_invoke_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::ConnectionType cppArg1 = ((::Qt::ConnectionType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QGenericReturnArgument cppArg2 = ::QGenericReturnArgument(((char*)0), ((void*)0));
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);
            if (!Shiboken::Object::isValid(pyArgs[12]))
                return 0;
            ::QGenericArgument cppArg12 = QGenericArgument();
            if (pythonToCpp[12]) pythonToCpp[12](pyArgs[12], &cppArg12);

            if (!PyErr_Occurred()) {
                // invoke(QObject*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->invoke(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaMethodFunc_invoke_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", "PySide.QtCore.QObject, PySide.QtCore.QGenericReturnArgument, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", "PySide.QtCore.QObject, PySide.QtCore.Qt.ConnectionType, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", "PySide.QtCore.QObject, PySide.QtCore.Qt.ConnectionType, PySide.QtCore.QGenericReturnArgument, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaMethod.invoke", overloads);
        return 0;
}

static PyObject* Sbk_QMetaMethodFunc_methodIndex(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // methodIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->methodIndex();
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

static PyObject* Sbk_QMetaMethodFunc_methodType(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // methodType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaMethod::MethodType cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->methodType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaMethodFunc_parameterNames(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parameterNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->parameterNames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaMethodFunc_parameterTypes(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parameterTypes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->parameterTypes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaMethodFunc_revision(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->revision();
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

static PyObject* Sbk_QMetaMethodFunc_signature(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // signature()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->signature();
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

static PyObject* Sbk_QMetaMethodFunc_tag(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tag()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->tag();
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

static PyObject* Sbk_QMetaMethodFunc_typeName(PyObject* self)
{
    ::QMetaMethod* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // typeName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaMethod*>(cppSelf)->typeName();
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

static PyObject* Sbk_QMetaMethod___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMetaMethod& cppSelf = *(((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMetaMethod_methods[] = {
    {"access", (PyCFunction)Sbk_QMetaMethodFunc_access, METH_NOARGS},
    {"enclosingMetaObject", (PyCFunction)Sbk_QMetaMethodFunc_enclosingMetaObject, METH_NOARGS},
    {"invoke", (PyCFunction)Sbk_QMetaMethodFunc_invoke, METH_VARARGS|METH_KEYWORDS},
    {"methodIndex", (PyCFunction)Sbk_QMetaMethodFunc_methodIndex, METH_NOARGS},
    {"methodType", (PyCFunction)Sbk_QMetaMethodFunc_methodType, METH_NOARGS},
    {"parameterNames", (PyCFunction)Sbk_QMetaMethodFunc_parameterNames, METH_NOARGS},
    {"parameterTypes", (PyCFunction)Sbk_QMetaMethodFunc_parameterTypes, METH_NOARGS},
    {"revision", (PyCFunction)Sbk_QMetaMethodFunc_revision, METH_NOARGS},
    {"signature", (PyCFunction)Sbk_QMetaMethodFunc_signature, METH_NOARGS},
    {"tag", (PyCFunction)Sbk_QMetaMethodFunc_tag, METH_NOARGS},
    {"typeName", (PyCFunction)Sbk_QMetaMethodFunc_typeName, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QMetaMethod___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMetaMethod_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMetaMethod_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMetaMethod_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QMetaMethod",
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
    /*tp_traverse*/         Sbk_QMetaMethod_traverse,
    /*tp_clear*/            Sbk_QMetaMethod_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMetaMethod_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMetaMethod_Init,
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
static void QMetaMethod_Access_PythonToCpp_QMetaMethod_Access(PyObject* pyIn, void* cppOut) {
    *((::QMetaMethod::Access*)cppOut) = (::QMetaMethod::Access) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMetaMethod_Access_PythonToCpp_QMetaMethod_Access_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX]))
        return QMetaMethod_Access_PythonToCpp_QMetaMethod_Access;
    return 0;
}
static PyObject* QMetaMethod_Access_CppToPython_QMetaMethod_Access(const void* cppIn) {
    int castCppIn = *((::QMetaMethod::Access*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX], castCppIn);

}

static void QMetaMethod_MethodType_PythonToCpp_QMetaMethod_MethodType(PyObject* pyIn, void* cppOut) {
    *((::QMetaMethod::MethodType*)cppOut) = (::QMetaMethod::MethodType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMetaMethod_MethodType_PythonToCpp_QMetaMethod_MethodType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX]))
        return QMetaMethod_MethodType_PythonToCpp_QMetaMethod_MethodType;
    return 0;
}
static PyObject* QMetaMethod_MethodType_CppToPython_QMetaMethod_MethodType(const void* cppIn) {
    int castCppIn = *((::QMetaMethod::MethodType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMetaMethod_PythonToCpp_QMetaMethod_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMetaMethod_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMetaMethod_PythonToCpp_QMetaMethod_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaMethod_Type))
        return QMetaMethod_PythonToCpp_QMetaMethod_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMetaMethod_PTR_CppToPython_QMetaMethod(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMetaMethod*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMetaMethod_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QMetaMethod_COPY_CppToPython_QMetaMethod(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QMetaMethod_Type, new ::QMetaMethod(*((::QMetaMethod*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QMetaMethod_PythonToCpp_QMetaMethod_COPY(PyObject* pyIn, void* cppOut) {
    *((::QMetaMethod*)cppOut) = *((::QMetaMethod*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QMetaMethod_PythonToCpp_QMetaMethod_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaMethod_Type))
        return QMetaMethod_PythonToCpp_QMetaMethod_COPY;
    return 0;
}

void init_QMetaMethod(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMetaMethod_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMetaMethod", "QMetaMethod",
        &Sbk_QMetaMethod_Type, &Shiboken::callCppDestructor< ::QMetaMethod >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMetaMethod_Type,
        QMetaMethod_PythonToCpp_QMetaMethod_PTR,
        is_QMetaMethod_PythonToCpp_QMetaMethod_PTR_Convertible,
        QMetaMethod_PTR_CppToPython_QMetaMethod,
        QMetaMethod_COPY_CppToPython_QMetaMethod);

    Shiboken::Conversions::registerConverterName(converter, "QMetaMethod");
    Shiboken::Conversions::registerConverterName(converter, "QMetaMethod*");
    Shiboken::Conversions::registerConverterName(converter, "QMetaMethod&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMetaMethod).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QMetaMethod_PythonToCpp_QMetaMethod_COPY,
        is_QMetaMethod_PythonToCpp_QMetaMethod_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Access'.
    SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMetaMethod_Type,
        "Access",
        "PySide.QtCore.QMetaMethod.Access",
        "QMetaMethod::Access");
    if (!SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX],
        &Sbk_QMetaMethod_Type, "Private", (long) QMetaMethod::Private))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX],
        &Sbk_QMetaMethod_Type, "Protected", (long) QMetaMethod::Protected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX],
        &Sbk_QMetaMethod_Type, "Public", (long) QMetaMethod::Public))
        return ;
    // Register converter for enum 'QMetaMethod::Access'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX],
            QMetaMethod_Access_CppToPython_QMetaMethod_Access);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMetaMethod_Access_PythonToCpp_QMetaMethod_Access,
            is_QMetaMethod_Access_PythonToCpp_QMetaMethod_Access_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_ACCESS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMetaMethod::Access");
        Shiboken::Conversions::registerConverterName(converter, "Access");
    }
    // End of 'Access' enum.

    // Initialization of enum 'MethodType'.
    SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMetaMethod_Type,
        "MethodType",
        "PySide.QtCore.QMetaMethod.MethodType",
        "QMetaMethod::MethodType");
    if (!SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX],
        &Sbk_QMetaMethod_Type, "Method", (long) QMetaMethod::Method))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX],
        &Sbk_QMetaMethod_Type, "Signal", (long) QMetaMethod::Signal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX],
        &Sbk_QMetaMethod_Type, "Slot", (long) QMetaMethod::Slot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX],
        &Sbk_QMetaMethod_Type, "Constructor", (long) QMetaMethod::Constructor))
        return ;
    // Register converter for enum 'QMetaMethod::MethodType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX],
            QMetaMethod_MethodType_CppToPython_QMetaMethod_MethodType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMetaMethod_MethodType_PythonToCpp_QMetaMethod_MethodType,
            is_QMetaMethod_MethodType_PythonToCpp_QMetaMethod_MethodType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_METHODTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMetaMethod::MethodType");
        Shiboken::Conversions::registerConverterName(converter, "MethodType");
    }
    // End of 'MethodType' enum.


    qRegisterMetaType< ::QMetaMethod >("QMetaMethod");
    qRegisterMetaType< ::QMetaMethod::Access >("QMetaMethod::Access");
    qRegisterMetaType< ::QMetaMethod::MethodType >("QMetaMethod::MethodType");
}
