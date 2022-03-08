#include "Snake.h"
#include "DirectionUtil.h"
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

const std::string Snake::get_snake_id() const
{
    return m_snake_id;
}

const Direction Snake::get_current_direction()
{
    Position current_pos = m_body[0];
    Position previous_pos = m_body[1];

    return direction_to_reach_field(previous_pos, current_pos);
}

std::vector<Direction> Snake::valid_directions()
{
    Direction head_direction = get_current_direction();

    return possible_directions(head_direction);
}
