/******************************************************************************
 * Author: Sean Foster                                       <monsterspace.cpp>
 * Date: 11/23/2017
 * Description: MonsterSpace class definition
******************************************************************************/
#include "monsterspace.hpp"

/******************************************************************************
 * sets ram to nullPtr just in case
******************************************************************************/
MonsterSpace::MonsterSpace()
{
  ram = nullptr;
}

MonsterSpace::~MonsterSpace()
{
  
}

/******************************************************************************
 * forces the player to interact when entering
******************************************************************************/
bool MonsterSpace::enter(Player *player)
{
  return interact(player);
}

/******************************************************************************
 * the player faces from 1 to 12 rams! dealing the number of rams as damage
 * to hit points... unless the player wears the shield properly
******************************************************************************/
bool MonsterSpace::interact(Player *player)
{
  int ramCount = Die(12).roll();
  for(int i = 0; i < ramCount; i++)
  {
    ram->loadIcon();
    std::cout << "\t";
  }
  if(!player->rightHandShield())
  {
    std::cout << "\nOuch!\tThe Rams hit ya for " << ramCount << " damage!\n";
    player->adjustHitPoints(-ramCount);
  }
  return player->isAlive();
}

/******************************************************************************
 * sets the ram pointer
******************************************************************************/
void MonsterSpace::setMonster(Ram *ram)
{
  this->ram = ram;
}