#include "Position.h"
#include <set>

Position::Position(const unsigned int x, const unsigned int y) : m_x(x), m_y(y)
{
}

Position::Position(const Position &position) : m_x(position.m_x), m_y(position.m_y)
{
}

const unsigned int Position::get_x() const
{
    return m_x;
}

const unsigned int Position::get_y() const
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
