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

#include "qpixmap_wrapper.h"

// Extra includes
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcolor.h>
#include <qdatastream.h>
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

QPixmapWrapper::QPixmapWrapper() : QPixmap() {
    // ... middle
}

QPixmapWrapper::QPixmapWrapper(const QSize & arg__1) : QPixmap(arg__1) {
    // ... middle
}

QPixmapWrapper::QPixmapWrapper(const QString & fileName, const char * format, QFlags<Qt::ImageConversionFlag> flags) : QPixmap(fileName, format, flags) {
    // ... middle
}

QPixmapWrapper::QPixmapWrapper(const char ** xpm) : QPixmap(xpm) {
    // ... middle
}

QPixmapWrapper::QPixmapWrapper(int w, int h) : QPixmap(w, h) {
    // ... middle
}

int QPixmapWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPixmap.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QPixmapWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPixmap.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QPixmapWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPixmap.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPixmapWrapper::~QPixmapWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPixmap_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPixmap >()))
        return -1;

    ::QPixmapWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QPixmap", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QPixmap()
    // 1: QPixmap(QImage)
    // 2: QPixmap(QPixmap)
    // 3: QPixmap(QSize)
    // 4: QPixmap(QString,const char*,QFlags<Qt::ImageConversionFlag>)
    // 5: QPixmap(const char**)
    // 6: QPixmap(int,int)
    if (numArgs == 0) {
        overloadId = 0; // QPixmap()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 6; // QPixmap(int,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // QPixmap(QString,const char*,QFlags<Qt::ImageConversionFlag>)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 4; // QPixmap(QString,const char*,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 4; // QPixmap(QString,const char*,QFlags<Qt::ImageConversionFlag>)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        overloadId = 3; // QPixmap(QSize)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QPixmap(QImage)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        overloadId = 2; // QPixmap(QPixmap)
    } else if (numArgs == 1
        && PySequence_Check(pyArgs[0])) {
        overloadId = 5; // QPixmap(const char**)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmap_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPixmap()
        {

            if (!PyErr_Occurred()) {
                // QPixmap()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPixmapWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPixmap(QImage image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QImage cppArg0 = ::QImage();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // QPixmap(QImage)
                // Begin code injection

                cptr = new QPixmapWrapper(QPixmap::fromImage(cppArg0));

                // End of code injection

            }
            break;
        }
        case 2: // QPixmap(const QPixmap & arg__1)
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
                // QPixmap(QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPixmapWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QPixmap(const QSize & arg__1)
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
                // QPixmap(QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPixmapWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QPixmap(const QString & fileName, const char * format, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPixmap_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QPixmap_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::ImageConversionFlag> cppArg2 = Qt::AutoColor;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QPixmap(QString,const char*,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPixmapWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QPixmap(const char ** xpm)
        {

            if (!PyErr_Occurred()) {
                // QPixmap(const char**)
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
                cptr = new QPixmapWrapper(xpm);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                free(xpm);
                // TEMPLATE - load_xpm - END

                // End of code injection

            }
            break;
        }
        case 6: // QPixmap(int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QPixmap(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPixmapWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPixmap >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPixmap_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPixmap_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QImage", "PySide.QtGui.QPixmap", "PySide.QtCore.QSize", "unicode, " SBK_STR_NAME " = None, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "PySide.QtCore.char", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap", overloads);
        return -1;
}

static PyObject* Sbk_QPixmapFunc_alphaChannel(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alphaChannel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->alphaChannel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPixmapFunc_cacheKey(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QPixmap*>(cppSelf)->cacheKey();
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

static PyObject* Sbk_QPixmapFunc_convertFromImage(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.convertFromImage(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.convertFromImage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:convertFromImage", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: convertFromImage(QImage,QFlags<Qt::ImageConversionFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // convertFromImage(QImage,QFlags<Qt::ImageConversionFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // convertFromImage(QImage,QFlags<Qt::ImageConversionFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_convertFromImage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.convertFromImage(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_convertFromImage_TypeError;
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
            // convertFromImage(QImage,QFlags<Qt::ImageConversionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->convertFromImage(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_convertFromImage_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.convertFromImage", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_copy(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.copy(): too many arguments");
        return 0;
    } else if (numArgs == 2 || numArgs == 3)
        goto Sbk_QPixmapFunc_copy_TypeError;

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
    if (overloadId == -1) goto Sbk_QPixmapFunc_copy_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // copy(const QRect & rect) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rect");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.copy(): got multiple values for keyword argument 'rect'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0]))))
                        goto Sbk_QPixmapFunc_copy_TypeError;
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
                QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->copy(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // copy(int x, int y, int width, int height) const
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
                QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->copy(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_copy_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect = QRect()", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.copy", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_createHeuristicMask(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.createHeuristicMask(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_createHeuristicMask_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "clipTight");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.createHeuristicMask(): got multiple values for keyword argument 'clipTight'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_QPixmapFunc_createHeuristicMask_TypeError;
            }
        }
        bool cppArg0 = true;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // createHeuristicMask(bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->createHeuristicMask(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_createHeuristicMask_TypeError:
        const char* overloads[] = {"bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.createHeuristicMask", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_createMaskFromColor(PyObject* self, PyObject* args)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createMaskFromColor", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createMaskFromColor(QColor)const
    // 1: createMaskFromColor(QColor,Qt::MaskMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createMaskFromColor(QColor)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // createMaskFromColor(QColor,Qt::MaskMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_createMaskFromColor_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // createMaskFromColor(const QColor & maskColor) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // createMaskFromColor(QColor)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QBitmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->createMaskFromColor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // createMaskFromColor(const QColor & maskColor, Qt::MaskMode mode) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::MaskMode cppArg1 = ((::Qt::MaskMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // createMaskFromColor(QColor,Qt::MaskMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QBitmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->createMaskFromColor(*cppArg0, cppArg1);
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

    Sbk_QPixmapFunc_createMaskFromColor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor", "PySide.QtGui.QColor, PySide.QtCore.Qt.MaskMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.createMaskFromColor", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_defaultDepth(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultDepth()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QPixmap::defaultDepth();
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

static PyObject* Sbk_QPixmapFunc_depth(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // depth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPixmap*>(cppSelf)->depth();
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

static PyObject* Sbk_QPixmapFunc_devType(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPixmap*>(cppSelf)->::QPixmap::devType() : const_cast<const ::QPixmap*>(cppSelf)->devType();
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

static PyObject* Sbk_QPixmapFunc_fill(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fill(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:fill", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: fill(QColor)
    // 1: fill(const QWidget*,QPoint)
    // 2: fill(const QWidget*,int,int)
    if (numArgs == 0) {
        overloadId = 0; // fill(QColor)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 2; // fill(const QWidget*,int,int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
            overloadId = 1; // fill(const QWidget*,QPoint)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0])))) {
        overloadId = 0; // fill(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_fill_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fill(const QColor & fillColor)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fillColor");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fill(): got multiple values for keyword argument 'fillColor'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0]))))
                        goto Sbk_QPixmapFunc_fill_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QColor cppArg0_local = Qt::white;
            ::QColor* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // fill(QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // fill(const QWidget * widget, const QPoint & ofs)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPoint cppArg1_local = ::QPoint();
            ::QPoint* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // fill(const QWidget*,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // fill(const QWidget * widget, int xofs, int yofs)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // fill(const QWidget*,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapFunc_fill_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor = Qt.white", "PySide.QtGui.QWidget, PySide.QtCore.QPoint", "PySide.QtGui.QWidget, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.fill", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_fromImage(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromImage(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromImage(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_fromImage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromImage(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_fromImage_TypeError;
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
            QPixmap cppResult = ::QPixmap::fromImage(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_fromImage_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.fromImage", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_fromImageReader(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromImageReader(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromImageReader(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromImageReader", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromImageReader(QImageReader*,QFlags<Qt::ImageConversionFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromImageReader(QImageReader*,QFlags<Qt::ImageConversionFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromImageReader(QImageReader*,QFlags<Qt::ImageConversionFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_fromImageReader_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromImageReader(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_fromImageReader_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QImageReader* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::ImageConversionFlag> cppArg1 = Qt::AutoColor;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromImageReader(QImageReader*,QFlags<Qt::ImageConversionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = ::QPixmap::fromImageReader(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_fromImageReader_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImageReader, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.fromImageReader", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_fromX11Pixmap(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromX11Pixmap(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromX11Pixmap(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromX11Pixmap", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromX11Pixmap(Qt::HANDLE,QPixmap::ShareMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromX11Pixmap(Qt::HANDLE,QPixmap::ShareMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromX11Pixmap(Qt::HANDLE,QPixmap::ShareMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_fromX11Pixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.fromX11Pixmap(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_fromX11Pixmap_TypeError;
            }
        }
        ::Qt::HANDLE cppArg0 = ::Qt::HANDLE();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QPixmap::ShareMode cppArg1 = QPixmap::ImplicitlyShared;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromX11Pixmap(Qt::HANDLE,QPixmap::ShareMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = ::QPixmap::fromX11Pixmap(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_fromX11Pixmap_TypeError:
        const char* overloads[] = {"Qt::HANDLE, PySide.QtGui.QPixmap.ShareMode = ImplicitlyShared", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.fromX11Pixmap", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_grabWidget(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWidget(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWidget(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:grabWidget", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: grabWidget(QWidget*,QRect)
    // 1: grabWidget(QWidget*,int,int,int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // grabWidget(QWidget*,int,int,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // grabWidget(QWidget*,int,int,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // grabWidget(QWidget*,int,int,int,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 1; // grabWidget(QWidget*,int,int,int,int)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                        overloadId = 1; // grabWidget(QWidget*,int,int,int,int)
                    }
                }
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // grabWidget(QWidget*,QRect)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_grabWidget_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // grabWidget(QWidget * widget, const QRect & rect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRect cppArg1_local = ::QRect();
            ::QRect* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // grabWidget(QWidget*,QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmap cppResult = ::QPixmap::grabWidget(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // grabWidget(QWidget * widget, int x, int y, int w, int h)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "x");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWidget(): got multiple values for keyword argument 'x'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_grabWidget_TypeError;
                }
                value = PyDict_GetItemString(kwds, "y");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWidget(): got multiple values for keyword argument 'y'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_grabWidget_TypeError;
                }
                value = PyDict_GetItemString(kwds, "w");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWidget(): got multiple values for keyword argument 'w'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QPixmapFunc_grabWidget_TypeError;
                }
                value = PyDict_GetItemString(kwds, "h");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWidget(): got multiple values for keyword argument 'h'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QPixmapFunc_grabWidget_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = -1;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // grabWidget(QWidget*,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmap cppResult = ::QPixmap::grabWidget(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_grabWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.QRect", "PySide.QtGui.QWidget, int = 0, int = 0, int = -1, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.grabWidget", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_grabWindow(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWindow(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWindow(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:grabWindow", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: grabWindow(ulong,int,int,int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // grabWindow(ulong,int,int,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // grabWindow(ulong,int,int,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // grabWindow(ulong,int,int,int,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // grabWindow(ulong,int,int,int,int)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                        overloadId = 0; // grabWindow(ulong,int,int,int,int)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_grabWindow_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "x");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWindow(): got multiple values for keyword argument 'x'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_grabWindow_TypeError;
            }
            value = PyDict_GetItemString(kwds, "y");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWindow(): got multiple values for keyword argument 'y'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QPixmapFunc_grabWindow_TypeError;
            }
            value = PyDict_GetItemString(kwds, "w");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWindow(): got multiple values for keyword argument 'w'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QPixmapFunc_grabWindow_TypeError;
            }
            value = PyDict_GetItemString(kwds, "h");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.grabWindow(): got multiple values for keyword argument 'h'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QPixmapFunc_grabWindow_TypeError;
            }
        }
        unsigned long cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = -1;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4 = -1;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // grabWindow(ulong,int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = ::QPixmap::grabWindow(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_grabWindow_TypeError:
        const char* overloads[] = {"unsigned long, int = 0, int = 0, int = -1, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.grabWindow", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_handle(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QPixmap*>(cppSelf)->handle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPixmapFunc_hasAlpha(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAlpha()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPixmap*>(cppSelf)->hasAlpha();
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

static PyObject* Sbk_QPixmapFunc_hasAlphaChannel(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAlphaChannel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPixmap*>(cppSelf)->hasAlphaChannel();
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

static PyObject* Sbk_QPixmapFunc_height(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPixmap*>(cppSelf)->height();
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

static PyObject* Sbk_QPixmapFunc_isNull(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPixmap*>(cppSelf)->isNull();
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

static PyObject* Sbk_QPixmapFunc_isQBitmap(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isQBitmap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPixmap*>(cppSelf)->isQBitmap();
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

static PyObject* Sbk_QPixmapFunc_load(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.load(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.load(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:load", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: load(QString,const char*,QFlags<Qt::ImageConversionFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // load(QString,const char*,QFlags<Qt::ImageConversionFlag>)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // load(QString,const char*,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 0; // load(QString,const char*,QFlags<Qt::ImageConversionFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_load_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.load(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_load_TypeError;
            }
            value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.load(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2]))))
                    goto Sbk_QPixmapFunc_load_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::ImageConversionFlag> cppArg2 = Qt::AutoColor;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // load(QString,const char*,QFlags<Qt::ImageConversionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->load(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_load_TypeError:
        const char* overloads[] = {"unicode, " SBK_STR_NAME " = None, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.load", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_loadFromData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.loadFromData(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.loadFromData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:loadFromData", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: loadFromData(QByteArray,const char*,QFlags<Qt::ImageConversionFlag>)
    // 1: loadFromData(const uchar*,uint,const char*,QFlags<Qt::ImageConversionFlag>)
    if (PyBytes_Check(pyArgs[0])) {
        if (numArgs == 1) {
            overloadId = 1; // loadFromData(const uchar*,uint,const char*,QFlags<Qt::ImageConversionFlag>)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // loadFromData(const uchar*,uint,const char*,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // loadFromData(const uchar*,uint,const char*,QFlags<Qt::ImageConversionFlag>)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // loadFromData(QByteArray,const char*,QFlags<Qt::ImageConversionFlag>)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // loadFromData(QByteArray,const char*,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 0; // loadFromData(QByteArray,const char*,QFlags<Qt::ImageConversionFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_loadFromData_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // loadFromData(const QByteArray & data, const char * format, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.loadFromData(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_loadFromData_TypeError;
                }
                value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.loadFromData(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_loadFromData_TypeError;
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
            ::QFlags<Qt::ImageConversionFlag> cppArg2 = Qt::AutoColor;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // loadFromData(QByteArray,const char*,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->loadFromData(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // loadFromData(const uchar * buf, uint len, const char * format, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.loadFromData(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_loadFromData_TypeError;
                }
                value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.loadFromData(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_loadFromData_TypeError;
                }
            }
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::ImageConversionFlag> cppArg2 = Qt::AutoColor;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // loadFromData(const uchar*,uint,const char*,QFlags<Qt::ImageConversionFlag>)
                // Begin code injection

                const uchar* buf_out = reinterpret_cast<const uchar*>(PyBytes_AS_STRING(pyArgs[1-1]));


                uint len_out = static_cast<uint>(PyBytes_Size(pyArgs[1-1]));

                // End of code injection
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->loadFromData(buf_out, len_out, cppArg1, cppArg2);
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

    Sbk_QPixmapFunc_loadFromData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, " SBK_STR_NAME " = None, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "PySide.QtCore.uchar, unsigned int, " SBK_STR_NAME " = None, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.loadFromData", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_mask(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mask()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->mask();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPixmapFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPixmap*>(cppSelf)->::QPixmap::metric(cppArg0) : const_cast<const ::QPixmap*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.metric", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_paintEngine(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPixmap*>(cppSelf)->::QPixmap::paintEngine() : const_cast<const ::QPixmap*>(cppSelf)->paintEngine();
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

static PyObject* Sbk_QPixmapFunc_rect(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QPixmap*>(cppSelf)->rect();
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

static PyObject* Sbk_QPixmapFunc_save(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.save(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.save(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_save_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // save(QIODevice * device, const char * format, int quality) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.save(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_save_TypeError;
                }
                value = PyDict_GetItemString(kwds, "quality");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.save(): got multiple values for keyword argument 'quality'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_save_TypeError;
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
                bool cppResult = const_cast<const ::QPixmap*>(cppSelf)->save(cppArg0, cppArg1, cppArg2);
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
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.save(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_save_TypeError;
                }
                value = PyDict_GetItemString(kwds, "quality");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.save(): got multiple values for keyword argument 'quality'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_save_TypeError;
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
                bool cppResult = const_cast<const ::QPixmap*>(cppSelf)->save(cppArg0, cppArg1, cppArg2);
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

    Sbk_QPixmapFunc_save_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, " SBK_STR_NAME " = None, int = -1", "unicode, " SBK_STR_NAME " = None, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.save", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_scaled(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaled(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaled(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_scaled_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // scaled(const QSize & s, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectMode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaled(): got multiple values for keyword argument 'aspectMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_scaled_TypeError;
                }
                value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaled(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_scaled_TypeError;
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
                QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->scaled(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // scaled(int w, int h, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectMode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaled(): got multiple values for keyword argument 'aspectMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[2]))))
                        goto Sbk_QPixmapFunc_scaled_TypeError;
                }
                value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaled(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[3]))))
                        goto Sbk_QPixmapFunc_scaled_TypeError;
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
                QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->scaled(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_scaled_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", "int, int, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.scaled", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_scaledToHeight(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaledToHeight(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaledToHeight(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_scaledToHeight_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaledToHeight(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_scaledToHeight_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::TransformationMode cppArg1 = Qt::FastTransformation;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scaledToHeight(int,Qt::TransformationMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->scaledToHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_scaledToHeight_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.scaledToHeight", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_scaledToWidth(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaledToWidth(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaledToWidth(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_scaledToWidth_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scaledToWidth(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QPixmapFunc_scaledToWidth_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::TransformationMode cppArg1 = Qt::FastTransformation;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scaledToWidth(int,Qt::TransformationMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->scaledToWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_scaledToWidth_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.scaledToWidth", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_scroll(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scroll(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scroll(): not enough arguments");
        return 0;
    } else if (numArgs == 5)
        goto Sbk_QPixmapFunc_scroll_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOO:scroll", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: scroll(int,int,QRect,QRegion*)
    // 1: scroll(int,int,int,int,int,int,QRegion*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs >= 6
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
            && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
            if (numArgs == 6) {
                overloadId = 1; // scroll(int,int,int,int,int,int,QRegion*)
            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[6])))) {
                overloadId = 1; // scroll(int,int,int,int,int,int,QRegion*)
            }
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // scroll(int,int,QRect,QRegion*)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[3])))) {
                overloadId = 0; // scroll(int,int,QRect,QRegion*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_scroll_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // scroll(int dx, int dy, const QRect & rect, QRegion * exposed)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "exposed");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scroll(): got multiple values for keyword argument 'exposed'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[3]))))
                        goto Sbk_QPixmapFunc_scroll_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRect cppArg2_local = ::QRect();
            ::QRect* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QRegion* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // scroll(int,int,QRect,QRegion*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scroll(cppArg0, cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // scroll(int dx, int dy, int x, int y, int width, int height, QRegion * exposed)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "exposed");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.scroll(): got multiple values for keyword argument 'exposed'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[6]))))
                        goto Sbk_QPixmapFunc_scroll_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QRegion* cppArg6 = 0;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!PyErr_Occurred()) {
                // scroll(int,int,int,int,int,int,QRegion*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scroll(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapFunc_scroll_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QRect, PySide.QtGui.QRegion = None", "int, int, int, int, int, int, PySide.QtGui.QRegion = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.scroll", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_setAlphaChannel(PyObject* self, PyObject* pyArg)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlphaChannel(QPixmap)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArg)))) {
        overloadId = 0; // setAlphaChannel(QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_setAlphaChannel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPixmap cppArg0_local = ::QPixmap();
        ::QPixmap* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setAlphaChannel(QPixmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlphaChannel(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapFunc_setAlphaChannel_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.setAlphaChannel", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_setMask(PyObject* self, PyObject* pyArg)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMask(QBitmap)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBITMAP_IDX], (pyArg)))) {
        overloadId = 0; // setMask(QBitmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_setMask_TypeError;

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
            // setMask(QBitmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMask(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapFunc_setMask_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBitmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.setMask", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_size(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QPixmap*>(cppSelf)->size();
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

static PyObject* Sbk_QPixmapFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QPixmap&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArg)))) {
        overloadId = 0; // swap(QPixmap&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPixmap cppArg0_local = ::QPixmap();
        ::QPixmap* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QPixmap&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.swap", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_toImage(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toImage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QPixmap*>(cppSelf)->toImage();
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

static PyObject* Sbk_QPixmapFunc_transformed(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.transformed(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.transformed(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_transformed_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // transformed(const QMatrix & arg__1, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.transformed(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_transformed_TypeError;
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
                QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->transformed(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // transformed(const QTransform & arg__1, Qt::TransformationMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPixmap.transformed(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QPixmapFunc_transformed_TypeError;
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
                QPixmap cppResult = const_cast<const ::QPixmap*>(cppSelf)->transformed(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_transformed_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", "PySide.QtGui.QTransform, PySide.QtCore.Qt.TransformationMode = Qt.FastTransformation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.transformed", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_trueMatrix(PyObject* self, PyObject* args)
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
    if (overloadId == -1) goto Sbk_QPixmapFunc_trueMatrix_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // trueMatrix(const QMatrix & m, int w, int h)
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
                QMatrix cppResult = ::QPixmap::trueMatrix(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
            }
            break;
        }
        case 1: // trueMatrix(const QTransform & m, int w, int h)
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
                QTransform cppResult = ::QPixmap::trueMatrix(*cppArg0, cppArg1, cppArg2);
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

    Sbk_QPixmapFunc_trueMatrix_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix, int, int", "PySide.QtGui.QTransform, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPixmap.trueMatrix", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_width(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPixmap*>(cppSelf)->width();
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

static PyObject* Sbk_QPixmapFunc_x11Info(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x11Info()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QX11Info & cppResult = const_cast<const ::QPixmap*>(cppSelf)->x11Info();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPixmapFunc_x11PictureHandle(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x11PictureHandle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QPixmap*>(cppSelf)->x11PictureHandle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPixmapFunc_x11SetDefaultScreen(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: x11SetDefaultScreen(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // x11SetDefaultScreen(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_x11SetDefaultScreen_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // x11SetDefaultScreen(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QPixmap::x11SetDefaultScreen(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPixmapFunc_x11SetDefaultScreen_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.x11SetDefaultScreen", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc_x11SetScreen(PyObject* self, PyObject* pyArg)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: x11SetScreen(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // x11SetScreen(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc_x11SetScreen_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // x11SetScreen(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->x11SetScreen(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPixmapFunc_x11SetScreen_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.x11SetScreen", overloads);
        return 0;
}

static PyObject* Sbk_QPixmap___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPixmap& cppSelf = *(((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPixmap_methods[] = {
    {"alphaChannel", (PyCFunction)Sbk_QPixmapFunc_alphaChannel, METH_NOARGS},
    {"cacheKey", (PyCFunction)Sbk_QPixmapFunc_cacheKey, METH_NOARGS},
    {"convertFromImage", (PyCFunction)Sbk_QPixmapFunc_convertFromImage, METH_VARARGS|METH_KEYWORDS},
    {"copy", (PyCFunction)Sbk_QPixmapFunc_copy, METH_VARARGS|METH_KEYWORDS},
    {"createHeuristicMask", (PyCFunction)Sbk_QPixmapFunc_createHeuristicMask, METH_VARARGS|METH_KEYWORDS},
    {"createMaskFromColor", (PyCFunction)Sbk_QPixmapFunc_createMaskFromColor, METH_VARARGS},
    {"defaultDepth", (PyCFunction)Sbk_QPixmapFunc_defaultDepth, METH_NOARGS|METH_STATIC},
    {"depth", (PyCFunction)Sbk_QPixmapFunc_depth, METH_NOARGS},
    {"devType", (PyCFunction)Sbk_QPixmapFunc_devType, METH_NOARGS},
    {"fill", (PyCFunction)Sbk_QPixmapFunc_fill, METH_VARARGS|METH_KEYWORDS},
    {"fromImage", (PyCFunction)Sbk_QPixmapFunc_fromImage, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromImageReader", (PyCFunction)Sbk_QPixmapFunc_fromImageReader, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromX11Pixmap", (PyCFunction)Sbk_QPixmapFunc_fromX11Pixmap, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"grabWidget", (PyCFunction)Sbk_QPixmapFunc_grabWidget, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"grabWindow", (PyCFunction)Sbk_QPixmapFunc_grabWindow, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"handle", (PyCFunction)Sbk_QPixmapFunc_handle, METH_NOARGS},
    {"hasAlpha", (PyCFunction)Sbk_QPixmapFunc_hasAlpha, METH_NOARGS},
    {"hasAlphaChannel", (PyCFunction)Sbk_QPixmapFunc_hasAlphaChannel, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QPixmapFunc_height, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QPixmapFunc_isNull, METH_NOARGS},
    {"isQBitmap", (PyCFunction)Sbk_QPixmapFunc_isQBitmap, METH_NOARGS},
    {"load", (PyCFunction)Sbk_QPixmapFunc_load, METH_VARARGS|METH_KEYWORDS},
    {"loadFromData", (PyCFunction)Sbk_QPixmapFunc_loadFromData, METH_VARARGS|METH_KEYWORDS},
    {"mask", (PyCFunction)Sbk_QPixmapFunc_mask, METH_NOARGS},
    {"metric", (PyCFunction)Sbk_QPixmapFunc_metric, METH_O},
    {"paintEngine", (PyCFunction)Sbk_QPixmapFunc_paintEngine, METH_NOARGS},
    {"rect", (PyCFunction)Sbk_QPixmapFunc_rect, METH_NOARGS},
    {"save", (PyCFunction)Sbk_QPixmapFunc_save, METH_VARARGS|METH_KEYWORDS},
    {"scaled", (PyCFunction)Sbk_QPixmapFunc_scaled, METH_VARARGS|METH_KEYWORDS},
    {"scaledToHeight", (PyCFunction)Sbk_QPixmapFunc_scaledToHeight, METH_VARARGS|METH_KEYWORDS},
    {"scaledToWidth", (PyCFunction)Sbk_QPixmapFunc_scaledToWidth, METH_VARARGS|METH_KEYWORDS},
    {"scroll", (PyCFunction)Sbk_QPixmapFunc_scroll, METH_VARARGS|METH_KEYWORDS},
    {"setAlphaChannel", (PyCFunction)Sbk_QPixmapFunc_setAlphaChannel, METH_O},
    {"setMask", (PyCFunction)Sbk_QPixmapFunc_setMask, METH_O},
    {"size", (PyCFunction)Sbk_QPixmapFunc_size, METH_NOARGS},
    {"swap", (PyCFunction)Sbk_QPixmapFunc_swap, METH_O},
    {"toImage", (PyCFunction)Sbk_QPixmapFunc_toImage, METH_NOARGS},
    {"transformed", (PyCFunction)Sbk_QPixmapFunc_transformed, METH_VARARGS|METH_KEYWORDS},
    {"trueMatrix", (PyCFunction)Sbk_QPixmapFunc_trueMatrix, METH_VARARGS|METH_STATIC},
    {"width", (PyCFunction)Sbk_QPixmapFunc_width, METH_NOARGS},
    {"x11Info", (PyCFunction)Sbk_QPixmapFunc_x11Info, METH_NOARGS},
    {"x11PictureHandle", (PyCFunction)Sbk_QPixmapFunc_x11PictureHandle, METH_NOARGS},
    {"x11SetDefaultScreen", (PyCFunction)Sbk_QPixmapFunc_x11SetDefaultScreen, METH_O|METH_STATIC},
    {"x11SetScreen", (PyCFunction)Sbk_QPixmapFunc_x11SetScreen, METH_O},

    {"__copy__", (PyCFunction)Sbk_QPixmap___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QPixmap___nb_bool(PyObject* self)
{
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QPixmapFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QPixmap)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QPixmap)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QPixmap) [reverse operator]
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

    Sbk_QPixmapFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPixmapFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPixmap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QPixmap&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QPixmap&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPixmapFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QPixmap&) [reverse operator]
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

    Sbk_QPixmapFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPixmap.__rshift__", overloads);
        return 0;
}

} // extern "C"

static int Sbk_QPixmap_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPixmap_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QPixmap_TypeAsNumber;

static SbkObjectType Sbk_QPixmap_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPixmap",
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
    /*tp_traverse*/         Sbk_QPixmap_traverse,
    /*tp_clear*/            Sbk_QPixmap_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPixmap_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPixmap_Init,
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

static void* Sbk_QPixmap_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QPixmap*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QPixmap_ShareMode_PythonToCpp_QPixmap_ShareMode(PyObject* pyIn, void* cppOut) {
    *((::QPixmap::ShareMode*)cppOut) = (::QPixmap::ShareMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPixmap_ShareMode_PythonToCpp_QPixmap_ShareMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX]))
        return QPixmap_ShareMode_PythonToCpp_QPixmap_ShareMode;
    return 0;
}
static PyObject* QPixmap_ShareMode_CppToPython_QPixmap_ShareMode(const void* cppIn) {
    int castCppIn = *((::QPixmap::ShareMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPixmap_PythonToCpp_QPixmap_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPixmap_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPixmap_PythonToCpp_QPixmap_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPixmap_Type))
        return QPixmap_PythonToCpp_QPixmap_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPixmap_PTR_CppToPython_QPixmap(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPixmap*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPixmap_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPixmap_COPY_CppToPython_QPixmap(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPixmap_Type, new ::QPixmapWrapper(*((::QPixmap*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPixmap_PythonToCpp_QPixmap_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPixmap*)cppOut) = *((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPixmap_PythonToCpp_QPixmap_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPixmap_Type))
        return QPixmap_PythonToCpp_QPixmap_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQSizeREF_PythonToCpp_QPixmap(PyObject* pyIn, void* cppOut) {
    *((::QPixmap*)cppOut) = ::QPixmap(*((::QSize*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_constQSizeREF_PythonToCpp_QPixmap_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyIn))
        return PySide_QtCore_constQSizeREF_PythonToCpp_QPixmap;
    return 0;
}

static void PySide_QtCore_constQStringREF_PythonToCpp_QPixmap(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QPixmap*)cppOut) = ::QPixmap(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QPixmap_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QPixmap;
    return 0;
}

void init_QPixmap(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPixmap_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPixmap_TypeAsNumber.nb_rshift = Sbk_QPixmapFunc___rshift__;
    Sbk_QPixmap_TypeAsNumber.nb_lshift = Sbk_QPixmapFunc___lshift__;
    SBK_NB_BOOL(Sbk_QPixmap_TypeAsNumber) = Sbk_QPixmap___nb_bool;
    Sbk_QPixmap_Type.super.ht_type.tp_as_number = &Sbk_QPixmap_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPixmap_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPixmap", "QPixmap",
        &Sbk_QPixmap_Type, &Shiboken::callCppDestructor< ::QPixmapWrapper >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPixmap_Type,
        QPixmap_PythonToCpp_QPixmap_PTR,
        is_QPixmap_PythonToCpp_QPixmap_PTR_Convertible,
        QPixmap_PTR_CppToPython_QPixmap,
        QPixmap_COPY_CppToPython_QPixmap);

    Shiboken::Conversions::registerConverterName(converter, "QPixmap");
    Shiboken::Conversions::registerConverterName(converter, "QPixmap*");
    Shiboken::Conversions::registerConverterName(converter, "QPixmap&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPixmap).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPixmapWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPixmap_PythonToCpp_QPixmap_COPY,
        is_QPixmap_PythonToCpp_QPixmap_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQSizeREF_PythonToCpp_QPixmap,
        is_PySide_QtCore_constQSizeREF_PythonToCpp_QPixmap_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QPixmap,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QPixmap_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QPixmap_Type, &Sbk_QPixmap_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ShareMode'.
    SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPixmap_Type,
        "ShareMode",
        "PySide.QtGui.QPixmap.ShareMode",
        "QPixmap::ShareMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX],
        &Sbk_QPixmap_Type, "ImplicitlyShared", (long) QPixmap::ImplicitlyShared))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX],
        &Sbk_QPixmap_Type, "ExplicitlyShared", (long) QPixmap::ExplicitlyShared))
        return ;
    // Register converter for enum 'QPixmap::ShareMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX],
            QPixmap_ShareMode_CppToPython_QPixmap_ShareMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPixmap_ShareMode_PythonToCpp_QPixmap_ShareMode,
            is_QPixmap_ShareMode_PythonToCpp_QPixmap_ShareMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPIXMAP_SHAREMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPixmap::ShareMode");
        Shiboken::Conversions::registerConverterName(converter, "ShareMode");
    }
    // End of 'ShareMode' enum.


    qRegisterMetaType< ::QPixmap >("QPixmap");
    qRegisterMetaType< ::QPixmap::ShareMode >("QPixmap::ShareMode");
}
