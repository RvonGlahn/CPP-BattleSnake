#pragma once

#include "Snake.h"
#include <string>
#include <vector>

class BoardState
{
  public:
    BoardState(unsigned int width, unsigned int, std::vector<Snake> &snakes, std::vector<Position> &food);
    BoardState(unsigned int width, unsigned int, std::vector<Snake> &snakes);
    BoardState(unsigned int width, unsigned int, std::vector<Position> &food);
    BoardState(unsigned int width, unsigned int);
    ~BoardState() = default;

    Snake get_snake_by_id(std::string &snake_id) const;

    void add_snake(Snake &new_snake);
    void add_food(Position &new_food);

    bool is_out_of_bounds(Position &pos) const;
    bool is_occupied_by_snake(Position &check_pos) const;
    bool is_occupied_by_food(Position &check_pos) const;
    bool is_occupied(Position &check_pos) const;

    unsigned int m_width;
    unsigned int m_height;
    std::vector<Snake> m_snakes;
    std::vector<Position> m_food;
};