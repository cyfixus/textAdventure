/******************************************************************************
 * Author: Sean Foster                                              <space.cpp>
 * Date: 11/23/2017
 * Description: Space class definition
******************************************************************************/
#include "space.hpp"
/******************************************************************************
 * sets a blank space maybe, later to write the name
 * pointers all set to nullptr and item is madesure to be not picked up
******************************************************************************/
Space::Space()
{
  setName("");
  setItem(nullptr);
  setTop(nullptr);
  setBottom(nullptr);
  setLeft(nullptr);
  setRight(nullptr);
  pickedUp = false;
}

Space::~Space()
{

}

/******************************************************************************
 * dummy enter function
******************************************************************************/
bool Space::enter(Player *)
{
  return true;
}

/******************************************************************************
 * dummy interact function
******************************************************************************/
bool Space::interact(Player *)
{
  return false;
}

/******************************************************************************
 * dummy moveto function
******************************************************************************/
bool Space::moveTo(Space *)
{
  return false;
}

/******************************************************************************
 * set the space name
******************************************************************************/
void Space::setName(std::string name)
{
  this->name = name;
}

/******************************************************************************
 * get the space name
******************************************************************************/
std::string Space::getName()
{
  return this->name;
}

/******************************************************************************
 * dummy retieve item
******************************************************************************/
void Space::retrieveItem(Player *player)
{
  
}

/******************************************************************************
 * item pointer getter, setter
******************************************************************************/
void Space::setItem(Item *item)
{
  this->item = item;
}

Item *Space::getItem()
{
  return this->item;
}


/******************************************************************************
 * getters and setters for adjacent spaces
******************************************************************************/
void Space::setTop(Space *top)
{
  this->top = top;
}
void Space::setRight(Space *right)
{
  this->right = right;
}
void Space::setBottom(Space *bottom)
{
  this->bottom = bottom;
}
void Space::setLeft(Space *left)
{
  this->left = left;
}
Space* Space::getTop()
{
  return this->top;
}
Space* Space::getRight()
{
  return this->right;
}
Space* Space::getBottom()
{
  return this->bottom;
}
Space* Space::getLeft()
{
  return this->left;
}

/******************************************************************************
 * dummy unlock door, setboss and setmonster
******************************************************************************/
void Space::unLockDoor()
{
  
}

void Space::setBoss(Boss *)
{

}

void Space::setMonster(Ram *)
{
  
}