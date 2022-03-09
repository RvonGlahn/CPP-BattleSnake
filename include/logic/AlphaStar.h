#include "BoardState.h"
#include "Position.h"

#include <map>
#include <queue>
#include <vector>

struct Node
{
    Position pos;
    float cost;
};

class CompareDist
{
  public:
    bool operator()(Node &n1, Node &n2);
};

float manhattan_distance(Node &a, Node &b);

std::vector<Position> a_star(Position start, Position goal, BoardState board);