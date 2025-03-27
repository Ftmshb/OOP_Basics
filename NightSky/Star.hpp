#ifndef STAR_HPP
#define STAR_HPP
#include <iostream>

class Star{

    private:
    int x;
    int y;
    int brightness;
    
    public:
    Star(int x, int y, int brightness);
    int get_x() const;
    int get_y() const;
    int get_brightness() const;
    void set_coordinates(int x, int y);
    void set_brightness(int brightness);

};

#endif