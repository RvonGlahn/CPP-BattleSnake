#include "Position.h"
#include <set>

Position::Position(const int x, const int y) : m_x(x), m_y(y)
{
}

Position::Position(const Position &position) : m_x(position.m_x), m_y(position.m_y)
{
}

Position::Position() : m_x(0), m_y(0)
{
}

int Position::get_x() const
{
    return m_x;
}

int Position::get_y() const
{
    return m_y;
}

bool Position::operator==(const Position &rhs) const
{
    if (m_x == rhs.m_x && m_y == rhs.m_y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Position::operator!=(const Position &rhs) const
{
    if (m_x == rhs.m_x && m_y == rhs.m_y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Position Position::step(Direction direction) const
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
