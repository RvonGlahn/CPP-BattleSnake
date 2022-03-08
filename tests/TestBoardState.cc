#include "BoardState.h"
#include "Position.h"
#include "Snake.h"
#include "catch2/catch.hpp"
#include <string>
#include <vector>

TEST_CASE("Test Boardstate")
{
    BoardState state1 = BoardState(10, 10);
    REQUIRE(state1.m_snakes.empty());

    std::vector<Position> food = {Position(1, 3), Position(3, 3)};
    std::string id = {"Hans"};
    Snake snaky = Snake(id);
    std::vector<Snake> snakes = {};

    BoardState state2 = BoardState(10, 10, food);
    Position out_of_bound_pos = Position(22, 22);
    Position occupied_pos = Position(1, 3);
    REQUIRE(state2.is_out_of_bounds(out_of_bound_pos));
    REQUIRE(state2.is_occupied(occupied_pos));

    auto num_snakes_pre = state2.m_snakes.size();
    auto num_food_pre = state2.m_food.size();
    Position new_food = Position(1, 4);

    state2.add_snake(snaky);
    state2.add_food(new_food);

    REQUIRE(num_snakes_pre < state2.m_snakes.size());
    REQUIRE(num_food_pre < state2.m_food.size());
}