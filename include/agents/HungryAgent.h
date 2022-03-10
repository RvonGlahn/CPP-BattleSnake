#pragma once

#include "AbstractAgent.h"
#include "BoardState.h"
#include "GameInfo.h"
#include "Snake.h"
#include <map>
#include <string>

class HungryAgent : public AbstractAgent
{
  private:
    std::string m_game_id;

  public:
    HungryAgent(std::string &game_id);
    ~HungryAgent() = default;

    snake_info get_snake();
    void start_game(GameInfo game, unsigned int turn, BoardState board, Snake you);
    Direction move(GameInfo game, unsigned int turn, BoardState board, Snake you);
    void end_game(GameInfo game, unsigned int turn, BoardState board, Snake you);
};