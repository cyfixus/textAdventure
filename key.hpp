/******************************************************************************
 * Author: Sean Foster                                                <key.hpp>
 * Date: 11/23/2017
 * Description: Key class declaration, inhereints icon to display key icon
******************************************************************************/
#ifndef KEY_HPP
#define KEY_HPP

#include "item.hpp"

class Key : public Item
{
  public:
    Key();
    ~Key();
};

#endif