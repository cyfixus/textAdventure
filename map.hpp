/******************************************************************************
 * Author: Sean Foster                                                <map.hpp>
 * Date: 11/23/2017
 * Description: Map class declaration, the map holds all the spaces, all the 
 *              items, and all the bad guys. It also sets them all up, and 
 *              puts them in their approrpriate spaces. I'd thought I could
 *              make this thing happen randomly, but I was wasting too much
 *              time not getting it to work.
******************************************************************************/
#ifndef MAP_HPP
#define MAP_HPP

#include "torch.hpp"
#include "key.hpp"
#include "sword.hpp"
#include "shield.hpp"
#include "monsterspace.hpp"
#include "bossspace.hpp"
#include "treasurespace.hpp"
#include "trapspace.hpp"
#include "player.hpp"
#include "ram.hpp"
#include "boss.hpp"
#include "menu.hpp"


class Map
{
  private:
    Space *torchRoom;
    Space *swordRoom;
    Space *keyRoom;
    Space *deathRoom;
    Space *ramRoom;
    Space *shieldRoom;
    Space *bossRoom;

    Space *currentSpace;

    Item *torch;
    Item *key;
    Item *sword;
    Item *shield;

    Ram *rams;
    Boss *nuclearBot;
    void createItems();
    void createMonsters();
    void createRooms();
    void connectRooms();

  public:
    Map();
    ~Map();
    Space *getCurrentSpace();
    int move(Player *);
    void moveToSpace(Space *, Player *);

};

#endif