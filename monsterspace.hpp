/******************************************************************************
 * Author: Sean Foster                                       <monstersapce.hpp>
 * Date: 11/23/2017
 * Description: MonsterSpace class declaration, derivative of space, I wanted
 *              this to be more universal, but had to settls for it holding
 *              only a ram, that can multiply
******************************************************************************/
#ifndef MONSTERSPACE_HPP
#define MONSTERSPACE_HPP

#include "space.hpp"
#include "ram.hpp"

class MonsterSpace : public Space
{
  private:
    Ram *ram;
  public:
    MonsterSpace();
    ~MonsterSpace();
    bool enter(Player *);
    bool interact(Player *);
    void setMonster(Ram *);
};

#endif