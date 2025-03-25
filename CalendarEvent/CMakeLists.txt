cmake_minimum_required(VERSION 3.10) 
project(CalendarEvent_Vector)       

set(CMAKE_CXX_STANDARD 11)              

add_executable(Event_app Calendar.cpp Event.cpp main.cpp)