#define CATCH_CONFIG_MAIN

#include "Position.h"
#include "catch2/catch.hpp"

TEST_CASE("Test my position class", "TestPosition")
{
    Position pos = Position(1, 2);

    REQUIRE(true == true);
}