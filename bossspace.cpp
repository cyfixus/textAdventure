/******************************************************************************
 * Author: Sean Foster                                          <bossspace.cpp>
 * Date: 11/23/2017
 * Description: BossSpace class definition
******************************************************************************/
#include "bossspace.hpp"

/******************************************************************************
 * BossSpace constructor allocates the bushWall destructor deallocates it
******************************************************************************/
BossSpace::BossSpace()
{
  door = new BushWall();
  door->setName("thick brush");
}

BossSpace::~BossSpace()
{
  delete door;
}

/******************************************************************************
 * enter interacts with the player if the door isn't locked, if the door is 
 * locked, the player will try to use the item in their right hand to open
 * the door, if it isn't a torch, the bush won't burn(door won't open).
******************************************************************************/
bool BossSpace::enter(Player *player)
{
  if(door->isLocked())
  {
    if(player->useRightHand(door))
    {
      std::cout << "\nYour torch burned through the brush!\n";
    }
    else
    {
      std::cout << "\nA thick brush blocks your entry!\n"
                   "It seems only your right hand can reach it\n";
    }
  }
  else if(!door->isLocked())
  {
    interact(player);
    return true;
  }
  return false;
}

/******************************************************************************
 * attack is called when the player can interact with the bossSpace. if the
 * player is properly equipped( sword in left, shield in right ), the boss
 * is defeated, otherwise... the player was no match.
******************************************************************************/
bool BossSpace::attack(Player *player)
{
  if(player->leftHandSword() && player->rightHandShield())
  {
    std::cout <<  "\n\n* * * *  ** ** * * * ** * * *** **  *"
                  "\n\t\tCongratulations!\n"
                  "\nYOU BEAT THE NUCLEAR ROBOT\n"
                  "************ ****** * *************\n"
                  "GET OUT WHILE YOU CAN!!!\n\n\t\t\t";
  }
  else
  {
    player->adjustHitPoints(-10);
  }
  return player->isAlive();
}

/******************************************************************************
 * interact prints out the boss icon and attacks the player
******************************************************************************/
bool BossSpace::interact(Player *player)
{
  boss->loadIcon();
  return attack(player);
}

/******************************************************************************
 * unlocks the door
******************************************************************************/
void BossSpace::unLockDoor()
{
  door->unLock();
}

/******************************************************************************
 * sets the boss pointer
******************************************************************************/
void BossSpace::setBoss(Boss *boss)
{
  this->boss = boss;
}