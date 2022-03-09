#include "AlphaStar.h"
#include "BoardState.h"
#include "Position.h"

#include <map>
#include <queue>
#include <vector>

class CompareDist
{
  public:
    bool operator()(Node &n1, Node &n2)
    {
        if (n1.cost > n2.cost)
            return true;
        else
            return false;
    }
};

float manhattan_distance(Node &a, Node &b)
{
    return (abs(a.pos.get_x() - b.pos.get_x()) + abs(a.pos.get_y() - b.pos.get_y()));
}

std::vector<Position> a_star(Position start, Position goal, BoardState board)
{
    auto cmp = [](Node a, Node b) { return a.cost > b.cost; };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> open_list(cmp);
}