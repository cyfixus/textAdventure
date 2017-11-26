/******************************************************************************
 * Author: Sean Foster                                                <die.cpp>
 * Date: 10/23/2017
 * Description: Die class definition. I kept getting errors from inheritence 
 * requesting a default constructor, so I created one to call the one with
 * sides. The used constructor sets N to the number of sides passed into the
 * constructor, and sets the total and lastRoll ints to 0. 
******************************************************************************/
#include "die.hpp"

Die::Die()
{
  Die(0);
}

Die::Die(int sides)
{
  setSides(sides);
  this->total = 0;
  this->lastRoll = 0;
  this->score = 0;
}

Die::~Die()
{

}

void Die::setSides(int sides)
{
  this->N = sides;
}

/******************************************************************************
 * roll 
 * the seed calculation was found at 
 * http://www.cplusplus.com/reference/algorithm/shuffle/ . I kept having
 * trouble acquiring different rolls for each die since the execution time was
 * really fast, but I found the use of this chrono function to give me the most
 * variable results of any seed method I  tried.
******************************************************************************/
int Die::roll()
{
  int roll = 0;
  if(this->N > 0)
  {
    unsigned seed = 
                  std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    roll = rand() % this->N + 1;
  }
  setLastRoll(roll);
  return roll;
}

/********************************
 * getSides returns the number of sides, used in output and averaging
 *******************************/
int Die::getSides()
{
  return this->N;
}

/*******************************
 * getLasRoll returns whatever the lastRoll was set to
 ******************************/
int Die::getLastRoll()
{
  return this->lastRoll;
}

/*******************************
 * setLastRoll sets the lastRoll member variable and returns it
 * I decided to return the value, to let the function also serve
 * to increment the total
 ******************************/
int Die::setLastRoll(int lastRoll)
{
  this->lastRoll = lastRoll;
  return this->lastRoll;
}

/*******************************
 * getTotal returns the total member variable
 *****************************/
int Die::getTotal()
{
  return this->total;
}

/******************************
 * returns the score, the points from rounds the Die has won
 *****************************/
int Die::getScore()
{
  return this->score;
}

/******************************
 * increases the score by 1
 *****************************/
void Die::incScore()
{
  this->score++;
}

/********************************
 * setTotal sets the total member variable to the passed total
 ********************************/
void Die::setTotal(int total)
{
  this->total = total;
}

/******************************
 * type returns in int representative of this as a normal die
 ******************************/
int Die::type()
{
  return 0;
}