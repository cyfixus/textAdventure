/******************************************************************************
 * Author: Sean Foster                                      <treasuresapce.hpp>
 * Date: 11/23/2017
 * Description: TreasureSpace class declaration, space class derivative that
 *              holds a potential gate, and an item of treasure!
******************************************************************************/
#ifndef TREASURESPACE_HPP
#define TREASURESPACE_HPP

#include "space.hpp"
#include "gate.hpp"

class TreasureSpace : public Space
{
  private:
    Gate *door;
  
  public:
    TreasureSpace();
    ~TreasureSpace();
    bool enter(Player *);
    bool interact(Player *);
    void unLockDoor();
  
};

#endif