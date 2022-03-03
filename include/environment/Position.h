#pragma once

#include "Direction.h"
#include <iostream>

class Position
{
  public:
    Position(const unsigned int x, const unsigned int y);
    Position(const Position &position);

    ~Position() = default;

    bool operator==(const Position &rhs);
    Position advanced(Direction direction);

  private:
    unsigned int m_x;
    unsigned int m_y;
};
