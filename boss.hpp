/******************************************************************************
 * Author: Sean Foster                                               <boss.hpp>
 * Date: 11/23/2017
 * Description: Boss class declaration inherints monster to display icons
******************************************************************************/
#ifndef BOSS_HPP
#define BOSS_HPP

#include "monster.hpp"

class Boss : public Monster
{
public:
  Boss();
  ~Boss();
};

#endif