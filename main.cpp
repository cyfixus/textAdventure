/******************************************************************************
 * Author: Sean Foster                                               <main.cpp>
 * Date: 11/23/2017
 * Description: Main for final project
******************************************************************************/
#include "menu.hpp"
#include "game.hpp"

#include <fstream>

/******************************************************************************
 * creates a newGame and asks the user to play again once the game is over
******************************************************************************/
int newGame()
{
  Game *game = new Game();
  delete game;
  int choice = menu("\nWould you like to play again?\n1. Yes\n2. No\n", 2);
  return choice;
}

/******************************************************************************
 * repeats the main story to the user starting a new game so long as the user
 * chooses to continue playing
******************************************************************************/
int main()
{
  string welcome = "\nWelcome! You are Stuck.\nWhile flitting among the"
                   " foliage, your carefree afternoon was interuppted as you" 
                   " clumsily fell through a patch of false earth.\nWhen you"
                   " finally come to, you find yourself in a moist, dark, and"
                   " smelly room."
                   "\n Strange sounds reverberate among the walls. There"
                   " must be some way out of this dumps.\n From the hole"
                   " through which you fell, enough light has made it to the"
                   " depths to allow you take make out the four directions"
                   " within the room.\nWould you care to look around?\n1. Look"
                   " around\n2. Quit\n";
  while(menu(welcome, 2) != 2)
  {
    if(newGame() == 2)
    {
      break;
    }
  }
  return 0;
}