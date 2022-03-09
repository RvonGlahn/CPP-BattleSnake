#include "BoardState.h"
#include "Position.h"

#include <map>
#include <queue>
#include <vector>

struct Node
{
    Position pos;
    int cost;
};

float manhattan_distance(Position &a, Position &b);

std::vector<Position> a_star(Position start, Position goal, BoardState board);

std::vector<Position> create_path(std::map<Position, Position> came_from, Position goal, Position start);