/******************************************************************************
 * Author: Sean Foster                                           <iventory.hpp>
 * Date: 11/23/2017
 * Description: Inventory class declaration
******************************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#define MAX_HANDS 2

#include "item.hpp"

class Inventory
{
private:
  int hands;
  Key *key;
  Sword *sword;
  Shield *shield;
  Lantern *lantern;

public:
  Inventory();
  ~Inventory();
  
};
#endif