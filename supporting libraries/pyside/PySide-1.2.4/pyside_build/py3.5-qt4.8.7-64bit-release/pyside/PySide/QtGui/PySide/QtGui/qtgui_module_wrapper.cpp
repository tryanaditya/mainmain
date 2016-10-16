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
#include "pyside_qtgui_python.h"

#include <qrgb.h>


// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtGuiTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtGuiTypeConverters;
    // Begin code injection

    PyObject* moduleQtGui;

    // End of code injection

void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtGui_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtGuiTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------
static PyObject* SbkQtGuiModule_qAlpha(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qAlpha(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // qAlpha(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qAlpha_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qAlpha(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = qAlpha(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qAlpha_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qAlpha", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qBlue(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qBlue(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // qBlue(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qBlue_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qBlue(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = qBlue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qBlue_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qBlue", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qGray(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto SbkQtGuiModule_qGray_TypeError;

    if (!PyArg_UnpackTuple(args, "qGray", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: qGray(uint)
    // 1: qGray(int,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 1; // qGray(int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[0])))) {
        overloadId = 0; // qGray(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qGray_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // qGray(unsigned int rgb)
        {
            unsigned int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // qGray(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = qGray(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // qGray(int r, int g, int b)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // qGray(int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = qGray(cppArg0, cppArg1, cppArg2);
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

    SbkQtGuiModule_qGray_TypeError:
        const char* overloads[] = {"unsigned int", "int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qGray", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qGreen(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qGreen(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // qGreen(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qGreen_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qGreen(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = qGreen(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qGreen_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qGreen", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qIsGray(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qIsGray(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // qIsGray(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qIsGray_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qIsGray(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = qIsGray(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qIsGray_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qIsGray", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qRed(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qRed(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArg)))) {
        overloadId = 0; // qRed(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qRed_TypeError;

    // Call function/method
    {
        unsigned int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qRed(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = qRed(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qRed_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "qRed", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qRgb(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qRgb", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: qRgb(int,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // qRgb(int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qRgb_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // qRgb(int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = qRgb(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qRgb_TypeError:
        const char* overloads[] = {"int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qRgb", overloads);
        return 0;
}

static PyObject* SbkQtGuiModule_qRgba(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qRgba", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: qRgba(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 0; // qRgba(int,int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto SbkQtGuiModule_qRgba_TypeError;

    // Call function/method
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
            // qRgba(int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned int cppResult = qRgba(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    SbkQtGuiModule_qRgba_TypeError:
        const char* overloads[] = {"int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "qRgba", overloads);
        return 0;
}


static PyMethodDef QtGui_methods[] = {
    {"qAlpha", (PyCFunction)SbkQtGuiModule_qAlpha, METH_O},
    {"qBlue", (PyCFunction)SbkQtGuiModule_qBlue, METH_O},
    {"qGray", (PyCFunction)SbkQtGuiModule_qGray, METH_VARARGS},
    {"qGreen", (PyCFunction)SbkQtGuiModule_qGreen, METH_O},
    {"qIsGray", (PyCFunction)SbkQtGuiModule_qIsGray, METH_O},
    {"qRed", (PyCFunction)SbkQtGuiModule_qRed, METH_O},
    {"qRgb", (PyCFunction)SbkQtGuiModule_qRgb, METH_VARARGS},
    {"qRgba", (PyCFunction)SbkQtGuiModule_qRgba, METH_VARARGS},
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QImageWriter(PyObject* module);
void init_QImageReader(PyObject* module);
void init_QTextLayout(PyObject* module);
void init_QTextLayout_FormatRange(PyObject* module);
void init_QDragLeaveEvent(PyObject* module);
void init_QHelpEvent(PyObject* module);
void init_QStatusTipEvent(PyObject* module);
void init_QWhatsThisClickedEvent(PyObject* module);
void init_QActionEvent(PyObject* module);
void init_QFileOpenEvent(PyObject* module);
void init_QToolBarChangeEvent(PyObject* module);
void init_QShortcutEvent(PyObject* module);
void init_QClipboardEvent(PyObject* module);
void init_QWindowStateChangeEvent(PyObject* module);
void init_QGestureEvent(PyObject* module);
void init_QPaintEvent(PyObject* module);
void init_QMoveEvent(PyObject* module);
void init_QResizeEvent(PyObject* module);
void init_QCloseEvent(PyObject* module);
void init_QIconDragEvent(PyObject* module);
void init_QShowEvent(PyObject* module);
void init_QHideEvent(PyObject* module);
void init_QHoverEvent(PyObject* module);
void init_QAccessibleEvent(PyObject* module);
void init_QGraphicsSceneEvent(PyObject* module);
void init_QGraphicsSceneMouseEvent(PyObject* module);
void init_QGraphicsSceneWheelEvent(PyObject* module);
void init_QGraphicsSceneContextMenuEvent(PyObject* module);
void init_QGraphicsSceneHoverEvent(PyObject* module);
void init_QGraphicsSceneHelpEvent(PyObject* module);
void init_QGraphicsSceneDragDropEvent(PyObject* module);
void init_QGraphicsSceneResizeEvent(PyObject* module);
void init_QGraphicsSceneMoveEvent(PyObject* module);
void init_QInputMethodEvent(PyObject* module);
void init_QInputMethodEvent_Attribute(PyObject* module);
void init_QDropEvent(PyObject* module);
void init_QDragMoveEvent(PyObject* module);
void init_QDragEnterEvent(PyObject* module);
void init_QPolygon(PyObject* module);
void init_QPolygonF(PyObject* module);
void init_QMatrix(PyObject* module);
void init_QPainterPathStroker(PyObject* module);
void init_QPaintDevice(PyObject* module);
void init_QPrinter(PyObject* module);
void init_QPicture(PyObject* module);
void init_QColor(PyObject* module);
void init_QSizePolicy(PyObject* module);
void init_QGraphicsLayoutItem(PyObject* module);
void init_QGraphicsLayout(PyObject* module);
void init_QGraphicsGridLayout(PyObject* module);
void init_QGraphicsLinearLayout(PyObject* module);
void init_QKeySequence(PyObject* module);
void init_QFont(PyObject* module);
void init_QGradient(PyObject* module);
void init_QConicalGradient(PyObject* module);
void init_QLinearGradient(PyObject* module);
void init_QRadialGradient(PyObject* module);
void init_QPalette(PyObject* module);
void init_QVector3D(PyObject* module);
void init_QVector4D(PyObject* module);
void init_QQuaternion(PyObject* module);
void init_QMatrix4x4(PyObject* module);
void init_QTextOption(PyObject* module);
void init_QTextOption_Tab(PyObject* module);
void init_QFontInfo(PyObject* module);
void init_QFontMetrics(PyObject* module);
void init_QFontMetricsF(PyObject* module);
void init_QCursor(PyObject* module);
void init_QLayoutItem(PyObject* module);
void init_QWidgetItem(PyObject* module);
void init_QSpacerItem(PyObject* module);
void init_QGestureRecognizer(PyObject* module);
void init_QToolTip(PyObject* module);
void init_QWhatsThis(PyObject* module);
void init_QTextItem(PyObject* module);
void init_QPaintEngineState(PyObject* module);
void init_QPrintEngine(PyObject* module);
void init_QPrinterInfo(PyObject* module);
void init_QTextLength(PyObject* module);
void init_QTextFormat(PyObject* module);
void init_QTextFrameFormat(PyObject* module);
void init_QTextTableFormat(PyObject* module);
void init_QTextCharFormat(PyObject* module);
void init_QTextImageFormat(PyObject* module);
void init_QTextTableCellFormat(PyObject* module);
void init_QTextBlockFormat(PyObject* module);
void init_QTextListFormat(PyObject* module);
void init_QTextCursor(PyObject* module);
void init_QStyleOption(PyObject* module);
void init_QStyleOptionToolBar(PyObject* module);
void init_QStyleHintReturn(PyObject* module);
void init_QStyleHintReturnMask(PyObject* module);
void init_QStyleHintReturnVariant(PyObject* module);
void init_QStyleOptionTabWidgetFrame(PyObject* module);
void init_QStyleOptionProgressBar(PyObject* module);
void init_QStyleOptionProgressBarV2(PyObject* module);
void init_QStyleOptionMenuItem(PyObject* module);
void init_QStyleOptionTabBarBase(PyObject* module);
void init_QStyleOptionTabBarBaseV2(PyObject* module);
void init_QStyleOptionButton(PyObject* module);
void init_QStyleOptionDockWidget(PyObject* module);
void init_QStyleOptionDockWidgetV2(PyObject* module);
void init_QStyleOptionToolBox(PyObject* module);
void init_QStyleOptionToolBoxV2(PyObject* module);
void init_QStyleOptionFocusRect(PyObject* module);
void init_QStyleOptionHeader(PyObject* module);
void init_QStyleOptionGraphicsItem(PyObject* module);
void init_QStyleOptionRubberBand(PyObject* module);
void init_QStyleOptionFrame(PyObject* module);
void init_QStyleOptionFrameV2(PyObject* module);
void init_QStyleOptionFrameV3(PyObject* module);
void init_QStyleOptionComplex(PyObject* module);
void init_QStyleOptionSlider(PyObject* module);
void init_QStyleOptionSpinBox(PyObject* module);
void init_QStyleOptionToolButton(PyObject* module);
void init_QStyleOptionComboBox(PyObject* module);
void init_QStyleOptionTitleBar(PyObject* module);
void init_QStyleOptionGroupBox(PyObject* module);
void init_QStyleOptionSizeGrip(PyObject* module);
void init_QStyleOptionViewItem(PyObject* module);
void init_QStyleOptionViewItemV2(PyObject* module);
void init_QStyleOptionViewItemV3(PyObject* module);
void init_QStyleOptionViewItemV4(PyObject* module);
void init_QStyleOptionTab(PyObject* module);
void init_QStyleOptionTabV2(PyObject* module);
void init_QStyleOptionTabV3(PyObject* module);
void init_QItemSelectionRange(PyObject* module);
void init_QItemSelection(PyObject* module);
void init_QFileIconProvider(PyObject* module);
void init_QItemEditorCreatorBase(PyObject* module);
void init_QItemEditorFactory(PyObject* module);
void init_QListWidgetItem(PyObject* module);
void init_QTableWidgetSelectionRange(PyObject* module);
void init_QTableWidgetItem(PyObject* module);
void init_QTreeWidgetItemIterator(PyObject* module);
void init_QTreeWidgetItem(PyObject* module);
void init_QFontDatabase(PyObject* module);
void init_QTextInlineObject(PyObject* module);
void init_QTextLine(PyObject* module);
void init_QTextObjectInterface(PyObject* module);
void init_QTextBlockUserData(PyObject* module);
void init_QTextBlock(PyObject* module);
void init_QTextBlock_iterator(PyObject* module);
void init_QTextFragment(PyObject* module);
void init_QTextDocumentFragment(PyObject* module);
void init_QTextTableCell(PyObject* module);
void init_QStyleFactory(PyObject* module);
void init_QDesktopServices(PyObject* module);
void init_QUndoCommand(PyObject* module);
void init_QIconEngine(PyObject* module);
void init_QImageIOHandler(PyObject* module);
void init_QPictureIO(PyObject* module);
void init_QPixmapCache(PyObject* module);
void init_QPixmapCache_Key(PyObject* module);
void init_QVector2D(PyObject* module);
void init_QInputContextFactory(PyObject* module);
void init_QX11Info(PyObject* module);
void init_QPainter(PyObject* module);
void init_QPainter_PixmapFragment(PyObject* module);
void init_QIcon(PyObject* module);
void init_QIconEngineV2(PyObject* module);
void init_QGraphicsItem(PyObject* module);
void init_QGraphicsLineItem(PyObject* module);
void init_QGraphicsPixmapItem(PyObject* module);
void init_QGraphicsItemGroup(PyObject* module);
void init_QAbstractGraphicsShapeItem(PyObject* module);
void init_QGraphicsSimpleTextItem(PyObject* module);
void init_QGraphicsPathItem(PyObject* module);
void init_QGraphicsRectItem(PyObject* module);
void init_QGraphicsEllipseItem(PyObject* module);
void init_QGraphicsPolygonItem(PyObject* module);
void init_QGraphicsAnchorLayout(PyObject* module);
void init_QImage(PyObject* module);
void init_QPixmap(PyObject* module);
void init_QBitmap(PyObject* module);
void init_QFocusEvent(PyObject* module);
void init_QInputEvent(PyObject* module);
void init_QMouseEvent(PyObject* module);
void init_QWheelEvent(PyObject* module);
void init_QTabletEvent(PyObject* module);
void init_QKeyEvent(PyObject* module);
void init_QContextMenuEvent(PyObject* module);
void init_QTouchEvent(PyObject* module);
void init_QTouchEvent_TouchPoint(PyObject* module);
void init_QPainterPath(PyObject* module);
void init_QPainterPath_Element(PyObject* module);
void init_QTransform(PyObject* module);
void init_QBrush(PyObject* module);
void init_QPen(PyObject* module);
void init_QTileRules(PyObject* module);
void init_QPaintEngine(PyObject* module);
void init_QStandardItem(PyObject* module);
void init_QUndoGroup(PyObject* module);
void init_QAbstractItemDelegate(PyObject* module);
void init_QStyledItemDelegate(PyObject* module);
void init_QItemDelegate(PyObject* module);
void init_QUndoStack(PyObject* module);
void init_QPyTextObject(PyObject* module);
void init_QItemSelectionModel(PyObject* module);
void init_QButtonGroup(PyObject* module);
void init_QGraphicsTransform(PyObject* module);
void init_QGraphicsScale(PyObject* module);
void init_QGraphicsRotation(PyObject* module);
void init_QGesture(PyObject* module);
void init_QPanGesture(PyObject* module);
void init_QPinchGesture(PyObject* module);
void init_QSwipeGesture(PyObject* module);
void init_QTapGesture(PyObject* module);
void init_QTapAndHoldGesture(PyObject* module);
void init_QDataWidgetMapper(PyObject* module);
void init_QDrag(PyObject* module);
void init_QApplication(PyObject* module);
void init_QAbstractTextDocumentLayout(PyObject* module);
void init_QPlainTextDocumentLayout(PyObject* module);
void init_QAbstractTextDocumentLayout_PaintContext(PyObject* module);
void init_QAbstractTextDocumentLayout_Selection(PyObject* module);
void init_QTextObject(PyObject* module);
void init_QTextBlockGroup(PyObject* module);
void init_QTextList(PyObject* module);
void init_QTextFrame(PyObject* module);
void init_QTextFrame_iterator(PyObject* module);
void init_QTextTable(PyObject* module);
void init_QFileSystemModel(PyObject* module);
void init_QProxyModel(PyObject* module);
void init_QStandardItemModel(PyObject* module);
void init_QAbstractProxyModel(PyObject* module);
void init_QSortFilterProxyModel(PyObject* module);
void init_QDirModel(PyObject* module);
void init_QStringListModel(PyObject* module);
void init_QGraphicsAnchor(PyObject* module);
void init_QSessionManager(PyObject* module);
void init_QShortcut(PyObject* module);
void init_QValidator(PyObject* module);
void init_QDoubleValidator(PyObject* module);
void init_QRegExpValidator(PyObject* module);
void init_QIntValidator(PyObject* module);
void init_QSound(PyObject* module);
void init_QGraphicsItemAnimation(PyObject* module);
void init_QSyntaxHighlighter(PyObject* module);
void init_QAction(PyObject* module);
void init_QWidgetAction(PyObject* module);
void init_QActionGroup(PyObject* module);
void init_QStyle(PyObject* module);
void init_QCommonStyle(PyObject* module);
void init_QWindowsStyle(PyObject* module);
void init_QCleanlooksStyle(PyObject* module);
void init_QGtkStyle(PyObject* module);
void init_QPlastiqueStyle(PyObject* module);
void init_QMotifStyle(PyObject* module);
void init_QCDEStyle(PyObject* module);
void init_QGraphicsScene(PyObject* module);
void init_QKeyEventTransition(PyObject* module);
void init_QMouseEventTransition(PyObject* module);
void init_QInputContext(PyObject* module);
void init_QGraphicsObject(PyObject* module);
void init_QGraphicsTextItem(PyObject* module);
void init_QGraphicsWidget(PyObject* module);
void init_QGraphicsProxyWidget(PyObject* module);
void init_QCompleter(PyObject* module);
void init_QLayout(PyObject* module);
void init_QGridLayout(PyObject* module);
void init_QStackedLayout(PyObject* module);
void init_QBoxLayout(PyObject* module);
void init_QHBoxLayout(PyObject* module);
void init_QVBoxLayout(PyObject* module);
void init_QFormLayout(PyObject* module);
void init_QTextDocument(PyObject* module);
void init_QClipboard(PyObject* module);
void init_QMovie(PyObject* module);
void init_QGraphicsEffect(PyObject* module);
void init_QGraphicsOpacityEffect(PyObject* module);
void init_QGraphicsColorizeEffect(PyObject* module);
void init_QGraphicsBlurEffect(PyObject* module);
void init_QGraphicsDropShadowEffect(PyObject* module);
void init_QSystemTrayIcon(PyObject* module);
void init_QRegion(PyObject* module);
void init_QWidget(PyObject* module);
void init_QStatusBar(PyObject* module);
void init_QToolBar(PyObject* module);
void init_QWorkspace(PyObject* module);
void init_QX11EmbedWidget(PyObject* module);
void init_QX11EmbedContainer(PyObject* module);
void init_QFrame(PyObject* module);
void init_QToolBox(PyObject* module);
void init_QStackedWidget(PyObject* module);
void init_QAbstractScrollArea(PyObject* module);
void init_QAbstractItemView(PyObject* module);
void init_QTableView(PyObject* module);
void init_QTableWidget(PyObject* module);
void init_QColumnView(PyObject* module);
void init_QHeaderView(PyObject* module);
void init_QTreeView(PyObject* module);
void init_QTreeWidget(PyObject* module);
void init_QListView(PyObject* module);
void init_QListWidget(PyObject* module);
void init_QScrollArea(PyObject* module);
void init_QGraphicsView(PyObject* module);
void init_QDesktopWidget(PyObject* module);
void init_QDialog(PyObject* module);
void init_QAbstractPageSetupDialog(PyObject* module);
void init_QAbstractPrintDialog(PyObject* module);
void init_QPrintDialog(PyObject* module);
void init_QColorDialog(PyObject* module);
void init_QErrorMessage(PyObject* module);
void init_QFileDialog(PyObject* module);
void init_QFontDialog(PyObject* module);
void init_QUndoView(PyObject* module);
void init_QAbstractButton(PyObject* module);
void init_QPushButton(PyObject* module);
void init_QCommandLinkButton(PyObject* module);
void init_QToolButton(PyObject* module);
void init_QRadioButton(PyObject* module);
void init_QCheckBox(PyObject* module);
void init_QCalendarWidget(PyObject* module);
void init_QComboBox(PyObject* module);
void init_QFontComboBox(PyObject* module);
void init_QLineEdit(PyObject* module);
void init_QInputDialog(PyObject* module);
void init_QMessageBox(PyObject* module);
void init_QPageSetupDialog(PyObject* module);
void init_QPrintPreviewDialog(PyObject* module);
void init_QDialogButtonBox(PyObject* module);
void init_QProgressDialog(PyObject* module);
void init_QDockWidget(PyObject* module);
void init_QWizard(PyObject* module);
void init_QFocusFrame(PyObject* module);
void init_QWizardPage(PyObject* module);
void init_QGroupBox(PyObject* module);
void init_QLabel(PyObject* module);
void init_QLCDNumber(PyObject* module);
void init_QMainWindow(PyObject* module);
void init_QAbstractSpinBox(PyObject* module);
void init_QSpinBox(PyObject* module);
void init_QDoubleSpinBox(PyObject* module);
void init_QDateTimeEdit(PyObject* module);
void init_QTimeEdit(PyObject* module);
void init_QDateEdit(PyObject* module);
void init_QMdiArea(PyObject* module);
void init_QAbstractSlider(PyObject* module);
void init_QSlider(PyObject* module);
void init_QScrollBar(PyObject* module);
void init_QDial(PyObject* module);
void init_QMdiSubWindow(PyObject* module);
void init_QMenu(PyObject* module);
void init_QTabBar(PyObject* module);
void init_QMenuBar(PyObject* module);
void init_QTabWidget(PyObject* module);
void init_QRubberBand(PyObject* module);
void init_QTextEdit(PyObject* module);
void init_QTextBrowser(PyObject* module);
void init_QTextEdit_ExtraSelection(PyObject* module);
void init_QPlainTextEdit(PyObject* module);
void init_QPrintPreviewWidget(PyObject* module);
void init_QProgressBar(PyObject* module);
void init_QSizeGrip(PyObject* module);
void init_QSplashScreen(PyObject* module);
void init_QSplitter(PyObject* module);
void init_QSplitterHandle(PyObject* module);
void init_QStylePainter(PyObject* module);
void init_QMatrix4x2(PyObject* module);
void init_QMatrix4x3(PyObject* module);
void init_QMatrix3x2(PyObject* module);
void init_QMatrix3x3(PyObject* module);
void init_QMatrix3x4(PyObject* module);
void init_QMatrix2x2(PyObject* module);
void init_QMatrix2x3(PyObject* module);
void init_QMatrix2x4(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------

// Extended Converters.

// Extended implicit conversions for PySide.QtCore.QPointF.
static void QPainterPath_Element_PythonToCpp_PySide_QtCore_QPointF(PyObject* pyIn, void* cppOut) {
    *((::QPointF*)cppOut) = ::QPointF(*((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_QPainterPath_Element_PythonToCpp_PySide_QtCore_QPointF_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX]))
        return QPainterPath_Element_PythonToCpp_PySide_QtCore_QPointF;
    return 0;
}

// Container Type converters.

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

// C++ to Python conversion for type 'QList<int >'.
static PyObject* _QList_int__CppToPython__QList_int_(const void* cppIn) {
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
static void _QList_int__PythonToCpp__QList_int_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QList_int__PythonToCpp__QList_int__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn))
        return _QList_int__PythonToCpp__QList_int_;
    return 0;
}

// C++ to Python conversion for type 'QList<QFontDatabase::WritingSystem >'.
static PyObject* _QList_QFontDatabase_WritingSystem__CppToPython__QList_QFontDatabase_WritingSystem_(const void* cppIn) {
    ::QList<QFontDatabase::WritingSystem >& cppInRef = *((::QList<QFontDatabase::WritingSystem >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QFontDatabase::WritingSystem >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QFontDatabase::WritingSystem cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QFontDatabase_WritingSystem__PythonToCpp__QList_QFontDatabase_WritingSystem_(PyObject* pyIn, void* cppOut) {
    ::QList<QFontDatabase::WritingSystem >& cppOutRef = *((::QList<QFontDatabase::WritingSystem >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QFontDatabase::WritingSystem cppItem = ((::QFontDatabase::WritingSystem)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QFontDatabase_WritingSystem__PythonToCpp__QList_QFontDatabase_WritingSystem__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), pyIn))
        return _QList_QFontDatabase_WritingSystem__PythonToCpp__QList_QFontDatabase_WritingSystem_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QTreeWidgetItem * > &'.
static PyObject* _constQList_QTreeWidgetItemPTR_REF_CppToPython__constQList_QTreeWidgetItemPTR_REF(const void* cppIn) {
    ::QList<QTreeWidgetItem * >& cppInRef = *((::QList<QTreeWidgetItem * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTreeWidgetItem * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTreeWidgetItem* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QTreeWidgetItemPTR_REF_PythonToCpp__constQList_QTreeWidgetItemPTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QTreeWidgetItem * >& cppOutRef = *((::QList<QTreeWidgetItem * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTreeWidgetItem* cppItem = ((::QTreeWidgetItem*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QTreeWidgetItemPTR_REF_PythonToCpp__constQList_QTreeWidgetItemPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], pyIn))
        return _constQList_QTreeWidgetItemPTR_REF_PythonToCpp__constQList_QTreeWidgetItemPTR_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QStandardItem * > &'.
static PyObject* _constQList_QStandardItemPTR_REF_CppToPython__constQList_QStandardItemPTR_REF(const void* cppIn) {
    ::QList<QStandardItem * >& cppInRef = *((::QList<QStandardItem * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QStandardItem * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QStandardItem* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QStandardItemPTR_REF_PythonToCpp__constQList_QStandardItemPTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QStandardItem * >& cppOutRef = *((::QList<QStandardItem * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QStandardItem* cppItem = ((::QStandardItem*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QStandardItemPTR_REF_PythonToCpp__constQList_QStandardItemPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], pyIn))
        return _constQList_QStandardItemPTR_REF_PythonToCpp__constQList_QStandardItemPTR_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QItemSelectionRange > &'.
static PyObject* _constQList_QItemSelectionRange_REF_CppToPython__constQList_QItemSelectionRange_REF(const void* cppIn) {
    ::QList<QItemSelectionRange >& cppInRef = *((::QList<QItemSelectionRange >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QItemSelectionRange >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QItemSelectionRange cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QItemSelectionRange_REF_PythonToCpp__constQList_QItemSelectionRange_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QItemSelectionRange >& cppOutRef = *((::QList<QItemSelectionRange >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QItemSelectionRange cppItem = ::QItemSelectionRange();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QItemSelectionRange_REF_PythonToCpp__constQList_QItemSelectionRange_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pyIn))
        return _constQList_QItemSelectionRange_REF_PythonToCpp__constQList_QItemSelectionRange_REF;
    return 0;
}

// C++ to Python conversion for type 'const QSet<QItemSelectionRange > &'.
static PyObject* _constQSet_QItemSelectionRange_REF_CppToPython__constQSet_QItemSelectionRange_REF(const void* cppIn) {
    ::QSet<QItemSelectionRange >& cppInRef = *((::QSet<QItemSelectionRange >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QSet<QItemSelectionRange >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QItemSelectionRange cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQSet_QItemSelectionRange_REF_PythonToCpp__constQSet_QItemSelectionRange_REF(PyObject* pyIn, void* cppOut) {
    ::QSet<QItemSelectionRange >& cppOutRef = *((::QSet<QItemSelectionRange >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QItemSelectionRange cppItem = ::QItemSelectionRange();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQSet_QItemSelectionRange_REF_PythonToCpp__constQSet_QItemSelectionRange_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pyIn))
        return _constQSet_QItemSelectionRange_REF_PythonToCpp__constQSet_QItemSelectionRange_REF;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QItemSelectionRange > &'.
static PyObject* _constQVector_QItemSelectionRange_REF_CppToPython__constQVector_QItemSelectionRange_REF(const void* cppIn) {
    ::QVector<QItemSelectionRange >& cppInRef = *((::QVector<QItemSelectionRange >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QItemSelectionRange >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QItemSelectionRange >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QItemSelectionRange cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QItemSelectionRange_REF_PythonToCpp__constQVector_QItemSelectionRange_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QItemSelectionRange >& cppOutRef = *((::QVector<QItemSelectionRange >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QItemSelectionRange cppItem = ::QItemSelectionRange();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QItemSelectionRange_REF_PythonToCpp__constQVector_QItemSelectionRange_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pyIn))
        return _constQVector_QItemSelectionRange_REF_PythonToCpp__constQVector_QItemSelectionRange_REF;
    return 0;
}

// C++ to Python conversion for type 'QVector<QTextLength >'.
static PyObject* _QVector_QTextLength__CppToPython__QVector_QTextLength_(const void* cppIn) {
    ::QVector<QTextLength >& cppInRef = *((::QVector<QTextLength >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QTextLength >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QTextLength >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QTextLength cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _QVector_QTextLength__PythonToCpp__QVector_QTextLength_(PyObject* pyIn, void* cppOut) {
    ::QVector<QTextLength >& cppOutRef = *((::QVector<QTextLength >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QTextLength cppItem = ::QTextLength();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__QVector_QTextLength__PythonToCpp__QVector_QTextLength__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pyIn))
        return _QVector_QTextLength__PythonToCpp__QVector_QTextLength_;
    return 0;
}

// C++ to Python conversion for type 'QMap<int, QVariant >'.
static PyObject* _QMap_int_QVariant__CppToPython__QMap_int_QVariant_(const void* cppIn) {
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
static void _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QMap_int_QVariant__PythonToCpp__QMap_int_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QTextOption::Tab > &'.
static PyObject* _constQList_QTextOption_Tab_REF_CppToPython__constQList_QTextOption_Tab_REF(const void* cppIn) {
    ::QList<QTextOption::Tab >& cppInRef = *((::QList<QTextOption::Tab >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTextOption::Tab >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTextOption::Tab cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QTextOption_Tab_REF_PythonToCpp__constQList_QTextOption_Tab_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QTextOption::Tab >& cppOutRef = *((::QList<QTextOption::Tab >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTextOption::Tab cppItem = ::QTextOption::Tab();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QTextOption_Tab_REF_PythonToCpp__constQList_QTextOption_Tab_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], pyIn))
        return _constQList_QTextOption_Tab_REF_PythonToCpp__constQList_QTextOption_Tab_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QPrinterInfo >'.
static PyObject* _QList_QPrinterInfo__CppToPython__QList_QPrinterInfo_(const void* cppIn) {
    ::QList<QPrinterInfo >& cppInRef = *((::QList<QPrinterInfo >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPrinterInfo >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPrinterInfo cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPrinterInfo__PythonToCpp__QList_QPrinterInfo_(PyObject* pyIn, void* cppOut) {
    ::QList<QPrinterInfo >& cppOutRef = *((::QList<QPrinterInfo >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPrinterInfo cppItem = ::QPrinterInfo();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPrinterInfo__PythonToCpp__QList_QPrinterInfo__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], pyIn))
        return _QList_QPrinterInfo__PythonToCpp__QList_QPrinterInfo_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPrinter::PageSize >'.
static PyObject* _QList_QPrinter_PageSize__CppToPython__QList_QPrinter_PageSize_(const void* cppIn) {
    ::QList<QPrinter::PageSize >& cppInRef = *((::QList<QPrinter::PageSize >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPrinter::PageSize >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPrinter::PageSize cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPrinter_PageSize__PythonToCpp__QList_QPrinter_PageSize_(PyObject* pyIn, void* cppOut) {
    ::QList<QPrinter::PageSize >& cppOutRef = *((::QList<QPrinter::PageSize >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPrinter::PageSize cppItem = ((::QPrinter::PageSize)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPrinter_PageSize__PythonToCpp__QList_QPrinter_PageSize__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), pyIn))
        return _QList_QPrinter_PageSize__PythonToCpp__QList_QPrinter_PageSize_;
    return 0;
}

// C++ to Python conversion for type 'QList<qreal >'.
static PyObject* _QList_qreal__CppToPython__QList_qreal_(const void* cppIn) {
    ::QList<qreal >& cppInRef = *((::QList<qreal >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<qreal >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            qreal cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_qreal__PythonToCpp__QList_qreal_(PyObject* pyIn, void* cppOut) {
    ::QList<qreal >& cppOutRef = *((::QList<qreal >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        qreal cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_qreal__PythonToCpp__QList_qreal__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyIn))
        return _QList_qreal__PythonToCpp__QList_qreal_;
    return 0;
}

// C++ to Python conversion for type 'QVector<qreal >'.
static PyObject* _QVector_qreal__CppToPython__QVector_qreal_(const void* cppIn) {
    ::QVector<qreal >& cppInRef = *((::QVector<qreal >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<qreal >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<qreal >::size_type idx = 0; idx < vectorSize; ++idx) {
            qreal cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _QVector_qreal__PythonToCpp__QVector_qreal_(PyObject* pyIn, void* cppOut) {
    ::QVector<qreal >& cppOutRef = *((::QVector<qreal >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        qreal cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__QVector_qreal__PythonToCpp__QVector_qreal__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyIn))
        return _QVector_qreal__PythonToCpp__QVector_qreal_;
    return 0;
}

// C++ to Python conversion for type 'QPair<qreal, QColor >'.
static PyObject* _QPair_qreal_QColor__CppToPython__QPair_qreal_QColor_(const void* cppIn) {
    ::QPair<qreal, QColor >& cppInRef = *((::QPair<qreal, QColor >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppInRef.second));
            return pyOut;

}
static void _QPair_qreal_QColor__PythonToCpp__QPair_qreal_QColor_(PyObject* pyIn, void* cppOut) {
    ::QPair<qreal, QColor >& cppOutRef = *((::QPair<qreal, QColor >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__QPair_qreal_QColor__PythonToCpp__QPair_qreal_QColor__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), false, SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX]), false, pyIn))
        return _QPair_qreal_QColor__PythonToCpp__QPair_qreal_QColor_;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QPair<qreal, QColor > > &'.
static PyObject* _constQVector_QPair_qreal_QColor__REF_CppToPython__constQVector_QPair_qreal_QColor__REF(const void* cppIn) {
    ::QVector<QPair<qreal, QColor > >& cppInRef = *((::QVector<QPair<qreal, QColor > >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QPair<qreal, QColor > >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QPair<qreal, QColor > >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QPair<qreal, QColor > cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QPair_qreal_QColor__REF_PythonToCpp__constQVector_QPair_qreal_QColor__REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QPair<qreal, QColor > >& cppOutRef = *((::QVector<QPair<qreal, QColor > >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QPair<qreal, QColor > cppItem = ::QPair<qreal, QColor >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QPair_qreal_QColor__REF_PythonToCpp__constQVector_QPair_qreal_QColor__REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX], pyIn))
        return _constQVector_QPair_qreal_QColor__REF_PythonToCpp__constQVector_QPair_qreal_QColor__REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QKeySequence >'.
static PyObject* _QList_QKeySequence__CppToPython__QList_QKeySequence_(const void* cppIn) {
    ::QList<QKeySequence >& cppInRef = *((::QList<QKeySequence >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QKeySequence >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QKeySequence cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QKeySequence__PythonToCpp__QList_QKeySequence_(PyObject* pyIn, void* cppOut) {
    ::QList<QKeySequence >& cppOutRef = *((::QList<QKeySequence >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QKeySequence cppItem = ::QKeySequence();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QKeySequence__PythonToCpp__QList_QKeySequence__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pyIn))
        return _QList_QKeySequence__PythonToCpp__QList_QKeySequence_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPolygonF >'.
static PyObject* _QList_QPolygonF__CppToPython__QList_QPolygonF_(const void* cppIn) {
    ::QList<QPolygonF >& cppInRef = *((::QList<QPolygonF >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPolygonF >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPolygonF cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPolygonF__PythonToCpp__QList_QPolygonF_(PyObject* pyIn, void* cppOut) {
    ::QList<QPolygonF >& cppOutRef = *((::QList<QPolygonF >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPolygonF cppItem = ::QPolygonF();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPolygonF__PythonToCpp__QList_QPolygonF__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyIn))
        return _QList_QPolygonF__PythonToCpp__QList_QPolygonF_;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QPointF > &'.
static PyObject* _constQVector_QPointF_REF_CppToPython__constQVector_QPointF_REF(const void* cppIn) {
    ::QVector<QPointF >& cppInRef = *((::QVector<QPointF >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QPointF >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QPointF >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QPointF cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QPointF_REF_PythonToCpp__constQVector_QPointF_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QPointF >& cppOutRef = *((::QVector<QPointF >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QPointF cppItem = ::QPointF();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QPointF_REF_PythonToCpp__constQVector_QPointF_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyIn))
        return _constQVector_QPointF_REF_PythonToCpp__constQVector_QPointF_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QPointF > &'.
static PyObject* _constQList_QPointF_REF_CppToPython__constQList_QPointF_REF(const void* cppIn) {
    ::QList<QPointF >& cppInRef = *((::QList<QPointF >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPointF >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPointF cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QPointF_REF_PythonToCpp__constQList_QPointF_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QPointF >& cppOutRef = *((::QList<QPointF >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPointF cppItem = ::QPointF();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QPointF_REF_PythonToCpp__constQList_QPointF_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyIn))
        return _constQList_QPointF_REF_PythonToCpp__constQList_QPointF_REF;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QPoint > &'.
static PyObject* _constQVector_QPoint_REF_CppToPython__constQVector_QPoint_REF(const void* cppIn) {
    ::QVector<QPoint >& cppInRef = *((::QVector<QPoint >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QPoint >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QPoint >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QPoint cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QPoint_REF_PythonToCpp__constQVector_QPoint_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QPoint >& cppOutRef = *((::QVector<QPoint >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QPoint cppItem = ::QPoint();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QPoint_REF_PythonToCpp__constQVector_QPoint_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pyIn))
        return _constQVector_QPoint_REF_PythonToCpp__constQVector_QPoint_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QPoint > &'.
static PyObject* _constQList_QPoint_REF_CppToPython__constQList_QPoint_REF(const void* cppIn) {
    ::QList<QPoint >& cppInRef = *((::QList<QPoint >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPoint >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPoint cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QPoint_REF_PythonToCpp__constQList_QPoint_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QPoint >& cppOutRef = *((::QList<QPoint >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPoint cppItem = ::QPoint();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QPoint_REF_PythonToCpp__constQList_QPoint_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pyIn))
        return _constQList_QPoint_REF_PythonToCpp__constQList_QPoint_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QTouchEvent::TouchPoint > &'.
static PyObject* _constQList_QTouchEvent_TouchPoint_REF_CppToPython__constQList_QTouchEvent_TouchPoint_REF(const void* cppIn) {
    ::QList<QTouchEvent::TouchPoint >& cppInRef = *((::QList<QTouchEvent::TouchPoint >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTouchEvent::TouchPoint >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTouchEvent::TouchPoint cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QTouchEvent_TouchPoint_REF_PythonToCpp__constQList_QTouchEvent_TouchPoint_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QTouchEvent::TouchPoint >& cppOutRef = *((::QList<QTouchEvent::TouchPoint >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTouchEvent::TouchPoint cppItem = ::QTouchEvent::TouchPoint(((int)0));
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QTouchEvent_TouchPoint_REF_PythonToCpp__constQList_QTouchEvent_TouchPoint_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], pyIn))
        return _constQList_QTouchEvent_TouchPoint_REF_PythonToCpp__constQList_QTouchEvent_TouchPoint_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QGesture * > &'.
static PyObject* _constQList_QGesturePTR_REF_CppToPython__constQList_QGesturePTR_REF(const void* cppIn) {
    ::QList<QGesture * >& cppInRef = *((::QList<QGesture * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QGesture * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QGesture* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QGesturePTR_REF_PythonToCpp__constQList_QGesturePTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QGesture * >& cppOutRef = *((::QList<QGesture * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QGesture* cppItem = ((::QGesture*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QGesturePTR_REF_PythonToCpp__constQList_QGesturePTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], pyIn))
        return _constQList_QGesturePTR_REF_PythonToCpp__constQList_QGesturePTR_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QInputMethodEvent::Attribute > &'.
static PyObject* _constQList_QInputMethodEvent_Attribute_REF_CppToPython__constQList_QInputMethodEvent_Attribute_REF(const void* cppIn) {
    ::QList<QInputMethodEvent::Attribute >& cppInRef = *((::QList<QInputMethodEvent::Attribute >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QInputMethodEvent::Attribute >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QInputMethodEvent::Attribute cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QInputMethodEvent_Attribute_REF_PythonToCpp__constQList_QInputMethodEvent_Attribute_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QInputMethodEvent::Attribute >& cppOutRef = *((::QList<QInputMethodEvent::Attribute >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QInputMethodEvent::Attribute cppItem = ::QInputMethodEvent::Attribute(((::QInputMethodEvent::AttributeType)0), ((int)0), ((int)0), ::QVariant());
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QInputMethodEvent_Attribute_REF_PythonToCpp__constQList_QInputMethodEvent_Attribute_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], pyIn))
        return _constQList_QInputMethodEvent_Attribute_REF_PythonToCpp__constQList_QInputMethodEvent_Attribute_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QTextLayout::FormatRange >'.
static PyObject* _QList_QTextLayout_FormatRange__CppToPython__QList_QTextLayout_FormatRange_(const void* cppIn) {
    ::QList<QTextLayout::FormatRange >& cppInRef = *((::QList<QTextLayout::FormatRange >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTextLayout::FormatRange >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTextLayout::FormatRange cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QTextLayout_FormatRange__PythonToCpp__QList_QTextLayout_FormatRange_(PyObject* pyIn, void* cppOut) {
    ::QList<QTextLayout::FormatRange >& cppOutRef = *((::QList<QTextLayout::FormatRange >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTextLayout::FormatRange cppItem = ::QTextLayout::FormatRange();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QTextLayout_FormatRange__PythonToCpp__QList_QTextLayout_FormatRange__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], pyIn))
        return _QList_QTextLayout_FormatRange__PythonToCpp__QList_QTextLayout_FormatRange_;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QTextLayout::FormatRange > &'.
static PyObject* _constQVector_QTextLayout_FormatRange_REF_CppToPython__constQVector_QTextLayout_FormatRange_REF(const void* cppIn) {
    ::QVector<QTextLayout::FormatRange >& cppInRef = *((::QVector<QTextLayout::FormatRange >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QTextLayout::FormatRange >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QTextLayout::FormatRange >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QTextLayout::FormatRange cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QTextLayout_FormatRange_REF_PythonToCpp__constQVector_QTextLayout_FormatRange_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QTextLayout::FormatRange >& cppOutRef = *((::QVector<QTextLayout::FormatRange >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QTextLayout::FormatRange cppItem = ::QTextLayout::FormatRange();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QTextLayout_FormatRange_REF_PythonToCpp__constQVector_QTextLayout_FormatRange_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], pyIn))
        return _constQVector_QTextLayout_FormatRange_REF_PythonToCpp__constQVector_QTextLayout_FormatRange_REF;
    return 0;
}

// C++ to Python conversion for type 'QVector<unsigned int >'.
static PyObject* _QVector_unsignedint__CppToPython__QVector_unsignedint_(const void* cppIn) {
    ::QVector<unsigned int >& cppInRef = *((::QVector<unsigned int >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<unsigned int >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<unsigned int >::size_type idx = 0; idx < vectorSize; ++idx) {
            unsigned int cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _QVector_unsignedint__PythonToCpp__QVector_unsignedint_(PyObject* pyIn, void* cppOut) {
    ::QVector<unsigned int >& cppOutRef = *((::QVector<unsigned int >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        unsigned int cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__QVector_unsignedint__PythonToCpp__QVector_unsignedint__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), pyIn))
        return _QVector_unsignedint__PythonToCpp__QVector_unsignedint_;
    return 0;
}

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

// C++ to Python conversion for type 'QList<QSize >'.
static PyObject* _QList_QSize__CppToPython__QList_QSize_(const void* cppIn) {
    ::QList<QSize >& cppInRef = *((::QList<QSize >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QSize >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QSize cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QSize__PythonToCpp__QList_QSize_(PyObject* pyIn, void* cppOut) {
    ::QList<QSize >& cppOutRef = *((::QList<QSize >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QSize cppItem = ::QSize();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QSize__PythonToCpp__QList_QSize__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyIn))
        return _QList_QSize__PythonToCpp__QList_QSize_;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QLine > &'.
static PyObject* _constQVector_QLine_REF_CppToPython__constQVector_QLine_REF(const void* cppIn) {
    ::QVector<QLine >& cppInRef = *((::QVector<QLine >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QLine >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QLine >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QLine cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QLine_REF_PythonToCpp__constQVector_QLine_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QLine >& cppOutRef = *((::QVector<QLine >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QLine cppItem = ::QLine();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QLine_REF_PythonToCpp__constQVector_QLine_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pyIn))
        return _constQVector_QLine_REF_PythonToCpp__constQVector_QLine_REF;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QLineF > &'.
static PyObject* _constQVector_QLineF_REF_CppToPython__constQVector_QLineF_REF(const void* cppIn) {
    ::QVector<QLineF >& cppInRef = *((::QVector<QLineF >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QLineF >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QLineF >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QLineF cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QLineF_REF_PythonToCpp__constQVector_QLineF_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QLineF >& cppOutRef = *((::QVector<QLineF >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QLineF cppItem = ::QLineF();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QLineF_REF_PythonToCpp__constQVector_QLineF_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pyIn))
        return _constQVector_QLineF_REF_PythonToCpp__constQVector_QLineF_REF;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QRect > &'.
static PyObject* _constQVector_QRect_REF_CppToPython__constQVector_QRect_REF(const void* cppIn) {
    ::QVector<QRect >& cppInRef = *((::QVector<QRect >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QRect >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QRect >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QRect cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QRect_REF_PythonToCpp__constQVector_QRect_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QRect >& cppOutRef = *((::QVector<QRect >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QRect cppItem = ::QRect();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QRect_REF_PythonToCpp__constQVector_QRect_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyIn))
        return _constQVector_QRect_REF_PythonToCpp__constQVector_QRect_REF;
    return 0;
}

// C++ to Python conversion for type 'const QVector<QRectF > &'.
static PyObject* _constQVector_QRectF_REF_CppToPython__constQVector_QRectF_REF(const void* cppIn) {
    ::QVector<QRectF >& cppInRef = *((::QVector<QRectF >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QRectF >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QRectF >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QRectF cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _constQVector_QRectF_REF_PythonToCpp__constQVector_QRectF_REF(PyObject* pyIn, void* cppOut) {
    ::QVector<QRectF >& cppOutRef = *((::QVector<QRectF >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QRectF cppItem = ::QRectF();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__constQVector_QRectF_REF_PythonToCpp__constQVector_QRectF_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyIn))
        return _constQVector_QRectF_REF_PythonToCpp__constQVector_QRectF_REF;
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

// C++ to Python conversion for type 'QList<QUndoStack * >'.
static PyObject* _QList_QUndoStackPTR__CppToPython__QList_QUndoStackPTR_(const void* cppIn) {
    ::QList<QUndoStack * >& cppInRef = *((::QList<QUndoStack * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QUndoStack * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QUndoStack* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QUNDOSTACK_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QUndoStackPTR__PythonToCpp__QList_QUndoStackPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QUndoStack * >& cppOutRef = *((::QList<QUndoStack * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QUndoStack* cppItem = ((::QUndoStack*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QUNDOSTACK_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QUndoStackPTR__PythonToCpp__QList_QUndoStackPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QUNDOSTACK_IDX], pyIn))
        return _QList_QUndoStackPTR__PythonToCpp__QList_QUndoStackPTR_;
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

// C++ to Python conversion for type 'QList<QGraphicsView * >'.
static PyObject* _QList_QGraphicsViewPTR__CppToPython__QList_QGraphicsViewPTR_(const void* cppIn) {
    ::QList<QGraphicsView * >& cppInRef = *((::QList<QGraphicsView * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QGraphicsView * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QGraphicsView* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QGraphicsViewPTR__PythonToCpp__QList_QGraphicsViewPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QGraphicsView * >& cppOutRef = *((::QList<QGraphicsView * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QGraphicsView* cppItem = ((::QGraphicsView*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QGraphicsViewPTR__PythonToCpp__QList_QGraphicsViewPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], pyIn))
        return _QList_QGraphicsViewPTR__PythonToCpp__QList_QGraphicsViewPTR_;
    return 0;
}

// C++ to Python conversion for type 'QPair<qreal, QPointF >'.
static PyObject* _QPair_qreal_QPointF__CppToPython__QPair_qreal_QPointF_(const void* cppIn) {
    ::QPair<qreal, QPointF >& cppInRef = *((::QPair<qreal, QPointF >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppInRef.second));
            return pyOut;

}
static void _QPair_qreal_QPointF__PythonToCpp__QPair_qreal_QPointF_(PyObject* pyIn, void* cppOut) {
    ::QPair<qreal, QPointF >& cppOutRef = *((::QPair<qreal, QPointF >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__QPair_qreal_QPointF__PythonToCpp__QPair_qreal_QPointF__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX]), false, pyIn))
        return _QPair_qreal_QPointF__PythonToCpp__QPair_qreal_QPointF_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<qreal, QPointF > >'.
static PyObject* _QList_QPair_qreal_QPointF___CppToPython__QList_QPair_qreal_QPointF__(const void* cppIn) {
    ::QList<QPair<qreal, QPointF > >& cppInRef = *((::QList<QPair<qreal, QPointF > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<qreal, QPointF > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<qreal, QPointF > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QPOINTF_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPair_qreal_QPointF___PythonToCpp__QList_QPair_qreal_QPointF__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<qreal, QPointF > >& cppOutRef = *((::QList<QPair<qreal, QPointF > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<qreal, QPointF > cppItem = ::QPair<qreal, QPointF >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QPOINTF_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPair_qreal_QPointF___PythonToCpp__QList_QPair_qreal_QPointF___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QPOINTF_IDX], pyIn))
        return _QList_QPair_qreal_QPointF___PythonToCpp__QList_QPair_qreal_QPointF__;
    return 0;
}

// C++ to Python conversion for type 'QPair<qreal, qreal >'.
static PyObject* _QPair_qreal_qreal__CppToPython__QPair_qreal_qreal_(const void* cppIn) {
    ::QPair<qreal, qreal >& cppInRef = *((::QPair<qreal, qreal >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppInRef.second));
            return pyOut;

}
static void _QPair_qreal_qreal__PythonToCpp__QPair_qreal_qreal_(PyObject* pyIn, void* cppOut) {
    ::QPair<qreal, qreal >& cppOutRef = *((::QPair<qreal, qreal >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__QPair_qreal_qreal__PythonToCpp__QPair_qreal_qreal__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), false, Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), false, pyIn))
        return _QPair_qreal_qreal__PythonToCpp__QPair_qreal_qreal_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<qreal, qreal > >'.
static PyObject* _QList_QPair_qreal_qreal___CppToPython__QList_QPair_qreal_qreal__(const void* cppIn) {
    ::QList<QPair<qreal, qreal > >& cppInRef = *((::QList<QPair<qreal, qreal > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<qreal, qreal > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<qreal, qreal > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QREAL_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPair_qreal_qreal___PythonToCpp__QList_QPair_qreal_qreal__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<qreal, qreal > >& cppOutRef = *((::QList<QPair<qreal, qreal > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<qreal, qreal > cppItem = ::QPair<qreal, qreal >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QREAL_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPair_qreal_qreal___PythonToCpp__QList_QPair_qreal_qreal___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QREAL_IDX], pyIn))
        return _QList_QPair_qreal_qreal___PythonToCpp__QList_QPair_qreal_qreal__;
    return 0;
}

// C++ to Python conversion for type 'const QHash<int, QByteArray > &'.
static PyObject* _constQHash_int_QByteArray_REF_CppToPython__constQHash_int_QByteArray_REF(const void* cppIn) {
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
static void _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, pyIn))
        return _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QTextFrame * >'.
static PyObject* _QList_QTextFramePTR__CppToPython__QList_QTextFramePTR_(const void* cppIn) {
    ::QList<QTextFrame * >& cppInRef = *((::QList<QTextFrame * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTextFrame * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTextFrame* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QTextFramePTR__PythonToCpp__QList_QTextFramePTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QTextFrame * >& cppOutRef = *((::QList<QTextFrame * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTextFrame* cppItem = ((::QTextFrame*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QTextFramePTR__PythonToCpp__QList_QTextFramePTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], pyIn))
        return _QList_QTextFramePTR__PythonToCpp__QList_QTextFramePTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QTextBlock >'.
static PyObject* _QList_QTextBlock__CppToPython__QList_QTextBlock_(const void* cppIn) {
    ::QList<QTextBlock >& cppInRef = *((::QList<QTextBlock >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTextBlock >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTextBlock cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QTextBlock__PythonToCpp__QList_QTextBlock_(PyObject* pyIn, void* cppOut) {
    ::QList<QTextBlock >& cppOutRef = *((::QList<QTextBlock >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTextBlock cppItem = ::QTextBlock();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QTextBlock__PythonToCpp__QList_QTextBlock__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pyIn))
        return _QList_QTextBlock__PythonToCpp__QList_QTextBlock_;
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

// C++ to Python conversion for type 'QList<QAbstractAnimation * >'.
static PyObject* _QList_QAbstractAnimationPTR__CppToPython__QList_QAbstractAnimationPTR_(const void* cppIn) {
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
static void _QList_QAbstractAnimationPTR__PythonToCpp__QList_QAbstractAnimationPTR_(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__QList_QAbstractAnimationPTR__PythonToCpp__QList_QAbstractAnimationPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], pyIn))
        return _QList_QAbstractAnimationPTR__PythonToCpp__QList_QAbstractAnimationPTR_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QAbstractState * > &'.
static PyObject* _constQList_QAbstractStatePTR_REF_CppToPython__constQList_QAbstractStatePTR_REF(const void* cppIn) {
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
static void _constQList_QAbstractStatePTR_REF_PythonToCpp__constQList_QAbstractStatePTR_REF(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__constQList_QAbstractStatePTR_REF_PythonToCpp__constQList_QAbstractStatePTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], pyIn))
        return _constQList_QAbstractStatePTR_REF_PythonToCpp__constQList_QAbstractStatePTR_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QGraphicsWidget * >'.
static PyObject* _QList_QGraphicsWidgetPTR__CppToPython__QList_QGraphicsWidgetPTR_(const void* cppIn) {
    ::QList<QGraphicsWidget * >& cppInRef = *((::QList<QGraphicsWidget * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QGraphicsWidget * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QGraphicsWidget* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QGraphicsWidgetPTR__PythonToCpp__QList_QGraphicsWidgetPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QGraphicsWidget * >& cppOutRef = *((::QList<QGraphicsWidget * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QGraphicsWidget* cppItem = ((::QGraphicsWidget*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QGraphicsWidgetPTR__PythonToCpp__QList_QGraphicsWidgetPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], pyIn))
        return _QList_QGraphicsWidgetPTR__PythonToCpp__QList_QGraphicsWidgetPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QListWidgetItem * >'.
static PyObject* _QList_QListWidgetItemPTR__CppToPython__QList_QListWidgetItemPTR_(const void* cppIn) {
    ::QList<QListWidgetItem * >& cppInRef = *((::QList<QListWidgetItem * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QListWidgetItem * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QListWidgetItem* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLISTWIDGETITEM_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QListWidgetItemPTR__PythonToCpp__QList_QListWidgetItemPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QListWidgetItem * >& cppOutRef = *((::QList<QListWidgetItem * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QListWidgetItem* cppItem = ((::QListWidgetItem*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLISTWIDGETITEM_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QListWidgetItemPTR__PythonToCpp__QList_QListWidgetItemPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QLISTWIDGETITEM_IDX], pyIn))
        return _QList_QListWidgetItemPTR__PythonToCpp__QList_QListWidgetItemPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QTableWidgetItem * >'.
static PyObject* _QList_QTableWidgetItemPTR__CppToPython__QList_QTableWidgetItemPTR_(const void* cppIn) {
    ::QList<QTableWidgetItem * >& cppInRef = *((::QList<QTableWidgetItem * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTableWidgetItem * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTableWidgetItem* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QTableWidgetItemPTR__PythonToCpp__QList_QTableWidgetItemPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QTableWidgetItem * >& cppOutRef = *((::QList<QTableWidgetItem * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTableWidgetItem* cppItem = ((::QTableWidgetItem*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QTableWidgetItemPTR__PythonToCpp__QList_QTableWidgetItemPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], pyIn))
        return _QList_QTableWidgetItemPTR__PythonToCpp__QList_QTableWidgetItemPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QTableWidgetSelectionRange >'.
static PyObject* _QList_QTableWidgetSelectionRange__CppToPython__QList_QTableWidgetSelectionRange_(const void* cppIn) {
    ::QList<QTableWidgetSelectionRange >& cppInRef = *((::QList<QTableWidgetSelectionRange >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTableWidgetSelectionRange >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTableWidgetSelectionRange cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QTableWidgetSelectionRange__PythonToCpp__QList_QTableWidgetSelectionRange_(PyObject* pyIn, void* cppOut) {
    ::QList<QTableWidgetSelectionRange >& cppOutRef = *((::QList<QTableWidgetSelectionRange >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTableWidgetSelectionRange cppItem = ::QTableWidgetSelectionRange();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QTableWidgetSelectionRange__PythonToCpp__QList_QTableWidgetSelectionRange__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], pyIn))
        return _QList_QTableWidgetSelectionRange__PythonToCpp__QList_QTableWidgetSelectionRange_;
    return 0;
}

// C++ to Python conversion for type 'QList<QTextEdit::ExtraSelection >'.
static PyObject* _QList_QTextEdit_ExtraSelection__CppToPython__QList_QTextEdit_ExtraSelection_(const void* cppIn) {
    ::QList<QTextEdit::ExtraSelection >& cppInRef = *((::QList<QTextEdit::ExtraSelection >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QTextEdit::ExtraSelection >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QTextEdit::ExtraSelection cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QTextEdit_ExtraSelection__PythonToCpp__QList_QTextEdit_ExtraSelection_(PyObject* pyIn, void* cppOut) {
    ::QList<QTextEdit::ExtraSelection >& cppOutRef = *((::QList<QTextEdit::ExtraSelection >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QTextEdit::ExtraSelection cppItem = ::QTextEdit::ExtraSelection();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QTextEdit_ExtraSelection__PythonToCpp__QList_QTextEdit_ExtraSelection__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], pyIn))
        return _QList_QTextEdit_ExtraSelection__PythonToCpp__QList_QTextEdit_ExtraSelection_;
    return 0;
}

// C++ to Python conversion for type 'QList<QMdiSubWindow * >'.
static PyObject* _QList_QMdiSubWindowPTR__CppToPython__QList_QMdiSubWindowPTR_(const void* cppIn) {
    ::QList<QMdiSubWindow * >& cppInRef = *((::QList<QMdiSubWindow * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QMdiSubWindow * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QMdiSubWindow* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMDISUBWINDOW_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QMdiSubWindowPTR__PythonToCpp__QList_QMdiSubWindowPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QMdiSubWindow * >& cppOutRef = *((::QList<QMdiSubWindow * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QMdiSubWindow* cppItem = ((::QMdiSubWindow*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMDISUBWINDOW_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QMdiSubWindowPTR__PythonToCpp__QList_QMdiSubWindowPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QMDISUBWINDOW_IDX], pyIn))
        return _QList_QMdiSubWindowPTR__PythonToCpp__QList_QMdiSubWindowPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QDockWidget * >'.
static PyObject* _QList_QDockWidgetPTR__CppToPython__QList_QDockWidgetPTR_(const void* cppIn) {
    ::QList<QDockWidget * >& cppInRef = *((::QList<QDockWidget * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QDockWidget * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QDockWidget* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QDockWidgetPTR__PythonToCpp__QList_QDockWidgetPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QDockWidget * >& cppOutRef = *((::QList<QDockWidget * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QDockWidget* cppItem = ((::QDockWidget*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QDockWidgetPTR__PythonToCpp__QList_QDockWidgetPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], pyIn))
        return _QList_QDockWidgetPTR__PythonToCpp__QList_QDockWidgetPTR_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QWizard::WizardButton > &'.
static PyObject* _constQList_QWizard_WizardButton_REF_CppToPython__constQList_QWizard_WizardButton_REF(const void* cppIn) {
    ::QList<QWizard::WizardButton >& cppInRef = *((::QList<QWizard::WizardButton >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWizard::WizardButton >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWizard::WizardButton cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QWIZARD_WIZARDBUTTON_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QWizard_WizardButton_REF_PythonToCpp__constQList_QWizard_WizardButton_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QWizard::WizardButton >& cppOutRef = *((::QList<QWizard::WizardButton >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWizard::WizardButton cppItem = ((::QWizard::WizardButton)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QWIZARD_WIZARDBUTTON_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QWizard_WizardButton_REF_PythonToCpp__constQList_QWizard_WizardButton_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QWIZARD_WIZARDBUTTON_IDX]), pyIn))
        return _constQList_QWizard_WizardButton_REF_PythonToCpp__constQList_QWizard_WizardButton_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QAbstractButton * >'.
static PyObject* _QList_QAbstractButtonPTR__CppToPython__QList_QAbstractButtonPTR_(const void* cppIn) {
    ::QList<QAbstractButton * >& cppInRef = *((::QList<QAbstractButton * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAbstractButton * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAbstractButton* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QAbstractButtonPTR__PythonToCpp__QList_QAbstractButtonPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QAbstractButton * >& cppOutRef = *((::QList<QAbstractButton * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAbstractButton* cppItem = ((::QAbstractButton*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QAbstractButtonPTR__PythonToCpp__QList_QAbstractButtonPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], pyIn))
        return _QList_QAbstractButtonPTR__PythonToCpp__QList_QAbstractButtonPTR_;
    return 0;
}

// C++ to Python conversion for type 'QMap<QDate, QTextCharFormat >'.
static PyObject* _QMap_QDate_QTextCharFormat__CppToPython__QMap_QDate_QTextCharFormat_(const void* cppIn) {
    ::QMap<QDate, QTextCharFormat >& cppInRef = *((::QMap<QDate, QTextCharFormat >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMap<QDate, QTextCharFormat >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QDate key = it.key();
            ::QTextCharFormat value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMap_QDate_QTextCharFormat__PythonToCpp__QMap_QDate_QTextCharFormat_(PyObject* pyIn, void* cppOut) {
    ::QMap<QDate, QTextCharFormat >& cppOutRef = *((::QMap<QDate, QTextCharFormat >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QDate cppKey = ::QDate();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], key, &(cppKey));
        ::QTextCharFormat cppValue = ::QTextCharFormat();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMap_QDate_QTextCharFormat__PythonToCpp__QMap_QDate_QTextCharFormat__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATE_IDX]), false, SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX]), false, pyIn))
        return _QMap_QDate_QTextCharFormat__PythonToCpp__QMap_QDate_QTextCharFormat_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QUrl > &'.
static PyObject* _constQList_QUrl_REF_CppToPython__constQList_QUrl_REF(const void* cppIn) {
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
static void _constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return _constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF;
    return 0;
}

// C++ to Python conversion for type 'QVector<QTextFormat >'.
static PyObject* _QVector_QTextFormat__CppToPython__QVector_QTextFormat_(const void* cppIn) {
    ::QVector<QTextFormat >& cppInRef = *((::QVector<QTextFormat >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QTextFormat >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QTextFormat >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QTextFormat cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _QVector_QTextFormat__PythonToCpp__QVector_QTextFormat_(PyObject* pyIn, void* cppOut) {
    ::QVector<QTextFormat >& cppOutRef = *((::QVector<QTextFormat >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QTextFormat cppItem = ::QTextFormat();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__QVector_QTextFormat__PythonToCpp__QVector_QTextFormat__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pyIn))
        return _QVector_QTextFormat__PythonToCpp__QVector_QTextFormat_;
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
    /* m_name     */ "QtGui",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtGui_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtGui)

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtGui_IDX_COUNT];
    SbkPySide_QtGuiTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtGui_CONVERTERS_IDX_COUNT];
    SbkPySide_QtGuiTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtGui", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtGui", QtGui_methods);
#endif

    // Initialize classes in the type system
    init_QImageWriter(module);
    init_QImageReader(module);
    init_QTextLayout(module);
    init_QTextLayout_FormatRange(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_IDX]->tp_dict);
    init_QDragLeaveEvent(module);
    init_QHelpEvent(module);
    init_QStatusTipEvent(module);
    init_QWhatsThisClickedEvent(module);
    init_QActionEvent(module);
    init_QFileOpenEvent(module);
    init_QToolBarChangeEvent(module);
    init_QShortcutEvent(module);
    init_QClipboardEvent(module);
    init_QWindowStateChangeEvent(module);
    init_QGestureEvent(module);
    init_QPaintEvent(module);
    init_QMoveEvent(module);
    init_QResizeEvent(module);
    init_QCloseEvent(module);
    init_QIconDragEvent(module);
    init_QShowEvent(module);
    init_QHideEvent(module);
    init_QHoverEvent(module);
    init_QAccessibleEvent(module);
    init_QGraphicsSceneEvent(module);
    init_QGraphicsSceneMouseEvent(module);
    init_QGraphicsSceneWheelEvent(module);
    init_QGraphicsSceneContextMenuEvent(module);
    init_QGraphicsSceneHoverEvent(module);
    init_QGraphicsSceneHelpEvent(module);
    init_QGraphicsSceneDragDropEvent(module);
    init_QGraphicsSceneResizeEvent(module);
    init_QGraphicsSceneMoveEvent(module);
    init_QInputMethodEvent(module);
    init_QInputMethodEvent_Attribute(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX]->tp_dict);
    init_QDropEvent(module);
    init_QDragMoveEvent(module);
    init_QDragEnterEvent(module);
    init_QPolygon(module);
    init_QPolygonF(module);
    init_QMatrix(module);
    init_QPainterPathStroker(module);
    init_QPaintDevice(module);
    init_QPrinter(module);
    init_QPicture(module);
    init_QColor(module);
    init_QSizePolicy(module);
    init_QGraphicsLayoutItem(module);
    init_QGraphicsLayout(module);
    init_QGraphicsGridLayout(module);
    init_QGraphicsLinearLayout(module);
    init_QKeySequence(module);
    init_QFont(module);
    init_QGradient(module);
    init_QConicalGradient(module);
    init_QLinearGradient(module);
    init_QRadialGradient(module);
    init_QPalette(module);
    init_QVector3D(module);
    init_QVector4D(module);
    init_QQuaternion(module);
    init_QMatrix4x4(module);
    init_QTextOption(module);
    init_QTextOption_Tab(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX]->tp_dict);
    init_QFontInfo(module);
    init_QFontMetrics(module);
    init_QFontMetricsF(module);
    init_QCursor(module);
    init_QLayoutItem(module);
    init_QWidgetItem(module);
    init_QSpacerItem(module);
    init_QGestureRecognizer(module);
    init_QToolTip(module);
    init_QWhatsThis(module);
    init_QTextItem(module);
    init_QPaintEngineState(module);
    init_QPrintEngine(module);
    init_QPrinterInfo(module);
    init_QTextLength(module);
    init_QTextFormat(module);
    init_QTextFrameFormat(module);
    init_QTextTableFormat(module);
    init_QTextCharFormat(module);
    init_QTextImageFormat(module);
    init_QTextTableCellFormat(module);
    init_QTextBlockFormat(module);
    init_QTextListFormat(module);
    init_QTextCursor(module);
    init_QStyleOption(module);
    init_QStyleOptionToolBar(module);
    init_QStyleHintReturn(module);
    init_QStyleHintReturnMask(module);
    init_QStyleHintReturnVariant(module);
    init_QStyleOptionTabWidgetFrame(module);
    init_QStyleOptionProgressBar(module);
    init_QStyleOptionProgressBarV2(module);
    init_QStyleOptionMenuItem(module);
    init_QStyleOptionTabBarBase(module);
    init_QStyleOptionTabBarBaseV2(module);
    init_QStyleOptionButton(module);
    init_QStyleOptionDockWidget(module);
    init_QStyleOptionDockWidgetV2(module);
    init_QStyleOptionToolBox(module);
    init_QStyleOptionToolBoxV2(module);
    init_QStyleOptionFocusRect(module);
    init_QStyleOptionHeader(module);
    init_QStyleOptionGraphicsItem(module);
    init_QStyleOptionRubberBand(module);
    init_QStyleOptionFrame(module);
    init_QStyleOptionFrameV2(module);
    init_QStyleOptionFrameV3(module);
    init_QStyleOptionComplex(module);
    init_QStyleOptionSlider(module);
    init_QStyleOptionSpinBox(module);
    init_QStyleOptionToolButton(module);
    init_QStyleOptionComboBox(module);
    init_QStyleOptionTitleBar(module);
    init_QStyleOptionGroupBox(module);
    init_QStyleOptionSizeGrip(module);
    init_QStyleOptionViewItem(module);
    init_QStyleOptionViewItemV2(module);
    init_QStyleOptionViewItemV3(module);
    init_QStyleOptionViewItemV4(module);
    init_QStyleOptionTab(module);
    init_QStyleOptionTabV2(module);
    init_QStyleOptionTabV3(module);
    init_QItemSelectionRange(module);
    init_QItemSelection(module);
    init_QFileIconProvider(module);
    init_QItemEditorCreatorBase(module);
    init_QItemEditorFactory(module);
    init_QListWidgetItem(module);
    init_QTableWidgetSelectionRange(module);
    init_QTableWidgetItem(module);
    init_QTreeWidgetItemIterator(module);
    init_QTreeWidgetItem(module);
    init_QFontDatabase(module);
    init_QTextInlineObject(module);
    init_QTextLine(module);
    init_QTextObjectInterface(module);
    init_QTextBlockUserData(module);
    init_QTextBlock(module);
    init_QTextBlock_iterator(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX]->tp_dict);
    init_QTextFragment(module);
    init_QTextDocumentFragment(module);
    init_QTextTableCell(module);
    init_QStyleFactory(module);
    init_QDesktopServices(module);
    init_QUndoCommand(module);
    init_QIconEngine(module);
    init_QImageIOHandler(module);
    init_QPictureIO(module);
    init_QPixmapCache(module);
    init_QPixmapCache_Key(SbkPySide_QtGuiTypes[SBK_QPIXMAPCACHE_IDX]->tp_dict);
    init_QVector2D(module);
    init_QInputContextFactory(module);
    init_QX11Info(module);
    init_QPainter(module);
    init_QPainter_PixmapFragment(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX]->tp_dict);
    init_QIcon(module);
    init_QIconEngineV2(module);
    init_QGraphicsItem(module);
    init_QGraphicsLineItem(module);
    init_QGraphicsPixmapItem(module);
    init_QGraphicsItemGroup(module);
    init_QAbstractGraphicsShapeItem(module);
    init_QGraphicsSimpleTextItem(module);
    init_QGraphicsPathItem(module);
    init_QGraphicsRectItem(module);
    init_QGraphicsEllipseItem(module);
    init_QGraphicsPolygonItem(module);
    init_QGraphicsAnchorLayout(module);
    init_QImage(module);
    init_QPixmap(module);
    init_QBitmap(module);
    init_QFocusEvent(module);
    init_QInputEvent(module);
    init_QMouseEvent(module);
    init_QWheelEvent(module);
    init_QTabletEvent(module);
    init_QKeyEvent(module);
    init_QContextMenuEvent(module);
    init_QTouchEvent(module);
    init_QTouchEvent_TouchPoint(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX]->tp_dict);
    init_QPainterPath(module);
    init_QPainterPath_Element(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX]->tp_dict);
    init_QTransform(module);
    init_QBrush(module);
    init_QPen(module);
    init_QTileRules(module);
    init_QPaintEngine(module);
    init_QStandardItem(module);
    init_QUndoGroup(module);
    init_QAbstractItemDelegate(module);
    init_QStyledItemDelegate(module);
    init_QItemDelegate(module);
    init_QUndoStack(module);
    init_QPyTextObject(module);
    init_QItemSelectionModel(module);
    init_QButtonGroup(module);
    init_QGraphicsTransform(module);
    init_QGraphicsScale(module);
    init_QGraphicsRotation(module);
    init_QGesture(module);
    init_QPanGesture(module);
    init_QPinchGesture(module);
    init_QSwipeGesture(module);
    init_QTapGesture(module);
    init_QTapAndHoldGesture(module);
    init_QDataWidgetMapper(module);
    init_QDrag(module);
    init_QApplication(module);
    init_QAbstractTextDocumentLayout(module);
    init_QPlainTextDocumentLayout(module);
    init_QAbstractTextDocumentLayout_PaintContext(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_IDX]->tp_dict);
    init_QAbstractTextDocumentLayout_Selection(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_IDX]->tp_dict);
    init_QTextObject(module);
    init_QTextBlockGroup(module);
    init_QTextList(module);
    init_QTextFrame(module);
    init_QTextFrame_iterator(SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX]->tp_dict);
    init_QTextTable(module);
    init_QFileSystemModel(module);
    init_QProxyModel(module);
    init_QStandardItemModel(module);
    init_QAbstractProxyModel(module);
    init_QSortFilterProxyModel(module);
    init_QDirModel(module);
    init_QStringListModel(module);
    init_QGraphicsAnchor(module);
    init_QSessionManager(module);
    init_QShortcut(module);
    init_QValidator(module);
    init_QDoubleValidator(module);
    init_QRegExpValidator(module);
    init_QIntValidator(module);
    init_QSound(module);
    init_QGraphicsItemAnimation(module);
    init_QSyntaxHighlighter(module);
    init_QAction(module);
    init_QWidgetAction(module);
    init_QActionGroup(module);
    init_QStyle(module);
    init_QCommonStyle(module);
    init_QWindowsStyle(module);
    init_QCleanlooksStyle(module);
    init_QGtkStyle(module);
    init_QPlastiqueStyle(module);
    init_QMotifStyle(module);
    init_QCDEStyle(module);
    init_QGraphicsScene(module);
    init_QKeyEventTransition(module);
    init_QMouseEventTransition(module);
    init_QInputContext(module);
    init_QGraphicsObject(module);
    init_QGraphicsTextItem(module);
    init_QGraphicsWidget(module);
    init_QGraphicsProxyWidget(module);
    init_QCompleter(module);
    init_QLayout(module);
    init_QGridLayout(module);
    init_QStackedLayout(module);
    init_QBoxLayout(module);
    init_QHBoxLayout(module);
    init_QVBoxLayout(module);
    init_QFormLayout(module);
    init_QTextDocument(module);
    init_QClipboard(module);
    init_QMovie(module);
    init_QGraphicsEffect(module);
    init_QGraphicsOpacityEffect(module);
    init_QGraphicsColorizeEffect(module);
    init_QGraphicsBlurEffect(module);
    init_QGraphicsDropShadowEffect(module);
    init_QSystemTrayIcon(module);
    init_QRegion(module);
    init_QWidget(module);
    init_QStatusBar(module);
    init_QToolBar(module);
    init_QWorkspace(module);
    init_QX11EmbedWidget(module);
    init_QX11EmbedContainer(module);
    init_QFrame(module);
    init_QToolBox(module);
    init_QStackedWidget(module);
    init_QAbstractScrollArea(module);
    init_QAbstractItemView(module);
    init_QTableView(module);
    init_QTableWidget(module);
    init_QColumnView(module);
    init_QHeaderView(module);
    init_QTreeView(module);
    init_QTreeWidget(module);
    init_QListView(module);
    init_QListWidget(module);
    init_QScrollArea(module);
    init_QGraphicsView(module);
    init_QDesktopWidget(module);
    init_QDialog(module);
    init_QAbstractPageSetupDialog(module);
    init_QAbstractPrintDialog(module);
    init_QPrintDialog(module);
    init_QColorDialog(module);
    init_QErrorMessage(module);
    init_QFileDialog(module);
    init_QFontDialog(module);
    init_QUndoView(module);
    init_QAbstractButton(module);
    init_QPushButton(module);
    init_QCommandLinkButton(module);
    init_QToolButton(module);
    init_QRadioButton(module);
    init_QCheckBox(module);
    init_QCalendarWidget(module);
    init_QComboBox(module);
    init_QFontComboBox(module);
    init_QLineEdit(module);
    init_QInputDialog(module);
    init_QMessageBox(module);
    init_QPageSetupDialog(module);
    init_QPrintPreviewDialog(module);
    init_QDialogButtonBox(module);
    init_QProgressDialog(module);
    init_QDockWidget(module);
    init_QWizard(module);
    init_QFocusFrame(module);
    init_QWizardPage(module);
    init_QGroupBox(module);
    init_QLabel(module);
    init_QLCDNumber(module);
    init_QMainWindow(module);
    init_QAbstractSpinBox(module);
    init_QSpinBox(module);
    init_QDoubleSpinBox(module);
    init_QDateTimeEdit(module);
    init_QTimeEdit(module);
    init_QDateEdit(module);
    init_QMdiArea(module);
    init_QAbstractSlider(module);
    init_QSlider(module);
    init_QScrollBar(module);
    init_QDial(module);
    init_QMdiSubWindow(module);
    init_QMenu(module);
    init_QTabBar(module);
    init_QMenuBar(module);
    init_QTabWidget(module);
    init_QRubberBand(module);
    init_QTextEdit(module);
    init_QTextBrowser(module);
    init_QTextEdit_ExtraSelection(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_IDX]->tp_dict);
    init_QPlainTextEdit(module);
    init_QPrintPreviewWidget(module);
    init_QProgressBar(module);
    init_QSizeGrip(module);
    init_QSplashScreen(module);
    init_QSplitter(module);
    init_QSplitterHandle(module);
    init_QStylePainter(module);
    init_QMatrix4x2(module);
    init_QMatrix4x3(module);
    init_QMatrix3x2(module);
    init_QMatrix3x3(module);
    init_QMatrix3x4(module);
    init_QMatrix2x2(module);
    init_QMatrix2x3(module);
    init_QMatrix2x4(module);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'QList<int>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_int__CppToPython__QList_int_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX], "QList<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX],
        _QList_int__PythonToCpp__QList_int_,
        is__QList_int__PythonToCpp__QList_int__Convertible);

    // Register converter for type 'QList<QFontDatabase::WritingSystem>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QFONTDATABASE_WRITINGSYSTEM_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QFontDatabase_WritingSystem__CppToPython__QList_QFontDatabase_WritingSystem_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QFONTDATABASE_WRITINGSYSTEM_IDX], "QList<QFontDatabase::WritingSystem>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QFONTDATABASE_WRITINGSYSTEM_IDX],
        _QList_QFontDatabase_WritingSystem__PythonToCpp__QList_QFontDatabase_WritingSystem_,
        is__QList_QFontDatabase_WritingSystem__PythonToCpp__QList_QFontDatabase_WritingSystem__Convertible);

    // Register converter for type 'const QList<QTreeWidgetItem*>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QTreeWidgetItemPTR_REF_CppToPython__constQList_QTreeWidgetItemPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX], "const QList<QTreeWidgetItem*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX], "QList<QTreeWidgetItem*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX],
        _constQList_QTreeWidgetItemPTR_REF_PythonToCpp__constQList_QTreeWidgetItemPTR_REF,
        is__constQList_QTreeWidgetItemPTR_REF_PythonToCpp__constQList_QTreeWidgetItemPTR_REF_Convertible);

    // Register converter for type 'const QList<QStandardItem*>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QStandardItemPTR_REF_CppToPython__constQList_QStandardItemPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], "const QList<QStandardItem*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], "QList<QStandardItem*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX],
        _constQList_QStandardItemPTR_REF_PythonToCpp__constQList_QStandardItemPTR_REF,
        is__constQList_QStandardItemPTR_REF_PythonToCpp__constQList_QStandardItemPTR_REF_Convertible);

    // Register converter for type 'const QList<QItemSelectionRange>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QItemSelectionRange_REF_CppToPython__constQList_QItemSelectionRange_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], "const QList<QItemSelectionRange>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], "QList<QItemSelectionRange>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX],
        _constQList_QItemSelectionRange_REF_PythonToCpp__constQList_QItemSelectionRange_REF,
        is__constQList_QItemSelectionRange_REF_PythonToCpp__constQList_QItemSelectionRange_REF_Convertible);

    // Register converter for type 'const QSet<QItemSelectionRange>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QSET_QITEMSELECTIONRANGE_IDX] = Shiboken::Conversions::createConverter(&PySet_Type, _constQSet_QItemSelectionRange_REF_CppToPython__constQSet_QItemSelectionRange_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QSET_QITEMSELECTIONRANGE_IDX], "const QSet<QItemSelectionRange>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QSET_QITEMSELECTIONRANGE_IDX], "QSet<QItemSelectionRange>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QSET_QITEMSELECTIONRANGE_IDX],
        _constQSet_QItemSelectionRange_REF_PythonToCpp__constQSet_QItemSelectionRange_REF,
        is__constQSet_QItemSelectionRange_REF_PythonToCpp__constQSet_QItemSelectionRange_REF_Convertible);

    // Register converter for type 'const QVector<QItemSelectionRange>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QITEMSELECTIONRANGE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QItemSelectionRange_REF_CppToPython__constQVector_QItemSelectionRange_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QITEMSELECTIONRANGE_IDX], "const QVector<QItemSelectionRange>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QITEMSELECTIONRANGE_IDX], "QVector<QItemSelectionRange>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QITEMSELECTIONRANGE_IDX],
        _constQVector_QItemSelectionRange_REF_PythonToCpp__constQVector_QItemSelectionRange_REF,
        is__constQVector_QItemSelectionRange_REF_PythonToCpp__constQVector_QItemSelectionRange_REF_Convertible);

    // Register converter for type 'QVector<QTextLength>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QVector_QTextLength__CppToPython__QVector_QTextLength_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX], "QVector<QTextLength>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX],
        _QVector_QTextLength__PythonToCpp__QVector_QTextLength_,
        is__QVector_QTextLength__PythonToCpp__QVector_QTextLength__Convertible);

    // Register converter for type 'QMap<int,QVariant>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_int_QVariant__CppToPython__QMap_int_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], "QMap<int,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX],
        _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_,
        is__QMap_int_QVariant__PythonToCpp__QMap_int_QVariant__Convertible);

    // Register converter for type 'const QList<QTextOption::Tab>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QTextOption_Tab_REF_CppToPython__constQList_QTextOption_Tab_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX], "const QList<QTextOption::Tab>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX], "QList<QTextOption::Tab>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX],
        _constQList_QTextOption_Tab_REF_PythonToCpp__constQList_QTextOption_Tab_REF,
        is__constQList_QTextOption_Tab_REF_PythonToCpp__constQList_QTextOption_Tab_REF_Convertible);

    // Register converter for type 'QList<QPrinterInfo>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTERINFO_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPrinterInfo__CppToPython__QList_QPrinterInfo_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTERINFO_IDX], "QList<QPrinterInfo>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTERINFO_IDX],
        _QList_QPrinterInfo__PythonToCpp__QList_QPrinterInfo_,
        is__QList_QPrinterInfo__PythonToCpp__QList_QPrinterInfo__Convertible);

    // Register converter for type 'QList<QPrinter::PageSize>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTER_PAGESIZE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPrinter_PageSize__CppToPython__QList_QPrinter_PageSize_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTER_PAGESIZE_IDX], "QList<QPrinter::PageSize>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTER_PAGESIZE_IDX],
        _QList_QPrinter_PageSize__PythonToCpp__QList_QPrinter_PageSize_,
        is__QList_QPrinter_PageSize__PythonToCpp__QList_QPrinter_PageSize__Convertible);

    // Register converter for type 'QList<qreal>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QREAL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_qreal__CppToPython__QList_qreal_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QREAL_IDX], "QList<qreal>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QREAL_IDX],
        _QList_qreal__PythonToCpp__QList_qreal_,
        is__QList_qreal__PythonToCpp__QList_qreal__Convertible);

    // Register converter for type 'QVector<qreal>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QVector_qreal__CppToPython__QVector_qreal_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX], "QVector<qreal>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX],
        _QVector_qreal__PythonToCpp__QVector_qreal_,
        is__QVector_qreal__PythonToCpp__QVector_qreal__Convertible);

    // Register converter for type 'QPair<qreal,QColor>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_qreal_QColor__CppToPython__QPair_qreal_QColor_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX], "QPair<qreal,QColor>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX],
        _QPair_qreal_QColor__PythonToCpp__QPair_qreal_QColor_,
        is__QPair_qreal_QColor__PythonToCpp__QPair_qreal_QColor__Convertible);

    // Register converter for type 'const QVector<QPair<qreal,QColor>>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QPair_qreal_QColor__REF_CppToPython__constQVector_QPair_qreal_QColor__REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX], "const QVector<QPair<qreal,QColor>>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX], "QVector<QPair<qreal,QColor>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX],
        _constQVector_QPair_qreal_QColor__REF_PythonToCpp__constQVector_QPair_qreal_QColor__REF,
        is__constQVector_QPair_qreal_QColor__REF_PythonToCpp__constQVector_QPair_qreal_QColor__REF_Convertible);

    // Register converter for type 'QList<QKeySequence>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QKeySequence__CppToPython__QList_QKeySequence_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX], "QList<QKeySequence>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX],
        _QList_QKeySequence__PythonToCpp__QList_QKeySequence_,
        is__QList_QKeySequence__PythonToCpp__QList_QKeySequence__Convertible);

    // Register converter for type 'QList<QPolygonF>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPolygonF__CppToPython__QList_QPolygonF_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX], "QList<QPolygonF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX],
        _QList_QPolygonF__PythonToCpp__QList_QPolygonF_,
        is__QList_QPolygonF__PythonToCpp__QList_QPolygonF__Convertible);

    // Register converter for type 'const QVector<QPointF>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QPointF_REF_CppToPython__constQVector_QPointF_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], "const QVector<QPointF>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], "QVector<QPointF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX],
        _constQVector_QPointF_REF_PythonToCpp__constQVector_QPointF_REF,
        is__constQVector_QPointF_REF_PythonToCpp__constQVector_QPointF_REF_Convertible);

    // Register converter for type 'const QList<QPointF>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QPointF_REF_CppToPython__constQList_QPointF_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINTF_IDX], "const QList<QPointF>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINTF_IDX], "QList<QPointF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINTF_IDX],
        _constQList_QPointF_REF_PythonToCpp__constQList_QPointF_REF,
        is__constQList_QPointF_REF_PythonToCpp__constQList_QPointF_REF_Convertible);

    // Register converter for type 'const QVector<QPoint>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QPoint_REF_CppToPython__constQVector_QPoint_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], "const QVector<QPoint>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], "QVector<QPoint>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX],
        _constQVector_QPoint_REF_PythonToCpp__constQVector_QPoint_REF,
        is__constQVector_QPoint_REF_PythonToCpp__constQVector_QPoint_REF_Convertible);

    // Register converter for type 'const QList<QPoint>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QPoint_REF_CppToPython__constQList_QPoint_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINT_IDX], "const QList<QPoint>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINT_IDX], "QList<QPoint>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINT_IDX],
        _constQList_QPoint_REF_PythonToCpp__constQList_QPoint_REF,
        is__constQList_QPoint_REF_PythonToCpp__constQList_QPoint_REF_Convertible);

    // Register converter for type 'const QList<QTouchEvent::TouchPoint>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QTouchEvent_TouchPoint_REF_CppToPython__constQList_QTouchEvent_TouchPoint_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX], "const QList<QTouchEvent::TouchPoint>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX], "QList<QTouchEvent::TouchPoint>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX],
        _constQList_QTouchEvent_TouchPoint_REF_PythonToCpp__constQList_QTouchEvent_TouchPoint_REF,
        is__constQList_QTouchEvent_TouchPoint_REF_PythonToCpp__constQList_QTouchEvent_TouchPoint_REF_Convertible);

    // Register converter for type 'const QList<QGesture*>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QGesturePTR_REF_CppToPython__constQList_QGesturePTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX], "const QList<QGesture*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX], "QList<QGesture*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX],
        _constQList_QGesturePTR_REF_PythonToCpp__constQList_QGesturePTR_REF,
        is__constQList_QGesturePTR_REF_PythonToCpp__constQList_QGesturePTR_REF_Convertible);

    // Register converter for type 'const QList<QInputMethodEvent::Attribute>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QInputMethodEvent_Attribute_REF_CppToPython__constQList_QInputMethodEvent_Attribute_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX], "const QList<QInputMethodEvent::Attribute>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX], "QList<QInputMethodEvent::Attribute>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX],
        _constQList_QInputMethodEvent_Attribute_REF_PythonToCpp__constQList_QInputMethodEvent_Attribute_REF,
        is__constQList_QInputMethodEvent_Attribute_REF_PythonToCpp__constQList_QInputMethodEvent_Attribute_REF_Convertible);

    // Register converter for type 'QList<QTextLayout::FormatRange>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTLAYOUT_FORMATRANGE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QTextLayout_FormatRange__CppToPython__QList_QTextLayout_FormatRange_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTLAYOUT_FORMATRANGE_IDX], "QList<QTextLayout::FormatRange>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTLAYOUT_FORMATRANGE_IDX],
        _QList_QTextLayout_FormatRange__PythonToCpp__QList_QTextLayout_FormatRange_,
        is__QList_QTextLayout_FormatRange__PythonToCpp__QList_QTextLayout_FormatRange__Convertible);

    // Register converter for type 'const QVector<QTextLayout::FormatRange>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLAYOUT_FORMATRANGE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QTextLayout_FormatRange_REF_CppToPython__constQVector_QTextLayout_FormatRange_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLAYOUT_FORMATRANGE_IDX], "const QVector<QTextLayout::FormatRange>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLAYOUT_FORMATRANGE_IDX], "QVector<QTextLayout::FormatRange>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLAYOUT_FORMATRANGE_IDX],
        _constQVector_QTextLayout_FormatRange_REF_PythonToCpp__constQVector_QTextLayout_FormatRange_REF,
        is__constQVector_QTextLayout_FormatRange_REF_PythonToCpp__constQVector_QTextLayout_FormatRange_REF_Convertible);

    // Register converter for type 'QVector<unsigned int>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QVector_unsignedint__CppToPython__QVector_unsignedint_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX], "QVector<unsigned int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX],
        _QVector_unsignedint__PythonToCpp__QVector_unsignedint_,
        is__QVector_unsignedint__PythonToCpp__QVector_unsignedint__Convertible);

    // Register converter for type 'QList<QGraphicsItem*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QGraphicsItemPTR__CppToPython__QList_QGraphicsItemPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], "QList<QGraphicsItem*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX],
        _QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR_,
        is__QList_QGraphicsItemPTR__PythonToCpp__QList_QGraphicsItemPTR__Convertible);

    // Register converter for type 'const QList<QGraphicsTransform*>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSTRANSFORMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QGraphicsTransformPTR_REF_CppToPython__constQList_QGraphicsTransformPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSTRANSFORMPTR_IDX], "const QList<QGraphicsTransform*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSTRANSFORMPTR_IDX], "QList<QGraphicsTransform*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSTRANSFORMPTR_IDX],
        _constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF,
        is__constQList_QGraphicsTransformPTR_REF_PythonToCpp__constQList_QGraphicsTransformPTR_REF_Convertible);

    // Register converter for type 'QList<QSize>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSIZE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QSize__CppToPython__QList_QSize_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSIZE_IDX], "QList<QSize>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSIZE_IDX],
        _QList_QSize__PythonToCpp__QList_QSize_,
        is__QList_QSize__PythonToCpp__QList_QSize__Convertible);

    // Register converter for type 'const QVector<QLine>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QLine_REF_CppToPython__constQVector_QLine_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINE_IDX], "const QVector<QLine>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINE_IDX], "QVector<QLine>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINE_IDX],
        _constQVector_QLine_REF_PythonToCpp__constQVector_QLine_REF,
        is__constQVector_QLine_REF_PythonToCpp__constQVector_QLine_REF_Convertible);

    // Register converter for type 'const QVector<QLineF>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINEF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QLineF_REF_CppToPython__constQVector_QLineF_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINEF_IDX], "const QVector<QLineF>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINEF_IDX], "QVector<QLineF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINEF_IDX],
        _constQVector_QLineF_REF_PythonToCpp__constQVector_QLineF_REF,
        is__constQVector_QLineF_REF_PythonToCpp__constQVector_QLineF_REF_Convertible);

    // Register converter for type 'const QVector<QRect>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QRect_REF_CppToPython__constQVector_QRect_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECT_IDX], "const QVector<QRect>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECT_IDX], "QVector<QRect>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECT_IDX],
        _constQVector_QRect_REF_PythonToCpp__constQVector_QRect_REF,
        is__constQVector_QRect_REF_PythonToCpp__constQVector_QRect_REF_Convertible);

    // Register converter for type 'const QVector<QRectF>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQVector_QRectF_REF_CppToPython__constQVector_QRectF_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECTF_IDX], "const QVector<QRectF>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECTF_IDX], "QVector<QRectF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECTF_IDX],
        _constQVector_QRectF_REF_PythonToCpp__constQVector_QRectF_REF,
        is__constQVector_QRectF_REF_PythonToCpp__constQVector_QRectF_REF_Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QUndoStack*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QUNDOSTACKPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QUndoStackPTR__CppToPython__QList_QUndoStackPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QUNDOSTACKPTR_IDX], "QList<QUndoStack*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QUNDOSTACKPTR_IDX],
        _QList_QUndoStackPTR__PythonToCpp__QList_QUndoStackPTR_,
        is__QList_QUndoStackPTR__PythonToCpp__QList_QUndoStackPTR__Convertible);

    // Register converter for type 'QList<QAction*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QACTIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QActionPTR__CppToPython__QList_QActionPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QACTIONPTR_IDX], "QList<QAction*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QACTIONPTR_IDX],
        _QList_QActionPTR__PythonToCpp__QList_QActionPTR_,
        is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible);

    // Register converter for type 'const QList<QRectF>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QRECTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QRectF_REF_CppToPython__constQList_QRectF_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QRECTF_IDX], "const QList<QRectF>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QRECTF_IDX], "QList<QRectF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QRECTF_IDX],
        _constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF,
        is__constQList_QRectF_REF_PythonToCpp__constQList_QRectF_REF_Convertible);

    // Register converter for type 'QList<QGraphicsView*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSVIEWPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QGraphicsViewPTR__CppToPython__QList_QGraphicsViewPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSVIEWPTR_IDX], "QList<QGraphicsView*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSVIEWPTR_IDX],
        _QList_QGraphicsViewPTR__PythonToCpp__QList_QGraphicsViewPTR_,
        is__QList_QGraphicsViewPTR__PythonToCpp__QList_QGraphicsViewPTR__Convertible);

    // Register converter for type 'QPair<qreal,QPointF>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QPOINTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_qreal_QPointF__CppToPython__QPair_qreal_QPointF_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QPOINTF_IDX], "QPair<qreal,QPointF>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QPOINTF_IDX],
        _QPair_qreal_QPointF__PythonToCpp__QPair_qreal_QPointF_,
        is__QPair_qreal_QPointF__PythonToCpp__QPair_qreal_QPointF__Convertible);

    // Register converter for type 'QList<QPair<qreal,QPointF>>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPAIR_QREAL_QPOINTF_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPair_qreal_QPointF___CppToPython__QList_QPair_qreal_QPointF__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPAIR_QREAL_QPOINTF_IDX], "QList<QPair<qreal,QPointF>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPAIR_QREAL_QPOINTF_IDX],
        _QList_QPair_qreal_QPointF___PythonToCpp__QList_QPair_qreal_QPointF__,
        is__QList_QPair_qreal_QPointF___PythonToCpp__QList_QPair_qreal_QPointF___Convertible);

    // Register converter for type 'QPair<qreal,qreal>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QREAL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_qreal_qreal__CppToPython__QPair_qreal_qreal_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QREAL_IDX], "QPair<qreal,qreal>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QPAIR_QREAL_QREAL_IDX],
        _QPair_qreal_qreal__PythonToCpp__QPair_qreal_qreal_,
        is__QPair_qreal_qreal__PythonToCpp__QPair_qreal_qreal__Convertible);

    // Register converter for type 'QList<QPair<qreal,qreal>>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPAIR_QREAL_QREAL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPair_qreal_qreal___CppToPython__QList_QPair_qreal_qreal__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPAIR_QREAL_QREAL_IDX], "QList<QPair<qreal,qreal>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPAIR_QREAL_QREAL_IDX],
        _QList_QPair_qreal_qreal___PythonToCpp__QList_QPair_qreal_qreal__,
        is__QList_QPair_qreal_qreal___PythonToCpp__QList_QPair_qreal_qreal___Convertible);

    // Register converter for type 'const QHash<int,QByteArray>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QHASH_INT_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _constQHash_int_QByteArray_REF_CppToPython__constQHash_int_QByteArray_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QHASH_INT_QBYTEARRAY_IDX], "const QHash<int,QByteArray>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QHASH_INT_QBYTEARRAY_IDX], "QHash<int,QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QHASH_INT_QBYTEARRAY_IDX],
        _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF,
        is__constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF_Convertible);

    // Register converter for type 'QList<QTextFrame*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTFRAMEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QTextFramePTR__CppToPython__QList_QTextFramePTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTFRAMEPTR_IDX], "QList<QTextFrame*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTFRAMEPTR_IDX],
        _QList_QTextFramePTR__PythonToCpp__QList_QTextFramePTR_,
        is__QList_QTextFramePTR__PythonToCpp__QList_QTextFramePTR__Convertible);

    // Register converter for type 'QList<QTextBlock>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTBLOCK_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QTextBlock__CppToPython__QList_QTextBlock_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTBLOCK_IDX], "QList<QTextBlock>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTBLOCK_IDX],
        _QList_QTextBlock__PythonToCpp__QList_QTextBlock_,
        is__QList_QTextBlock__PythonToCpp__QList_QTextBlock__Convertible);

    // Register converter for type 'QList<QWidget*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIDGETPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWidgetPTR__CppToPython__QList_QWidgetPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIDGETPTR_IDX], "QList<QWidget*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIDGETPTR_IDX],
        _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_,
        is__QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR__Convertible);

    // Register converter for type 'QList<QAbstractAnimation*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTANIMATIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QAbstractAnimationPTR__CppToPython__QList_QAbstractAnimationPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTANIMATIONPTR_IDX], "QList<QAbstractAnimation*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTANIMATIONPTR_IDX],
        _QList_QAbstractAnimationPTR__PythonToCpp__QList_QAbstractAnimationPTR_,
        is__QList_QAbstractAnimationPTR__PythonToCpp__QList_QAbstractAnimationPTR__Convertible);

    // Register converter for type 'const QList<QAbstractState*>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTSTATEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QAbstractStatePTR_REF_CppToPython__constQList_QAbstractStatePTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTSTATEPTR_IDX], "const QList<QAbstractState*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTSTATEPTR_IDX], "QList<QAbstractState*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTSTATEPTR_IDX],
        _constQList_QAbstractStatePTR_REF_PythonToCpp__constQList_QAbstractStatePTR_REF,
        is__constQList_QAbstractStatePTR_REF_PythonToCpp__constQList_QAbstractStatePTR_REF_Convertible);

    // Register converter for type 'QList<QGraphicsWidget*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSWIDGETPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QGraphicsWidgetPTR__CppToPython__QList_QGraphicsWidgetPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSWIDGETPTR_IDX], "QList<QGraphicsWidget*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSWIDGETPTR_IDX],
        _QList_QGraphicsWidgetPTR__PythonToCpp__QList_QGraphicsWidgetPTR_,
        is__QList_QGraphicsWidgetPTR__PythonToCpp__QList_QGraphicsWidgetPTR__Convertible);

    // Register converter for type 'QList<QListWidgetItem*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QLISTWIDGETITEMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QListWidgetItemPTR__CppToPython__QList_QListWidgetItemPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QLISTWIDGETITEMPTR_IDX], "QList<QListWidgetItem*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QLISTWIDGETITEMPTR_IDX],
        _QList_QListWidgetItemPTR__PythonToCpp__QList_QListWidgetItemPTR_,
        is__QList_QListWidgetItemPTR__PythonToCpp__QList_QListWidgetItemPTR__Convertible);

    // Register converter for type 'QList<QTableWidgetItem*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTABLEWIDGETITEMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QTableWidgetItemPTR__CppToPython__QList_QTableWidgetItemPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTABLEWIDGETITEMPTR_IDX], "QList<QTableWidgetItem*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTABLEWIDGETITEMPTR_IDX],
        _QList_QTableWidgetItemPTR__PythonToCpp__QList_QTableWidgetItemPTR_,
        is__QList_QTableWidgetItemPTR__PythonToCpp__QList_QTableWidgetItemPTR__Convertible);

    // Register converter for type 'QList<QTableWidgetSelectionRange>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTABLEWIDGETSELECTIONRANGE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QTableWidgetSelectionRange__CppToPython__QList_QTableWidgetSelectionRange_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTABLEWIDGETSELECTIONRANGE_IDX], "QList<QTableWidgetSelectionRange>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTABLEWIDGETSELECTIONRANGE_IDX],
        _QList_QTableWidgetSelectionRange__PythonToCpp__QList_QTableWidgetSelectionRange_,
        is__QList_QTableWidgetSelectionRange__PythonToCpp__QList_QTableWidgetSelectionRange__Convertible);

    // Register converter for type 'QList<QTextEdit::ExtraSelection>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTEDIT_EXTRASELECTION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QTextEdit_ExtraSelection__CppToPython__QList_QTextEdit_ExtraSelection_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTEDIT_EXTRASELECTION_IDX], "QList<QTextEdit::ExtraSelection>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTEDIT_EXTRASELECTION_IDX],
        _QList_QTextEdit_ExtraSelection__PythonToCpp__QList_QTextEdit_ExtraSelection_,
        is__QList_QTextEdit_ExtraSelection__PythonToCpp__QList_QTextEdit_ExtraSelection__Convertible);

    // Register converter for type 'QList<QMdiSubWindow*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QMDISUBWINDOWPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QMdiSubWindowPTR__CppToPython__QList_QMdiSubWindowPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QMDISUBWINDOWPTR_IDX], "QList<QMdiSubWindow*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QMDISUBWINDOWPTR_IDX],
        _QList_QMdiSubWindowPTR__PythonToCpp__QList_QMdiSubWindowPTR_,
        is__QList_QMdiSubWindowPTR__PythonToCpp__QList_QMdiSubWindowPTR__Convertible);

    // Register converter for type 'QList<QDockWidget*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QDOCKWIDGETPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QDockWidgetPTR__CppToPython__QList_QDockWidgetPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QDOCKWIDGETPTR_IDX], "QList<QDockWidget*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QDOCKWIDGETPTR_IDX],
        _QList_QDockWidgetPTR__PythonToCpp__QList_QDockWidgetPTR_,
        is__QList_QDockWidgetPTR__PythonToCpp__QList_QDockWidgetPTR__Convertible);

    // Register converter for type 'const QList<QWizard::WizardButton>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIZARD_WIZARDBUTTON_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QWizard_WizardButton_REF_CppToPython__constQList_QWizard_WizardButton_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIZARD_WIZARDBUTTON_IDX], "const QList<QWizard::WizardButton>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIZARD_WIZARDBUTTON_IDX], "QList<QWizard::WizardButton>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIZARD_WIZARDBUTTON_IDX],
        _constQList_QWizard_WizardButton_REF_PythonToCpp__constQList_QWizard_WizardButton_REF,
        is__constQList_QWizard_WizardButton_REF_PythonToCpp__constQList_QWizard_WizardButton_REF_Convertible);

    // Register converter for type 'QList<QAbstractButton*>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTBUTTONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QAbstractButtonPTR__CppToPython__QList_QAbstractButtonPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTBUTTONPTR_IDX], "QList<QAbstractButton*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTBUTTONPTR_IDX],
        _QList_QAbstractButtonPTR__PythonToCpp__QList_QAbstractButtonPTR_,
        is__QList_QAbstractButtonPTR__PythonToCpp__QList_QAbstractButtonPTR__Convertible);

    // Register converter for type 'QMap<QDate,QTextCharFormat>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_QDATE_QTEXTCHARFORMAT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QDate_QTextCharFormat__CppToPython__QMap_QDate_QTextCharFormat_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_QDATE_QTEXTCHARFORMAT_IDX], "QMap<QDate,QTextCharFormat>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_QDATE_QTEXTCHARFORMAT_IDX],
        _QMap_QDate_QTextCharFormat__PythonToCpp__QMap_QDate_QTextCharFormat_,
        is__QMap_QDate_QTextCharFormat__PythonToCpp__QMap_QDate_QTextCharFormat__Convertible);

    // Register converter for type 'const QList<QUrl>&'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QURL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QUrl_REF_CppToPython__constQList_QUrl_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QURL_IDX], "const QList<QUrl>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QURL_IDX], "QList<QUrl>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QURL_IDX],
        _constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF,
        is__constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF_Convertible);

    // Register converter for type 'QVector<QTextFormat>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTFORMAT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QVector_QTextFormat__CppToPython__QVector_QTextFormat_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTFORMAT_IDX], "QVector<QTextFormat>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTFORMAT_IDX],
        _QVector_QTextFormat__PythonToCpp__QVector_QTextFormat_,
        is__QVector_QTextFormat__PythonToCpp__QVector_QTextFormat__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);


    // Extended implicit conversions for PySide.QtCore.QPointF.
    Shiboken::Conversions::addPythonToCppValueConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX],
        QPainterPath_Element_PythonToCpp_PySide_QtCore_QPointF,
        is_QPainterPath_Element_PythonToCpp_PySide_QtCore_QPointF_Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtGuiTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtGuiTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtGui");
    }
    // Begin code injection
    // ========================================================================
    // START of custom code block [file: glue/qtgui_qapp.cpp]
    // Init qApp macro to None.
    if (qApp) {
        PyObject* pyApp = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], qApp);
        Py_INCREF(pyApp);
        PyModule_AddObject(module, "qApp", pyApp);
    } else {
        Py_INCREF(Py_None);
        PyModule_AddObject(module, "qApp", Py_None);
    }
    moduleQtGui = module;

    // END of custom code block [file: glue/qtgui_qapp.cpp]
    // ========================================================================

    // End of code injection


    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
