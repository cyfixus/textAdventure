/******************************************************************************
 * Author: Sean Foster                                      <treasurespace.cpp>
 * Date: 11/23/2017
 * Description: TreasureSpace class definition
******************************************************************************/
#include "treasurespace.hpp"

/******************************************************************************
 * sets up the locked gate, treasure rooms are passed their names
******************************************************************************/
TreasureSpace::TreasureSpace()
{
  door = new Gate();
  door->setName("locked gate");
}

/******************************************************************************
 * deallocates that door
******************************************************************************/
TreasureSpace::~TreasureSpace()
{
  delete door;
}

/******************************************************************************
 * unlock the door overrride, so not all treasure rooms(ie key room) have to
 * be locked
******************************************************************************/
void TreasureSpace::unLockDoor()
{
  door->unLock();
}

/******************************************************************************
 * player tries to enter the treasure space, if the door is locked, the key is
 * tried, and if the user has a key in either hand the user can enter, if not
 * the requirement of a key is reported
******************************************************************************/
bool TreasureSpace::enter(Player *player)
{
  if(door->isLocked())
  {
    if(player->useRightHand(door) || player->useLeftHand(door))
    {
      return true;
    }
    std::cout << "\n\tX\tX\tX\tX\tX\tX"
                 "\nYou need a key to enter this room!\n"
                 "\n\tX\tX\tX\tX\tX\tX";
    return false;
  }
  return true;
}

/******************************************************************************
 * if a user is in a room and wants to interact, the available item is reported
 * and then the player is asked to picked it up, picking up the item if desired
******************************************************************************/
bool TreasureSpace::interact(Player *player)
{
  if(!pickedUp)
  {
    item->loadIcon();
    string itemPresent = "\nThere is a " + item->getName() + " on the ground\n"
                         + "Would you like to pick it up?\n1. Yes\n2. No\n";
    if(menu(itemPresent, 2) == 1)
    {
      if(player->pickUpItem(item))
      {
        pickedUp = true;
        return true;
      }
    } 
  }
  return false;
}