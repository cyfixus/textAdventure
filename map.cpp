/******************************************************************************
 * Author: Sean Foster                                                <map.cpp>
 * Date: 11/23/2017
 * Description: Map class definition
******************************************************************************/
#include "map.hpp"

/******************************************************************************
 * Map constructor creates the items, monsters, rooms, puts the items and
 *  monsters in the rooms, then connects the rooms and sets the currentSpace
 *  to the torchRoom.
******************************************************************************/
Map::Map()
{
  createItems();
  createMonsters();
  createRooms();
  connectRooms();
  currentSpace = torchRoom;
}

/******************************************************************************
 * deallocates all the contents of the map
******************************************************************************/
Map::~Map()
{
  delete torchRoom;
  delete keyRoom;
  delete shieldRoom;
  delete swordRoom;
  delete deathRoom;
  delete ramRoom;
  delete bossRoom;

  delete torch;
  delete shield;
  delete sword;
  delete key;

  delete rams;
  delete nuclearBot;
}

/******************************************************************************
 * allocates the torch, key, sword, and shield
******************************************************************************/
void Map::createItems()
{
  torch = new Torch();
  key = new Key();
  sword = new Sword();
  shield = new Shield();
}

/******************************************************************************
 * allocates the rams and the boss
******************************************************************************/
void Map::createMonsters()
{
  rams = new Ram();
  nuclearBot = new Boss();
}

/******************************************************************************
 * creates all seven spaces, the torch room, the key room, the sword room,
 * the shield room, the trap space, the ram room, and the boss room
******************************************************************************/
void Map::createRooms()
{
  torchRoom = new TreasureSpace();
  torchRoom->setName("torch room");
  torchRoom->setItem(torch);
  torchRoom->unLockDoor();

  keyRoom = new TreasureSpace();
  keyRoom->setName("key room");
  keyRoom->setItem(key);
  keyRoom->unLockDoor();

  swordRoom = new TreasureSpace();
  swordRoom->setName("sword room");
  swordRoom->setItem(sword);

  shieldRoom = new TreasureSpace();
  shieldRoom->setName("shield room");
  shieldRoom->setItem(shield);
  shieldRoom->unLockDoor();

  deathRoom = new TrapSpace();

  ramRoom = new MonsterSpace();
  ramRoom->setName("ram room");
  ramRoom->setMonster(rams);

  bossRoom = new BossSpace();
  bossRoom->setName("boss room");
  bossRoom->setBoss(nuclearBot);
}

/******************************************************************************
 * connects the rooms accoringly
*                     _________________                   _________________
*                   |                 |                 |                 |
*                   |     ☠☠☠☠☠☠☠     |                 |                 |
*                   |     ☠ʘ☠ ☠ʘ☠     |                 |       ┏┳┳┓      |
*                   |     ☠☠☠ʆ☠☠☠     |                 |       ☢┖┚☢      |
*                   |      ☠╙╖╫☠      |                 |        ʮʝ       |
*                   |      ☠☠☠☠☠      |                 |       ξ┃┃ζ      |
*                   |                 |                 |       ┏┻┻┓      |
*                   |                 |                 |                 |
*  _________________|____         ____|_________________|____         ____|
* |                 |    🚪🚪🚪🚪🚪🚪🚪🚪🚪    |                 |    ՊՊՊՊՊՊՊՊՊ    |
* |                 |                 |       ɤ         |                 |
* |        ╽        🚪                []                []                 |
* |        ┃        🚪       ɚϫʵ      []    ɤ      ɤ    []       ┏┯┓       |
* |       ┍╋┑       🚪       ┕╫┙      []                []       ƪ◍ʃ       |
* |        ╹        🚪        ║       []                []                 |
* |                 🚪                []            ɤ   []                 |
* |                 |                 |                 |                 |
* |_________________|____         ____|_________________|_________________|
*                   |                 |            
*                   |                 |            
*                   |                 |            
*                   |                 |            
*                   |      Ϡ━┻┻       |            
*                   |                 |            
*                   |                 |            
*                   |                 |            
*                   |_________________|            
*
******************************************************************************/
void Map::connectRooms()
{
  torchRoom->setBottom(keyRoom);
  keyRoom->setTop(torchRoom);
  torchRoom->setLeft(swordRoom);
  swordRoom->setRight(torchRoom);
  torchRoom->setTop(deathRoom);
  deathRoom->setBottom(torchRoom);
  torchRoom->setRight(ramRoom);
  ramRoom->setLeft(torchRoom);
  ramRoom->setRight(shieldRoom);
  shieldRoom->setLeft(ramRoom);
  shieldRoom->setTop(bossRoom);
  bossRoom->setBottom(shieldRoom);
}

/******************************************************************************
 * returns the current space the player occupies on the map
******************************************************************************/
Space *Map::getCurrentSpace()
{
  return this->currentSpace;
}

/******************************************************************************
 * gives the player options and moves accordingly
******************************************************************************/
int Map::move(Player *player)
{
  string moveOptions = "\n***************************************************"
                       "\nWould you like to look around?\n1. Look around here"
                       "\n\nOr travel in another direction?"
                       "\n2. North\n3. East\n4. South\n5. West"
                       "\n\nOr do something else..."
                       "\n6. Drop Item\n7. Give up\n";
  int choice = menu(moveOptions, 7);
  switch(choice)
  {
    case 1:
      //the player can interact with the current space(pick up items)
      currentSpace->interact(player);
      break;
    //2-5 player tries to move, top, right, bottom, left
    case 2:
      moveToSpace(currentSpace->getTop(), player);
      break;
    case 3:
      moveToSpace(currentSpace->getRight(), player);
      break;
    case 4:
      moveToSpace(currentSpace->getBottom(), player);
      break;
    case 5:
      moveToSpace(currentSpace->getLeft(), player);
      break;
    case 6:
      //brings up the player's menu to drop an item, to allow for returning
      //to the interact(pick up) menu.
      player->dropItem();
      break;
    case 7:
      break;
  }
  return choice;
}

/******************************************************************************
 * starts off reporting the player's inventory. if the space the player is
 * trying to move to is a nullptr, the player is informed that they've hit a 
 * wall, otherwise, the player tries to enter the space (calling the space 
 * derivitives function if possible), the currentspace is changed to the
 * moved to space and the player loses one hit point, reporting the results
******************************************************************************/
void Map::moveToSpace(Space *space, Player *player)
{
  player->listInventory();
  if(space != nullptr)
  {
    if(space->enter(player))
    {
      this->currentSpace = space;
      player->adjustHitPoints(-1);
      std::cout << "\nYou weaken entering the " << space->getName() <<
                   "\nYou have the energy to take " << player->getHitPoints()
                   << " more steps\n";
    }
  }
  else
  {
    std::cout << "\nYou smack your face into a slimy wall!\nGROSS!\n"
                 "You can't go that direction\n";
  }
}