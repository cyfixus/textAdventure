/******************************************************************************
 * Author: Sean Foster                                            <passage.hpp>
 * Date: 11/23/2017
 * Description: Passage class declaration, these are obstacles between spaces
 *               they have names and can be locked and unlocked.
******************************************************************************/
#ifndef PASSAGE_HPP
#define PASSAGE_HPP

#include "item.hpp"

class Passage
{
protected:
  std::string name; 
  bool locked;
public:
  Passage();
  virtual ~Passage();
  void setName(std::string);
  std::string getName();
  bool isLocked();
  virtual bool unLock(Item *);
  virtual void unLock();
};

#endif