/******************************************************************************
 * Author: Sean Foster                                          <validator.cpp>
 * Date: 11/01/2017
 * Description: Validates input string for int
******************************************************************************/
#include "validator.hpp"

/******************************************************************************
 * isValidInt takes in a string, and sets an iterator i to 0. this function 
 * accepts signed numbers by skipping the iterator ahead if the first 
 * character is the negative sign. each char of the string is iterated 
 * through,each char is validated as a digit, if neither, false is returned
******************************************************************************/
bool isValidInt(string checkString)
{
  int i = 0;
  if(checkString.at(i)=='-')
  {
    i++;
  }
  for(; i < (int)checkString.length(); ++i)
  {
    if (!std::isdigit(checkString.at(i)))
    {
      return false;
    }
  }
  return true;
}

/******************************************************************************
 * getIntValidator takes in a string, checks that its a valid int, then calls
 * std::stoi, to convert it to an int. returns an IntValidator struct that is
 * used in menu to validate user input and get the valid input as well. I
 * realized returning -1 wouldn't really be an issue for a menu, but if I were
 * to extend menu, or even to use these functions elsewhere, It should be able
 * to deal with negative numbers, rather than using the negative value as false
******************************************************************************/
IntValidator getIntValidator(string checkString)
{
  bool valid = false;
  int validInt = 0;
  if (isValidInt(checkString))
  {
    try{
      validInt = std::stoi(checkString, nullptr, 0);
      valid = true;
    }
    catch (const std::out_of_range& oor)
    {
      valid = false;
    }
  }
  return {valid, validInt};
}