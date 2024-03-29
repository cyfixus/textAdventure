/******************************************************************************
 * Author: Sean Foster                                               <gate.cpp>
 * Date: 11/23/2017
 * Description: Gate class declaration
******************************************************************************/
#include "gate.hpp"

/******************************************************************************
 * Gate constructor locks the gate
******************************************************************************/
Gate::Gate()
{
  locked = true;
}

Gate::~Gate()
{

}

/******************************************************************************
 * unlockes the gate if the item is a key
******************************************************************************/
bool Gate::unLock(Item *item)
{
  if(item->getName() == "key")
  {
    unLock();
  }
  return !isLocked();
}

/******************************************************************************
 * unlocks the gate regardless
******************************************************************************/
void Gate::unLock()
{
  this->locked = false;
}