#define CATCH_CONFIG_MAIN

#include "Position.h"
#include "catch2/catch.hpp"

TEST_CASE("Test position ctor", "TestPosition")
{
    Position pos = Position(1, 2);

    SECTION("Test value initialization")
    {
        REQUIRE(pos.get_x() == 1);
        REQUIRE(pos.get_y() == 2);
    }
    SECTION("Test object initialization")
    {
        Position pos2 = Position(pos);
        REQUIRE(pos2.get_x() == 1);
        REQUIRE(pos2.get_y() == 2);
    }
}

TEST_CASE("Test position step")
{
    Position pos = Position(1, 2);

    auto pos_step = pos.step(Direction::DOWN);
    REQUIRE(pos_step.get_y() == 1);

    pos_step = pos.step(Direction::UP);
    REQUIRE(pos_step.get_y() == 3);

    pos_step = pos.step(Direction::LEFT);
    REQUIRE(pos_step.get_x() == 0);

    pos_step = pos.step(Direction::RIGHT);
    REQUIRE(pos_step.get_x() == 2);
}

TEST_CASE("Test position equal operator")
{
    Position pos = Position(1, 2);
    auto pos2 = Position(pos);

    REQUIRE(pos == pos2);
}
