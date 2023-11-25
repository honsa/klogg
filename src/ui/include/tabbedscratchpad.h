/*
 * Copyright (C) 2019 Anton Filimonov and other contributors
 *
 * This file is part of klogg.
 *
 * klogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * klogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with klogg.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KLOGG_TABBEDSCRATCHPAD_H
#define KLOGG_TABBEDSCRATCHPAD_H

#include <QKeyEvent>
#include <QTabWidget>
#include <QWidget>

class TabbedScratchPad : public QWidget {
    Q_OBJECT
  public:
    explicit TabbedScratchPad( QWidget* parent = nullptr );

    ~TabbedScratchPad() = default;
    TabbedScratchPad( const TabbedScratchPad& ) = delete;
    TabbedScratchPad& operator=( const TabbedScratchPad& ) = delete;

  public Q_SLOTS:
    void addData( QString data );
    void replaceData( QString data );

  protected:
    void keyPressEvent( QKeyEvent* event ) override;

  private:
    void addTab();

  private:
    QTabWidget* tabWidget_{ nullptr };
    int tabCounter_{};
};

#endif // KLOGG_TABBEDSCRATCHPAD_H
