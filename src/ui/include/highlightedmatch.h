/*
 * Copyright (C) 2020 Anton Filimonov and other contributors
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

#ifndef KLOGG_HIGHLIGHTEDMATCH_H
#define KLOGG_HIGHLIGHTEDMATCH_H

#include "linetypes.h"
#include <QColor>

// Represents a match result for QuickFind or highlighter
class HighlightedMatch {
  public:
    // Construct a match (must be initialised)
    HighlightedMatch( LineColumn start_column, LineLength size, QColor foreColor, QColor backColor )
        : startColumn_{ start_column }
        , size_{ size }
        , foreColor_{ foreColor }
        , backColor_{ backColor }
    {
    }

    LineColumn startColumn() const
    {
        return startColumn_;
    }

    LineLength size() const
    {
        return size_;
    }

    QColor foreColor() const
    {
        return foreColor_;
    }

    QColor backColor() const
    {
        return backColor_;
    }

  private:
    LineColumn startColumn_;
    LineLength size_;

    QColor foreColor_;
    QColor backColor_;
};

#endif // KLOGG_HIGHLIGHTEDMATCH_H
