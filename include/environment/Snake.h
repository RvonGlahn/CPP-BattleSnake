#pragma once

#include <string>
#include <vector>

#include "Direction.h"
#include "Position.h"

class Snake
{
  public:
    Snake(std::string &snake_id);
    Snake(std::string &snake_id,
          std::string &snake_name,
          std::string &snake_color,
          std::vector<Position> &body,
          unsigned int health,
          double latency);

    ~Snake() = default;

    const unsigned int get_health() const;
    const unsigned int get_length() const;
    const std::vector<Position> get_body() const;
    const Position get_head() const;
    const Position get_tail() const;
    const Direction get_current_direction();

    void set_initial_position(const Position start_position);

    std::vector<Direction> valid_directions();

  private:
    std::string m_snake_id;
    std::string m_snake_name;
    std::string m_snake_color;

    std::vector<Position> m_body;
    unsigned int m_health = 100;
    double m_latency = 0.0;
};