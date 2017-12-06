###############################################################################
# Author: Sean Foster         																		   <Makefile>
# Date: 11/23/2017
# Description: Makefile for Final Project: A Text-based Game
###############################################################################
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = menu.o validator.o die.o game.o space.o entity.o monster.o ram.o boss.o player.o monsterspace.o bossspace.o treasurespace.o trapspace.o item.o key.o sword.o shield.o torch.o death.o map.o passage.o gate.o bushwall.o main.o

SRCS = menu.cpp validator.cpp die.cpp game.cpp space.cpp entity.cpp monster.cpp ram.cpp boss.cpp player.cpp monsterspace.cpp bossspace.cpp treasurespace.cpp trapspace.cpp item.cpp key.cpp sword.cpp shield.cpp torch.cpp death.cpp map.cpp passage.cpp gate.cpp bushwall.cpp main.cpp

HEADERS = menu.hpp validator.hpp die.hpp game.hpp space.hpp entity.hpp monster.hpp ram.hpp boss.hpp player.hpp monsterspace.hpp bossspace.hpp treasurespace.hpp trapspace.hpp item.hpp key.hpp sword.hpp shield.hpp torch.hpp death.hpp passage.hpp gate.hpp bushwall.hpp map.hpp 

#target: dependencies
#		rule to build

game: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o game