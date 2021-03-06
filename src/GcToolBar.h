/*
 * Copyright 2011 (c) Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_GcToolBar_h
#define _GC_GcToolBar_h 1

#include <QtGui>
#include <QList>
#include <QAction>

class GcToolButton : public QWidget
{
    Q_OBJECT

public:

    GcToolButton(QWidget *parent, QAction *);
    bool selected;
    QAction *action;

public slots:
    void paintEvent (QPaintEvent *event);

private:

    void paintBackground(QPaintEvent *event);
    QLabel *label;

};

class GcToolBar : public QWidget
{
    Q_OBJECT

public:

    GcToolBar(QWidget *parent);
    ~GcToolBar();

public slots:
    bool eventFilter(QObject *o,QEvent *e);
    void paintEvent (QPaintEvent *event);
    void addAction(QAction *);
    void addWidget(QWidget *); // any widget but doesn't toggle selection
    void addStretch();
    void select(int index);

private:
    QHBoxLayout *layout;
    QList<GcToolButton*> buttons;

    void paintBackground(QPaintEvent *);
};

#endif
