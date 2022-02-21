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

Position::Position(const unsigned int x, const unsigned int y) : m_x(x), m_y(y)
{
}

Position::Position(const Position &position) : m_x(position.m_x), m_y(position.m_y)
{
}

bool Position::operator==(const Position &rhs)
{
    if (m_x == rhs.m_x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Position Position::advanced(Direction direction)
{

    if (direction == Direction::UP)
    {
        return Position(m_x, m_y + 1);
    }
    else if (direction == Direction::LEFT)
    {
        return Position(m_x - 1, m_y);
    }
    else if (direction == Direction::RIGHT)
    {
        return Position(m_x + 1, m_y);
    }
    else
    {
        return Position(m_x, m_y - 1);
    }
}