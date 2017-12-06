/******************************************************************************
 * Author: Sean Foster                                               <game.cpp>
 * Date: 11/23/2017
 * Description: Game definition
******************************************************************************/
#include "game.hpp"

/******************************************************************************
 * Game allocates the map and the player, reports the current space of the
 * player and if the player is still alive, asks the player what to do from
 * the map.
******************************************************************************/
Game::Game()
{
  map = new Map();
  player = new Player();
  do
  {
    reportCurrentSpace();
    if(!player->isAlive())
    {
      std::cout << "\nlooks like you are dead...\n";
      break;
    }
  }while(map->move(player) != 7);
}

/******************************************************************************
 * deallocates the player and the map
******************************************************************************/
Game::~Game()
{
  delete map;
  delete player;
}

/******************************************************************************
 * reports where the player thinks the player may be.
******************************************************************************/
void Game::reportCurrentSpace()
{
  Space *currentSpace = map->getCurrentSpace();
  std::cout << "\nYou find yourself in what appears to be a "
            << currentSpace->getName() << std::endl;
}