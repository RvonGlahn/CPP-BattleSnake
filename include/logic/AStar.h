#pragma once
#include "BoardState.h"
#include "Position.h"
#include "Util.h"

#include <map>
#include <queue>
#include <vector>

struct QueueComp
{
    bool operator()(const Node &a, const Node &b) const
    {
        return a.cost > b.cost;
    }
};

struct MapComp
{
    bool operator()(const Position &lhs, const Position &rhs) const
    {
        return lhs.get_x() < rhs.get_x();
    }
};

class AStar
{
  private:
    BoardState m_board;
    std::map<Position, Position, MapComp> m_came_from;
    std::priority_queue<Node, std::vector<Node>, QueueComp> m_frontier;

    Position m_start;
    Position m_goal;
    Position m_previous_position;

    std::vector<Position> create_path();
    bool valid_node(Position &next_position);

  public:
    AStar(BoardState &board, Position &start, Position &goal);

    std::vector<Position> search_path();
};
