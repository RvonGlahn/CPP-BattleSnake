#include "AStar.h"
#include "BoardState.h"
#include "Position.h"
#include "Snake.h"
#include "catch2/catch.hpp"
#include <string>
#include <vector>

TEST_CASE("Test manhattan distance")
{
    Position pos1 = Position(1, 5);
    Position pos2 = Position(5, 6);

    REQUIRE(manhattan_distance(pos1, pos2) == 5);
}

TEST_CASE("Test AStar")
{
    Position start = Position(1, 5);
    Position goal = Position(8, 0);

    BoardState game = BoardState(10, 10);
    AStar search = AStar(game, start, goal);
    std::vector<Position> path = search.search_path();

    //REQUIRE
}
