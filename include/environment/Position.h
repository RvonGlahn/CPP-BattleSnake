#pragma once

#include "Direction.h"
#include <iostream>
#include <set>

class Position
{
  public:
    Position(const int x, const int y);
    Position(const Position &position);
    Position();

    ~Position() = default;

    bool operator==(const Position &rhs) const;
    bool operator!=(const Position &rhs) const;
    Position step(Direction direction) const;

    int get_x() const;
    int get_y() const;

  private:
    int m_x;
    int m_y;
};
