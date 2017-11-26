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

OBJS = menu.o validator.o die.o game.o  space.o player.o monsterroom.o main.o

SRCS = menu.cpp validator.cpp die.cpp game.cpp  space.cpp player.cpp monsterroom.cpp main.cpp

HEADERS = menu.hpp validator.hpp die.hpp game.hpp space.hpp player.hpp monsterroom.hpp 

#target: dependencies
#		rule to build

game: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o game