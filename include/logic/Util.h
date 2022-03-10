#pragma once

#include "Position.h"
#include <cstdlib>

float manhattan_distance(Position &a, Position &b);

struct Node
{
    Position pos;
    int cost;
};