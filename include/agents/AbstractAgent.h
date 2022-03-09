#pragma once
#include "BoardState.h"
#include "Snake.h"
#include <map>
#include <string>

using snake_info = std::map<std::string, std::string>;

class AbstractAgent
{
  public:
    virtual snake_info get_snake() = 0;
    virtual void start_game(GameInfo game, unsigned int turn, BoardState board, Snake you) = 0;
    virtual Direction move(GameInfo game, unsigned int turn, BoardState board, Snake you) = 0;
    virtual void end_game(GameInfo game, unsigned int turn, BoardState board, Snake you) = 0;
};