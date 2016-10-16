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

#include "qcolor_wrapper.h"

// Extra includes
#include <QVariant>
#include <qcolor.h>
#include <qdatastream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QColor_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QColor >()))
        return -1;

    ::QColor* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor(): too many arguments");
        return -1;
    } else if (numArgs == 2)
        goto Sbk_QColor_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:QColor", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QColor()
    // 1: QColor(QVariant)
    // 2: QColor(Qt::GlobalColor)
    // 3: QColor(QColor)
    // 4: QColor(QString)
    // 5: QColor(int,int,int,int)
    // 6: QColor(uint)
    if (numArgs == 0) {
        overloadId = 0; // QColor()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 4; // QColor(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArgs[0])))) {
        overloadId = 2; // QColor(Qt::GlobalColor)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[0])))) {
        overloadId = 6; // QColor(uint)
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 5; // QColor(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 5; // QColor(int,int,int,int)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QColor(QVariant)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0])))) {
        overloadId = 3; // QColor(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColor_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QColor()
        {

            if (!PyErr_Occurred()) {
                // QColor()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QColor();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QColor(QVariant arg__1)
        {
            ::QVariant cppArg0 = ::QVariant();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // QColor(QVariant)
                // Begin code injection

                if (cppArg0.type() == QVariant::Color)
                    cptr = new QColor(cppArg0.value<QColor>());
                else
                    PyErr_SetString(PyExc_TypeError, "QVariant must be holding a QColor");

                // End of code injection

            }
            break;
        }
        case 2: // QColor(Qt::GlobalColor color)
        {
            ::Qt::GlobalColor cppArg0 = ((::Qt::GlobalColor)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QColor(Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QColor(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QColor(const QColor & color)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QColor(QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QColor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QColor(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QColor(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QColor(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QColor(int r, int g, int b, int a)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "a");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor(): got multiple values for keyword argument 'a'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QColor_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 255;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QColor(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QColor(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QColor(unsigned int rgb)
        {
            unsigned int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QColor(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QColor(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QColor >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QColor_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QColor_Init_TypeError:
        const char* overloads[] = {"", "QVariant", "PySide.QtCore.Qt.GlobalColor", "PySide.QtGui.QColor", "unicode", "int, int, int, int = 255", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor", overloads);
        return -1;
}

static PyObject* Sbk_QColorFunc___reduce__(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            switch(cppSelf->spec()) {
              case QColor::Rgb:
              {
                  qreal r, g, b, a;
                  cppSelf->getRgbF(&r, &g, &b, &a);
                  pyResult = Py_BuildValue("(ON(s(ffff)))", Py_TYPE(self), PyTuple_New(0), "setRgbF", (float)r, (float)g, (float)b, (float)a);
                  break;
              }
              case QColor::Hsv:
              {
                  qreal h, s, v, a;
                  cppSelf->getHsvF(&h, &s, &v, &a);
                  pyResult = Py_BuildValue("(ON(s(ffff)))", Py_TYPE(self), PyTuple_New(0), "setHsvF", (float)h, (float)s, (float)v, (float)a);
                  break;
              }
              case QColor::Cmyk:
              {
                  qreal c, m, y, k, a;
                  cppSelf->getCmykF(&c, &m, &y, &k, &a);
                  pyResult = Py_BuildValue("(ON(s(fffff)))", Py_TYPE(self), PyTuple_New(0), "setCmykF", (float)c, (float)m, (float)y, (float)k, (float)a);
                  break;
              }
              #if QT_VERSION >= 0x040600
              case QColor::Hsl:
              {
                  qreal h, s, l, a;
                  cppSelf->getHslF(&h, &s, &l, &a);
                  pyResult = Py_BuildValue("(ON(s(ffff)))", Py_TYPE(self), PyTuple_New(0), "setHslF", (float)h, (float)s, (float)l, (float)a);
                  break;
              }
              #endif
              default:
              {
                  pyResult = Py_BuildValue("(N(O))", PyObject_Type(self), Py_None);
              }
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc___repr__(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - qcolor_repr - START
            switch(cppSelf->spec()) {
            case QColor::Rgb:
            {
            qreal r, g, b, a;
            cppSelf->getRgbF(&r, &g, &b, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromRgbF(%.6f, %.6f, %.6f, %.6f)", r, g, b, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            case QColor::Hsv:
            {
            qreal h, s, v, a;
            cppSelf->getHsvF(&h, &s, &v, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromHsvF(%.6f, %.6f, %.6f, %.6f)", h, s, v, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            case QColor::Cmyk:
            {
            qreal c, m, y, k, a;
            cppSelf->getCmykF(&c, &m, &y, &k, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromCmykF(%.6f, %.6f, %.6f, %.6f, %.6f)", c, m, y, k, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            #if QT_VERSION >= 0x040600
            case QColor::Hsl:
            {
            qreal h, s, l, a;
            cppSelf->getHslF(&h, &s, &l, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromHslF(%.6f, %.6f, %.6f, %.6f)", h, s, l, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            #endif
            default:
            {
            pyResult = Shiboken::String::fromCString("PySide.QtGui.QColor()");
            }
            }
            // TEMPLATE - qcolor_repr - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc___setstate__(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: __setstate__(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // __setstate__(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc___setstate___TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __setstate__(PyObject*)
            // Begin code injection

            Shiboken::AutoDecRef func(PyObject_GetAttr(self, PyTuple_GET_ITEM(pyArg, 0)));
            PyObject* args = PyTuple_GET_ITEM(pyArg, 1);
            pyResult = PyObject_Call(func, args, NULL);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc___setstate___TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.__setstate__", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc___str__(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __str__()
            // Begin code injection

            // TEMPLATE - qcolor_repr - START
            switch(cppSelf->spec()) {
            case QColor::Rgb:
            {
            qreal r, g, b, a;
            cppSelf->getRgbF(&r, &g, &b, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromRgbF(%.6f, %.6f, %.6f, %.6f)", r, g, b, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            case QColor::Hsv:
            {
            qreal h, s, v, a;
            cppSelf->getHsvF(&h, &s, &v, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromHsvF(%.6f, %.6f, %.6f, %.6f)", h, s, v, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            case QColor::Cmyk:
            {
            qreal c, m, y, k, a;
            cppSelf->getCmykF(&c, &m, &y, &k, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromCmykF(%.6f, %.6f, %.6f, %.6f, %.6f)", c, m, y, k, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            #if QT_VERSION >= 0x040600
            case QColor::Hsl:
            {
            qreal h, s, l, a;
            cppSelf->getHslF(&h, &s, &l, &a);
            QString repr = QString().sprintf("PySide.QtGui.QColor.fromHslF(%.6f, %.6f, %.6f, %.6f)", h, s, l, a);
            pyResult = Shiboken::String::fromCString(qPrintable(repr));
            break;
            }
            #endif
            default:
            {
            pyResult = Shiboken::String::fromCString("PySide.QtGui.QColor()");
            }
            }
            // TEMPLATE - qcolor_repr - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_allowX11ColorNames(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allowX11ColorNames()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QColor::allowX11ColorNames();
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

static PyObject* Sbk_QColorFunc_alpha(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alpha()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->alpha();
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

static PyObject* Sbk_QColorFunc_alphaF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alphaF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->alphaF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_black(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // black()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->black();
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

static PyObject* Sbk_QColorFunc_blackF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blackF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->blackF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_blue(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->blue();
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

static PyObject* Sbk_QColorFunc_blueF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blueF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->blueF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_colorNames(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colorNames()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QColor::colorNames();
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

static PyObject* Sbk_QColorFunc_convertTo(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: convertTo(QColor::Spec)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX]), (pyArg)))) {
        overloadId = 0; // convertTo(QColor::Spec)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_convertTo_TypeError;

    // Call function/method
    {
        ::QColor::Spec cppArg0 = ((::QColor::Spec)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // convertTo(QColor::Spec)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->convertTo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_convertTo_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor.Spec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.convertTo", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_cyan(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cyan()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->cyan();
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

static PyObject* Sbk_QColorFunc_cyanF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cyanF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->cyanF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_darker(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.darker(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:darker", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: darker(int)const
    if (numArgs == 0) {
        overloadId = 0; // darker(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // darker(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_darker_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "f");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.darker(): got multiple values for keyword argument 'f'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QColorFunc_darker_TypeError;
            }
        }
        int cppArg0 = 200;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // darker(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->darker(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_darker_TypeError:
        const char* overloads[] = {"int = 200", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.darker", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromCmyk(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromCmyk(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromCmyk(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:fromCmyk", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: fromCmyk(int,int,int,int,int)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // fromCmyk(int,int,int,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            overloadId = 0; // fromCmyk(int,int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromCmyk_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromCmyk(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QColorFunc_fromCmyk_TypeError;
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
        int cppArg4 = 255;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // fromCmyk(int,int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromCmyk(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromCmyk_TypeError:
        const char* overloads[] = {"int, int, int, int, int = 255", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromCmyk", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromCmykF(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromCmykF(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromCmykF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:fromCmykF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: fromCmykF(qreal,qreal,qreal,qreal,qreal)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // fromCmykF(qreal,qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
            overloadId = 0; // fromCmykF(qreal,qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromCmykF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromCmykF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4]))))
                    goto Sbk_QColorFunc_fromCmykF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        qreal cppArg4 = 1.0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // fromCmykF(qreal,qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromCmykF(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromCmykF_TypeError:
        const char* overloads[] = {"float, float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromCmykF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromHsl(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsl(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fromHsl", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: fromHsl(int,int,int,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // fromHsl(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // fromHsl(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromHsl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsl(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_fromHsl_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 255;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fromHsl(int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromHsl(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromHsl_TypeError:
        const char* overloads[] = {"int, int, int, int = 255", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromHsl", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromHslF(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHslF(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHslF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fromHslF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: fromHslF(qreal,qreal,qreal,qreal)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // fromHslF(qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 0; // fromHslF(qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromHslF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHslF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_fromHslF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1.0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fromHslF(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromHslF(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromHslF_TypeError:
        const char* overloads[] = {"float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromHslF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromHsv(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsv(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsv(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fromHsv", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: fromHsv(int,int,int,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // fromHsv(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // fromHsv(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromHsv_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsv(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_fromHsv_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 255;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fromHsv(int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromHsv(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromHsv_TypeError:
        const char* overloads[] = {"int, int, int, int = 255", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromHsv", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromHsvF(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsvF(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsvF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fromHsvF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: fromHsvF(qreal,qreal,qreal,qreal)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // fromHsvF(qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 0; // fromHsvF(qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromHsvF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromHsvF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_fromHsvF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1.0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fromHsvF(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromHsvF(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromHsvF_TypeError:
        const char* overloads[] = {"float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromHsvF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromRgb(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromRgb(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromRgb(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_QColorFunc_fromRgb_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:fromRgb", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: fromRgb(int,int,int,int)
    // 1: fromRgb(uint)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[0])))) {
        overloadId = 1; // fromRgb(uint)
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // fromRgb(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // fromRgb(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromRgb_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fromRgb(int r, int g, int b, int a)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "a");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromRgb(): got multiple values for keyword argument 'a'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QColorFunc_fromRgb_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 255;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // fromRgb(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QColor cppResult = ::QColor::fromRgb(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
            }
            break;
        }
        case 1: // fromRgb(unsigned int rgb)
        {
            unsigned int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // fromRgb(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QColor cppResult = ::QColor::fromRgb(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromRgb_TypeError:
        const char* overloads[] = {"int, int, int, int = 255", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromRgb", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromRgbF(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromRgbF(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromRgbF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fromRgbF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: fromRgbF(qreal,qreal,qreal,qreal)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // fromRgbF(qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 0; // fromRgbF(qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromRgbF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.fromRgbF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_fromRgbF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1.0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fromRgbF(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromRgbF(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromRgbF_TypeError:
        const char* overloads[] = {"float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.fromRgbF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_fromRgba(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromRgba(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // fromRgba(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_fromRgba_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromRgba(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = ::QColor::fromRgba(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_fromRgba_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.fromRgba", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_getCmyk(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCmyk(int*,int*,int*,int*,int*)
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number*,number* - START
            int a, b, c, d, e;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->getCmyk(&a, &b, &c, &d, &e);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(5);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));
            PyTuple_SET_ITEM(pyResult, 4, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &e));
            // TEMPLATE - fix_number*,number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getCmykF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCmykF(qreal*,qreal*,qreal*,qreal*,qreal*)
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number*,number* - START
            qreal a, b, c, d, e;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->getCmykF(&a, &b, &c, &d, &e);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(5);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &d));
            PyTuple_SET_ITEM(pyResult, 4, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &e));
            // TEMPLATE - fix_number*,number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getHsl(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHsl(int*,int*,int*,int*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            int a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QColor::getHsl(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getHslF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHslF(qreal*,qreal*,qreal*,qreal*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            qreal a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QColor::getHslF(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getHsv(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHsv(int*,int*,int*,int*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            int a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QColor::getHsv(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getHsvF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHsvF(qreal*,qreal*,qreal*,qreal*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            qreal a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QColor::getHsvF(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getRgb(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getRgb(int*,int*,int*,int*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            int a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QColor::getRgb(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_getRgbF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getRgbF(qreal*,qreal*,qreal*,qreal*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            qreal a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QColor::getRgbF(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_green(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // green()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->green();
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

static PyObject* Sbk_QColorFunc_greenF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // greenF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->greenF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_hslHue(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hslHue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->hslHue();
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

static PyObject* Sbk_QColorFunc_hslHueF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hslHueF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->hslHueF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_hslSaturation(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hslSaturation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->hslSaturation();
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

static PyObject* Sbk_QColorFunc_hslSaturationF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hslSaturationF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->hslSaturationF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_hsvHue(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hsvHue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->hsvHue();
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

static PyObject* Sbk_QColorFunc_hsvHueF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hsvHueF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->hsvHueF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_hsvSaturation(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hsvSaturation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->hsvSaturation();
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

static PyObject* Sbk_QColorFunc_hsvSaturationF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hsvSaturationF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->hsvSaturationF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_hue(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->hue();
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

static PyObject* Sbk_QColorFunc_hueF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hueF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->hueF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_isValid(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QColor*>(cppSelf)->isValid();
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

static PyObject* Sbk_QColorFunc_isValidColor(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isValidColor(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isValidColor(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_isValidColor_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isValidColor(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QColor::isValidColor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_isValidColor_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.isValidColor", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_lighter(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.lighter(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:lighter", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: lighter(int)const
    if (numArgs == 0) {
        overloadId = 0; // lighter(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // lighter(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_lighter_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "f");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.lighter(): got multiple values for keyword argument 'f'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QColorFunc_lighter_TypeError;
            }
        }
        int cppArg0 = 150;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // lighter(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->lighter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QColorFunc_lighter_TypeError:
        const char* overloads[] = {"int = 150", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.lighter", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_lightness(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lightness()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->lightness();
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

static PyObject* Sbk_QColorFunc_lightnessF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lightnessF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->lightnessF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_magenta(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // magenta()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->magenta();
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

static PyObject* Sbk_QColorFunc_magentaF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // magentaF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->magentaF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_name(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QColor*>(cppSelf)->name();
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

static PyObject* Sbk_QColorFunc_red(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // red()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->red();
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

static PyObject* Sbk_QColorFunc_redF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // redF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->redF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_rgb(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rgb()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = const_cast<const ::QColor*>(cppSelf)->rgb();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_rgba(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rgba()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = const_cast<const ::QColor*>(cppSelf)->rgba();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_saturation(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // saturation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->saturation();
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

static PyObject* Sbk_QColorFunc_saturationF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // saturationF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->saturationF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_setAllowX11ColorNames(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAllowX11ColorNames(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAllowX11ColorNames(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setAllowX11ColorNames_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAllowX11ColorNames(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QColor::setAllowX11ColorNames(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setAllowX11ColorNames_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setAllowX11ColorNames", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setAlpha(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlpha(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setAlpha(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setAlpha_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlpha(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlpha(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setAlpha_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setAlpha", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setAlphaF(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlphaF(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setAlphaF(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setAlphaF_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlphaF(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlphaF(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setAlphaF_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setAlphaF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setBlue(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlue(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setBlue(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setBlue_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBlue(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setBlue_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setBlue", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setBlueF(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlueF(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBlueF(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setBlueF_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBlueF(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlueF(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setBlueF_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setBlueF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setCmyk(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setCmyk(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setCmyk(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:setCmyk", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setCmyk(int,int,int,int,int)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // setCmyk(int,int,int,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            overloadId = 0; // setCmyk(int,int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setCmyk_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setCmyk(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QColorFunc_setCmyk_TypeError;
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
        int cppArg4 = 255;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // setCmyk(int,int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCmyk(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setCmyk_TypeError:
        const char* overloads[] = {"int, int, int, int, int = 255", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setCmyk", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setCmykF(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setCmykF(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setCmykF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:setCmykF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setCmykF(qreal,qreal,qreal,qreal,qreal)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // setCmykF(qreal,qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
            overloadId = 0; // setCmykF(qreal,qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setCmykF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setCmykF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4]))))
                    goto Sbk_QColorFunc_setCmykF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        qreal cppArg4 = 1.0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // setCmykF(qreal,qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCmykF(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setCmykF_TypeError:
        const char* overloads[] = {"float, float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setCmykF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setGreen(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGreen(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setGreen(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setGreen_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGreen(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGreen(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setGreen_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setGreen", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setGreenF(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGreenF(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setGreenF(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setGreenF_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGreenF(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGreenF(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setGreenF_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setGreenF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setHsl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsl(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setHsl", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setHsl(int,int,int,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setHsl(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // setHsl(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setHsl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsl(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_setHsl_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 255;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setHsl(int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHsl(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setHsl_TypeError:
        const char* overloads[] = {"int, int, int, int = 255", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setHsl", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setHslF(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHslF(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHslF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setHslF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setHslF(qreal,qreal,qreal,qreal)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setHslF(qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 0; // setHslF(qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setHslF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHslF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_setHslF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1.0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setHslF(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHslF(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setHslF_TypeError:
        const char* overloads[] = {"float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setHslF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setHsv(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsv(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsv(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setHsv", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setHsv(int,int,int,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setHsv(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // setHsv(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setHsv_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsv(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_setHsv_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 255;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setHsv(int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHsv(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setHsv_TypeError:
        const char* overloads[] = {"int, int, int, int = 255", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setHsv", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setHsvF(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsvF(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsvF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setHsvF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setHsvF(qreal,qreal,qreal,qreal)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setHsvF(qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 0; // setHsvF(qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setHsvF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setHsvF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_setHsvF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1.0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setHsvF(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHsvF(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setHsvF_TypeError:
        const char* overloads[] = {"float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setHsvF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setNamedColor(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNamedColor(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setNamedColor(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setNamedColor_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNamedColor(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNamedColor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setNamedColor_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setNamedColor", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setRed(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRed(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setRed(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setRed_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRed(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRed(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setRed_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setRed", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setRedF(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRedF(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setRedF(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setRedF_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRedF(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRedF(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setRedF_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setRedF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setRgb(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setRgb(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setRgb(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_QColorFunc_setRgb_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:setRgb", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setRgb(int,int,int,int)
    // 1: setRgb(uint)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[0])))) {
        overloadId = 1; // setRgb(uint)
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setRgb(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // setRgb(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setRgb_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setRgb(int r, int g, int b, int a)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "a");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setRgb(): got multiple values for keyword argument 'a'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QColorFunc_setRgb_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 255;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setRgb(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setRgb(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setRgb(unsigned int rgb)
        {
            unsigned int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setRgb(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setRgb(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setRgb_TypeError:
        const char* overloads[] = {"int, int, int, int = 255", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setRgb", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setRgbF(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setRgbF(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setRgbF(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setRgbF", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setRgbF(qreal,qreal,qreal,qreal)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setRgbF(qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 0; // setRgbF(qreal,qreal,qreal,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setRgbF_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "a");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QColor.setRgbF(): got multiple values for keyword argument 'a'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QColorFunc_setRgbF_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1.0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setRgbF(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRgbF(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setRgbF_TypeError:
        const char* overloads[] = {"float, float, float, float = 1.0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QColor.setRgbF", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_setRgba(PyObject* self, PyObject* pyArg)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRgba(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // setRgba(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc_setRgba_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRgba(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRgba(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QColorFunc_setRgba_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.setRgba", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc_spec(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // spec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor::Spec cppResult = const_cast<const ::QColor*>(cppSelf)->spec();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_toCmyk(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toCmyk()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->toCmyk();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_toHsl(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toHsl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->toHsl();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_toHsv(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toHsv()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->toHsv();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_toRgb(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toRgb()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QColor*>(cppSelf)->toRgb();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_toTuple(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTuple()
            // Begin code injection

            switch(cppSelf->spec()) {
            case QColor::Rgb:
            {
                  int r, g, b, a;
                  cppSelf->getRgb(&r, &g, &b, &a);
                  pyResult = Py_BuildValue("iiii", r, g, b, a);
                  break;
            }
            case QColor::Hsv:
            {
                  int h, s, v, a;
                  cppSelf->getHsv(&h, &s, &v, &a);
                  pyResult = Py_BuildValue("iiii", h, s, v, a);
                  break;
            }
            case QColor::Cmyk:
            {
                  int c, m, y, k, a;
                  cppSelf->getCmyk(&c, &m, &y, &k, &a);
                  pyResult = Py_BuildValue("iiiii", c, m, y, k, a);
                  break;
            }
            case QColor::Hsl:
            {
                  int h, s, l, a;
                  cppSelf->getHsl(&h, &s, &l, &a);
                  pyResult = Py_BuildValue("iiii", h, s, l, a);
                  break;
            }
            default:
            {
                  pyResult = 0;
            }
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_value(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // value()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->value();
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

static PyObject* Sbk_QColorFunc_valueF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // valueF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->valueF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColorFunc_yellow(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // yellow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QColor*>(cppSelf)->yellow();
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

static PyObject* Sbk_QColorFunc_yellowF(PyObject* self)
{
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // yellowF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QColor*>(cppSelf)->yellowF();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QColor___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QColor& cppSelf = *(((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QColor_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QColorFunc___reduce__, METH_NOARGS},
    {"__setstate__", (PyCFunction)Sbk_QColorFunc___setstate__, METH_O},
    {"allowX11ColorNames", (PyCFunction)Sbk_QColorFunc_allowX11ColorNames, METH_NOARGS|METH_STATIC},
    {"alpha", (PyCFunction)Sbk_QColorFunc_alpha, METH_NOARGS},
    {"alphaF", (PyCFunction)Sbk_QColorFunc_alphaF, METH_NOARGS},
    {"black", (PyCFunction)Sbk_QColorFunc_black, METH_NOARGS},
    {"blackF", (PyCFunction)Sbk_QColorFunc_blackF, METH_NOARGS},
    {"blue", (PyCFunction)Sbk_QColorFunc_blue, METH_NOARGS},
    {"blueF", (PyCFunction)Sbk_QColorFunc_blueF, METH_NOARGS},
    {"colorNames", (PyCFunction)Sbk_QColorFunc_colorNames, METH_NOARGS|METH_STATIC},
    {"convertTo", (PyCFunction)Sbk_QColorFunc_convertTo, METH_O},
    {"cyan", (PyCFunction)Sbk_QColorFunc_cyan, METH_NOARGS},
    {"cyanF", (PyCFunction)Sbk_QColorFunc_cyanF, METH_NOARGS},
    {"darker", (PyCFunction)Sbk_QColorFunc_darker, METH_VARARGS|METH_KEYWORDS},
    {"fromCmyk", (PyCFunction)Sbk_QColorFunc_fromCmyk, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromCmykF", (PyCFunction)Sbk_QColorFunc_fromCmykF, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromHsl", (PyCFunction)Sbk_QColorFunc_fromHsl, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromHslF", (PyCFunction)Sbk_QColorFunc_fromHslF, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromHsv", (PyCFunction)Sbk_QColorFunc_fromHsv, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromHsvF", (PyCFunction)Sbk_QColorFunc_fromHsvF, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromRgb", (PyCFunction)Sbk_QColorFunc_fromRgb, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromRgbF", (PyCFunction)Sbk_QColorFunc_fromRgbF, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromRgba", (PyCFunction)Sbk_QColorFunc_fromRgba, METH_O|METH_STATIC},
    {"getCmyk", (PyCFunction)Sbk_QColorFunc_getCmyk, METH_NOARGS},
    {"getCmykF", (PyCFunction)Sbk_QColorFunc_getCmykF, METH_NOARGS},
    {"getHsl", (PyCFunction)Sbk_QColorFunc_getHsl, METH_NOARGS},
    {"getHslF", (PyCFunction)Sbk_QColorFunc_getHslF, METH_NOARGS},
    {"getHsv", (PyCFunction)Sbk_QColorFunc_getHsv, METH_NOARGS},
    {"getHsvF", (PyCFunction)Sbk_QColorFunc_getHsvF, METH_NOARGS},
    {"getRgb", (PyCFunction)Sbk_QColorFunc_getRgb, METH_NOARGS},
    {"getRgbF", (PyCFunction)Sbk_QColorFunc_getRgbF, METH_NOARGS},
    {"green", (PyCFunction)Sbk_QColorFunc_green, METH_NOARGS},
    {"greenF", (PyCFunction)Sbk_QColorFunc_greenF, METH_NOARGS},
    {"hslHue", (PyCFunction)Sbk_QColorFunc_hslHue, METH_NOARGS},
    {"hslHueF", (PyCFunction)Sbk_QColorFunc_hslHueF, METH_NOARGS},
    {"hslSaturation", (PyCFunction)Sbk_QColorFunc_hslSaturation, METH_NOARGS},
    {"hslSaturationF", (PyCFunction)Sbk_QColorFunc_hslSaturationF, METH_NOARGS},
    {"hsvHue", (PyCFunction)Sbk_QColorFunc_hsvHue, METH_NOARGS},
    {"hsvHueF", (PyCFunction)Sbk_QColorFunc_hsvHueF, METH_NOARGS},
    {"hsvSaturation", (PyCFunction)Sbk_QColorFunc_hsvSaturation, METH_NOARGS},
    {"hsvSaturationF", (PyCFunction)Sbk_QColorFunc_hsvSaturationF, METH_NOARGS},
    {"hue", (PyCFunction)Sbk_QColorFunc_hue, METH_NOARGS},
    {"hueF", (PyCFunction)Sbk_QColorFunc_hueF, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QColorFunc_isValid, METH_NOARGS},
    {"isValidColor", (PyCFunction)Sbk_QColorFunc_isValidColor, METH_O|METH_STATIC},
    {"lighter", (PyCFunction)Sbk_QColorFunc_lighter, METH_VARARGS|METH_KEYWORDS},
    {"lightness", (PyCFunction)Sbk_QColorFunc_lightness, METH_NOARGS},
    {"lightnessF", (PyCFunction)Sbk_QColorFunc_lightnessF, METH_NOARGS},
    {"magenta", (PyCFunction)Sbk_QColorFunc_magenta, METH_NOARGS},
    {"magentaF", (PyCFunction)Sbk_QColorFunc_magentaF, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QColorFunc_name, METH_NOARGS},
    {"red", (PyCFunction)Sbk_QColorFunc_red, METH_NOARGS},
    {"redF", (PyCFunction)Sbk_QColorFunc_redF, METH_NOARGS},
    {"rgb", (PyCFunction)Sbk_QColorFunc_rgb, METH_NOARGS},
    {"rgba", (PyCFunction)Sbk_QColorFunc_rgba, METH_NOARGS},
    {"saturation", (PyCFunction)Sbk_QColorFunc_saturation, METH_NOARGS},
    {"saturationF", (PyCFunction)Sbk_QColorFunc_saturationF, METH_NOARGS},
    {"setAllowX11ColorNames", (PyCFunction)Sbk_QColorFunc_setAllowX11ColorNames, METH_O|METH_STATIC},
    {"setAlpha", (PyCFunction)Sbk_QColorFunc_setAlpha, METH_O},
    {"setAlphaF", (PyCFunction)Sbk_QColorFunc_setAlphaF, METH_O},
    {"setBlue", (PyCFunction)Sbk_QColorFunc_setBlue, METH_O},
    {"setBlueF", (PyCFunction)Sbk_QColorFunc_setBlueF, METH_O},
    {"setCmyk", (PyCFunction)Sbk_QColorFunc_setCmyk, METH_VARARGS|METH_KEYWORDS},
    {"setCmykF", (PyCFunction)Sbk_QColorFunc_setCmykF, METH_VARARGS|METH_KEYWORDS},
    {"setGreen", (PyCFunction)Sbk_QColorFunc_setGreen, METH_O},
    {"setGreenF", (PyCFunction)Sbk_QColorFunc_setGreenF, METH_O},
    {"setHsl", (PyCFunction)Sbk_QColorFunc_setHsl, METH_VARARGS|METH_KEYWORDS},
    {"setHslF", (PyCFunction)Sbk_QColorFunc_setHslF, METH_VARARGS|METH_KEYWORDS},
    {"setHsv", (PyCFunction)Sbk_QColorFunc_setHsv, METH_VARARGS|METH_KEYWORDS},
    {"setHsvF", (PyCFunction)Sbk_QColorFunc_setHsvF, METH_VARARGS|METH_KEYWORDS},
    {"setNamedColor", (PyCFunction)Sbk_QColorFunc_setNamedColor, METH_O},
    {"setRed", (PyCFunction)Sbk_QColorFunc_setRed, METH_O},
    {"setRedF", (PyCFunction)Sbk_QColorFunc_setRedF, METH_O},
    {"setRgb", (PyCFunction)Sbk_QColorFunc_setRgb, METH_VARARGS|METH_KEYWORDS},
    {"setRgbF", (PyCFunction)Sbk_QColorFunc_setRgbF, METH_VARARGS|METH_KEYWORDS},
    {"setRgba", (PyCFunction)Sbk_QColorFunc_setRgba, METH_O},
    {"spec", (PyCFunction)Sbk_QColorFunc_spec, METH_NOARGS},
    {"toCmyk", (PyCFunction)Sbk_QColorFunc_toCmyk, METH_NOARGS},
    {"toHsl", (PyCFunction)Sbk_QColorFunc_toHsl, METH_NOARGS},
    {"toHsv", (PyCFunction)Sbk_QColorFunc_toHsv, METH_NOARGS},
    {"toRgb", (PyCFunction)Sbk_QColorFunc_toRgb, METH_NOARGS},
    {"toTuple", (PyCFunction)Sbk_QColorFunc_toTuple, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QColorFunc_value, METH_NOARGS},
    {"valueF", (PyCFunction)Sbk_QColorFunc_valueF, METH_NOARGS},
    {"yellow", (PyCFunction)Sbk_QColorFunc_yellow, METH_NOARGS},
    {"yellowF", (PyCFunction)Sbk_QColorFunc_yellowF, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QColor___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QColorFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QColor)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QColor)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QColor) [reverse operator]
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

    Sbk_QColorFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QColorFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QColor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QColor&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QColor&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QColorFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QColor&) [reverse operator]
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

    Sbk_QColorFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QColor.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QColor_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QColor& cppSelf = *(((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
                // operator!=(const QColor & c) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QColor cppArg0_local = ::QColor();
                ::QColor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
                // operator==(const QColor & c) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QColor cppArg0_local = ::QColor();
                ::QColor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
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
            goto Sbk_QColor_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QColor_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QColor_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QColor_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QColor_TypeAsNumber;

static SbkObjectType Sbk_QColor_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QColor",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QColorFunc___repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              Sbk_QColorFunc___str__,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QColor_traverse,
    /*tp_clear*/            Sbk_QColor_clear,
    /*tp_richcompare*/      Sbk_QColor_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QColor_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QColor_Init,
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
static void QColor_Spec_PythonToCpp_QColor_Spec(PyObject* pyIn, void* cppOut) {
    *((::QColor::Spec*)cppOut) = (::QColor::Spec) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QColor_Spec_PythonToCpp_QColor_Spec_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX]))
        return QColor_Spec_PythonToCpp_QColor_Spec;
    return 0;
}
static PyObject* QColor_Spec_CppToPython_QColor_Spec(const void* cppIn) {
    int castCppIn = *((::QColor::Spec*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QColor_PythonToCpp_QColor_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QColor_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QColor_PythonToCpp_QColor_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QColor_Type))
        return QColor_PythonToCpp_QColor_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QColor_PTR_CppToPython_QColor(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QColor*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QColor_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QColor_COPY_CppToPython_QColor(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QColor_Type, new ::QColor(*((::QColor*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QColor_PythonToCpp_QColor_COPY(PyObject* pyIn, void* cppOut) {
    *((::QColor*)cppOut) = *((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QColor_PythonToCpp_QColor_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QColor_Type))
        return QColor_PythonToCpp_QColor_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_Qt_GlobalColor_PythonToCpp_QColor(PyObject* pyIn, void* cppOut) {
    ::Qt::GlobalColor cppIn = ((::Qt::GlobalColor)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), pyIn, &cppIn);
    *((::QColor*)cppOut) = ::QColor(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_Qt_GlobalColor_PythonToCpp_QColor_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX], pyIn))
        return PySide_QtCore_Qt_GlobalColor_PythonToCpp_QColor;
    return 0;
}

static void PySide_QtCore_constQStringREF_PythonToCpp_QColor(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QColor*)cppOut) = ::QColor(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QColor_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QColor;
    return 0;
}

static void PySide_QtCore_unsignedint_PythonToCpp_QColor(PyObject* pyIn, void* cppOut) {
    unsigned int cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), pyIn, &cppIn);
    *((::QColor*)cppOut) = ::QColor(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_unsignedint_PythonToCpp_QColor_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_unsignedint_PythonToCpp_QColor;
    return 0;
}

void init_QColor(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QColor_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QColor_TypeAsNumber.nb_rshift = Sbk_QColorFunc___rshift__;
    Sbk_QColor_TypeAsNumber.nb_lshift = Sbk_QColorFunc___lshift__;
    Sbk_QColor_Type.super.ht_type.tp_as_number = &Sbk_QColor_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QColor_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QColor", "QColor",
        &Sbk_QColor_Type, &Shiboken::callCppDestructor< ::QColor >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QColor_Type,
        QColor_PythonToCpp_QColor_PTR,
        is_QColor_PythonToCpp_QColor_PTR_Convertible,
        QColor_PTR_CppToPython_QColor,
        QColor_COPY_CppToPython_QColor);

    Shiboken::Conversions::registerConverterName(converter, "QColor");
    Shiboken::Conversions::registerConverterName(converter, "QColor*");
    Shiboken::Conversions::registerConverterName(converter, "QColor&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QColor).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QColor_PythonToCpp_QColor_COPY,
        is_QColor_PythonToCpp_QColor_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_Qt_GlobalColor_PythonToCpp_QColor,
        is_PySide_QtCore_Qt_GlobalColor_PythonToCpp_QColor_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QColor,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QColor_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_unsignedint_PythonToCpp_QColor,
        is_PySide_QtCore_unsignedint_PythonToCpp_QColor_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Spec'.
    SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QColor_Type,
        "Spec",
        "PySide.QtGui.QColor.Spec",
        "QColor::Spec");
    if (!SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX],
        &Sbk_QColor_Type, "Invalid", (long) QColor::Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX],
        &Sbk_QColor_Type, "Rgb", (long) QColor::Rgb))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX],
        &Sbk_QColor_Type, "Hsv", (long) QColor::Hsv))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX],
        &Sbk_QColor_Type, "Cmyk", (long) QColor::Cmyk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX],
        &Sbk_QColor_Type, "Hsl", (long) QColor::Hsl))
        return ;
    // Register converter for enum 'QColor::Spec'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX],
            QColor_Spec_CppToPython_QColor_Spec);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QColor_Spec_PythonToCpp_QColor_Spec,
            is_QColor_Spec_PythonToCpp_QColor_Spec_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCOLOR_SPEC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QColor::Spec");
        Shiboken::Conversions::registerConverterName(converter, "Spec");
    }
    // End of 'Spec' enum.


    qRegisterMetaType< ::QColor >("QColor");
    qRegisterMetaType< ::QColor::Spec >("QColor::Spec");
}
