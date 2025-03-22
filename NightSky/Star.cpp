#include <iostream>
#include "Star.hpp"
using namespace std;

Star::Star(int x, int y, int brightness){
    set_coordinates(x, y);
    set_brightness(brightness);

    this->x = x;
    this->y = y;
    this->brightness = brightness; 
}

float Star::get_x() const{return x;}
float Star::get_y() const{return y;}
float Star::get_brightness() const{return brightness;}

void Star::set_coordinates(int x, int y){
    if(x<0 || x>20 || y<0 || y>20){
        throw invalid_argument("coordinates must be between 0 and 20 ! \n");
    }
}

void Star::set_brightness(int brightness){
    if(brightness<1 || brightness>100){
        throw invalid_argument("Brightness star must be between 1 and 100 ! \n");
    }
}