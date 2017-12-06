/******************************************************************************
 * Author: Sean Foster                                      <trapspace.cpp>
 * Date: 11/23/2017
 * Description: TrapSpace class definition
******************************************************************************/
#include "trapspace.hpp"

/******************************************************************************
 * sets the locked gate to the trap room
******************************************************************************/
TrapSpace::TrapSpace()
{
  door = new Gate();
  door->setName("locked gate");
  setName("trap room");
}

/******************************************************************************
 * deletes the door
******************************************************************************/
TrapSpace::~TrapSpace()
{
  delete door;
}

/******************************************************************************
 * overrides unlocking the door
******************************************************************************/
void TrapSpace::unLockDoor()
{
  door->unLock();
}

/******************************************************************************
 * player tries to enter, if the player wields the key in either hand, the
 * player enters and dies in the trap
******************************************************************************/
bool TrapSpace::enter(Player *player)
{
  if(player->useRightHand(door) || player->useLeftHand(door))
  {
    player->adjustHitPoints(-20);
    std::cout << "\nCongratulations! You fell into a trap!\n";
    Death *death = new Death();
    death->loadIcon();
    delete death;
    return true;
  }
  std::cout << "\n\tX\tX\tX\tX\tX\tX"
             "\nYou need a key to enter this room!\n"
             "\n\tX\tX\tX\tX\tX\tX";
  return false;
}