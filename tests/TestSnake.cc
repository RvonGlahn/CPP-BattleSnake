#include "Snake.h"
#include "catch2/catch.hpp"

#include <string>

TEST_CASE("Test ctor of Snake class and getter", "[snake]")
{
    auto id_1 = std::string("snake1");
    Snake snake1 = Snake(id_1);

    REQUIRE(snake1.get_health() == 100);

    auto id_2 = std::string("snake2");
    auto name_2 = std::string("Juergen");
    auto color_2 = std::string("#234");
    std::vector<Position> body_2 = {Position(1, 2), Position(1, 3), Position(1, 4)};
    Snake snake2 = Snake(id_2, name_2, color_2, body_2, 80, 0.5);

    REQUIRE(snake2.get_health() == 80);
    REQUIRE(snake2.get_head() == Position(1, 2));
    REQUIRE(snake2.get_tail() == Position(1, 4));
    REQUIRE(snake2.get_length() == 3);
}