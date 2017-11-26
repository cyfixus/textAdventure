/******************************************************************************
 * Author: Sean Foster                                               <menu.cpp>
 * Date: 11/01/2017
 * Description: Menu function displays input string as options list. 
 *              optionCount ensures a valid selection can be returned.
******************************************************************************/
#include "menu.hpp"

int menu(string menuOptions, int optionCount)
{
  string choice = "";
  int selection = 0;
  bool invalidSelection = true;
  //loops until valid selection is made
  while(invalidSelection)
  {
    //print out the menu and get the choice
    std::cout << menuOptions;
    std::getline(std::cin, choice);
    //IntValidator is a struct returning whether the passed string was an int
    //and the valid int if one was entered
    if(choice != "")
    {
      IntValidator intValidator = getIntValidator(choice);

      if(intValidator.Valid)
      {
        selection = intValidator.validInt;
        if((selection > 0 && selection <= optionCount) || optionCount == -1)
        {
          invalidSelection = false;
        }
      }
    }
  }  
  return selection;
}


/******************************************************************************
 * getString returns a string for a particular target
******************************************************************************/
string getString(string target)
{
  string choice = "";
  std::cout << "\nPlease enter a string for " << target << ": ";
  std::getline(std::cin, choice);
  return choice;
}


/******************************************************************************
 * getInt Asks user to enter a valid integer and repeats until user enters a 
 * valid integer as validated through an IntValidator
******************************************************************************/
int getInt()
{
  return menu("\nPlease enter a valid integer:\n", -1);
}