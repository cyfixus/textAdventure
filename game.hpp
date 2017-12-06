/******************************************************************************
 * Author: Sean Foster                                               <game.hpp>
 * Date: 11/23/2017
 * Description: Game declaration. Game holds a player and a map
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "menu.hpp"
#include "map.hpp"
#include "player.hpp"

class Game
{
  private:
    Player *player;
    Map *map;
  public:
    Game();
    ~Game();
    void reportCurrentSpace();
};

#endif