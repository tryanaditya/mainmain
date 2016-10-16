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

#include "qbitmap_wrapper.h"

// Extra includes
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcolor.h>
#include <qimage.h>
#include <qimagereader.h>
#include <qimagewriter.h>
#include <qiodevice.h>
#include <qmatrix.h>
#include <qpaintengine.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qtransform.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QBitmapWrapper::QBitmapWrapper() : QBitmap() {
    // ... middle
}

QBitmapWrapper::QBitmapWrapper(const QPixmap & arg__1) : QBitmap(arg__1) {
    // ... middle
}

QBitmapWrapper::QBitmapWrapper(const QSize & arg__1) : QBitmap(arg__1) {
    // ... middle
}

QBitmapWrapper::QBitmapWrapper(const QString & fileName, const char * format) : QBitmap(fileName, format) {
    // ... middle
}

QBitmapWrapper::QBitmapWrapper(int w, int h) : QBitmap(w, h) {
    // ... middle
}

int QBitmapWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPixmap::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBitmap.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QBitmapWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPixmap::metric(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBitmap.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QBitmapWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPixmap::paintEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPaintEngine*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBitmap.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QBitmapWrapper::~QBitmapWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QBitmap_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QBitmap >()))
        return -1;

    ::QBitmapWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QBitmap", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QBitmap()
    // 1: QBitmap(QPixmap)
    // 2: QBitmap(QSize)
    // 3: QBitmap(QString,const char*)
    // 4: QBitmap(int,int)
    if (numArgs == 0) {
        overloadId = 0; // QBitmap()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 4; // QBitmap(int,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QBitmap(QString,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 3; // QBitmap(QString,const char*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QBitmap(QSize)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        overloadId = 1; // QBitmap(QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitmap_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QBitmap()
        {

            if (!PyErr_Occurred()) {
                // QBitmap()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitmapWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QBitmap(const QPixmap & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPixmap cppArg0_local = ::QPixmap();
            ::QPixmap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBitmap(QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitmapWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QBitmap(const QSize & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBitmap(QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitmapWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QBitmap(const QString & fileName, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QBitmap_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QBitmap(QString,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitmapWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QBitmap(int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QBitmap(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitmapWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QBitmap >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QBitmap_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QBitmap_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPixmap", "PySide.QtCore.QSize", "unicode, " SBK_STR_NAME " = None", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBitmap", overloads);
        return -1;
}

static PyObject* Sbk_QBitmapFunc_clear(PyObject* self)
{
    ::QBitmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QBitmapFunc_fromData(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap.fromData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap.fromData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:fromData", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: fromData(QSize,const uchar*,QImage::Format)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))
        && Shiboken::Buffer::checkType(pyArgs[1])) {
        if (numArgs == 2) {
            overloadId = 0; // fromData(QSize,const uchar*,QImage::Format)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[2])))) {
            overloadId = 0; // fromData(QSize,const uchar*,QImage::Format)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitmapFunc_fromData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "monoFormat");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap.fromData(): got multiple values for keyword argument 'monoFormat'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[2]))))
                    goto Sbk_QBitmapFunc_fromData_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QImage::Format cppArg2 = QImage::Format_MonoLSB;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // fromData(QSize,const uchar*,QImage::Format)
            // Begin code injection

            uchar* buffer = (uchar*) Shiboken::Buffer::getPointer(pyArgs[2-1]);
            QBitmap cppResult = QBitmap::fromData(*cppArg0, buffer, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitmapFunc_fromData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, PySide.QtCore.uchar, PySide.QtGui.QImage.Format = QImage.Format_MonoLSB", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBitmap.fromData", overloads);
        return 0;
}

static PyObject* Sbk_QBitmapFunc_fromImage(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap.fromImage(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap.fromImage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromImage", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromImage(QImage,QFlags<Qt::ImageConversionFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromImage(QImage,QFlags<Qt::ImageConversionFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromImage(QImage,QFlags<Qt::ImageConversionFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitmapFunc_fromImage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBitmap.fromImage(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QBitmapFunc_fromImage_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QFlags<Qt::ImageConversionFlag> cppArg1 = Qt::AutoColor;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromImage(QImage,QFlags<Qt::ImageConversionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitmap cppResult = ::QBitmap::fromImage(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitmapFunc_fromImage_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBitmap.fromImage", overloads);
        return 0;
}

static PyObject* Sbk_QBitmapFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QBitmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QBitmap&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (pyArg)))) {
        overloadId = 0; // swap(QBitmap&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitmapFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitmap cppArg0_local = ::QBitmap();
        ::QBitmap* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QBitmap&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBitmapFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBitmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBitmap.swap", overloads);
        return 0;
}

static PyObject* Sbk_QBitmapFunc_transformed(PyObject* self, PyObject* pyArg)
{
    ::QBitmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: transformed(QMatrix)const
    // 1: transformed(QTransform)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 1; // transformed(QTransform)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArg)))) {
        overloadId = 0; // transformed(QMatrix)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitmapFunc_transformed_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // transformed(const QMatrix & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QMatrix cppArg0_local = ::QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // transformed(QMatrix)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QBitmap cppResult = const_cast<const ::QBitmap*>(cppSelf)->transformed(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // transformed(const QTransform & matrix) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // transformed(QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QBitmap cppResult = const_cast<const ::QBitmap*>(cppSelf)->transformed(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitmapFunc_transformed_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix", "PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBitmap.transformed", overloads);
        return 0;
}

static PyObject* Sbk_QBitmap___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBitmap& cppSelf = *(((::QBitmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QBitmap_methods[] = {
    {"clear", (PyCFunction)Sbk_QBitmapFunc_clear, METH_NOARGS},
    {"fromData", (PyCFunction)Sbk_QBitmapFunc_fromData, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromImage", (PyCFunction)Sbk_QBitmapFunc_fromImage, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"swap", (PyCFunction)Sbk_QBitmapFunc_swap, METH_O},
    {"transformed", (PyCFunction)Sbk_QBitmapFunc_transformed, METH_O},

    {"__copy__", (PyCFunction)Sbk_QBitmap___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QBitmap___nb_bool(PyObject* self)
{
    ::QBitmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QBitmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QBitmap_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QBitmap_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QBitmap_TypeAsNumber;

static SbkObjectType Sbk_QBitmap_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QBitmap",
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
    /*tp_traverse*/         Sbk_QBitmap_traverse,
    /*tp_clear*/            Sbk_QBitmap_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QBitmap_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QBitmap_Init,
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

static void* Sbk_QBitmap_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QBitmap*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QBitmap_PythonToCpp_QBitmap_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QBitmap_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QBitmap_PythonToCpp_QBitmap_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBitmap_Type))
        return QBitmap_PythonToCpp_QBitmap_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QBitmap_PTR_CppToPython_QBitmap(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QBitmap*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QBitmap_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QBitmap_COPY_CppToPython_QBitmap(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QBitmap_Type, new ::QBitmapWrapper(*((::QBitmap*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QBitmap_PythonToCpp_QBitmap_COPY(PyObject* pyIn, void* cppOut) {
    *((::QBitmap*)cppOut) = *((::QBitmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QBitmap_PythonToCpp_QBitmap_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBitmap_Type))
        return QBitmap_PythonToCpp_QBitmap_COPY;
    return 0;
}

// Implicit conversions.
static void constQPixmapREF_PythonToCpp_QBitmap(PyObject* pyIn, void* cppOut) {
    *((::QBitmap*)cppOut) = ::QBitmap(*((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQPixmapREF_PythonToCpp_QBitmap_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyIn))
        return constQPixmapREF_PythonToCpp_QBitmap;
    return 0;
}

void init_QBitmap(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QBitmap_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QBitmap_TypeAsNumber) = Sbk_QBitmap___nb_bool;
    Sbk_QBitmap_Type.super.ht_type.tp_as_number = &Sbk_QBitmap_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QBitmap_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QBitmap", "QBitmap",
        &Sbk_QBitmap_Type, &Shiboken::callCppDestructor< ::QBitmapWrapper >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QBitmap_Type,
        QBitmap_PythonToCpp_QBitmap_PTR,
        is_QBitmap_PythonToCpp_QBitmap_PTR_Convertible,
        QBitmap_PTR_CppToPython_QBitmap,
        QBitmap_COPY_CppToPython_QBitmap);

    Shiboken::Conversions::registerConverterName(converter, "QBitmap");
    Shiboken::Conversions::registerConverterName(converter, "QBitmap*");
    Shiboken::Conversions::registerConverterName(converter, "QBitmap&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBitmap).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBitmapWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QBitmap_PythonToCpp_QBitmap_COPY,
        is_QBitmap_PythonToCpp_QBitmap_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQPixmapREF_PythonToCpp_QBitmap,
        is_constQPixmapREF_PythonToCpp_QBitmap_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QBitmap_Type, &Sbk_QBitmap_typeDiscovery);


    qRegisterMetaType< ::QBitmap >("QBitmap");
}
