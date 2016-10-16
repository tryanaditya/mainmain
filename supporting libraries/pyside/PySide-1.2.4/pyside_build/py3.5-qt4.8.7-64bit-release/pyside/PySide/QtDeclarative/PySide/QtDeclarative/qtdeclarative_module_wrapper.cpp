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
#include "pyside_qtdeclarative_python.h"



// Extra includes
#include <QtDeclarative>
#include "pysideqmlregistertype.h"

// Current module's type array.
PyTypeObject** SbkPySide_QtDeclarativeTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtDeclarativeTypeConverters;

void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtDeclarative_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtDeclarativeTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------
static PyObject* SbkQtDeclarativeModule_qmlRegisterType(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qmlRegisterType", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: qmlRegisterType(PyTypeObject,const char*,int,int,const char*)
    if (numArgs == 5
        && PyType_Check(pyArgs[0])
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4])))) {
        overloadId = 0; // qmlRegisterType(PyTypeObject,const char*,int,int,const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtDeclarativeModule_qmlRegisterType_TypeError;

    // Call function/method
    {
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        SBK_UNUSED(cppArg1)
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        SBK_UNUSED(cppArg2)
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        SBK_UNUSED(cppArg3)
        const char* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        SBK_UNUSED(cppArg4)

        if (!PyErr_Occurred()) {
            // qmlRegisterType(PyTypeObject,const char*,int,int,const char*)
            // Begin code injection

            int cppResult = PySide::qmlRegisterType(pyArgs[0], cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtDeclarativeModule_qmlRegisterType_TypeError:
        const char* overloads[] = {"PyTypeObject, " SBK_STR_NAME ", int, int, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qmlRegisterType", overloads);
        return 0;
}


static PyMethodDef QtDeclarative_methods[] = {
    {"qmlRegisterType", (PyCFunction)SbkQtDeclarativeModule_qmlRegisterType, METH_VARARGS},
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QDeclarativeListReference(PyObject* module);
void init_QDeclarativeParserStatus(PyObject* module);
void init_QDeclarativePropertyValueSource(PyObject* module);
void init_QDeclarativeError(PyObject* module);
void init_QDeclarativeExtensionInterface(PyObject* module);
void init_QDeclarativeImageProvider(PyObject* module);
void init_QDeclarativeNetworkAccessManagerFactory(PyObject* module);
void init_QDeclarativeProperty(PyObject* module);
void init_QDeclarativeScriptString(PyObject* module);
void init_QDeclarativeComponent(PyObject* module);
void init_QDeclarativePropertyMap(PyObject* module);
void init_QDeclarativeContext(PyObject* module);
void init_QDeclarativeEngine(PyObject* module);
void init_QDeclarativeExpression(PyObject* module);
void init_QDeclarativeExtensionPlugin(PyObject* module);
void init_QDeclarativeView(PyObject* module);
void init_QDeclarativeItem(PyObject* module);

// Enum definitions ------------------------------------------------------------
// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;
PyTypeObject** SbkPySide_QtNetworkTypes;
SbkConverter** SbkPySide_QtNetworkTypeConverters;
PyTypeObject** SbkPySide_QtGuiTypes;
SbkConverter** SbkPySide_QtGuiTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'QList<QGraphicsItem * >'.
static PyObject* _QList_QGraphicsItemPTR__CppToPython__QList_QGraphicsItemPTR_(const void* cppIn) {
    ::QList<QGraphicsItem * >& cppInRef = *((::QList<QGraphicsItem * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QGraphicsItem * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QGraphicsItem* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QGraphicsItem * >& cppOutRef = *((::QList<QGraphicsItem * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QGraphicsItem* cppItem = ((::QGraphicsItem*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], pyIn))
        return _QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QObject * > &'.
static PyObject* _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF(const void* cppIn) {
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
static void _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyIn))
        return _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QByteArray >'.
static PyObject* _QList_QByteArray__CppToPython__QList_QByteArray_(const void* cppIn) {
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
static void _QList_QByteArray__PythonToCpp__QList_QByteArray_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyIn))
        return _QList_QByteArray__PythonToCpp__QList_QByteArray_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QGraphicsTransform * > &'.
static PyObject* _constQList_QGraphicsTransformPTR_REF_CppToPython__constQList_QGraphicsTransformPTR_REF(const void* cppIn) {
    ::QList<QGraphicsTransform * >& cppInRef = *((::QList<QGraphicsTransform * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QGraphicsTransform * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QGraphicsTransform* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSTRANSFORM_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QGraphicsTransform * >& cppOutRef = *((::QList<QGraphicsTransform * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QGraphicsTransform* cppItem = ((::QGraphicsTransform*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSTRANSFORM_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QGRAPHICSTRANSFORM_IDX], pyIn))
        return _constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QDeclarativeError > &'.
static PyObject* _constQList_QDeclarativeError_REF_CppToPython__constQList_QDeclarativeError_REF(const void* cppIn) {
    ::QList<QDeclarativeError >& cppInRef = *((::QList<QDeclarativeError >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QDeclarativeError >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QDeclarativeError cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEERROR_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QDeclarativeError_REF_PythonToCpp__constQList_QDeclarativeError_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QDeclarativeError >& cppOutRef = *((::QList<QDeclarativeError >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QDeclarativeError cppItem = ::QDeclarativeError();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEERROR_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QDeclarativeError_REF_PythonToCpp__constQList_QDeclarativeError_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEERROR_IDX], pyIn))
        return _constQList_QDeclarativeError_REF_PythonToCpp__constQList_QDeclarativeError_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QAction * >'.
static PyObject* _QList_QActionPTR__CppToPython__QList_QActionPTR_(const void* cppIn) {
    ::QList<QAction * >& cppInRef = *((::QList<QAction * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAction * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAction* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QActionPTR__PythonToCpp__QList_QActionPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QAction * >& cppOutRef = *((::QList<QAction * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAction* cppItem = ((::QAction*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], pyIn))
        return _QList_QActionPTR__PythonToCpp__QList_QActionPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QWidget * >'.
static PyObject* _QList_QWidgetPTR__CppToPython__QList_QWidgetPTR_(const void* cppIn) {
    ::QList<QWidget * >& cppInRef = *((::QList<QWidget * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWidget * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWidget* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QWidget * >& cppOutRef = *((::QList<QWidget * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWidget* cppItem = ((::QWidget*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyIn))
        return _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QRectF > &'.
static PyObject* _constQList_QRectF_REF_CppToPython__constQList_QRectF_REF(const void* cppIn) {
    ::QList<QRectF >& cppInRef = *((::QList<QRectF >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QRectF >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QRectF cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QRectF >& cppOutRef = *((::QList<QRectF >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QRectF cppItem = ::QRectF();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyIn))
        return _constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QVariant >'.
static PyObject* _QList_QVariant__CppToPython__QList_QVariant_(const void* cppIn) {
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
static void _QList_QVariant__PythonToCpp__QList_QVariant_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn))
        return _QList_QVariant__PythonToCpp__QList_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'QList<QString >'.
static PyObject* _QList_QString__CppToPython__QList_QString_(const void* cppIn) {
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
static void _QList_QString__PythonToCpp__QList_QString_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QList_QString__PythonToCpp__QList_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return _QList_QString__PythonToCpp__QList_QString_;
    return 0;
}

// C++ to Python conversion for type 'QMap<QString, QVariant >'.
static PyObject* _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_(const void* cppIn) {
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
static void _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_;
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
    /* m_name     */ "QtDeclarative",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtDeclarative_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtDeclarative)

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtNetwork"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtNetworkTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtNetworkTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtGui"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtGuiTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtGuiTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtDeclarative_IDX_COUNT];
    SbkPySide_QtDeclarativeTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtDeclarative_CONVERTERS_IDX_COUNT];
    SbkPySide_QtDeclarativeTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtDeclarative", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtDeclarative", QtDeclarative_methods);
#endif

    // Initialize classes in the type system
    init_QDeclarativeListReference(module);
    init_QDeclarativeParserStatus(module);
    init_QDeclarativePropertyValueSource(module);
    init_QDeclarativeError(module);
    init_QDeclarativeExtensionInterface(module);
    init_QDeclarativeImageProvider(module);
    init_QDeclarativeNetworkAccessManagerFactory(module);
    init_QDeclarativeProperty(module);
    init_QDeclarativeScriptString(module);
    init_QDeclarativeComponent(module);
    init_QDeclarativePropertyMap(module);
    init_QDeclarativeContext(module);
    init_QDeclarativeEngine(module);
    init_QDeclarativeExpression(module);
    init_QDeclarativeExtensionPlugin(module);
    init_QDeclarativeView(module);
    init_QDeclarativeItem(module);

    // Register converter for type 'QList<QGraphicsItem*>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSITEMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QGraphicsItemPTR__CppToPython__QList_QGraphicsItemPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSITEMPTR_IDX], "QList<QGraphicsItem*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSITEMPTR_IDX],
        _QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR_,
        is__QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR__Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'const QList<QGraphicsTransform*>&'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSTRANSFORMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QGraphicsTransformPTR_REF_CppToPython__constQList_QGraphicsTransformPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSTRANSFORMPTR_IDX], "const QList<QGraphicsTransform*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSTRANSFORMPTR_IDX], "QList<QGraphicsTransform*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QGRAPHICSTRANSFORMPTR_IDX],
        _constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF,
        is__constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF_Convertible);

    // Register converter for type 'const QList<QDeclarativeError>&'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QDECLARATIVEERROR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QDeclarativeError_REF_CppToPython__constQList_QDeclarativeError_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QDECLARATIVEERROR_IDX], "const QList<QDeclarativeError>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QDECLARATIVEERROR_IDX], "QList<QDeclarativeError>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QDECLARATIVEERROR_IDX],
        _constQList_QDeclarativeError_REF_PythonToCpp__constQList_QDeclarativeError_REF,
        is__constQList_QDeclarativeError_REF_PythonToCpp__constQList_QDeclarativeError_REF_Convertible);

    // Register converter for type 'QList<QAction*>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QACTIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QActionPTR__CppToPython__QList_QActionPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QACTIONPTR_IDX], "QList<QAction*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QACTIONPTR_IDX],
        _QList_QActionPTR__PythonToCpp__QList_QActionPTR_,
        is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible);

    // Register converter for type 'QList<QWidget*>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QWIDGETPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWidgetPTR__CppToPython__QList_QWidgetPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QWIDGETPTR_IDX], "QList<QWidget*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QWIDGETPTR_IDX],
        _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_,
        is__QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR__Convertible);

    // Register converter for type 'const QList<QRectF>&'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QRECTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QRectF_REF_CppToPython__constQList_QRectF_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QRECTF_IDX], "const QList<QRectF>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QRECTF_IDX], "QList<QRectF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QRECTF_IDX],
        _constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF,
        is__constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF_Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Initialization of enums.

    // Initialization of anonymous enum identified by enum value 'QML_HAS_ATTACHED_PROPERTIES'.
    if (PyModule_AddIntConstant(module, "QML_HAS_ATTACHED_PROPERTIES", (long) QML_HAS_ATTACHED_PROPERTIES) < 0)
        return SBK_MODULE_INIT_ERROR;
    // End of 'QML_HAS_ATTACHED_PROPERTIES' enum.

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtDeclarativeTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtDeclarativeTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtDeclarative");
    }
    // Begin code injection

    PySide::initQmlSupport(module);

    // End of code injection


    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
