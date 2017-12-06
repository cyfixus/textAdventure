/******************************************************************************
 * Author: Sean Foster                                              <space.hpp>
 * Date: 11/23/2017
 * Description: Space class declaration, spaces have the potential to hold an
 *              item, this was originally so you could place an item down
 *              somewhere to retrieve it, but I couldn't get it working so
 *              if you drop an item, it will disappear = )
 *              the base space class is aware of the player, the item base
 *              class, and the individual boss and ram classes(I was having
 *              trouble with inheriting monster and bassing boss)
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <sstream>
#include <vector>
#include "die.hpp"
#include "menu.hpp"
#include "player.hpp"
#include "item.hpp"
#include "boss.hpp"
#include "ram.hpp"

class Space
{
    /**************************************************************************
     * space base holds the name of the space, its item pointer, whether or not
     * that item has been picked up, and poitners to the other four spaces
    **************************************************************************/
  protected:
    std::string name;
    Item *item;
    bool pickedUp;
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    /**************************************************************************
     * spaces can be entered, interacted with by a player, and doors can be
     * unlocked. the boss and monsters can also be set 
     * a space can move to another space, and set the name, get the name of 
     * the space, as well as allow the player to retrieve the item, and deal
     * with the logistics of the item pointer.
    **************************************************************************/
  public:
    Space();
    virtual ~Space();
    virtual bool enter(Player *);
    virtual void unLockDoor();
    virtual bool interact(Player *);
    virtual void setBoss(Boss *);
    virtual void setMonster(Ram *);
    bool moveTo(Space *);
    void setName(std::string);
    std::string getName();
    void retrieveItem(Player *);
    void setItem(Item *);
    Item* getItem();

    //setters getters for adjacent spaces
    void setTop(Space *);
    void setRight(Space *);
    void setBottom(Space *);
    void setLeft(Space *);
    Space * getTop();
    Space * getRight();
    Space * getBottom();
    Space * getLeft();


};
#endif