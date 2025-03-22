cmake_minimum_required(VERSION 3.10) 
project(NightSky_Vector)       

set(CMAKE_CXX_STANDARD 11)              

add_executable(Star_app Sky.cpp Star.cpp main.cpp)