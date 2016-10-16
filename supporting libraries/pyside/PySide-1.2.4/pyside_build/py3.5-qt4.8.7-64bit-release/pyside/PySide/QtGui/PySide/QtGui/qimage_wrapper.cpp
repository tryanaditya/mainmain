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

#include "qimage_wrapper.h"

// Extra includes
#include <QMatrix>
#include <QStringList>
#include <QVector>
#include <qbytearray.h>
#include <qcolor.h>
#include <qdatastream.h>
#include <qimage.h>
#include <qiodevice.h>
#include <qmatrix.h>
#include <qpaintengine.h>
#include <qpoint.h>
#include <qrect.h>
#include <qsize.h>
#include <qtransform.h>


// Native ---------------------------------------------------------

QImageWrapper::QImageWrapper() : QImage() {
    // ... middle
}

QImageWrapper::QImageWrapper(const QSize & size, QImage::Format format) : QImage(size, format) {
    // ... middle
}

QImageWrapper::QImageWrapper(const QString & fileName, const char * format) : QImage(fileName, format) {
    // ... middle
}

QImageWrapper::QImageWrapper(const char ** xpm) : QImage(xpm) {
    // ... middle
}

QImageWrapper::QImageWrapper(int width, int height, QImage::Format format) : QImage(width, height, format) {
    // ... middle
}

QImageWrapper::QImageWrapper(uchar * data, int width, int height, QImage::Format format) : QImage(data, width, height, format) {
    // ... middle
}

QImageWrapper::QImageWrapper(uchar * data, int width, int height, int bytesPerLine, QImage::Format format) : QImage(data, width, height, bytesPerLine, format) {
    // ... middle
}

int QImageWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImage::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImage.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QImageWrapper::metric(QPaintDevice::PaintDeviceMetric metric) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImage::metric(metric);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &metric)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImage.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QImageWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImage::paintEngine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImage.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QImageWrapper::~QImageWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QImage_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QImage >()))
        return -1;

    ::QImageWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QImage", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QImage()
    // 1: QImage(QString&,int,int,QImage::Format)
    // 2: QImage(QString&,int,int,int,QImage::Format)
    // 3: QImage(QImage)
    // 4: QImage(QSize,QImage::Format)
    // 5: QImage(QString,const char*)
    // 6: QImage(const char**)
    // 7: QImage(int,int,QImage::Format)
    // 8: QImage(uchar*,int,int,QImage::Format)
    // 9: QImage(uchar*,int,int,int,QImage::Format)
    if (numArgs == 0) {
        overloadId = 0; // QImage()
    } else if (numArgs >= 3
        && Shiboken::Buffer::checkType(pyArgs[0])
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 4
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[3])))) {
            overloadId = 8; // QImage(uchar*,int,int,QImage::Format)
        } else if (numArgs == 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[4])))) {
            overloadId = 9; // QImage(uchar*,int,int,int,QImage::Format)
        }
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[2])))) {
        overloadId = 7; // QImage(int,int,QImage::Format)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[1])))) {
        overloadId = 4; // QImage(QSize,QImage::Format)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        overloadId = 3; // QImage(QImage)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 5; // QImage(QString,const char*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 5; // QImage(QString,const char*)
        } else if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 4
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[3])))) {
                overloadId = 1; // QImage(QString&,int,int,QImage::Format)
            } else if (numArgs == 5
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
                && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[4])))) {
                overloadId = 2; // QImage(QString&,int,int,int,QImage::Format)
            }
        }
    } else if (numArgs == 1
        && PySequence_Check(pyArgs[0])) {
        overloadId = 6; // QImage(const char**)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImage_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QImage()
        {

            if (!PyErr_Occurred()) {
                // QImage()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QImage(QString & arg__1, int arg__2, int arg__3, QImage::Format arg__4)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)
            ::QImage::Format cppArg3 = ((::QImage::Format)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)

            if (!PyErr_Occurred()) {
                // QImage(QString&,int,int,QImage::Format)
                // Begin code injection

                // TEMPLATE - qimage_buffer_constructor - START
                uchar* ptr = (uchar*) Shiboken::Buffer::getPointer(pyArgs[1-1]);
                cptr = new QImageWrapper(ptr, cppArg1, cppArg2, cppArg3);
                // TEMPLATE - qimage_buffer_constructor - END

                // End of code injection

            }
            break;
        }
        case 2: // QImage(QString & arg__1, int arg__2, int arg__3, int arg__4, QImage::Format arg__5)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)
            ::QImage::Format cppArg4 = ((::QImage::Format)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);
            SBK_UNUSED(cppArg4)

            if (!PyErr_Occurred()) {
                // QImage(QString&,int,int,int,QImage::Format)
                // Begin code injection

                // TEMPLATE - qimage_buffer_constructor - START
                uchar* ptr = (uchar*) Shiboken::Buffer::getPointer(pyArgs[1-1]);
                cptr = new QImageWrapper(ptr, cppArg1, cppArg2, cppArg3, cppArg4);
                // TEMPLATE - qimage_buffer_constructor - END

                // End of code injection

            }
            break;
        }
        case 3: // QImage(const QImage & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QImage cppArg0_local = ::QImage();
            ::QImage* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QImage(QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QImage(const QSize & size, QImage::Format format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QImage::Format cppArg1 = ((::QImage::Format)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QImage(QSize,QImage::Format)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWrapper(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QImage(const QString & fileName, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QImage_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QImage(QString,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QImage(const char ** xpm)
        {

            if (!PyErr_Occurred()) {
                // QImage(const char**)
                // Begin code injection

                // TEMPLATE - load_xpm - START
                Shiboken::AutoDecRef strList(PySequence_Fast(pyArgs[1-1], "Invalid sequence."));
                int lineCount = PySequence_Fast_GET_SIZE(strList.object());
                for (int line = 0; line < lineCount; ++line) {
                if (!Shiboken::String::check(PySequence_Fast_GET_ITEM(strList.object(), line))) {
                    PyErr_SetString(PyExc_TypeError, "The argument must be a sequence of strings.");
                    break;
                }
                }

                const char** xpm = (const char**) malloc (lineCount * sizeof(const char**));
                for (int line = 0; line < lineCount; ++line)
                xpm[line] = Shiboken::String::toCString(PySequence_Fast_GET_ITEM(strList.object(), line));

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new QImageWrapper(xpm);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                free(xpm);
                // TEMPLATE - load_xpm - END

                // End of code injection

            }
            break;
        }
        case 7: // QImage(int width, int height, QImage::Format format)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QImage::Format cppArg2 = ((::QImage::Format)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QImage(int,int,QImage::Format)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // QImage(uchar * data, int width, int height, QImage::Format format)
        {
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QImage::Format cppArg3 = ((::QImage::Format)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QImage(uchar*,int,int,QImage::Format)
                // Begin code injection

                // TEMPLATE - qimage_buffer_constructor - START
                uchar* ptr = (uchar*) Shiboken::Buffer::getPointer(pyArgs[1-1]);
                cptr = new QImageWrapper(ptr, cppArg1, cppArg2, cppArg3);
                // TEMPLATE - qimage_buffer_constructor - END

                // End of code injection

            }
            break;
        }
        case 9: // QImage(uchar * data, int width, int height, int bytesPerLine, QImage::Format format)
        {
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QImage::Format cppArg4 = ((::QImage::Format)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QImage(uchar*,int,int,int,QImage::Format)
                // Begin code injection

                // TEMPLATE - qimage_buffer_constructor - START
                uchar* ptr = (uchar*) Shiboken::Buffer::getPointer(pyArgs[1-1]);
                cptr = new QImageWrapper(ptr, cppArg1, cppArg2, cppArg3, cppArg4);
                // TEMPLATE - qimage_buffer_constructor - END

                // End of code injection

            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QImage >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QImage_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QImage_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QString, int, int, PySide.QtGui.QImage.Format", "PySide.QtCore.QString, int, int, int, PySide.QtGui.QImage.Format", "PySide.QtGui.QImage", "PySide.QtCore.QSize, PySide.QtGui.QImage.Format", "unicode, " SBK_STR_NAME " = None", "PySide.QtCore.char", "int, int, PySide.QtGui.QImage.Format", "PySide.QtCore.uchar, int, int, PySide.QtGui.QImage.Format", "PySide.QtCore.uchar, int, int, int, PySide.QtGui.QImage.Format", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage", overloads);
        return -1;
}

static PyObject* Sbk_QImageFunc_allGray(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allGray()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImage*>(cppSelf)->allGray();
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

static PyObject* Sbk_QImageFunc_alphaChannel(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alphaChannel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->alphaChannel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_bitPlaneCount(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bitPlaneCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->bitPlaneCount();
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

static PyObject* Sbk_QImageFunc_bits(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bits()
            // Begin code injection

            // byteCount() is only available on Qt4.7, so we use bytesPerLine * height
            pyResult = Shiboken::Buffer::newObject(cppSelf->bits(), cppSelf->bytesPerLine() * cppSelf->height(), Shiboken::Buffer::ReadWrite);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_byteCount(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // byteCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->byteCount();
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

static PyObject* Sbk_QImageFunc_bytesPerLine(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesPerLine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->bytesPerLine();
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

static PyObject* Sbk_QImageFunc_cacheKey(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QImage*>(cppSelf)->cacheKey();
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

static PyObject* Sbk_QImageFunc_color(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: color(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // color(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_color_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // color(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = const_cast<const ::QImage*>(cppSelf)->color(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_color_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.color", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_colorCount(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colorCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->colorCount();
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

static PyObject* Sbk_QImageFunc_colorTable(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colorTable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<unsigned int > cppResult = const_cast<const ::QImage*>(cppSelf)->colorTable();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_constBits(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // constBits()const
            // Begin code injection

            pyResult = Shiboken::Buffer::newObject(cppSelf->constBits(), cppSelf->byteCount());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_constScanLine(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: constScanLine(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // constScanLine(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_constScanLine_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // constScanLine(int)const
            // Begin code injection

            pyResult = Shiboken::Buffer::newObject(cppSelf->constScanLine(cppArg0), cppSelf->bytesPerLine());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_constScanLine_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.constScanLine", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_convertToFormat(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.convertToFormat(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.convertToFormat(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:convertToFormat", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: convertToFormat(QImage::Format,QFlags<Qt::ImageConversionFlag>)const
    // 1: convertToFormat(QImage::Format,QVector<uint>,QFlags<Qt::ImageConversionFlag>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // convertToFormat(QImage::Format,QFlags<Qt::ImageConversionFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // convertToFormat(QImage::Format,QVector<uint>,QFlags<Qt::ImageConversionFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // convertToFormat(QImage::Format,QVector<uint>,QFlags<Qt::ImageConversionFlag>)const
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // convertToFormat(QImage::Format,QFlags<Qt::ImageConversionFlag>)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_convertToFormat_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // convertToFormat(QImage::Format f, QFlags<Qt::ImageConversionFlag> flags) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.convertToFormat(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QImageFunc_convertToFormat_TypeError;
                }
            }
            ::QImage::Format cppArg0 = ((::QImage::Format)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<Qt::ImageConversionFlag> cppArg1 = Qt::AutoColor;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // convertToFormat(QImage::Format,QFlags<Qt::ImageConversionFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->convertToFormat(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
        case 1: // convertToFormat(QImage::Format f, const QVector<unsigned int > & colorTable, QFlags<Qt::ImageConversionFlag> flags) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.convertToFormat(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QImageFunc_convertToFormat_TypeError;
                }
            }
            ::QImage::Format cppArg0 = ((::QImage::Format)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVector<unsigned int > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::ImageConversionFlag> cppArg2 = Qt::AutoColor;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // convertToFormat(QImage::Format,QVector<uint>,QFlags<Qt::ImageConversionFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->convertToFormat(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_convertToFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage.Format, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "PySide.QtGui.QImage.Format, list, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.convertToFormat", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_copy(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.copy(): too many arguments");
        return 0;
    } else if (numArgs == 2 || numArgs == 3)
        goto Sbk_QImageFunc_copy_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:copy", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: copy(QRect)const
    // 1: copy(int,int,int,int)const
    if (numArgs == 0) {
        overloadId = 0; // copy(QRect)const
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // copy(int,int,int,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // copy(QRect)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_copy_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // copy(const QRect & rect) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rect");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.copy(): got multiple values for keyword argument 'rect'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0]))))
                        goto Sbk_QImageFunc_copy_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // copy(QRect)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->copy(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
        case 1: // copy(int x, int y, int w, int h) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // copy(int,int,int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->copy(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_copy_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect = QRect()", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.copy", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_createAlphaMask(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createAlphaMask(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:createAlphaMask", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: createAlphaMask(QFlags<Qt::ImageConversionFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // createAlphaMask(QFlags<Qt::ImageConversionFlag>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 0; // createAlphaMask(QFlags<Qt::ImageConversionFlag>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_createAlphaMask_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createAlphaMask(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[0]))))
                    goto Sbk_QImageFunc_createAlphaMask_TypeError;
            }
        }
        ::QFlags<Qt::ImageConversionFlag> cppArg0 = Qt::AutoColor;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // createAlphaMask(QFlags<Qt::ImageConversionFlag>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->createAlphaMask(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_createAlphaMask_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.createAlphaMask", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_createHeuristicMask(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createHeuristicMask(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:createHeuristicMask", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: createHeuristicMask(bool)const
    if (numArgs == 0) {
        overloadId = 0; // createHeuristicMask(bool)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // createHeuristicMask(bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_createHeuristicMask_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "clipTight");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createHeuristicMask(): got multiple values for keyword argument 'clipTight'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_QImageFunc_createHeuristicMask_TypeError;
            }
        }
        bool cppArg0 = true;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // createHeuristicMask(bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->createHeuristicMask(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_createHeuristicMask_TypeError:
        const char* overloads[] = {"bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.createHeuristicMask", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_createMaskFromColor(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createMaskFromColor(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createMaskFromColor(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:createMaskFromColor", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createMaskFromColor(uint,Qt::MaskMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createMaskFromColor(uint,Qt::MaskMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // createMaskFromColor(uint,Qt::MaskMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_createMaskFromColor_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.createMaskFromColor(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QImageFunc_createMaskFromColor_TypeError;
            }
        }
        unsigned int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::MaskMode cppArg1 = Qt::MaskInColor;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createMaskFromColor(uint,Qt::MaskMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->createMaskFromColor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_createMaskFromColor_TypeError:
        const char* overloads[] = {"unsigned int, PySide.QtCore.Qt.MaskMode = Qt.MaskInColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.createMaskFromColor", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_depth(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // depth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->depth();
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

static PyObject* Sbk_QImageFunc_devType(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImage*>(cppSelf)->::QImage::devType() : const_cast<const ::QImage*>(cppSelf)->devType();
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

static PyObject* Sbk_QImageFunc_dotsPerMeterX(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dotsPerMeterX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->dotsPerMeterX();
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

static PyObject* Sbk_QImageFunc_dotsPerMeterY(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dotsPerMeterY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->dotsPerMeterY();
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

static PyObject* Sbk_QImageFunc_fill(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fill(Qt::GlobalColor)
    // 1: fill(QColor)
    // 2: fill(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArg)))) {
        overloadId = 0; // fill(Qt::GlobalColor)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArg)))) {
        overloadId = 2; // fill(uint)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 1; // fill(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_fill_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fill(Qt::GlobalColor color)
        {
            ::Qt::GlobalColor cppArg0 = ((::Qt::GlobalColor)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // fill(Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // fill(const QColor & color)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // fill(QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // fill(uint pixel)
        {
            uint cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // fill(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_fill_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.GlobalColor", "PySide.QtGui.QColor", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.fill", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_format(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage::Format cppResult = const_cast<const ::QImage*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_fromData(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.fromData(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.fromData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromData", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromData(QByteArray,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromData(QByteArray,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // fromData(QByteArray,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_fromData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.fromData(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                    goto Sbk_QImageFunc_fromData_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        const char* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromData(QByteArray,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = ::QImage::fromData(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_fromData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.fromData", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_hasAlphaChannel(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAlphaChannel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImage*>(cppSelf)->hasAlphaChannel();
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

static PyObject* Sbk_QImageFunc_height(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->height();
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

static PyObject* Sbk_QImageFunc_invertPixels(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.invertPixels(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:invertPixels", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: invertPixels(QImage::InvertMode)
    if (numArgs == 0) {
        overloadId = 0; // invertPixels(QImage::InvertMode)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // invertPixels(QImage::InvertMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_invertPixels_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.invertPixels(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QImageFunc_invertPixels_TypeError;
            }
        }
        ::QImage::InvertMode cppArg0 = QImage::InvertRgb;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // invertPixels(QImage::InvertMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->invertPixels(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_invertPixels_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage.InvertMode = InvertRgb", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.invertPixels", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_isGrayscale(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isGrayscale()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImage*>(cppSelf)->isGrayscale();
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

static PyObject* Sbk_QImageFunc_isNull(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImage*>(cppSelf)->isNull();
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

static PyObject* Sbk_QImageFunc_load(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.load(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.load(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:load", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: load(QIODevice*,const char*)
    // 1: load(QString,const char*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        overloadId = 0; // load(QIODevice*,const char*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // load(QString,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 1; // load(QString,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_load_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // load(QIODevice * device, const char * format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // load(QIODevice*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->load(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // load(const QString & fileName, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.load(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QImageFunc_load_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // load(QString,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->load(cppArg0, cppArg1);
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

    Sbk_QImageFunc_load_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, " SBK_STR_NAME "", "unicode, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.load", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_loadFromData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.loadFromData(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.loadFromData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:loadFromData", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: loadFromData(QByteArray,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // loadFromData(QByteArray,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // loadFromData(QByteArray,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_loadFromData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "aformat");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.loadFromData(): got multiple values for keyword argument 'aformat'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                    goto Sbk_QImageFunc_loadFromData_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        const char* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // loadFromData(QByteArray,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->loadFromData(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_loadFromData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.loadFromData", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: metric(QPaintDevice::PaintDeviceMetric)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), (pyArg)))) {
        overloadId = 0; // metric(QPaintDevice::PaintDeviceMetric)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImage*>(cppSelf)->::QImage::metric(cppArg0) : const_cast<const ::QImage*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.metric", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_mirrored(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.mirrored(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:mirrored", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mirrored(bool,bool)const
    if (numArgs == 0) {
        overloadId = 0; // mirrored(bool,bool)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // mirrored(bool,bool)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // mirrored(bool,bool)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_mirrored_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "horizontally");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.mirrored(): got multiple values for keyword argument 'horizontally'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_QImageFunc_mirrored_TypeError;
            }
            value = PyDict_GetItemString(kwds, "vertically");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.mirrored(): got multiple values for keyword argument 'vertically'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QImageFunc_mirrored_TypeError;
            }
        }
        bool cppArg0 = false;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mirrored(bool,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->mirrored(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_mirrored_TypeError:
        const char* overloads[] = {"bool = false, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.mirrored", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_numBytes(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numBytes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->numBytes();
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

static PyObject* Sbk_QImageFunc_numColors(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numColors()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->numColors();
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

static PyObject* Sbk_QImageFunc_offset(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // offset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QImage*>(cppSelf)->offset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_paintEngine(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImage*>(cppSelf)->::QImage::paintEngine() : const_cast<const ::QImage*>(cppSelf)->paintEngine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_pixel(PyObject* self, PyObject* args)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "pixel", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: pixel(QPoint)const
    // 1: pixel(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // pixel(int,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // pixel(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_pixel_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // pixel(const QPoint & pt) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // pixel(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                unsigned int cppResult = const_cast<const ::QImage*>(cppSelf)->pixel(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
            }
            break;
        }
        case 1: // pixel(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // pixel(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                unsigned int cppResult = const_cast<const ::QImage*>(cppSelf)->pixel(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_pixel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.pixel", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_pixelIndex(PyObject* self, PyObject* args)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "pixelIndex", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: pixelIndex(QPoint)const
    // 1: pixelIndex(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // pixelIndex(int,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // pixelIndex(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_pixelIndex_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // pixelIndex(const QPoint & pt) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // pixelIndex(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QImage*>(cppSelf)->pixelIndex(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // pixelIndex(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // pixelIndex(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QImage*>(cppSelf)->pixelIndex(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_pixelIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.pixelIndex", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_rect(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QImage*>(cppSelf)->rect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_rgbSwapped(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rgbSwapped()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->rgbSwapped();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_save(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.save(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.save(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:save", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: save(QIODevice*,const char*,int)const
    // 1: save(QString,const char*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // save(QIODevice*,const char*,int)const
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // save(QIODevice*,const char*,int)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // save(QIODevice*,const char*,int)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // save(QString,const char*,int)const
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // save(QString,const char*,int)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // save(QString,const char*,int)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_save_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // save(QIODevice * device, const char * format, int quality) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.save(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QImageFunc_save_TypeError;
                }
                value = PyDict_GetItemString(kwds, "quality");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.save(): got multiple values for keyword argument 'quality'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QImageFunc_save_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // save(QIODevice*,const char*,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QImage*>(cppSelf)->save(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // save(const QString & fileName, const char * format, int quality) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.save(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QImageFunc_save_TypeError;
                }
                value = PyDict_GetItemString(kwds, "quality");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.save(): got multiple values for keyword argument 'quality'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QImageFunc_save_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // save(QString,const char*,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QImage*>(cppSelf)->save(cppArg0, cppArg1, cppArg2);
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

    Sbk_QImageFunc_save_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, " SBK_STR_NAME " = None, int = -1", "unicode, " SBK_STR_NAME " = None, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.save", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_scaled(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaled(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaled(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:scaled", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: scaled(QSize,Qt::AspectRatioMode,Qt::TransformationMode)const
    // 1: scaled(int,int,Qt::AspectRatioMode,Qt::TransformationMode)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // scaled(int,int,Qt::AspectRatioMode,Qt::TransformationMode)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // scaled(int,int,Qt::AspectRatioMode,Qt::TransformationMode)const
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[3])))) {
                overloadId = 1; // scaled(int,int,Qt::AspectRatioMode,Qt::TransformationMode)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // scaled(QSize,Qt::AspectRatioMode,Qt::TransformationMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // scaled(QSize,Qt::AspectRatioMode,Qt::TransformationMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // scaled(QSize,Qt::AspectRatioMode,Qt::TransformationMode)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_scaled_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // scaled(const QSize & s, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectMode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaled(): got multiple values for keyword argument 'aspectMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QImageFunc_scaled_TypeError;
                }
                value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaled(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[2]))))
                        goto Sbk_QImageFunc_scaled_TypeError;
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

            ::Qt::AspectRatioMode cppArg1 = Qt::IgnoreAspectRatio;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::TransformationMode cppArg2 = Qt::FastTransformation;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // scaled(QSize,Qt::AspectRatioMode,Qt::TransformationMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->scaled(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
        case 1: // scaled(int w, int h, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectMode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaled(): got multiple values for keyword argument 'aspectMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[2]))))
                        goto Sbk_QImageFunc_scaled_TypeError;
                }
                value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaled(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[3]))))
                        goto Sbk_QImageFunc_scaled_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::AspectRatioMode cppArg2 = Qt::IgnoreAspectRatio;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Qt::TransformationMode cppArg3 = Qt::FastTransformation;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // scaled(int,int,Qt::AspectRatioMode,Qt::TransformationMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->scaled(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_scaled_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", "int, int, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.scaled", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_scaledToHeight(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaledToHeight(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaledToHeight(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:scaledToHeight", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scaledToHeight(int,Qt::TransformationMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // scaledToHeight(int,Qt::TransformationMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // scaledToHeight(int,Qt::TransformationMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_scaledToHeight_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaledToHeight(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QImageFunc_scaledToHeight_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::TransformationMode cppArg1 = Qt::FastTransformation;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scaledToHeight(int,Qt::TransformationMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->scaledToHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_scaledToHeight_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.scaledToHeight", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_scaledToWidth(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaledToWidth(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaledToWidth(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:scaledToWidth", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scaledToWidth(int,Qt::TransformationMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // scaledToWidth(int,Qt::TransformationMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // scaledToWidth(int,Qt::TransformationMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_scaledToWidth_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.scaledToWidth(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QImageFunc_scaledToWidth_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::TransformationMode cppArg1 = Qt::FastTransformation;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scaledToWidth(int,Qt::TransformationMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QImage*>(cppSelf)->scaledToWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_scaledToWidth_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.scaledToWidth", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_scanLine(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scanLine(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // scanLine(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_scanLine_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scanLine(int)
            // Begin code injection

            pyResult = Shiboken::Buffer::newObject(cppSelf->scanLine(cppArg0), cppSelf->bytesPerLine(), Shiboken::Buffer::ReadWrite);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_scanLine_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.scanLine", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setAlphaChannel(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlphaChannel(QImage)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
        overloadId = 0; // setAlphaChannel(QImage)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setAlphaChannel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setAlphaChannel(QImage)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlphaChannel(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setAlphaChannel_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setAlphaChannel", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setColor(PyObject* self, PyObject* args)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColor(int,uint)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[1])))) {
        overloadId = 0; // setColor(int,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setColor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        unsigned int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColor(int,uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setColor_TypeError:
        const char* overloads[] = {"int, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.setColor", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setColorCount(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColorCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setColorCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setColorCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColorCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColorCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setColorCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setColorCount", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setColorTable(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColorTable(QVector<uint>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX], (pyArg)))) {
        overloadId = 0; // setColorTable(QVector<uint>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setColorTable_TypeError;

    // Call function/method
    {
        ::QVector<unsigned int > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColorTable(QVector<uint>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColorTable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setColorTable_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setColorTable", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setDotsPerMeterX(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDotsPerMeterX(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setDotsPerMeterX(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setDotsPerMeterX_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDotsPerMeterX(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDotsPerMeterX(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setDotsPerMeterX_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setDotsPerMeterX", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setDotsPerMeterY(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDotsPerMeterY(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setDotsPerMeterY(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setDotsPerMeterY_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDotsPerMeterY(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDotsPerMeterY(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setDotsPerMeterY_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setDotsPerMeterY", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setNumColors(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumColors(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setNumColors(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setNumColors_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumColors(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumColors(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setNumColors_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setNumColors", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setOffset(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOffset(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setOffset(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setOffset_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPoint cppArg0_local = ::QPoint();
        ::QPoint* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setOffset(QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOffset(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setOffset_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.setOffset", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setPixel(PyObject* self, PyObject* args)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPixel", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setPixel(QPoint,uint)
    // 1: setPixel(int,int,uint)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[2])))) {
        overloadId = 1; // setPixel(int,int,uint)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[1])))) {
        overloadId = 0; // setPixel(QPoint,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setPixel_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPixel(const QPoint & pt, uint index_or_rgb)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            uint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setPixel(QPoint,uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPixel(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPixel(int x, int y, uint index_or_rgb)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            uint cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setPixel(int,int,uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPixel(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setPixel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, unsigned int", "int, int, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.setPixel", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_setText(PyObject* self, PyObject* args)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setText", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setText(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setText(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_setText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setText(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setText(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_setText_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.setText", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_size(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QImage*>(cppSelf)->size();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QImage&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
        overloadId = 0; // swap(QImage&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QImage&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.swap", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_text(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.text(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:text", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: text(QString)const
    if (numArgs == 0) {
        overloadId = 0; // text(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // text(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_text_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "key");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.text(): got multiple values for keyword argument 'key'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QImageFunc_text_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // text(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QImage*>(cppSelf)->text(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_text_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.text", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_textKeys(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textKeys()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QImage*>(cppSelf)->textKeys();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageFunc_transformed(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.transformed(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.transformed(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:transformed", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: transformed(QMatrix,Qt::TransformationMode)const
    // 1: transformed(QTransform,Qt::TransformationMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // transformed(QTransform,Qt::TransformationMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // transformed(QTransform,Qt::TransformationMode)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // transformed(QMatrix,Qt::TransformationMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // transformed(QMatrix,Qt::TransformationMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_transformed_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // transformed(const QMatrix & matrix, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.transformed(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QImageFunc_transformed_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMatrix cppArg0_local = ::QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::TransformationMode cppArg1 = Qt::FastTransformation;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // transformed(QMatrix,Qt::TransformationMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->transformed(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
        case 1: // transformed(const QTransform & matrix, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImage.transformed(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QImageFunc_transformed_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::TransformationMode cppArg1 = Qt::FastTransformation;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // transformed(QTransform,Qt::TransformationMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage cppResult = const_cast<const ::QImage*>(cppSelf)->transformed(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_transformed_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", "PySide.QtGui.QTransform, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.transformed", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_trueMatrix(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "trueMatrix", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: trueMatrix(QMatrix,int,int)
    // 1: trueMatrix(QTransform,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 1; // trueMatrix(QTransform,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // trueMatrix(QMatrix,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_trueMatrix_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // trueMatrix(const QMatrix & arg__1, int w, int h)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMatrix cppArg0_local = ::QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // trueMatrix(QMatrix,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMatrix cppResult = ::QImage::trueMatrix(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
            }
            break;
        }
        case 1: // trueMatrix(const QTransform & arg__1, int w, int h)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // trueMatrix(QTransform,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTransform cppResult = ::QImage::trueMatrix(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc_trueMatrix_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix, int, int", "PySide.QtGui.QTransform, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.trueMatrix", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_valid(PyObject* self, PyObject* args)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "valid", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: valid(QPoint)const
    // 1: valid(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // valid(int,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // valid(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc_valid_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // valid(const QPoint & pt) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // valid(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QImage*>(cppSelf)->valid(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // valid(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // valid(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QImage*>(cppSelf)->valid(cppArg0, cppArg1);
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

    Sbk_QImageFunc_valid_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImage.valid", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc_width(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImage*>(cppSelf)->width();
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

static PyObject* Sbk_QImage___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QImage& cppSelf = *(((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QImage_methods[] = {
    {"allGray", (PyCFunction)Sbk_QImageFunc_allGray, METH_NOARGS},
    {"alphaChannel", (PyCFunction)Sbk_QImageFunc_alphaChannel, METH_NOARGS},
    {"bitPlaneCount", (PyCFunction)Sbk_QImageFunc_bitPlaneCount, METH_NOARGS},
    {"bits", (PyCFunction)Sbk_QImageFunc_bits, METH_NOARGS},
    {"byteCount", (PyCFunction)Sbk_QImageFunc_byteCount, METH_NOARGS},
    {"bytesPerLine", (PyCFunction)Sbk_QImageFunc_bytesPerLine, METH_NOARGS},
    {"cacheKey", (PyCFunction)Sbk_QImageFunc_cacheKey, METH_NOARGS},
    {"color", (PyCFunction)Sbk_QImageFunc_color, METH_O},
    {"colorCount", (PyCFunction)Sbk_QImageFunc_colorCount, METH_NOARGS},
    {"colorTable", (PyCFunction)Sbk_QImageFunc_colorTable, METH_NOARGS},
    {"constBits", (PyCFunction)Sbk_QImageFunc_constBits, METH_NOARGS},
    {"constScanLine", (PyCFunction)Sbk_QImageFunc_constScanLine, METH_O},
    {"convertToFormat", (PyCFunction)Sbk_QImageFunc_convertToFormat, METH_VARARGS|METH_KEYWORDS},
    {"copy", (PyCFunction)Sbk_QImageFunc_copy, METH_VARARGS|METH_KEYWORDS},
    {"createAlphaMask", (PyCFunction)Sbk_QImageFunc_createAlphaMask, METH_VARARGS|METH_KEYWORDS},
    {"createHeuristicMask", (PyCFunction)Sbk_QImageFunc_createHeuristicMask, METH_VARARGS|METH_KEYWORDS},
    {"createMaskFromColor", (PyCFunction)Sbk_QImageFunc_createMaskFromColor, METH_VARARGS|METH_KEYWORDS},
    {"depth", (PyCFunction)Sbk_QImageFunc_depth, METH_NOARGS},
    {"devType", (PyCFunction)Sbk_QImageFunc_devType, METH_NOARGS},
    {"dotsPerMeterX", (PyCFunction)Sbk_QImageFunc_dotsPerMeterX, METH_NOARGS},
    {"dotsPerMeterY", (PyCFunction)Sbk_QImageFunc_dotsPerMeterY, METH_NOARGS},
    {"fill", (PyCFunction)Sbk_QImageFunc_fill, METH_O},
    {"format", (PyCFunction)Sbk_QImageFunc_format, METH_NOARGS},
    {"fromData", (PyCFunction)Sbk_QImageFunc_fromData, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"hasAlphaChannel", (PyCFunction)Sbk_QImageFunc_hasAlphaChannel, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QImageFunc_height, METH_NOARGS},
    {"invertPixels", (PyCFunction)Sbk_QImageFunc_invertPixels, METH_VARARGS|METH_KEYWORDS},
    {"isGrayscale", (PyCFunction)Sbk_QImageFunc_isGrayscale, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QImageFunc_isNull, METH_NOARGS},
    {"load", (PyCFunction)Sbk_QImageFunc_load, METH_VARARGS|METH_KEYWORDS},
    {"loadFromData", (PyCFunction)Sbk_QImageFunc_loadFromData, METH_VARARGS|METH_KEYWORDS},
    {"metric", (PyCFunction)Sbk_QImageFunc_metric, METH_O},
    {"mirrored", (PyCFunction)Sbk_QImageFunc_mirrored, METH_VARARGS|METH_KEYWORDS},
    {"numBytes", (PyCFunction)Sbk_QImageFunc_numBytes, METH_NOARGS},
    {"numColors", (PyCFunction)Sbk_QImageFunc_numColors, METH_NOARGS},
    {"offset", (PyCFunction)Sbk_QImageFunc_offset, METH_NOARGS},
    {"paintEngine", (PyCFunction)Sbk_QImageFunc_paintEngine, METH_NOARGS},
    {"pixel", (PyCFunction)Sbk_QImageFunc_pixel, METH_VARARGS},
    {"pixelIndex", (PyCFunction)Sbk_QImageFunc_pixelIndex, METH_VARARGS},
    {"rect", (PyCFunction)Sbk_QImageFunc_rect, METH_NOARGS},
    {"rgbSwapped", (PyCFunction)Sbk_QImageFunc_rgbSwapped, METH_NOARGS},
    {"save", (PyCFunction)Sbk_QImageFunc_save, METH_VARARGS|METH_KEYWORDS},
    {"scaled", (PyCFunction)Sbk_QImageFunc_scaled, METH_VARARGS|METH_KEYWORDS},
    {"scaledToHeight", (PyCFunction)Sbk_QImageFunc_scaledToHeight, METH_VARARGS|METH_KEYWORDS},
    {"scaledToWidth", (PyCFunction)Sbk_QImageFunc_scaledToWidth, METH_VARARGS|METH_KEYWORDS},
    {"scanLine", (PyCFunction)Sbk_QImageFunc_scanLine, METH_O},
    {"setAlphaChannel", (PyCFunction)Sbk_QImageFunc_setAlphaChannel, METH_O},
    {"setColor", (PyCFunction)Sbk_QImageFunc_setColor, METH_VARARGS},
    {"setColorCount", (PyCFunction)Sbk_QImageFunc_setColorCount, METH_O},
    {"setColorTable", (PyCFunction)Sbk_QImageFunc_setColorTable, METH_O},
    {"setDotsPerMeterX", (PyCFunction)Sbk_QImageFunc_setDotsPerMeterX, METH_O},
    {"setDotsPerMeterY", (PyCFunction)Sbk_QImageFunc_setDotsPerMeterY, METH_O},
    {"setNumColors", (PyCFunction)Sbk_QImageFunc_setNumColors, METH_O},
    {"setOffset", (PyCFunction)Sbk_QImageFunc_setOffset, METH_O},
    {"setPixel", (PyCFunction)Sbk_QImageFunc_setPixel, METH_VARARGS},
    {"setText", (PyCFunction)Sbk_QImageFunc_setText, METH_VARARGS},
    {"size", (PyCFunction)Sbk_QImageFunc_size, METH_NOARGS},
    {"swap", (PyCFunction)Sbk_QImageFunc_swap, METH_O},
    {"text", (PyCFunction)Sbk_QImageFunc_text, METH_VARARGS|METH_KEYWORDS},
    {"textKeys", (PyCFunction)Sbk_QImageFunc_textKeys, METH_NOARGS},
    {"transformed", (PyCFunction)Sbk_QImageFunc_transformed, METH_VARARGS|METH_KEYWORDS},
    {"trueMatrix", (PyCFunction)Sbk_QImageFunc_trueMatrix, METH_VARARGS|METH_STATIC},
    {"valid", (PyCFunction)Sbk_QImageFunc_valid, METH_VARARGS},
    {"width", (PyCFunction)Sbk_QImageFunc_width, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QImage___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QImage___nb_bool(PyObject* self)
{
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QImageFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QImage)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QImage)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QImage) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QImageFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QImage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QImage&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QImage&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QImage&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImage.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QImage_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QImage& cppSelf = *(((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
                // operator!=(const QImage & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QImage cppArg0_local = ::QImage();
                ::QImage* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
                // operator==(const QImage & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QImage cppArg0_local = ::QImage();
                ::QImage* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
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
            goto Sbk_QImage_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QImage_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QImage_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QImage_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QImage_TypeAsNumber;

static SbkObjectType Sbk_QImage_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QImage",
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
    /*tp_traverse*/         Sbk_QImage_traverse,
    /*tp_clear*/            Sbk_QImage_clear,
    /*tp_richcompare*/      Sbk_QImage_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QImage_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QImage_Init,
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

static void* Sbk_QImage_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QImage*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QImage_InvertMode_PythonToCpp_QImage_InvertMode(PyObject* pyIn, void* cppOut) {
    *((::QImage::InvertMode*)cppOut) = (::QImage::InvertMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QImage_InvertMode_PythonToCpp_QImage_InvertMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX]))
        return QImage_InvertMode_PythonToCpp_QImage_InvertMode;
    return 0;
}
static PyObject* QImage_InvertMode_CppToPython_QImage_InvertMode(const void* cppIn) {
    int castCppIn = *((::QImage::InvertMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX], castCppIn);

}

static void QImage_Format_PythonToCpp_QImage_Format(PyObject* pyIn, void* cppOut) {
    *((::QImage::Format*)cppOut) = (::QImage::Format) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QImage_Format_PythonToCpp_QImage_Format_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]))
        return QImage_Format_PythonToCpp_QImage_Format;
    return 0;
}
static PyObject* QImage_Format_CppToPython_QImage_Format(const void* cppIn) {
    int castCppIn = *((::QImage::Format*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QImage_PythonToCpp_QImage_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QImage_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QImage_PythonToCpp_QImage_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QImage_Type))
        return QImage_PythonToCpp_QImage_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QImage_PTR_CppToPython_QImage(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QImage*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QImage_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QImage_COPY_CppToPython_QImage(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QImage_Type, new ::QImageWrapper(*((::QImage*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QImage_PythonToCpp_QImage_COPY(PyObject* pyIn, void* cppOut) {
    *((::QImage*)cppOut) = *((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QImage_PythonToCpp_QImage_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QImage_Type))
        return QImage_PythonToCpp_QImage_COPY;
    return 0;
}

void init_QImage(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QImage_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QImage_TypeAsNumber.nb_rshift = Sbk_QImageFunc___rshift__;
    Sbk_QImage_TypeAsNumber.nb_lshift = Sbk_QImageFunc___lshift__;
    SBK_NB_BOOL(Sbk_QImage_TypeAsNumber) = Sbk_QImage___nb_bool;
    Sbk_QImage_Type.super.ht_type.tp_as_number = &Sbk_QImage_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QImage_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QImage", "QImage",
        &Sbk_QImage_Type, &Shiboken::callCppDestructor< ::QImageWrapper >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QImage_Type,
        QImage_PythonToCpp_QImage_PTR,
        is_QImage_PythonToCpp_QImage_PTR_Convertible,
        QImage_PTR_CppToPython_QImage,
        QImage_COPY_CppToPython_QImage);

    Shiboken::Conversions::registerConverterName(converter, "QImage");
    Shiboken::Conversions::registerConverterName(converter, "QImage*");
    Shiboken::Conversions::registerConverterName(converter, "QImage&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QImage).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QImageWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QImage_PythonToCpp_QImage_COPY,
        is_QImage_PythonToCpp_QImage_COPY_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QImage_Type, &Sbk_QImage_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'InvertMode'.
    SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QImage_Type,
        "InvertMode",
        "PySide.QtGui.QImage.InvertMode",
        "QImage::InvertMode");
    if (!SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX],
        &Sbk_QImage_Type, "InvertRgb", (long) QImage::InvertRgb))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX],
        &Sbk_QImage_Type, "InvertRgba", (long) QImage::InvertRgba))
        return ;
    // Register converter for enum 'QImage::InvertMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX],
            QImage_InvertMode_CppToPython_QImage_InvertMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QImage_InvertMode_PythonToCpp_QImage_InvertMode,
            is_QImage_InvertMode_PythonToCpp_QImage_InvertMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QImage::InvertMode");
        Shiboken::Conversions::registerConverterName(converter, "InvertMode");
    }
    // End of 'InvertMode' enum.

    // Initialization of enum 'Format'.
    SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QImage_Type,
        "Format",
        "PySide.QtGui.QImage.Format",
        "QImage::Format");
    if (!SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_Invalid", (long) QImage::Format_Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_Mono", (long) QImage::Format_Mono))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_MonoLSB", (long) QImage::Format_MonoLSB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_Indexed8", (long) QImage::Format_Indexed8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_RGB32", (long) QImage::Format_RGB32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_ARGB32", (long) QImage::Format_ARGB32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_ARGB32_Premultiplied", (long) QImage::Format_ARGB32_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_RGB16", (long) QImage::Format_RGB16))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_ARGB8565_Premultiplied", (long) QImage::Format_ARGB8565_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_RGB666", (long) QImage::Format_RGB666))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_ARGB6666_Premultiplied", (long) QImage::Format_ARGB6666_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_RGB555", (long) QImage::Format_RGB555))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_ARGB8555_Premultiplied", (long) QImage::Format_ARGB8555_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_RGB888", (long) QImage::Format_RGB888))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_RGB444", (long) QImage::Format_RGB444))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
        &Sbk_QImage_Type, "Format_ARGB4444_Premultiplied", (long) QImage::Format_ARGB4444_Premultiplied))
        return ;
    // Register converter for enum 'QImage::Format'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX],
            QImage_Format_CppToPython_QImage_Format);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QImage_Format_PythonToCpp_QImage_Format,
            is_QImage_Format_PythonToCpp_QImage_Format_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QImage::Format");
        Shiboken::Conversions::registerConverterName(converter, "Format");
    }
    // End of 'Format' enum.


    qRegisterMetaType< ::QImage >("QImage");
    qRegisterMetaType< ::QImage::InvertMode >("QImage::InvertMode");
    qRegisterMetaType< ::QImage::Format >("QImage::Format");
}
