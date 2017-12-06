/******************************************************************************
 * Author: Sean Foster                                            <monster.hpp>
 * Date: 11/23/2017
 * Description: Monster class declaration, allows for printing of the monster
 *                  icons. Originally this was to be an inherited class from
 *                  entity, but I found I wanted to display the ascii(unicode)
 *                  art a little more than try to implement serious battle
 *                  functionality, so I stuck with the proper equipment to win
 *                  monster pretty much mirrors item, I had trouble inheriting
 *                  it from item when I realized what I was doing, but couldn't
 *                  get it to work properly and landed on this, it works...
******************************************************************************/
#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <fstream>
#include <iostream>

class Monster
{
protected:
  std::string name;
  std::string icon;
public:
  Monster();
  Monster(std::string, std::string);
  virtual ~Monster();
  void setName(std::string);
  std::string getName();
  void setIcon(std::string);
  void loadIcon();
  void printIcon(std::ifstream&);
};

#endif