#include <iostream>
#include <filesystem>

#include "loguru.hpp"
#include "server.h"

// multi threading for snakes
int main(int argc, char **argv)
{
    // auto current_path = std::filesystem::current_path();
    // merge path and names
    // use own file for setting up logging in logs
    // how to init loguru ?

    loguru::init(argc, argv);
    loguru::add_file("everything.log", loguru::Append, loguru::Verbosity_MAX);
    loguru::add_file("info.log", loguru::Append, loguru::Verbosity_INFO);
    loguru::add_file("warning.log", loguru::Append, loguru::Verbosity_WARNING);
    loguru::add_file("error.log", loguru::Append, loguru::Verbosity_ERROR);

    LOG_F(INFO, "Hello this is an info!");
    LOG_F(WARNING, "Hello this is a warning!");
    LOG_F(ERROR, "Hello this is an error!");
    std::cout << "Start BattleSnake." << std::endl;

    start_server();

    end_server();

    return 0;
}