/******************************************************************************
 * Author: Sean Foster                                                <die.hpp>
 * Date: 10/23/2017
 * Description: Die class header. Die have N representative of the number of
 *              sides, lastRoll to keep track of the last roll to allow passing
 *              of the Die object, rather than individual variables that can be
 *              contained within the Die object. Total represents the total of 
 *              all the rolls. 
 *              There is a default constructor, a constructor that takes an int
 *              which is the one used by the program, a virtual destructor,
 *              virtual roll function, getters and setters, and a function to
 *              ask whether or not the die type is loaded.
******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <random>
#include <chrono>

class Die
{

  protected: 
    int N;
    int lastRoll;
    int total;
    int score;

  public:
    Die();
    Die(int);
    virtual ~Die();
    virtual int roll();
    int getSides();
    int getLastRoll();
    int setLastRoll(int);
    int getTotal();
    int getScore();
    void incScore();
    void setTotal(int);
    void setSides(int);
    virtual int type();
};

#endif