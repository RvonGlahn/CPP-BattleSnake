#include <iostream>

#include "agent.h"
#include "server.h"

// use drogon

/**
 * @brief start server and call related functions
 *
 */
void start_server()
{
    std::cout << "Start Server" << std::endl;
    configure_routes();
}

/**
 * @brief Configure all routes for BattleSnake Server
 *
 */
void configure_routes()
{
    std::cout << "Post methods" << std::endl;
}

void end_server()
{
    std::cout << "End Server" << std::endl;
}

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool reload_server()
{
    std::cout << "Reload Server" << std::endl;

    bool ret = true;
    return ret;
}