#include "Direction.h"
#include "Position.h"
#include <stdlib.h>
#include <vector>

std::vector<Direction> possible_directions(Direction snake_direction)
{
    if (snake_direction == Direction::UP)
    {
        std::vector<Direction> dirs = {Direction::UP, Direction::RIGHT, Direction::LEFT};
        return dirs;
    }
    else if (snake_direction == Direction::DOWN)
    {
        std::vector<Direction> dirs = {Direction::DOWN, Direction::RIGHT, Direction::LEFT};
        return dirs;
    }
    else if (snake_direction == Direction::LEFT)
    {
        std::vector<Direction> dirs = {Direction::UP, Direction::DOWN, Direction::LEFT};
        return dirs;
    }
    else if (snake_direction == Direction::RIGHT)
    {
        std::vector<Direction> dirs = {Direction::UP, Direction::RIGHT, Direction::DOWN};
        return dirs;
    }
    else
    {
        std::vector<Direction> dirs = {Direction::UP, Direction::RIGHT, Direction::LEFT, Direction::DOWN};
        return dirs;
    }
};

Direction direction_to_reach_field(Position &from_position, Position &to_position)
{
    auto delta_x = to_position.get_x() - from_position.get_x();
    auto delta_y = to_position.get_y() - from_position.get_y();

    if (delta_x > 0)
    {
        return Direction::RIGHT;
    }
    else if (delta_x < 0)
    {
        return Direction::LEFT;
    }
    else if (delta_y > 0)
    {
        return Direction::UP;
    }
    else if (delta_y < 0)
    {
        return Direction::DOWN;
    }
    else
    {
        return Direction(rand() % 4);
    }
};