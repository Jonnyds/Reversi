cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)
add_definitions(-std=gnu++0x)

set(SOURCE_FILES main.cpp Board.cpp Board.h Disc.cpp Disc.h BoardLogic.cpp BoardLogic.h PlayerHuman.cpp PlayerHuman.h GameFlow.cpp GameFlow.h PlayerType.cpp PlayerType.h PlayerAI.cpp PlayerAI.h Menu.cpp Menu.h PlayerClient.cpp PlayerClient.h)
add_executable(main ${SOURCE_FILES})
