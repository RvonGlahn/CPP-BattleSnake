#include <iostream>

#include "Position.h"
#include "Server.h"

// use drogon
// handle multi threading here
// create mechanism to restart server

void start_server()
{
    std::cout << "Start Server" << std::endl;
    configure_routes();
}

void configure_routes()
{
    std::cout << "Post methods" << std::endl;
}

void end_server()
{
    std::cout << "End Server" << std::endl;
}

bool reload_server()
{
    std::cout << "Reload Server" << std::endl;

    bool ret = true;
    return ret;
}