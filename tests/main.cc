#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "server.h"

TEST_CASE("Test my boost function", "TestBoost")
{
    bool b = reload_server();

    REQUIRE(true == b);
}