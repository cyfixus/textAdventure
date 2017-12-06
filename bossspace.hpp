/******************************************************************************
 * Author: Sean Foster                                          <bossspace.hpp>
 * Date: 11/23/2017
 * Description: BossSpace class declaration, inherits Space. the bossSpace has
 *              a bushwall that requires the torch(in the righr hand) to burn
 *              through, once, the wall has been burned through, the player can
 *              attempt to battle the boss.
******************************************************************************/
#ifndef BOSSSPACE_HPP
#define BOSSSPACE_HPP

#include "space.hpp"
#include "bushwall.hpp"
#include "boss.hpp"

class BossSpace : public Space
{
  private:
    BushWall *door;
    Boss *boss;
  
  public:
    BossSpace();
    ~BossSpace();
    bool enter(Player *);
    bool interact(Player *);
    void unLockDoor();
    void setBoss(Boss *);
    bool attack(Player *);
};

#endif