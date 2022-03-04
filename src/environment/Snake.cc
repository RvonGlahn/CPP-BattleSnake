#include "Snake.h"
#include <string>

Snake::Snake(std::string &snake_id) : m_snake_id(snake_id)
{
}

Snake::Snake(std::string &snake_id,
             std::string &snake_name,
             std::string &snake_color,
             std::vector<Position> &body,
             unsigned int health,
             double latency)
    : m_snake_id(snake_id), m_snake_name(snake_name), m_snake_color(snake_color), m_body(body), m_health(health),
      m_latency(latency)
{
}

const unsigned int Snake::get_health() const
{
    return m_health;
}

const unsigned int Snake::get_length() const
{
    return m_body.size();
}

const std::vector<Position> Snake::get_body() const
{
    return m_body;
}

const Position Snake::get_head() const
{
    return m_body.front();
}

const Position Snake::get_tail() const
{
    return m_body.back();
}

// const Direction Snake::get_current_direction();
// void set_initial_position(const Position start_position);
// std::vector<Direction> possible_directions();
// const bool is_alive() const;
