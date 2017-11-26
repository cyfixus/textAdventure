/******************************************************************************
 * Author: Sean Foster                                               <item.hpp>
 * Date: 11/23/2017
 * Description: item class declaration
******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <fstream>

class Item
{
  private:
    std::string name = "";
  public:
    Item();
    virtual ~Item() = 0;
};

#endif