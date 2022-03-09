#include "AlphaStar.h"
#include "BoardState.h"
#include "Position.h"

#include <map>
#include <queue>
#include <vector>

float manhattan_distance(Position &start, Position &goal)
{
    return (abs(start.get_x() - goal.get_x()) + abs(start.get_y() - goal.get_y()));
}

std::vector<Position> a_star(Position start, Position goal, BoardState board)
{
    auto cmp = [](Node a, Node b) { return a.cost > b.cost; };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> frontier(cmp);
    std::map<Position, Position> came_from;

    Node start_node = {start, 0};
    frontier.push(start_node);

    while (!frontier.empty())
    {
        Node current_node = frontier.top();
        frontier.pop();

        if (current_node.pos == start)
        {
            std::vector<Position> path = create_path(came_from, goal, start);
            return path;
        }
    }
}

std::vector<Position> create_path(std::map<Position, Position> came_from, Position goal, Position start)
{
}