#include "AStar.h"
#include "BoardState.h"
#include "DirectionUtil.h"
#include "Position.h"
#include "Util.h"

#include <vector>

AStar::AStar(BoardState &board, Position &start, Position &goal)
    : m_board(board), m_start(start), m_goal(goal), m_previous_position(start)
{
    Node start_node = {m_start, 0};
    m_frontier.push(start_node);
}

std::vector<Position> AStar::search_path()
{
    while (!m_frontier.empty())
    {
        Node current_node = m_frontier.top();
        m_frontier.pop();

        if (current_node.pos == m_start)
        {
            std::vector<Position> path = create_path();
            return path;
        }

        m_came_from[m_previous_position] = current_node.pos;
        m_previous_position = current_node.pos;

        explore_current_node(current_node);
    }

    std::vector<Position> path = create_path();
    return path;
}

void AStar::explore_current_node(Node current_node)
{
    for (auto next_position : neighbor_positions(current_node.pos))
    {
        if (!valid_node(next_position))
        {
            continue;
        }

        int cost = current_node.cost + manhattan_distance(current_node.pos, m_goal);

        Node new_node = {next_position, cost};
        m_frontier.push(new_node);
    }
}

bool AStar::valid_node(Position &next_position)
{
    bool valid_node = true;
    if (m_came_from.find(next_position) != m_came_from.end())
    {
        valid_node = false;
    }

    if (m_board.is_occupied_by_snake(next_position) || m_board.is_out_of_bounds(next_position))
    {
        valid_node = false;
    }

    return valid_node;
}

std::vector<Position> AStar::create_path()
{
    std::vector<Position> path;
    Position position = m_goal;

    while (position != m_start)
    {
        path.push_back(position);
        position = m_came_from[position];
    }

    return path;
}