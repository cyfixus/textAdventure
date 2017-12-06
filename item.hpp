/******************************************************************************
 * Author: Sean Foster                                               <item.hpp>
 * Date: 11/23/2017
 * Description: item class declaration, items are the bases for the four items
 *              in the game. key, torch, sword, and shield. the base class 
 *              provides access to print the icons corressponding to the items
******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <fstream>
#include <iostream>

class Item
{
  private:
    std::string name;
    std::string icon;
  public:
    Item();
    Item(std::string, std::string);
    virtual ~Item();
    void setName(std::string);
    std::string getName();
    void setIcon(std::string);
    void loadIcon();
    void printIcon(std::ifstream&);
};

#endif