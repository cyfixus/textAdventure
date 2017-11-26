/******************************************************************************
 * Author: Sean Foster                                        <monsterroom.hpp>
 * Date: 11/23/2017
 * Description: MonsterRoom class declaration
******************************************************************************/
#ifndef MONSTERROOM_HPP
#define MONSTERROOM_HPP

#include "space.hpp"

class MonsterRoom : public Space
{
  private:
  
  public:
    MonsterRoom();
    ~MonsterRoom();
    bool enter();
    bool interact(Player *);
    bool moveTo(Space *);
  
};

#endif