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

#ifndef SBK_QHELPINDEXWIDGETWRAPPER_H
#define SBK_QHELPINDEXWIDGETWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qhelpindexwidget.h>

namespace PySide { class DynamicQMetaObject; }

class QHelpIndexWidgetWrapper : public QHelpIndexWidget
{
public:
    virtual void actionEvent(QActionEvent * event);
    virtual void changeEvent(QEvent * arg__1);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void closeEditor(QWidget * editor, QAbstractItemDelegate::EndEditHint hint);
    virtual void closeEvent(QCloseEvent * event);
    virtual void commitData(QWidget * editor);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * arg__1);
    virtual void currentChanged(const QModelIndex & current, const QModelIndex & previous);
    virtual void customEvent(QEvent * arg__1);
    virtual void dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void doItemsLayout();
    virtual void dragEnterEvent(QDragEnterEvent * event);
    virtual void dragLeaveEvent(QDragLeaveEvent * e);
    virtual void dragMoveEvent(QDragMoveEvent * e);
    virtual void dropEvent(QDropEvent * e);
    virtual bool edit(const QModelIndex & index, QAbstractItemView::EditTrigger trigger, QEvent * event);
    virtual void editorDestroyed(QObject * editor);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * e);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
    virtual int horizontalOffset() const;
    virtual void horizontalScrollbarAction(int action);
    virtual void horizontalScrollbarValueChanged(int value);
    virtual QModelIndex indexAt(const QPoint & p) const;
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery query) const;
    virtual bool isIndexHidden(const QModelIndex & index) const;
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void keyboardSearch(const QString & search);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * event);
    virtual const QMetaObject * metaObject() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * e);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * e);
    virtual QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, QFlags<Qt::KeyboardModifier> modifiers);
    virtual void moveEvent(QMoveEvent * event);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * e);
    virtual void reset();
    virtual void resizeEvent(QResizeEvent * e);
    virtual void rowsAboutToBeRemoved(const QModelIndex & parent, int start, int end);
    virtual void rowsInserted(const QModelIndex & parent, int start, int end);
    virtual void scrollContentsBy(int dx, int dy);
    virtual void scrollTo(const QModelIndex & index, QAbstractItemView::ScrollHint hint = EnsureVisible);
    virtual void selectAll();
    virtual QModelIndexList selectedIndexes() const;
    virtual void selectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
    virtual QFlags<QItemSelectionModel::SelectionFlag> selectionCommand(const QModelIndex & index, const QEvent * event = 0) const;
    virtual void setModel(QAbstractItemModel * model);
    virtual void setRootIndex(const QModelIndex & index);
    virtual void setSelection(const QRect & rect, QFlags<QItemSelectionModel::SelectionFlag> command);
    virtual void setSelectionModel(QItemSelectionModel * selectionModel);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * event);
    virtual QSize sizeHint() const;
    virtual int sizeHintForColumn(int column) const;
    virtual int sizeHintForRow(int row) const;
    virtual void startDrag(QFlags<Qt::DropAction> supportedActions);
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * e);
    virtual void updateEditorData();
    virtual void updateEditorGeometries();
    virtual void updateGeometries();
    virtual int verticalOffset() const;
    virtual void verticalScrollbarAction(int action);
    virtual void verticalScrollbarValueChanged(int value);
    virtual QStyleOptionViewItem viewOptions() const;
    virtual bool viewportEvent(QEvent * event);
    virtual QRect visualRect(const QModelIndex & index) const;
    virtual QRegion visualRegionForSelection(const QItemSelection & selection) const;
    virtual void wheelEvent(QWheelEvent * arg__1);
    virtual ~QHelpIndexWidgetWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QHELPINDEXWIDGETWRAPPER_H

