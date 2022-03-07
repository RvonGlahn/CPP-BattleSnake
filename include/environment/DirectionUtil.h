#pragma once

#include "Direction.h"
#include "Position.h"
#include <vector>

std::vector<Direction> possible_directions(Direction snake_direction);

Direction direction_to_reach_field(Position &from_position, Position &to_position);

std::vector<Position> neighbor_positions(Position &position);