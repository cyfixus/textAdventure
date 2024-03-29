/******************************************************************************
 * Author: Sean Foster                                               <item.cpp>
 * Date: 11/23/2017
 * Description: Item class definition
******************************************************************************/
#include "item.hpp"

/******************************************************************************
 * Item constructor sets up a blank icon
******************************************************************************/
Item::Item()
{
  setName("");
  setIcon("");
}
/******************************************************************************
 * Item constructor sets up an item with passed paramters
******************************************************************************/
Item::Item(std::string name, std::string icon)
{
  setName(name);
  setIcon(icon);
}

Item::~Item()
{

}

/******************************************************************************
 * sets the icon string(path)
******************************************************************************/
void Item::setIcon(std::string icon)
{
  this->icon = icon;
}

/******************************************************************************
 * sets the icon name
******************************************************************************/
void Item::setName(std::string name)
{
  this->name = name;

}

/******************************************************************************
 * returns icon name
******************************************************************************/
std::string Item::getName()
{
  return this->name;
}

/******************************************************************************
 * creates an ifstream based on the icon(path) and calls printIcon
******************************************************************************/
void Item::loadIcon()
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
 * opens up the plaintext file refereenced by icon(path) and prints it line by
 * line to the terminal.
******************************************************************************/
void Item::printIcon(std::ifstream &ifs)
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
