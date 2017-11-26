/******************************************************************************
 * Author: Sean Foster                                              <space.hpp>
 * Date: 11/23/2017
 * Description: Space class declaration
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "die.hpp"
#include "menu.hpp"
#include "player.hpp"

class Space
{
  private:
    Space *top = nullptr;
    Space *right = nullptr;
    Space *bottom = nullptr;
    Space *left = nullptr;

  public:
    Space();
    virtual ~Space() = 0;
    virtual bool enter() = 0;
    virtual bool interact(Player *) = 0;
    virtual bool moveTo(Space *) = 0;
  
};
#endif