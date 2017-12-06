/******************************************************************************
 * Author: Sean Foster                                           <bushwall.hpp>
 * Date: 11/23/2017
 * Description: BushWall class declaration, inherits passage, bushwall is used
 *              specifically for the boss space.
******************************************************************************/
#ifndef BUSHWALL_HPP
#define BUSHWALL_HPP

#include "passage.hpp"

class BushWall : public Passage
{
  public:
    BushWall();
    ~BushWall();
    bool unLock(Item *);
    void unLock();
};

#endif