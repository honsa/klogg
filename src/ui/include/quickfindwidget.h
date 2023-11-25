/*
 * Copyright (C) 2010, 2013 Nicolas Bonnefon and other contributors
 *
 * This file is part of glogg.
 *
 * glogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glogg.  If not, see <http://www.gnu.org/licenses/>.
 */

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

#ifndef QUICKFINDWIDGET_H
#define QUICKFINDWIDGET_H

#include <QWidget>
#include <QTimer>

class QHBoxLayout;
class QLineEdit;
class QToolButton;
class QLabel;
class QCheckBox;
class QFNotification;

enum QFDirection {
    Forward,
    Backward,
};

class QuickFindWidget : public QWidget
{
  Q_OBJECT

  public:
    QuickFindWidget( QWidget* parent = nullptr );

    // Show the widget with the given direction
    // when requested by the user (the widget won't timeout)
    void userActivate();

  public Q_SLOTS:
    // Instructs the widget to change the pattern displayed
    void changeDisplayedPattern( const QString& newPattern, bool isRegex );

    // Show the widget for a notification (will timeout)
    void notify( const QFNotification& message );
    // Clear the notification
    void clearNotification();

  private Q_SLOTS:
    void doSearchForward();
    void doSearchBackward();
    void returnHandler();
    void closeHandler();
    void notificationTimeout();
    void textChanged();

  Q_SIGNALS:
    // Sent when Return is pressed to confirm the pattern
    // (pattern and ignor_case flag)
    void patternConfirmed( const QString&, bool, bool );
    // Sent every time the pattern is modified
    // (pattern and ignor_case flag)
    void patternUpdated( const QString&, bool, bool );
    void close();
    // Emitted when the user closes the window
    void cancelSearch();
    void searchForward();
    void searchBackward();
    void searchNext();

  private:
    QHBoxLayout* layout_;

    QToolButton* closeButton_;
    QToolButton* nextButton_;
    QToolButton* previousButton_;
    QLineEdit*   editQuickFind_;
    QCheckBox*   ignoreCaseCheck_;
    QLabel*      notificationText_;

    QToolButton* setupToolButton(const QString &text, const QString &icon);
    bool isIgnoreCase() const;
    bool isRegexSearch() const;

    QTimer*      notificationTimer_;

    QFDirection  direction_;

    // Whether the user explicitely wants us on the screen
    bool         userRequested_;

    int          patternCursorPosition_;
};

#endif
