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

int Star::get_x() const{return x;}
int Star::get_y() const{return y;}
int Star::get_brightness() const{return brightness;}

void Star::set_coordinates(int x, int y){
    if(x<0 || x>20 || y<0 || y>20){
        throw invalid_argument("coordinates must be between 0 and 20 ! \n");
    }
}

void Star::set_brightness(int brightness){
    if(brightness<1 || brightness>3){
        throw invalid_argument("Brightness star must be 1 or 2 or 3 ! \n");
    }
}