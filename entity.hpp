/******************************************************************************
 * Author: Sean Foster                                             <entity.hpp>
 * Date: 11/23/2017
 * Description: Entity class declaration, I originally planned to use the
 *              enemies as entities, but I got stuck for far too long and
 *              made them their own thing similar to items ><. Entity serves
 *              as the base class for the player, and future enemies.
******************************************************************************/
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "menu.hpp"
#include "item.hpp"

class Entity
{
private:
  int hitPoints;
  bool alive;
  string name;

public:
  Entity();
  virtual ~Entity();
  virtual bool attack(Item *);
  void setName(string);
  string getName();
  int getHitPoints();
  int adjustHitPoints(int);
  bool isAlive();
  
};

#endif