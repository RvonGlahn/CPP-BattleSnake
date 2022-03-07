#pragma once

#include "Direction.h"
#include <iostream>
#include <set>

class Position
{
  public:
    Position(const unsigned int x, const unsigned int y);
    Position(const Position &position);

    ~Position() = default;

    bool operator==(const Position &rhs) const;
    Position step(Direction direction) const;

    const unsigned int get_x() const;
    const unsigned int get_y() const;

  private:
    unsigned int m_x;
    unsigned int m_y;
};
