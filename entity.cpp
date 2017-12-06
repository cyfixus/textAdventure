/******************************************************************************
 * Author: Sean Foster                                             <entity.cpp>
 * Date: 11/23/2017
 * Description: Entity class declaration
******************************************************************************/
#include "entity.hpp"

/******************************************************************************
 * Entity constructor starts off alive with 20 hitpoints
******************************************************************************/
Entity::Entity()
{
  hitPoints = 20;
  alive = true;
}

Entity::~Entity()
{

}

/******************************************************************************
 * attack is a virtual function, this one set to false for testing
******************************************************************************/
bool Entity::attack(Item *item)
{
  return false;
}

/******************************************************************************
 * returns current hit points
******************************************************************************/
int Entity::getHitPoints()
{
  return this->hitPoints;
}

/******************************************************************************
 * adjusts hit points, sets alive if necessary and returns the hitpoints
******************************************************************************/
int Entity::adjustHitPoints(int hitPoints)
{
  this->hitPoints += hitPoints;
  if(getHitPoints() <= 0)
  {
    alive = false;
  }
  return getHitPoints();
}

/******************************************************************************
 * returns whether or not the entity is alive
******************************************************************************/
bool Entity::isAlive()
{
  return this->alive;
}

/******************************************************************************
 * setters and getters for the name
******************************************************************************/
void Entity::setName(string name)
{
  this->name = name;
}

string Entity::getName()
{
  return this->name;
}