#include "Position.h"

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