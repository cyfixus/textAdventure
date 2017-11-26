/******************************************************************************
 * Author: Sean Foster                                          <validator.hpp>
 * Date: 10/23/2017
 * Description: Validator prototypes, the function uses string functions like
 *              at(), length() so I included the using directive here, I also 
 *              used the isdigit() function located in cctype
******************************************************************************/
#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP
#include <cctype>
#include <string>
#include <stdexcept>
#include <iostream>

using std::string;
/******************************************************************************
 * IntValidator struct used to return whether a string was a valid int and if
 * so the valid int is also returned.
******************************************************************************/
struct IntValidator
{
  bool Valid;
  int validInt;
};

bool isValidInt(string);
IntValidator getIntValidator(string);

#endif