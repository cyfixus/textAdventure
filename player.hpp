/******************************************************************************
 * Author: Sean Foster                                             <player.hpp>
 * Date: 11/23/2017
 * Description: Player class declaration, inherits entity, player has two hands
 *              thats the limit to the inventory, the player has to navigate
 *              the map, and intelligently place things in the player's hands.
 *              the plyer can drop items, but dropped items... disappear...
 *              so drop to rearrange wisely! it can be done!
******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <sstream>
#include "entity.hpp"
#include "passage.hpp"
#include "menu.hpp"

class Player : public Entity
{
private:
  Item *leftHand;
  Item *rightHand;
public:
  Player();
  ~Player();
  bool pickUpItem(Item *);
  bool dropItem();
  bool rightHandShield();
  bool leftHandSword();
  bool useRightHand(Passage *);
  bool useLeftHand(Passage *);
  void listInventory();
  
};

#endif