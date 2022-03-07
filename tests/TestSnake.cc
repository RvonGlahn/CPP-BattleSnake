#include "Snake.h"
#include "catch2/catch.hpp"

#include <string>

Snake create_snake()
{
    auto id = std::string("snake2");
    auto name = std::string("Juergen");
    auto color = std::string("#234");
    std::vector<Position> body = {Position(1, 2), Position(1, 3), Position(1, 4)};
    Snake snake = Snake(id, name, color, body, 80, 0.5);

    return snake;
}

TEST_CASE("Test ctor of Snake class and getter", "[snake]")
{
    auto id_1 = std::string("snake1");
    Snake snake1 = Snake(id_1);

    REQUIRE(snake1.get_health() == 100);

    Snake snake2 = create_snake();
    REQUIRE(snake2.get_health() == 80);
    REQUIRE(snake2.get_head() == Position(1, 2));
    REQUIRE(snake2.get_tail() == Position(1, 4));
    REQUIRE(snake2.get_length() == 3);
    REQUIRE(snake2.get_current_direction() == Direction::DOWN);
}

TEST_CASE("test valid direction")
{
    Snake snake1 = create_snake();
    std::vector<Direction> vec = {Direction::DOWN, Direction::RIGHT, Direction::LEFT};

    REQUIRE(vec == snake1.valid_directions());
}