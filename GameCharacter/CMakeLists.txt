cmake_minimum_required(VERSION 3.10) 
project(GAME_Vector)       

set(CMAKE_CXX_STANDARD 11)              

add_executable(game_app Game.cpp Character.cpp main.cpp)