/******************************************************************************
 * Author: Sean Foster                                      <trapsapce.hpp>
 * Date: 11/23/2017
 * Description: TrapSpace class declaration, inherints space, holds a locked
 *              door that requires a key, read this first and you won't die!
******************************************************************************/
#ifndef TRAPSPACE_HPP
#define TRAPSPACE_HPP

#include "space.hpp"
#include "death.hpp"
#include "gate.hpp"

class TrapSpace : public Space
{
  private:
    Gate *door;
  
  public:
    TrapSpace();
    ~TrapSpace();
    bool enter(Player *);
    void unLockDoor();
};

#endif