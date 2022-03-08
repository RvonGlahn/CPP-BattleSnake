#include "BoardState.h"
#include <iostream>

BoardState::BoardState(unsigned int width, unsigned int height) : m_width(width), m_height(height)
{
}

BoardState::BoardState(unsigned int width, unsigned int, std::vector<Snake> &snakes, std::vector<Position> &food)
    : m_width(width), m_height(m_height), m_snakes(snakes), m_food(food)
{
}

BoardState::BoardState(unsigned int width, unsigned int, std::vector<Snake> &snakes)
    : m_width(width), m_height(m_height), m_snakes(snakes)
{
}

BoardState::BoardState(unsigned int width, unsigned int, std::vector<Position> &food)
    : m_width(width), m_height(m_height), m_food(food)
{
}

Snake BoardState::get_snake_by_id(std::string &snake_id) const
{
    for (const auto &snake : m_snakes)
    {
        if (snake.get_snake_id() == snake_id)
        {
            return snake;
        }
    }

    std::cout << "No Snake Found!" << std::endl;
}

void BoardState::add_snake(Snake &new_snake)
{
    m_snakes.push_back(new_snake);
}

void BoardState::add_food(Position &new_food)
{
    m_food.push_back(new_food);
}

bool BoardState::is_out_of_bounds(Position &pos) const
{
    if (pos.get_x() < 0 || pos.get_x() >= m_width)
    {
        return true;
    }
    if (pos.get_y() < 0 || pos.get_y() >= m_height)
    {
        return true;
    }

    return false;
}

bool BoardState::is_occupied_by_snake(Position &check_pos) const
{
    for (const auto &snake : m_snakes)
    {
        auto snake_body = snake.get_body();
        for (const auto &pos : snake_body)
        {
            if (check_pos == pos)
            {
                return true;
            }
        }
    }

    return false;
}

bool BoardState::is_occupied_by_food(Position &check_pos) const
{
    for (const auto &food : m_food)
    {
        if (check_pos == food)
        {
            return true;
        }
    }
}

bool BoardState::is_occupied(Position &check_pos) const
{
    return is_occupied_by_food(check_pos) || is_occupied_by_snake(check_pos);
}