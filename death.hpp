/******************************************************************************
 * Author: Sean Foster                                              <death.hpp>
 * Date: 11/23/2017
 * Description: Death class declaration, the icon for dying in the trap room
******************************************************************************/
#ifndef DEATH_HPP
#define DEATH_HPP

#include "item.hpp"

class Death : public Item
{
  public:
    Death();
    ~Death();
};

#endif