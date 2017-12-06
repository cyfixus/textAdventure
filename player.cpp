/******************************************************************************
 * Author: Sean Foster                                             <player.cpp>
 * Date: 11/23/2017
 * Description: Player class declaration
******************************************************************************/
#include "player.hpp"

/******************************************************************************
 * makes sure the player is known and player's hands are empty
******************************************************************************/
Player::Player()
{
  leftHand = nullptr;
  rightHand = nullptr;
  setName("player");
}

Player::~Player()
{

}

/******************************************************************************
 * tries to pickup an item, if the player has items in both hands, the player
 * is informed the hands are full and false is returned.
 * if the player has a free hand, the left hand is tried first, otherwise the
 * right hand is tried, when a free hand is found, the item is placed in the
 * hand and true is returned.
******************************************************************************/
bool Player::pickUpItem(Item *item)
{
  bool pickedUp = false;
  if(leftHand != nullptr && rightHand != nullptr)
  {
    std::cout << "\nYour hands are full, you can't pick up anymore!\n";
    return pickedUp;
  }
  if(leftHand == nullptr)
  {
    leftHand = item;
    pickedUp = true;
  }
  else if(rightHand == nullptr)
  {
    rightHand = item;
    pickedUp = true;
  }
  return pickedUp;
}

/******************************************************************************
 * attempts to drop an item, if the hands are empty, nothing can be dropped,
 * otherwise, the player is given a choice and can drop from either hand
******************************************************************************/
bool Player::dropItem()
{
  bool dropped = false;
  if(leftHand == nullptr && rightHand == nullptr)
  {
    std::cout << "\nYour hands are empty, you have nothing to drop!\n";
    return dropped;
  }
  std::stringstream itemList;
  itemList << "\nFrom which hand would you like to drop an item?\n";
  if(leftHand != nullptr)
  {
    itemList << "1. Left Hand wields " << leftHand->getName() << std::endl;
  }
  if(rightHand != nullptr)
  {
    itemList << "2. Right Hand wields " << rightHand->getName() << std::endl;
  }
  itemList << "3. Don't Drop Anything!\n";
  int choice = menu(itemList.str(), 3);
  switch(choice)
  {
    case 1:
      std::cout << "\nDropping " << leftHand->getName() << std::endl;
      leftHand = nullptr;
      dropped = true;
      break;
    case 2:
      std::cout << "\nDropping " << rightHand->getName() << std::endl;
      rightHand = nullptr;
      dropped = true;
      break;
    case 3:
      break;
  }
  return dropped;
}

/******************************************************************************
 * returns whether or not the shield is in the right hand and reports the
 * deficiency
******************************************************************************/
bool Player::rightHandShield()
{
  if(rightHand != nullptr)
  {
    if(rightHand->getName() == "shield")
    {
      return true;
    }
  }
  std::cout << "\nYou're not carrying the shield Correctly!\n"
               "\t\t\t\t...YOU GOT SMASHED TO SMITHEREEENS!\n";
  return false;
}

/******************************************************************************
 * returns whether the sword is in the left hand and reports the deficiency
******************************************************************************/
bool Player::leftHandSword()
{
  if(leftHand != nullptr)
  {
    if(leftHand->getName() == "sword")
    {
      return true;
    }
  }
  std::cout << "\nYou're not carrying the sword Correctly!\n"
               "\t\t\t\t....what'd were you trying to do?!!!\n";
  return false;
}

/******************************************************************************
 * tries to use the right hand to unlock a passage
******************************************************************************/
bool Player::useRightHand(Passage *passage)
{
  if(rightHand != nullptr)
  {
    return passage->unLock(rightHand);
  }
  return false;
}

/******************************************************************************
 * tries to use the left hand to unlock a passage
******************************************************************************/
bool Player::useLeftHand(Passage *passage)
{
  if(leftHand != nullptr)
  {
     return passage->unLock(leftHand);
  }
  return false;
}

/******************************************************************************
 * lists the inventory of the player
******************************************************************************/
void Player::listInventory()
{
  std::cout << "\nYou are currently wielding ";
  if(leftHand != nullptr)
  {
    std::cout << "\tLeft Hand: " << leftHand->getName();
  }
  if(rightHand != nullptr)
  {
    std::cout << "\tRight Hand: " << rightHand->getName();
  }
  if(leftHand == nullptr && rightHand == nullptr)
  {
    std::cout << "nothing";
  }
  std::cout << std::endl;
}