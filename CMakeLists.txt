cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Disc.cpp Disc.h BoardLogic.cpp BoardLogic.h PlayerHuman.cpp PlayerHuman.h GameFlow.cpp GameFlow.h PlayerType.cpp PlayerType.h PlayerAI.cpp PlayerAI.h)
add_executable(Ex2 ${SOURCE_FILES})