cmake_minimum_required(VERSION 3.10)
project(Medical)

set(CMAKE_CXX_STANDARD 11)

add_executable(Medical Hospital.cpp Patient.cpp main.cpp)