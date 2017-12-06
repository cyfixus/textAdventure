/******************************************************************************
 * Author: Sean Foster                                           <bushwall.cpp>
 * Date: 11/23/2017
 * Description: BushWall class declaration
******************************************************************************/
#include "bushwall.hpp"

/******************************************************************************
 * Bushwall constructor lockes the bushwall
******************************************************************************/
BushWall::BushWall()
{
  locked = true;
}

BushWall::~BushWall()
{

}
/******************************************************************************
 * unlock, will unlock the bushwall if the item unlocking is a torch
******************************************************************************/
bool BushWall::unLock(Item *item)
{
  if(item->getName() == "torch")
  {
    unLock();
  }
  return isLocked();
}

/******************************************************************************
 * unlock override
******************************************************************************/
void BushWall::unLock()
{
  this->locked = false;
}