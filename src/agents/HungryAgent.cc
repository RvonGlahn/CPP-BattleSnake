#include <iostream>

#include "AbstractAgent.h"
#include "Direction.h"
#include "HungryAgent.h"
#include "Position.h"
#include <string>

// use oat++
// handle multi threading here
// create mechanism to restart server

HungryAgent::HungryAgent(std::string &game_id) : m_game_id(game_id)
{
}

snake_info HungryAgent::get_snake()
{
    snake_info info;

    info["apiversion"] = "1";
    info["author"] = "Rasmus";
    info["color"] = "#F5CEEF";
    info["head"] = "silly";
    info["tail"] = "fat-rattle";
    info["version"] = "0.0.1";

    return info;
}

void HungryAgent::start_game(GameInfo game, unsigned int turn, BoardState board, Snake you)
{
}

Direction HungryAgent::move(GameInfo game, unsigned int turn, BoardState board, Snake you)
{
    return Direction::DOWN;
}

void HungryAgent::end_game(GameInfo game, unsigned int turn, BoardState board, Snake you)
{
    std::cout << "Clean up!" << std::endl;
}