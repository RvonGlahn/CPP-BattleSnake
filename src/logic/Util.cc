#include "Position.h"
#include <cstdlib>

float manhattan_distance(Position &start, Position &goal)
{
    float x_abs = std::abs(start.get_x() - goal.get_x());
    float y_abs = std::abs(start.get_y() - goal.get_y());

    return x_abs + y_abs;
}