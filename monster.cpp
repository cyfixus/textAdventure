/******************************************************************************
 * Author: Sean Foster                                            <monster.cpp>
 * Date: 11/23/2017
 * Description: Monster class declaration
******************************************************************************/
#include "monster.hpp"

/******************************************************************************
 * Monster constructor sets a blank icon
******************************************************************************/
Monster::Monster()
{
  setName("");
  setIcon("");
}

/******************************************************************************
 * creates Monster with a specified name and icon
******************************************************************************/
Monster::Monster(std::string name, std::string icon)
{
  setName(name);
  setIcon(icon);
}
Monster::~Monster()
{

}

/******************************************************************************
 * sets the monster icon(path)
******************************************************************************/
void Monster::setIcon(std::string icon)
{
  this->icon = icon;
}

/******************************************************************************
 * sets the monster's name
******************************************************************************/
void Monster::setName(std::string name)
{
  this->name = name;

}

/******************************************************************************
 * returns the monster's name
******************************************************************************/
std::string Monster::getName()
{
  return this->name;
}

/******************************************************************************
 * creates an ifstream to open the icon(path) and print it if exists
******************************************************************************/
void Monster::loadIcon()
{
  std::ifstream ifs;
  ifs.open(icon.c_str());
  if(ifs)
  {
    printIcon(ifs);
  }
  else
  {
    std::cout << "\ncouldn't find " << icon << std::endl;
  }
  ifs.close();
}

/******************************************************************************
 * prints the ifstream line by line
******************************************************************************/
void Monster::printIcon(std::ifstream &ifs)
{
  bool keepReading = true;
  while(keepReading)
  {
    std::string line = "";
    std::getline(ifs, line);
    std::cout << line << std::endl;
    if(ifs.peek() == EOF)
    {
      keepReading = false;
    }
  }
}
