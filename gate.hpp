/******************************************************************************
 * Author: Sean Foster                                               <gate.hpp>
 * Date: 11/23/2017
 * Description: Gate class declaration, the gate can be unlocked with a key
******************************************************************************/
#ifndef GATE_HPP
#define GATE_HPP

#include "passage.hpp"

class Gate : public Passage
{
  public:
    Gate();
    ~Gate();
    bool unLock(Item *);
    void unLock();
};

#endif